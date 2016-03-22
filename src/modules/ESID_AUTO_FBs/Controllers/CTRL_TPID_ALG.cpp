/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CTRL_TPID_ALG
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-02-09/EQUEROL - UJI_ESID - 
 *************************************************************************/

#include "CTRL_TPID_ALG.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CTRL_TPID_ALG_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CTRL_TPID_ALG, g_nStringIdCTRL_TPID_ALG)

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anDataInputNames[] = {g_nStringIdT, g_nStringIdyref, g_nStringIdym, g_nStringIdU_MAX, g_nStringIdU_MIN, g_nStringIdKP, g_nStringIdTD, g_nStringIdTI, g_nStringIdN, g_nStringIdBP, g_nStringIdBD};

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdStatus, g_nStringIdu};

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL};

const TForteInt16 FORTE_CTRL_TPID_ALG::scm_anEIWithIndexes[] = {0, 12, -1};
const TDataIOID FORTE_CTRL_TPID_ALG::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255, 1, 2, 255};
const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdStop};

const TDataIOID FORTE_CTRL_TPID_ALG::scm_anEOWith[] = {0, 1, 255, 2, 255};
const TForteInt16 FORTE_CTRL_TPID_ALG::scm_anEOWithIndexes[] = {0, 3, -1, -1};
const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO, g_nStringIdStart};

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anInternalsNames[] = {g_nStringIdINIT_OK, g_nStringIdpd, g_nStringIdqd, g_nStringIdD, g_nStringIdI, g_nStringIdqi, g_nStringIdyref_old, g_nStringIdym_old};

const CStringDictionary::TStringId FORTE_CTRL_TPID_ALG::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_CTRL_TPID_ALG::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_CTRL_TPID_ALG::scm_stInternalVars = {8, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_CTRL_TPID_ALG::setInitialValues(){
  yref_old() = 0;
  ym_old() = 0;
}

void FORTE_CTRL_TPID_ALG::alg_INIT(void){
INIT_OK() = false;
Status() = "Invalid input parameters";
QO() = false;
/*  input parameters and calculate the new constants */
if((N() != 0.0) && (T() > 0) && (TI() != 0.0) && (((N()*T()+TD())) != 0.0)){
	pd() = TD()/((N()*T()+TD()));
	qd() = KP()*TD()/((1+TD()/((N()*T()))));
	qi() = KP()*T()/TI();
	yref_old() = yref();
	ym_old() = ym();
	D() = 0.0;
	I() = 0.0;
	Status() = "Controller started";
	QO() = true;
	INIT_OK() = true;
};
}

void FORTE_CTRL_TPID_ALG::alg_REQ(void){
D() = pd()*D()+qd()*((BD()*((yref()-yref_old()))-ym()+ym_old()));
if((((((u() > U_MIN()) || (((ym()-yref())) > 0))) && (((u() < U_MAX()) || (((ym()-yref())) < 0)))))){
	I() = I()+qi()*((ym()-yref()));
};
u() = KP()*((BP()*yref()-ym()))+D()+I();
if((u() > U_MAX())){
	u() = U_MAX();
}
else
  if((u() < U_MIN())){
	u() = U_MIN();	
};
yref_old() = yref();
ym_old() = ym();
}

void FORTE_CTRL_TPID_ALG::alg_RST(void){
pd() = 0.0;
qd() = 0.0;
qi() = 0.0;
yref_old() = 0.0;
ym_old() = 0.0;
D() = 0.0;
I() = 0.0;
Status() = "Controller stopped";
QO() = true;
}


void FORTE_CTRL_TPID_ALG::enterStateHALT(void){
  m_nECCState = scm_nStateHALT;
}

void FORTE_CTRL_TPID_ALG::enterStateIDLE(void){
  m_nECCState = scm_nStateIDLE;
}

void FORTE_CTRL_TPID_ALG::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_CTRL_TPID_ALG::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_CTRL_TPID_ALG::enterStateRESET(void){
  m_nECCState = scm_nStateRESET;
  alg_RST();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_CTRL_TPID_ALG::enterStateSTART_SAMPLING(void){
  m_nECCState = scm_nStateSTART_SAMPLING;
  sendOutputEvent( scm_nEventStartID);
}

void FORTE_CTRL_TPID_ALG::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateHALT:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIDLE:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
        if(scm_nEventStopID == pa_nEIID)
          enterStateRESET();
        else
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(INIT_OK() == false)
          enterStateHALT();
        else
        if(INIT_OK() == true)
          enterStateSTART_SAMPLING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(1)
          enterStateIDLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRESET:
        if(1)
          enterStateHALT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTART_SAMPLING:
        if(1)
          enterStateIDLE();
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


