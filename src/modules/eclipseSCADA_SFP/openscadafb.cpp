/*******************************************************************************
 * Copyright (c) 2007-2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "openscadafb.h"

COpenSCADAFB::COpenSCADAFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
    const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData,
    TForteByte *pa_acFBVarsData) :
        CFunctionBlock(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData),
        m_bInitialized(false), m_ppstInputItemList(0), m_ppstOutputItemList(0){

}

COpenSCADAFB::~COpenSCADAFB(){
  delete[] m_ppstInputItemList;
}

void COpenSCADAFB::allocateOpenScadaData(TForteUInt8 pa_unNumDIs, TForteUInt8 pa_unNumDOs){
  if(0 != m_ppstInputItemList){
    // we are reconfigured free data first
    delete[] m_ppstInputItemList;
  }
  else{
    // this is the first time this FB tries to configure check if OpenSCADA handler is running and start if necessary
    if(!COpenSCADASFPServerHandler::getInstance().isAlive()){
      COpenSCADASFPServerHandler::getInstance().start();
    }
  }

  if((0 != pa_unNumDIs) || (0 != pa_unNumDOs)){
    m_ppstInputItemList = new TOpenSCADAItem[pa_unNumDOs];
    m_ppstOutputItemList = &(m_ppstInputItemList[pa_unNumDIs]);
  }
}

bool COpenSCADAFB::registerDataPoints(CIEC_STRING &pa_roBaseAddress, TForteUInt8 pa_unNumDIs, const CStringDictionary::TStringId* pa_cacDataInputNames, TIEC_ANYPtr pa_poDataInputs,
    TForteUInt8 pa_unNumDOs, const CStringDictionary::TStringId* pa_cacDataOutputNames, TIEC_ANYPtr pa_poDataOutputs){
  bool bRetVal = false;
  COpenSCADASFPServerHandler &roOpenSCADAHandler(COpenSCADASFPServerHandler::getInstance());

  allocateOpenScadaData(pa_unNumDIs, pa_unNumDOs);

  TForteUInt16 unBaseAddrLength = pa_roBaseAddress.length();
  char *acItemIdBuffer = new char[unBaseAddrLength + cg_nIdentifierLength];
  strncpy(acItemIdBuffer, pa_roBaseAddress.getValue(), unBaseAddrLength);

  if(0 != pa_unNumDIs){
    for(unsigned int i = 0; i < pa_unNumDIs; i++){
      strncat(acItemIdBuffer, CStringDictionary::getInstance().get(pa_cacDataInputNames[i]), cg_nIdentifierLength);
      acItemIdBuffer[unBaseAddrLength + cg_nIdentifierLength] = '\0';
      //TODO find way of export datapoint comments for selected FBs like these without the need that all FBs will get them
      roOpenSCADAHandler.registerReadDataPoint(m_ppstInputItemList[i], acItemIdBuffer, "Test description", pa_poDataInputs[i]);
      //FIXME add error handling and roll back if registration didn't work
    }
  }

  if(0 != pa_unNumDOs){
    for(unsigned int i = 0; i < pa_unNumDOs; i++){
      strncat(acItemIdBuffer, CStringDictionary::getInstance().get(pa_cacDataOutputNames[i]), cg_nIdentifierLength);
      acItemIdBuffer[unBaseAddrLength + cg_nIdentifierLength] = '\0';
      //TODO find way of export datapoint comments for selected FBs like these without the need that all FBs will get them
      roOpenSCADAHandler.registerWriteDataPoint(m_ppstOutputItemList[i], acItemIdBuffer, "Test description", pa_poDataOutputs[i], this);
      //FIXME add error handling and roll back if registration didn't work
    }
  }
  bRetVal = true;
  return bRetVal;
}

void COpenSCADAFB::unregisterDataPoints(TForteUInt8 pa_unNumDIs, TForteUInt8 pa_unNumDOs){
  if(m_bInitialized){
    COpenSCADASFPServerHandler &roOpenSCADAHandler(COpenSCADASFPServerHandler::getInstance());
    if((0 != pa_unNumDIs) && (0 != m_ppstInputItemList)){
      for(unsigned int i = 0; i < pa_unNumDIs; i++){
        roOpenSCADAHandler.unregisterReadDataPoint(m_ppstInputItemList[i]);
      }
    }

    if((0 != pa_unNumDOs) && (0 != m_ppstOutputItemList)){
      for(unsigned int i = 0; i < pa_unNumDOs; i++){
        roOpenSCADAHandler.unregisterWriteDataPoint(m_ppstOutputItemList[i]);
      }
    }
    m_bInitialized = false;
  }
}
