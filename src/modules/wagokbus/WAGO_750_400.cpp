/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WAGO_750_400
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-09-11/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "WAGO_750_400.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WAGO_750_400_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WAGO_750_400, g_nStringIdWAGO_750_400)

const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdSLOT};

const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdIN1, g_nStringIdIN2};

const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_WAGO_750_400::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_WAGO_750_400::scm_anEIWith[] = {0, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_WAGO_750_400::scm_anEOWith[] = {0, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_WAGO_750_400::scm_anEOWithIndexes[] = {0, 2, 6, -1};
const CStringDictionary::TStringId FORTE_WAGO_750_400::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_WAGO_750_400::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_WAGO_750_400::applyKBusInputData(){
  IN1() =  (m_acIndata[0] & 0x01) ? true : false;
  IN2() =  (m_acIndata[0] & 0x02) ? true : false;
}

void FORTE_WAGO_750_400::udpateKBusOutputData(){
   //there is nothing to be done here as we are an input only terminal
}

bool FORTE_WAGO_750_400::checkTerminalId(u16 pa_unTerminalId){
  // FIXME find out the correct terminal id for this terminal, for now accept any.
  return true;
}
