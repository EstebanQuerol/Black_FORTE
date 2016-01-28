/*******************************************************************************
 * Copyright (c) 2007 - 2015 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "kbushandler.h"
#include "kbusfb.h"
#include <devexec.h>
#include <devlog.h>
#include <unistd.h>
#include <thread.h>

DEFINE_SINGLETON(CKBusHandler)

const unsigned int CKBusHandler::scm_unMaxTerminalInputData;

CKBusHandler::CKBusHandler() :
    m_unTaskId(0){ // 0 has been taken from example may needs to be rechecked
  tDeviceInfo deviceList[10]; // the list of devices given by the ADI
  size_t nrDevicesFound; // number of devices found

  m_pstAppDevInterface = adi_GetApplicationInterface();

  m_pstAppDevInterface->Init();
  m_pstAppDevInterface->ScanDevices();
  m_pstAppDevInterface->GetDeviceList(sizeof(deviceList), deviceList, &nrDevicesFound);

  // find kbus device

  for(size_t i = 0; i < nrDevicesFound; ++i){
    if(strcmp(deviceList[i].DeviceName, "libpackbus") == 0){
      m_nKBusDeviceId = deviceList[i].DeviceId;
      if(m_pstAppDevInterface->OpenDevice(m_nKBusDeviceId) == DAL_SUCCESS){

        if(loadTerminalInformation()){
          return; //we successfully initialized everything so we can return
        }
      }
    }
  }

  //if we are here the initialization could not be finished clean up and close everything
  closeKBusInterface();
}

CKBusHandler::~CKBusHandler(){
  closeKBusInterface();
}

bool CKBusHandler::isKBusRunning(){
  return ((isAlive()) && (m_nKBusDeviceId != scm_nInvalidDeviceId));
}

tldkc_KbusInfo_TerminalInfo *CKBusHandler::getTerminalInfo(TForteUInt8 pa_unSlot){
  tldkc_KbusInfo_TerminalInfo *pstRetVal = 0;

  if(pa_unSlot <= m_unTerminalCount){
    pstRetVal = &(m_astTerminalDescription[pa_unSlot]);
  }

  return pstRetVal;
}

u16 CKBusHandler::getTerminalId(TForteUInt8 pa_unSlot){
  u16 unRetVal = 0;
  if(pa_unSlot <= m_unTerminalCount){
    unRetVal = m_aunTerminalIds[pa_unSlot];
  }
  return unRetVal;
}

void CKBusHandler::run(){
  //TODO add thread priority settings

  tApplicationStateChangedEvent stEvent;

  // Set application state to "Running" to drive kbus by ourselves.
  stEvent.State = ApplicationState_Running;
  if(DAL_SUCCESS == m_pstAppDevInterface->ApplicationStateChanged(stEvent)){
    while(isAlive()){
      usleep(10000); // wait 10 ms  TODO make this configurable

      if(!triggerKBusCycle()){
        //we have severe problem exit KBus handling thread
        //TODO check how can we recover or at least inform the user
        break;

      }

      // read inputs inform FBs
      updateReadData();

    }
  }
  else{
    DEVLOG_ERROR("CKBusHandler: Set application state to 'Running' failed\n");
  }
  closeKBusInterface();
}

void CKBusHandler::writeOutputDataToKBus(TForteByte *pa_acData, tldkc_KbusInfo_TerminalInfo *pa_pstTerminal){
  m_pstAppDevInterface->WriteStart(m_nKBusDeviceId, m_unTaskId);
  m_pstAppDevInterface->WriteBytes(m_nKBusDeviceId, m_unTaskId, pa_pstTerminal->OffsetOutput_bits, pa_pstTerminal->SizeOutput_bits,
  pa_acData);
  m_pstAppDevInterface->WriteEnd(m_nKBusDeviceId, m_unTaskId);
}

void CKBusHandler::updateReadData(){
  m_oReadFBListSync.lock();
  m_pstAppDevInterface->ReadStart(m_nKBusDeviceId, m_unTaskId); /* lock PD-In data */

  TReadFBContainer::Iterator itEnd(m_lstReadFBList.end());
  for(TReadFBContainer::Iterator itRunner = m_lstReadFBList.begin(); itRunner != itEnd; ++itRunner){
    if((*itRunner)->onKBusCylce(*this)){
      startNewEventChain(*itRunner);
    }
  }

  m_pstAppDevInterface->ReadEnd(m_nKBusDeviceId, m_unTaskId); /* unlock PD-In data */
  m_oReadFBListSync.unlock();
}

TForteByte *CKBusHandler::readInputDataFromKBus(tldkc_KbusInfo_TerminalInfo *pa_pstTerminal){
  m_pstAppDevInterface->ReadBytes(m_nKBusDeviceId, m_unTaskId, pa_pstTerminal->OffsetInput_bits, pa_pstTerminal->SizeInput_bits, m_acInputDataBuffer);

  return m_acInputDataBuffer;
}

void CKBusHandler::enableHandler(void){
//TODO add means for enbabling and disabling KBus event generation
}

void CKBusHandler::disableHandler(void){
}

void CKBusHandler::setPriority(int){
//TODO use rt prempt options for setting kbushandler's thread priority
}

int CKBusHandler::getPriority(void) const{
  return 0;
}

void CKBusHandler::closeKBusInterface(){
  if(0 != m_pstAppDevInterface){
    m_pstAppDevInterface->CloseDevice(m_nKBusDeviceId); // close kbus device
    m_pstAppDevInterface->Exit(); // disconnect ADI-Interface

    m_nKBusDeviceId = scm_nInvalidDeviceId;
    m_pstAppDevInterface = 0;
  }
}

bool CKBusHandler::triggerKBusCycle(){
  bool bRetVal = false;
  uint32_t unPushRetVal = 0;

  if(DAL_SUCCESS == m_pstAppDevInterface->CallDeviceSpecificFunction("libpackbus_Push", &unPushRetVal)){
    if(DAL_SUCCESS == unPushRetVal){
      m_pstAppDevInterface->WatchdogTrigger();
      bRetVal = true;
    }
    else{
      DEVLOG_ERROR("CKBusHandler: Function 'libpackbus_Push' failed\n");
    }
  }
  else{
    DEVLOG_ERROR("CKBusHandler: CallDeviceSpecificFunction for 'libpackbus_Push' failed\n");
  }
  return bRetVal;
}

bool CKBusHandler::loadTerminalInformation(){
  bool bRetVal = false;

  if(KbusInfo_Failed != ldkc_KbusInfo_Create()){
    tldkc_KbusInfo_TerminalInfo terminalDescription[LDKC_KBUS_TERMINAL_COUNT_MAX];

    if(KbusInfo_Failed != ldkc_KbusInfo_GetTerminalInfo(OS_ARRAY_SIZE(terminalDescription), m_astTerminalDescription, &m_unTerminalCount)){

      if(KbusInfo_Failed != ldkc_KbusInfo_GetTerminalList(OS_ARRAY_SIZE(m_aunTerminalIds), m_aunTerminalIds, NULL)){
        bRetVal = true;
      }
      else{
        DEVLOG_ERROR("CKBusHandler: ldkc_KbusInfo_GetTerminalList() failed\n");
      }
    }
    else{
      DEVLOG_ERROR("CKBusHandler: ldkc_KbusInfo_GetTerminalInfo() failed\n");
    }

  }
  else{
    DEVLOG_ERROR("CKBusHandler: ldkc_KbusInfo_Create() failed\n");
  }

  if(!bRetVal){
    ldkc_KbusInfo_Destroy();
  }

  return bRetVal;
}

void CKBusHandler::registerKBusReadFB(CKBusFB *pa_poFB){
  m_oReadFBListSync.lock();
  m_lstReadFBList.push_back(pa_poFB);
  m_oReadFBListSync.unlock();
}

void CKBusHandler::unregisterKBusReadFB(CKBusFB *pa_poFB){
  m_oReadFBListSync.lock();

  TReadFBContainer::Iterator itRunner(m_lstReadFBList.begin());
  TReadFBContainer::Iterator itRefNode(m_lstReadFBList.end());
  TReadFBContainer::Iterator itEnd(m_lstReadFBList.end());

  while(itRunner != itEnd){
    if(*itRunner == pa_poFB){
      if(itRefNode == itEnd){
        m_lstReadFBList.pop_front();
      }
      else{
        m_lstReadFBList.eraseAfter(itRefNode);
      }
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }

  m_oReadFBListSync.unlock();
}
