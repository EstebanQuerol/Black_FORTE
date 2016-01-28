/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: E_RTimeOut
 *** Description: Simple implementation of the timeout services
 *** Version: 
 ***     1.0: 2012-12-18/AZ - 4DIAC-Consortium - 
 *************************************************************************/

#include "E_RTimeOut.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_RTimeOut_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_E_RTimeOut, g_nStringIdE_RTimeOut)

const TForteInt16 FORTE_E_RTimeOut::scm_anEOWithIndexes[] = {-1};
const SAdapterInstanceDef FORTE_E_RTimeOut::scm_astAdapterInstances[] = {
{g_nStringIdARTimeOut, g_nStringIdTimeOutSocket, false }};

const SFBInterfaceSpec FORTE_E_RTimeOut::scm_stFBInterfaceSpec = {
  0,  0,  0,  0,
  0,  0,   0, 0,  0,  0, 0, 
  0,  0, 0,
  1,scm_astAdapterInstances};


const SCFB_FBInstanceData FORTE_E_RTimeOut::scm_astInternalFBs[] = {
  {g_nStringIdDLY, g_nStringIdE_RDELAY},
};

const SCFB_FBConnectionData FORTE_E_RTimeOut::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTimeOutSocket, g_nStringIdSTART), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDLY, g_nStringIdSTART), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTimeOutSocket, g_nStringIdSTOP), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDLY, g_nStringIdSTOP), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDLY, g_nStringIdEO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTimeOutSocket, g_nStringIdTimeOut), CCompositeFB::scm_nAdapterMarker |0},
};

const SCFB_FBConnectionData FORTE_E_RTimeOut::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdTimeOutSocket, g_nStringIdDT), CCompositeFB::scm_nAdapterMarker |0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDLY, g_nStringIdDT), 0},
};

const SCFB_FBNData FORTE_E_RTimeOut::scm_stFBNData = {
  1, scm_astInternalFBs,
  3, scm_astEventConnections,
  0, 0,
  1, scm_astDataConnections,
  0, 0,
  0, 0
};


