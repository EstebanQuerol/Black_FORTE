/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_CURRENTCALC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-04-06/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_CURRENTCALC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_CURRENTCALC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_CURRENTCALC, g_nStringIdB_CURRENTCALC)

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdRT, g_nStringIdPERIODOMUESTREO, g_nStringIdPERIODOCALCULO};

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anDataOutputNames[] = {g_nStringIdIrms};

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_B_CURRENTCALC::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_B_CURRENTCALC::scm_anEIWith[] = {2, 0, 1, 3, 255};
const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_B_CURRENTCALC::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_B_CURRENTCALC::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anEventOutputNames[] = {g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anInternalsNames[] = {g_nStringIdN, g_nStringIdSUMATORIO};

const CStringDictionary::TStringId FORTE_B_CURRENTCALC::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_B_CURRENTCALC::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_B_CURRENTCALC::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_B_CURRENTCALC::setInitialValues(){
  N() = 0;
}

void FORTE_B_CURRENTCALC::alg_INIT(void){

}

void FORTE_B_CURRENTCALC::alg_REQ(void){
N() = N()+1;
SUMATORIO() = SUMATORIO()+((((((IN()-0.9))*RT()*PERIODOMUESTREO()))*((((IN()-0.9))*RT()*PERIODOMUESTREO()))));
}

void FORTE_B_CURRENTCALC::alg_CALCULO(void){

Irms() =(CIEC_REAL)SQRT((CIEC_REAL) (SUMATORIO()/PERIODOCALCULO()) );
N() = 0;
SUMATORIO() = 0;

}


void FORTE_B_CURRENTCALC::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_CURRENTCALC::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_B_CURRENTCALC::enterStateState(void){
  m_nECCState = scm_nStateState;
  alg_CALCULO();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_CURRENTCALC::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(N() < PERIODOCALCULO())
          enterStateSTART();
        else
        if(N() == PERIODOCALCULO())
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


