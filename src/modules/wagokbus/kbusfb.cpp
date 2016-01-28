/*******************************************************************************
 * Copyright (c) 2007 - 2015 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "kbushandler.h"
#include "kbusfb.h"

CKBusFB::CKBusFB(CResource *pa_poSrcRes,
    const SFBInterfaceSpec *pa_pstInterfaceSpec,
    const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData,
    TForteByte *pa_acFBVarsData) :
        CEventSourceFB(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData),
        m_acIndata(0),
        m_acOutdata(0),
        m_bInitialized(false){
}

CKBusFB::~CKBusFB(){
  delete[] m_acIndata;
}

void CKBusFB::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventINITID:
      handleINIT();
      break;
    case scm_nEventREQID:
      handleREQ();
      break;
    case cg_nExternalEventID:
      handleExternalEvent();
      break;
    default:
      break;
  }
}

void CKBusFB::handleINIT(){
  if(true == QI() && (!m_bInitialized)){
    initialize();
  }
  else if(m_bInitialized){
    deInitialize();
  }
  sendOutputEvent(scm_nEventINITOID);
}

void CKBusFB::handleREQ(){
  if(true == QI()){
    if(m_bInitialized){
      if(CKBusHandler::getInstance().isKBusRunning()){
        //the read data needs not to be read again as this already handled in the external event
        //and with the sendOutputEvent it will be applied to the connection
        udpateKBusOutputData();
        CKBusHandler::getInstance().writeOutputDataToKBus(m_acOutdata, m_pstTerminalInfo);
        sendOutputEvent(scm_nEventCNFID);
      }
      else{
        deInitialize();
        sendOutputEvent(scm_nEventINITOID);
      }
    } else{
      QO() = false;
      sendOutputEvent(scm_nEventREQID);
    }
  }
  else{
    //inhibited FB execution
    sendOutputEvent(scm_nEventREQID);
  }
}

void CKBusFB::handleExternalEvent(){
  if(CKBusHandler::getInstance().isKBusRunning()){
    applyKBusInputData();
    QO() = true;
    sendOutputEvent(scm_nEventINDID);
  }
  else{
    deInitialize();
    sendOutputEvent(scm_nEventINITOID);
  }
}

bool CKBusFB::onKBusCylce(CKBusHandler &pa_roKBusHandler){
  bool bRetval = false;

  if(0 != m_pstTerminalInfo->SizeInput_bits){
    TForteByte *acNewInputData = pa_roKBusHandler.readInputDataFromKBus(m_pstTerminalInfo);
    bRetval = (0 != memcmp(m_acIndata, acNewInputData, getInputDataSize()));
    memcpy(m_acIndata, acNewInputData, getInputDataSize());
  }

  return bRetval;
}

void CKBusFB::initialize(){
  QO() = false;

  if(checkTerminalId(CKBusHandler::getInstance().getTerminalId(SLOT()))){
    m_pstTerminalInfo = CKBusHandler::getInstance().getTerminalInfo(SLOT());
    if(0 != m_pstTerminalInfo){

      if(0 == m_acIndata){
        allocateIOData();
      }

      if(0 != getInputDataSize()){
        CKBusHandler::getInstance().registerKBusReadFB(this);
      }

      if(!CKBusHandler::getInstance().isAlive()){
        CKBusHandler::getInstance().start();
      }
      QO() = true;
      m_bInitialized = true;
      setEventChainExecutor(m_poInvokingExecEnv);
    }
  }
}

void CKBusFB::deInitialize(){
  if(0 != getInputDataSize()){
    CKBusHandler::getInstance().registerKBusReadFB(this);
  }
}


void CKBusFB::allocateIOData(){
  m_acIndata = new TForteByte[getInputDataSize() + getOutputDataSize()];
  m_acOutdata = m_acIndata + getInputDataSize();
}
