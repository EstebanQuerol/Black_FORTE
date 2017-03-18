/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Time_driven_PID
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-11-02/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "Time_driven_PID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Time_driven_PID_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Time_driven_PID, g_nStringIdTime_driven_PID)

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anDataInputNames[] = {g_nStringIdYm, g_nStringIdYref, g_nStringIdK, g_nStringIdTi, g_nStringIdTd, g_nStringIdInterval, g_nStringIdLIM_H, g_nStringIdLIM_L, g_nStringIdbeta, g_nStringIdN};

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anDataOutputNames[] = {g_nStringIdu, g_nStringIdLIM};

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_Time_driven_PID::scm_anEIWithIndexes[] = {0, 11, 22};
const TDataIOID FORTE_Time_driven_PID::scm_anEIWith[] = {0, 8, 9, 1, 2, 3, 4, 5, 6, 7, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255};
const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_Time_driven_PID::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_Time_driven_PID::scm_anEOWithIndexes[] = {-1, 0, 2};
const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anInternalsNames[] = {g_nStringIdyold, g_nStringIdud, g_nStringIdui};

const CStringDictionary::TStringId FORTE_Time_driven_PID::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Time_driven_PID::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  10,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Time_driven_PID::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_Time_driven_PID::alg_RESET(void){
ud() = 0.0;
ui() = 0.0;
yold() = 0.0;
}

void FORTE_Time_driven_PID::alg_REQ(void){
CIEC_REAL up;
;


up = K()*((beta()*Yref()-Ym()));
ud() = ((Td()/((Td()+N()*Interval()))))*ud()-((K()*Td()*N()/((Td()+N()*Interval()))))*((Ym()-yold()));
u() = up+ui()+ud();

ui() = ui()+((K()*Interval()/Ti()))*((Yref()-Ym()));
yold() = Ym();

if((u() < LIM_L())){
	u() = 0.0;
};

if((u() > LIM_H())){
	u() = 100.0;
};
}


void FORTE_Time_driven_PID::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Time_driven_PID::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_RESET();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Time_driven_PID::enterStateRST(void){
  m_nECCState = scm_nStateRST;
  alg_RESET();
}

void FORTE_Time_driven_PID::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Time_driven_PID::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventRSTID == pa_nEIID)
          enterStateRST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRST:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


