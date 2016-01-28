/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "RMT_RES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RMT_RES_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(RMT_RES, g_nStringIdRMT_RES);

const CStringDictionary::TStringId RMT_RES::scm_aunVarInputNameIds[] = {g_nStringIdMGR_ID};
const CStringDictionary::TStringId RMT_RES::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};


const SFBInterfaceSpec RMT_RES::scm_stRESInterfaceSpec = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  scm_aunVarInputNameIds,
  scm_aunDIDataTypeIds,
  0,
  0,
  0,
  0,
  0
  };


RMT_RES::RMT_RES(CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_poDevice):
       CResource(pa_poDevice, &scm_stRESInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){
  addFB(CTypeLib::createFB(g_nStringIdSTART, g_nStringIdE_RESTART, this));
  addFB(CTypeLib::createFB(g_nStringIdMGR_FF, g_nStringIdE_SR, this));
  addFB(CTypeLib::createFB(g_nStringIdKERNEL, g_nStringIdDM_KRNL, this));

  forte::core::SManagementCMD command;

  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdCOLD);
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdS);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdWARM);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdS);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdSTOP);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdR);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_FF);
  command.mFirstParam.pushBack(g_nStringIdEO);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdKERNEL);
  command.mSecondParam.pushBack(g_nStringIdINIT);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_FF);
  command.mFirstParam.pushBack(g_nStringIdQ);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdKERNEL);
  command.mSecondParam.pushBack(g_nStringIdQI);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_ID);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdKERNEL);
  command.mSecondParam.pushBack(g_nStringIdID);
  createConnection(command);
}

RMT_RES::~RMT_RES(){
}



