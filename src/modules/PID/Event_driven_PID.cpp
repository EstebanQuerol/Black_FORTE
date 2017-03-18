/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Event_driven_PID
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-11-02/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "Event_driven_PID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Event_driven_PID_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Event_driven_PID, g_nStringIdEvent_driven_PID)

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anDataInputNames[] = {g_nStringIdYm, g_nStringIdYref, g_nStringIdK, g_nStringIdTi, g_nStringIdTd, g_nStringIdbeta, g_nStringIdN, g_nStringIdSample_time, g_nStringIdtmax, g_nStringIdE_lim, g_nStringIdE_precision, g_nStringIdLIM_H, g_nStringIdLIM_L};

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anDataOutputNames[] = {g_nStringIdU};

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_Event_driven_PID::scm_anEIWithIndexes[] = {0, 2, 16};
const TDataIOID FORTE_Event_driven_PID::scm_anEIWith[] = {0, 255, 0, 1, 2, 3, 4, 7, 11, 12, 9, 8, 5, 6, 10, 255, 0, 1, 2, 3, 4, 7, 11, 12, 9, 8, 5, 6, 10, 255};
const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdRST};

const TDataIOID FORTE_Event_driven_PID::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Event_driven_PID::scm_anEOWithIndexes[] = {-1, 0, -1, -1};
const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdNO_MOD};

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anInternalsNames[] = {g_nStringIdES, g_nStringIdYOLD, g_nStringIdUD, g_nStringIdUI, g_nStringIdElapsed_time};

const CStringDictionary::TStringId FORTE_Event_driven_PID::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Event_driven_PID::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  13,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Event_driven_PID::scm_stInternalVars = {5, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Event_driven_PID::setInitialValues(){
  ES() = 0.0;
  YOLD() = 0.0;
  UD() = 0.0;
  UI() = 0.0;
  Elapsed_time() = 0.0;
}

void FORTE_Event_driven_PID::alg_RESET(void){
ES() = 0.0;
YOLD() = 0.0;
UD() = 0.0;
UI() = 0.0;
Elapsed_time() = Sample_time();
}

void FORTE_Event_driven_PID::alg_REQ(void){
CIEC_REAL up;


	ES() = Yref()-Ym();
	up = K()*((beta()*Yref()-Ym()));
	UD() = Td()/((Td()+N()*Elapsed_time()))*UD()-Td()/((Td()+N()*Elapsed_time()))*K()*N()*((Ym()-YOLD()));
	U() = up+UD()+UI();
	UI() = UI()+K()/Ti()*Elapsed_time()*((Yref()-Ym()));
	YOLD() = Ym();
	
	if((U() > LIM_H())){
		U() = 100.0;

	};
	
	if((U() < LIM_L())){
		U() = 0.0;
	};
	Elapsed_time() = Sample_time();
	
}

void FORTE_Event_driven_PID::alg_ALG(void){
Elapsed_time() = Elapsed_time()+Sample_time();
}


void FORTE_Event_driven_PID::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Event_driven_PID::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_RESET();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Event_driven_PID::enterStateRST(void){
  m_nECCState = scm_nStateRST;
  alg_RESET();
}

void FORTE_Event_driven_PID::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
}

void FORTE_Event_driven_PID::enterStateSENDCNF(void){
  m_nECCState = scm_nStateSENDCNF;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Event_driven_PID::enterStateSENDNOMOD(void){
  m_nECCState = scm_nStateSENDNOMOD;
  alg_ALG();
  sendOutputEvent( scm_nEventNO_MODID);
}

void FORTE_Event_driven_PID::executeEvent(int pa_nEIID){
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
        if(((((abs((((Yref()-Ym()))*E_precision()-ES()*E_precision())) > ((E_lim()*E_precision()))))) || (((Elapsed_time() > tmax())))))
          enterStateSENDCNF();
        else
        if(!((((abs((((Yref()-Ym()))*E_precision()-ES()*E_precision())) > ((E_lim()*E_precision()))))) || (((Elapsed_time() > tmax())))))
          enterStateSENDNOMOD();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSENDCNF:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSENDNOMOD:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


