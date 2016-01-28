/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: EMB_RMT_RES
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2010-01-20/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/
#include "EMB_RMT_RES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EMB_RMT_RES_gen.cpp"
#endif
#include "../events/E_RESTART.h"
#include "../ita/DEV_MGR.h"
#include "../events/E_SR.h"
#include <commfb.h>


//DEFINE_FIRMWARE_FB(EMB_RMT_RES, g_nStringIdEMB_RMT_RES);

const SFBInterfaceSpec EMB_RMT_RES::scm_stRESInterfaceSpec = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

//const char * const EMB_RMT_RES::scm_acId = "fbdk[].ip[localhost:61499]";

EMB_RMT_RES::EMB_RMT_RES(const CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_poDevice, const char * pa_acId):
             CResource(pa_poDevice, &scm_stRESInterfaceSpec, pa_nInstanceNameId, 0, 0){

  addFB(CTypeLib::createFB(g_nStringIdSTART, g_nStringIdE_RESTART, this));
  addFB(CTypeLib::createFB(g_nStringIdMGR_FF, g_nStringIdE_SR, this));
  CFunctionBlock *poFB = CTypeLib::createFB(g_nStringIdSVR, g_nStringIdSERVER_1_2, this);
  addFB(poFB);
  static_cast<forte::com_infra::CCommFB *>(poFB)->ID() = pa_acId;

  addFB(CTypeLib::createFB(g_nStringIdMGR, g_nStringIdDEV_MGR, this));

  forte::core::SManagementCMD command;

  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdCOLD);
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdS);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdwARM);
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
  command.mSecondParam.pushBack(g_nStringIdSVR);
  command.mSecondParam.pushBack(g_nStringIdINIT);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSVR);
  command.mFirstParam.pushBack(g_nStringIdINITO);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdINIT);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSVR);
  command.mFirstParam.pushBack(g_nStringIdIND);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdREQ);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR);
  command.mFirstParam.pushBack(g_nStringIdCNF);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdSVR);
  command.mSecondParam.pushBack(g_nStringIdRSP);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_FF);
  command.mFirstParam.pushBack(g_nStringIdQ);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdSVR);
  command.mSecondParam.pushBack(g_nStringIdQI);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSVR);
  command.mFirstParam.pushBack(g_nStringIdQO);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdQI);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSVR);
  command.mFirstParam.pushBack(g_nStringIdRD_1);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdDST);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSVR);
  command.mFirstParam.pushBack(g_nStringIdRD_2);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdRQST);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR);
  command.mFirstParam.pushBack(g_nStringIdRESP);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdSVR);
  command.mSecondParam.pushBack(g_nStringIdSD_1);
  createConnection(command);
}

EMB_RMT_RES::~EMB_RMT_RES(){
}

CStringDictionary::TStringId EMB_RMT_RES::getFBTypeId(void) const {
  return g_nStringIdEMB_RMT_RES;
}



