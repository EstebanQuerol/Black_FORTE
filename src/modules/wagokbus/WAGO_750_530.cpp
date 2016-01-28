/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WAGO_750_530
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-09-11/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "WAGO_750_530.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WAGO_750_530_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WAGO_750_530, g_nStringIdWAGO_750_530)

const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdSLOT, g_nStringIdDO1, g_nStringIdDO2, g_nStringIdDO3, g_nStringIdDO4, g_nStringIdDO5, g_nStringIdDO6, g_nStringIdDO7, g_nStringIdDO8};

const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_WAGO_750_530::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_WAGO_750_530::scm_anEIWith[] = {0, 1, 255, 0, 2, 3, 4, 5, 6, 7, 8, 9, 255};
const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_WAGO_750_530::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_WAGO_750_530::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_WAGO_750_530::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_WAGO_750_530::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  10,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};



void FORTE_WAGO_750_530::applyKBusInputData(){
  //there is nothing to be done here as we are an output only terminal
}

void FORTE_WAGO_750_530::udpateKBusOutputData(){
  m_acOutdata[0] = 0;

  CIEC_ANY *m_poVar = getDI(2);

  for(unsigned int i = 1; i <= 128; i <<= 2){
    if(true == static_cast<CIEC_BOOL *>(m_poVar)->operator bool()){
      m_acOutdata[0] += static_cast<TForteByte>(i);
    }
    ++m_poVar;
  }
}

bool FORTE_WAGO_750_530::checkTerminalId(u16 pa_unTerminalId){
  // FIXME find out the correct terminal id for this terminal, for now accept any.
  return true;
}



