/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CTRL_TPID
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2016-02-08/EQUEROL - UJI_ESID - 
 *************************************************************************/

#include "CTRL_TPID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CTRL_TPID_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CTRL_TPID, g_nStringIdCTRL_TPID)

const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anDataInputNames[] = {g_nStringIdT, g_nStringIdYref, g_nStringIdYm, g_nStringIdU_MAX, g_nStringIdU_MIN, g_nStringIdKP, g_nStringIdTD, g_nStringIdTI, g_nStringIdN, g_nStringIdBP, g_nStringIdBD};

const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anDataInputTypeIds[] = {g_nStringIdTIME, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdStatus, g_nStringIdu};

const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL};

const TForteInt16 FORTE_CTRL_TPID::scm_anEIWithIndexes[] = {0, 12};
const TDataIOID FORTE_CTRL_TPID::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255};
const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdStop};

const TDataIOID FORTE_CTRL_TPID::scm_anEOWith[] = {0, 1, 255, 2, 255};
const TForteInt16 FORTE_CTRL_TPID::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_CTRL_TPID::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND};

const SFBInterfaceSpec FORTE_CTRL_TPID::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_CTRL_TPID::scm_astInternalFBs[] = {
  {g_nStringIdE_CYCLE, g_nStringIdE_CYCLE},
  {g_nStringIdF_TIME_TO_REAL, g_nStringIdF_TIME_TO_REAL},
  {g_nStringIdCTRL_TPID_ALG, g_nStringIdCTRL_TPID_ALG},
};

const SCFB_FBConnectionData FORTE_CTRL_TPID::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdStop), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CYCLE, g_nStringIdSTOP), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_TIME_TO_REAL, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CYCLE, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdEO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIND), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_TIME_TO_REAL, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdStart), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CYCLE, g_nStringIdSTART), 0},
};

const SCFB_FBFannedOutConnectionData FORTE_CTRL_TPID::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdStop), 2},
};

const SCFB_FBConnectionData FORTE_CTRL_TPID::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_CYCLE, g_nStringIdDT), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdYref), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdyref), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_TIME_TO_REAL, g_nStringIdOUT), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdT), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdYm), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdym), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdU_MAX), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdU_MAX), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdU_MIN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdU_MIN), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdKP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdKP), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTD), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdTD), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdTI), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdTI), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdN), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdBP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdBP), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdBD), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdBD), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdu), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdu), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdStatus), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdStatus), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdCTRL_TPID_ALG, g_nStringIdQO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQO), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_CTRL_TPID::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_TIME_TO_REAL, g_nStringIdIN), 1},
};

const SCFB_FBNData FORTE_CTRL_TPID::scm_stFBNData = {
  3, scm_astInternalFBs,
  7, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  15, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


