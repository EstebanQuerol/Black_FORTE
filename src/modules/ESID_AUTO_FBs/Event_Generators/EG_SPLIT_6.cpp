/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EG_SPLIT_6
 *** Description: Split an event
 *** Version: 
 ***     0.0: 2016-03-16/EQUEROL - ESID-UJI - 
 *************************************************************************/

#include "EG_SPLIT_6.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EG_SPLIT_6_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_EG_SPLIT_6, g_nStringIdEG_SPLIT_6)

const TForteInt16 FORTE_EG_SPLIT_6::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_EG_SPLIT_6::scm_anEventInputNames[] = {g_nStringIdEI};

const TForteInt16 FORTE_EG_SPLIT_6::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_EG_SPLIT_6::scm_anEventOutputNames[] = {g_nStringIdEO1, g_nStringIdEO2, g_nStringIdEO3, g_nStringIdEO4, g_nStringIdEO5, g_nStringIdEO6};

const SFBInterfaceSpec FORTE_EG_SPLIT_6::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  6,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


void FORTE_EG_SPLIT_6::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_EG_SPLIT_6::enterStateEO(void){
  m_nECCState = scm_nStateEO;
  sendOutputEvent( scm_nEventEO1ID);
  sendOutputEvent( scm_nEventEO2ID);
  sendOutputEvent( scm_nEventEO3ID);
  sendOutputEvent( scm_nEventEO4ID);
  sendOutputEvent( scm_nEventEO5ID);
  sendOutputEvent( scm_nEventEO6ID);
}

void FORTE_EG_SPLIT_6::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventEIID == pa_nEIID)
          enterStateEO();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEO:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


