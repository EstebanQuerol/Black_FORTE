/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Durand_PID
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2017-02-20/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "Durand_PID.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Durand_PID_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Durand_PID, g_nStringIdDurand_PID)

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdyref, g_nStringIdym, g_nStringIdhnom, g_nStringIde_lim, g_nStringIdprecision, g_nStringIdK, g_nStringIdTi, g_nStringIdTd, g_nStringIdchoice, g_nStringIdhmax, g_nStringIdN, g_nStringIdbeta, g_nStringIdLIM_H, g_nStringIdLIM_L};

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdu};

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL};

const TForteInt16 FORTE_Durand_PID::scm_anEIWithIndexes[] = {0, 16};
const TDataIOID FORTE_Durand_PID::scm_anEIWith[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 255, 0, 1, 2, 3, 4, 5, 7, 6, 8, 9, 10, 11, 12, 13, 14, 255};
const CStringDictionary::TStringId FORTE_Durand_PID::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Durand_PID::scm_anEOWith[] = {0, 255, 0, 1, 255, 0, 255};
const TForteInt16 FORTE_Durand_PID::scm_anEOWithIndexes[] = {0, 2, 5, -1};
const CStringDictionary::TStringId FORTE_Durand_PID::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdNOEJEC};

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anInternalsNames[] = {g_nStringIderror, g_nStringIdhact, g_nStringIderror_old, g_nStringIdui, g_nStringIdud, g_nStringIdy_old, g_nStringIdhe, g_nStringIdhact_i, g_nStringIdup};

const CStringDictionary::TStringId FORTE_Durand_PID::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Durand_PID::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  15,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Durand_PID::scm_stInternalVars = {9, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Durand_PID::setInitialValues(){
  error() = 0;
  hact() = 0;
  error_old() = 0;
  ui() = 0;
  ud() = 0;
  y_old() = 0;
  he() = 0;
  hact_i() = 0;
  up() = 0;
}

void FORTE_Durand_PID::alg_initialize(void){

QO() = QI();
error() = 0;
hact() = 0;
error_old() = 0;
ui() = 0;
ud() = 0;
y_old() = 0;
}

void FORTE_Durand_PID::alg_deInitialize(void){

QO() = false;
}

void FORTE_Durand_PID::alg_Calculos_previos(void){


error() = yref()-ym();
hact() = hact()+hnom();


}

void FORTE_Durand_PID::alg_Calculo_PID(void){




up() = K()*((beta()*yref()-ym()));

if((choice() == 1)){
	ui() = ui()+K()/Ti()*hact()*error();
};
if((choice() == 2)){	
		if((hact() >= hmax())){
			he() = ((hact()-hnom()))*e_lim()+hnom()*error();
		}
else{
			he() = hact()*error();
		};
		ui() = ui()+K()/Ti()*he();
};
if((choice() == 3)){
	
	hact_i() = hact()*((exp((hnom()-hact()))));
		ui() = ui()+K()/Ti()*hact_i()*error();
};
if((choice() == 4)){	
	if((hact() >= hmax())){
			hact_i() = hact()*((exp((hnom()-hact()))));
			he() = ((hact_i()-hnom()))*e_lim()+hnom()*error();
		}
else{
			he() = hact()*error();
		};
			ui() = ui()+K()/Ti()*he();

			
};

ud() = Td()/((N()*hact()+Td()))*ud()-K()*Td()*N()/((N()*hact()+Td()))*((ym()-y_old()));

u() = up()+ui()+ud();

if((u() > LIM_H())){
	u() = LIM_H();
};
if((u() < LIM_L())){
	u() = LIM_L();
};

error_old() = error();
y_old() = ym();
hact() = 0;


}


void FORTE_Durand_PID::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Durand_PID::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Durand_PID::enterStateNormalOp(void){
  m_nECCState = scm_nStateNormalOp;
  alg_Calculos_previos();
}

void FORTE_Durand_PID::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_Durand_PID::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Durand_PID::enterStateEjecucion(void){
  m_nECCState = scm_nStateEjecucion;
  alg_Calculo_PID();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Durand_PID::enterStateNoejecucion(void){
  m_nECCState = scm_nStateNoejecucion;
  sendOutputEvent( scm_nEventNOEJECID);
}

void FORTE_Durand_PID::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNormalOp:
        if(((abs((precision()*error()-precision()*error_old())) > e_lim()*precision())))
          enterStateEjecucion();
        else
        if(!((abs((precision()*error()-precision()*error_old())) > e_lim()*precision())))
          enterStateNoejecucion();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventINITID == pa_nEIID)
          enterStateDeInit();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateNormalOp();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEjecucion:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNoejecucion:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 6.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


