/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_MID
 *** Description: L characters of IN
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_MID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_MID_gen.cpp"
#endif
#include <anyhelper.h>

DEFINE_FIRMWARE_FB(FORTE_F_MID, g_nStringIdF_MID)

const CStringDictionary::TStringId FORTE_F_MID::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdL, g_nStringIdP};

const CStringDictionary::TStringId FORTE_F_MID::scm_anDataInputTypeIds[] = {g_nStringIdANY_STRING, g_nStringIdANY_INT, g_nStringIdANY_INT};

const CStringDictionary::TStringId FORTE_F_MID::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_MID::scm_anDataOutputTypeIds[] = {g_nStringIdANY_STRING};

const TForteInt16 FORTE_F_MID::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_MID::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_F_MID::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_MID::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_MID::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_MID::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_MID::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_MID::executeEvent(int pa_nEIID){
  if (scm_nEventREQID == pa_nEIID) {
    anyStringFBHelper<FORTE_F_MID>(IN().getDataTypeID(), *this);
    sendOutputEvent(scm_nEventCNFID);
  }
}



