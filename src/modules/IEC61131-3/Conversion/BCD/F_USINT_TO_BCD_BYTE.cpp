/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_USINT_TO_BCD_BYTE
 *** Description: convert USINT Binary Coded Decimal to BYTE
 *** Version: 
 ***     0.0: 2013-08-29/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_USINT_TO_BCD_BYTE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_USINT_TO_BCD_BYTE_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_USINT_TO_BCD_BYTE, g_nStringIdF_USINT_TO_BCD_BYTE)

const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anDataOutputTypeIds[] = {g_nStringIdBYTE};

const TForteInt16 FORTE_F_USINT_TO_BCD_BYTE::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_USINT_TO_BCD_BYTE::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_USINT_TO_BCD_BYTE::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_USINT_TO_BCD_BYTE::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_USINT_TO_BCD_BYTE::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_USINT_TO_BCD_BYTE::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_USINT_TO_BCD_BYTE::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = USINT_TO_BCD_BYTE(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
