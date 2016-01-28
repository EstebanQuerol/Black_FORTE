/*******************************************************************************
 * Copyright (c) 2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "anyadapter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "anyadapter_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(CAnyAdapter, g_nStringIdANY_ADAPTER)

const SFBInterfaceSpec CAnyAdapter::scm_stFBInterfaceSpec = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

CAnyAdapter::CAnyAdapter(CStringDictionary::TStringId pa_anAdapterInstanceName, CResource *pa_poSrcRes, bool pa_bIsPlug) :
    CAdapter(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_anAdapterInstanceName, &scm_stFBInterfaceSpec, pa_bIsPlug, 0, 0){
  memset(&m_stCurrentFBInterfaceSpec, 0, sizeof(SFBInterfaceSpec));
}

CAnyAdapter::~CAnyAdapter(){
}

bool CAnyAdapter::connect(CAdapter *pa_poPeer, CAdapterConnection *pa_poAdConn){
  //mirror the peer's interface definition
  m_stCurrentFBInterfaceSpec.m_nNumEIs = pa_poPeer->getAdapterInterfaceSpec()->m_nNumEOs;
  m_stCurrentFBInterfaceSpec.m_aunEINames = pa_poPeer->getAdapterInterfaceSpec()->m_aunEONames;
  m_stCurrentFBInterfaceSpec.m_anEIWith = pa_poPeer->getAdapterInterfaceSpec()->m_anEOWith;
  m_stCurrentFBInterfaceSpec.m_anEIWithIndexes = pa_poPeer->getAdapterInterfaceSpec()->m_anEOWithIndexes;
  m_stCurrentFBInterfaceSpec.m_nNumEOs = pa_poPeer->getAdapterInterfaceSpec()->m_nNumEIs;
  m_stCurrentFBInterfaceSpec.m_aunEONames = pa_poPeer->getAdapterInterfaceSpec()->m_aunEINames;
  m_stCurrentFBInterfaceSpec.m_anEOWith = pa_poPeer->getAdapterInterfaceSpec()->m_anEIWith;
  m_stCurrentFBInterfaceSpec.m_anEOWithIndexes = pa_poPeer->getAdapterInterfaceSpec()->m_anEIWithIndexes;
  m_stCurrentFBInterfaceSpec.m_nNumDIs = pa_poPeer->getAdapterInterfaceSpec()->m_nNumDOs;
  m_stCurrentFBInterfaceSpec.m_aunDINames = pa_poPeer->getAdapterInterfaceSpec()->m_aunDONames;
  m_stCurrentFBInterfaceSpec.m_aunDIDataTypeNames = pa_poPeer->getAdapterInterfaceSpec()->m_aunDODataTypeNames;
  m_stCurrentFBInterfaceSpec.m_nNumDOs = pa_poPeer->getAdapterInterfaceSpec()->m_nNumDIs;
  m_stCurrentFBInterfaceSpec.m_aunDONames = pa_poPeer->getAdapterInterfaceSpec()->m_aunDINames;
  m_stCurrentFBInterfaceSpec.m_aunDODataTypeNames = pa_poPeer->getAdapterInterfaceSpec()->m_aunDIDataTypeNames;


  TForteByte *acFBConnData = new TForteByte[genAdapterFBConnDataSize(m_stCurrentFBInterfaceSpec.m_nNumEIs, m_stCurrentFBInterfaceSpec.m_nNumEOs, m_stCurrentFBInterfaceSpec.m_nNumDIs, m_stCurrentFBInterfaceSpec.m_nNumDOs)];
  TForteByte *acFBVarsData = new TForteByte[genFBVarsDataSize(m_stCurrentFBInterfaceSpec.m_nNumDIs, m_stCurrentFBInterfaceSpec.m_nNumDOs)];

  setupFBInterface(&m_stCurrentFBInterfaceSpec, acFBConnData, acFBVarsData, true);

  return CAdapter::connect(pa_poPeer, pa_poAdConn);
}

bool CAnyAdapter::disconnect(CAdapterConnection *pa_poAdConn){
  bool bRetVal = CAdapter::disconnect(pa_poAdConn);

  //clean interface data and reset to empty interface
  freeAllData();
  setupFBInterface(&scm_stFBInterfaceSpec, 0, 0, false);

  return bRetVal;
}
