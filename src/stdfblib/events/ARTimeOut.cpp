/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ARTimeOut
 *** Description: Interface for a resetable time out service
 *** Version: 
 *************************************************************************/

#include "ARTimeOut.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ARTimeOut_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(FORTE_ARTimeOut, g_nStringIdARTimeOut)

const CStringDictionary::TStringId FORTE_ARTimeOut::scm_anDataOutputNames[] = {g_nStringIdDT};

const CStringDictionary::TStringId FORTE_ARTimeOut::scm_anDataOutputTypeIds[] = {g_nStringIdTIME};

const TForteInt16 FORTE_ARTimeOut::scm_anEIWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_ARTimeOut::scm_anEventInputNames[] = {g_nStringIdTimeOut};

const TDataIOID FORTE_ARTimeOut::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_ARTimeOut::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_ARTimeOut::scm_anEventOutputNames[] = {g_nStringIdSTART, g_nStringIdSTOP};

const SFBInterfaceSpec FORTE_ARTimeOut::scm_stFBInterfaceSpecSocket = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SFBInterfaceSpec FORTE_ARTimeOut::scm_stFBInterfaceSpecPlug = {
  2,  scm_anEventOutputNames,  scm_anEOWith,  scm_anEOWithIndexes,
  1,  scm_anEventInputNames,  0, 0,  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0,  0, 0,
  0, 0
};



