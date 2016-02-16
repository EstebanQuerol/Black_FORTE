/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: C_RESTART_CLIENT
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2016-02-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "C_RESTART_CLIENT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "C_RESTART_CLIENT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_C_RESTART_CLIENT, g_nStringIdC_RESTART_CLIENT)

const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anDataInputNames[] = {g_nStringIdTIME1, g_nStringIdWSTRING1, g_nStringIdN};

const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anDataInputTypeIds[] = {g_nStringIdTIME, g_nStringIdWSTRING, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdEQ};

const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_C_RESTART_CLIENT::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_C_RESTART_CLIENT::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_C_RESTART_CLIENT::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_C_RESTART_CLIENT::scm_anEOWithIndexes[] = {-1, 0, 3, -1};
const CStringDictionary::TStringId FORTE_C_RESTART_CLIENT::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdINITCLIENT};

const SFBInterfaceSpec FORTE_C_RESTART_CLIENT::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_C_RESTART_CLIENT::scm_astInternalFBs[] = {
  {g_nStringIdWSTRING2WSTRING, g_nStringIdWSTRING2WSTRING},
  {g_nStringIdB_EQ_WSTRING, g_nStringIdB_EQ_WSTRING},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdE_SR, g_nStringIdE_SR},
  {g_nStringIdE_SWITCH, g_nStringIdE_SWITCH},
  {g_nStringIdE_PERMIT, g_nStringIdE_PERMIT},
  {g_nStringIdF_NOT, g_nStringIdF_NOT},
  {g_nStringIdE_PERMIT_2, g_nStringIdE_PERMIT},
  {g_nStringIdE_PERMIT_3, g_nStringIdE_PERMIT},
  {g_nStringIdE_CTD, g_nStringIdE_CTD},
  {g_nStringIdF_NOT_3, g_nStringIdF_NOT},
  {g_nStringIdF_GT, g_nStringIdF_GT},
  {g_nStringIdE_PERMIT_3_1, g_nStringIdE_PERMIT},
  {g_nStringIdF_NOT_3_1, g_nStringIdF_NOT},
  {g_nStringIdE_PERMIT_2_1, g_nStringIdE_PERMIT},
  {g_nStringIdF_NOT_2, g_nStringIdF_NOT},
};

const SCFB_FBParameter FORTE_C_RESTART_CLIENT::scm_astParamters[] = {
  {1, g_nStringIdWSTRING2, "OK"},
  {11, g_nStringIdIN2, "UINT#0"},
};

const SCFB_FBConnectionData FORTE_C_RESTART_CLIENT::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWSTRING2WSTRING, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdB_EQ_WSTRING, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT, g_nStringIdCNF), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT, g_nStringIdEI), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdB_EQ_WSTRING, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT, g_nStringIdREQ), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEO0), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SR, g_nStringIdS), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEO1), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SR, g_nStringIdR), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEI), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SR, g_nStringIdEO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITCLIENT), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2, g_nStringIdEO), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3, g_nStringIdEO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT, g_nStringIdEO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3, g_nStringIdEI), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdCDO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3, g_nStringIdREQ), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdLDO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3, g_nStringIdREQ), 10},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWSTRING2WSTRING, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdREQ), 11},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3_1, g_nStringIdEO), 12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdCNF), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3_1, g_nStringIdREQ), 13},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3_1, g_nStringIdCNF), 13, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdLD), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2_1, g_nStringIdEO), 14, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_2, g_nStringIdCNF), 15, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2_1, g_nStringIdEI), 14},
};

const SCFB_FBFannedOutConnectionData FORTE_C_RESTART_CLIENT::scm_astFannedOutEventConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2, g_nStringIdEI), 7},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdCD), 9},
  {7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdLD), 9},
  {9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3_1, g_nStringIdEI), 12},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_2, g_nStringIdREQ), 15},
};

const SCFB_FBConnectionData FORTE_C_RESTART_CLIENT::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWSTRING2WSTRING, g_nStringIdOUT), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdB_EQ_WSTRING, g_nStringIdWSTRING1), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdWSTRING1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWSTRING2WSTRING, g_nStringIdIN), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT, g_nStringIdOUT), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT, g_nStringIdPERMIT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdB_EQ_WSTRING, g_nStringIdBOOL1), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdEQ), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTIME1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SR, g_nStringIdQ), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQ), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdPV), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CTD, g_nStringIdQ), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3, g_nStringIdIN), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3, g_nStringIdOUT), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3, g_nStringIdPERMIT), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdOUT), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3_1, g_nStringIdIN), 13},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_3_1, g_nStringIdOUT), 13, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_3_1, g_nStringIdPERMIT), 12},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_2, g_nStringIdOUT), 15, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2_1, g_nStringIdPERMIT), 14},
};

const SCFB_FBFannedOutConnectionData FORTE_C_RESTART_CLIENT::scm_astFannedOutDataConnections[] = {
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT, g_nStringIdIN), 6},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_PERMIT_2, g_nStringIdPERMIT), 7},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_NOT_2, g_nStringIdIN), 15},
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdG), 4},
  {6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_GT, g_nStringIdIN1), 11},
};

const SCFB_FBNData FORTE_C_RESTART_CLIENT::scm_stFBNData = {
  16, scm_astInternalFBs,
  19, scm_astEventConnections,
  5, scm_astFannedOutEventConnections,
  12, scm_astDataConnections,
  5, scm_astFannedOutDataConnections,
  2, scm_astParamters
};


