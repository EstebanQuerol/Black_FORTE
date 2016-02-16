/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: STRING_DEMUX2N
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-11-13/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "STRING_DEMUX2N.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "STRING_DEMUX2N_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_STRING_DEMUX2N, g_nStringIdSTRING_DEMUX2N)

const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anDataInputNames[] = {g_nStringIdSTRA1, g_nStringIdSTRA2, g_nStringIdSTRB1, g_nStringIdSTRB2, g_nStringIdSTRC1, g_nStringIdSTRC2, g_nStringIdSTRD1, g_nStringIdSTRD2, g_nStringIdSTRE1, g_nStringIdSTRE2};

const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anDataOutputNames[] = {g_nStringIdSTROUT1, g_nStringIdSTROUT2};

const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_STRING_DEMUX2N::scm_anEIWithIndexes[] = {0, 3, 6, 9, 12};
const TDataIOID FORTE_STRING_DEMUX2N::scm_anEIWith[] = {0, 1, 255, 2, 3, 255, 4, 5, 255, 6, 7, 255, 8, 9, 255};
const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anEventInputNames[] = {g_nStringIdEIA, g_nStringIdEIB, g_nStringIdEIC, g_nStringIdEID, g_nStringIdEIE};

const TDataIOID FORTE_STRING_DEMUX2N::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_STRING_DEMUX2N::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_STRING_DEMUX2N::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec FORTE_STRING_DEMUX2N::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  10,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_STRING_DEMUX2N::alg_A_ESTRA(void){
STROUT1() = STRA1();
STROUT2() = STRA2();
}

void FORTE_STRING_DEMUX2N::alg_A_ESTRB(void){
STROUT1() = STRB1();
STROUT2() = STRB2();
}

void FORTE_STRING_DEMUX2N::alg_A_ESTRC(void){
STROUT1() = STRC1();
STROUT2() = STRC2();
}

void FORTE_STRING_DEMUX2N::alg_A_ESTRD(void){
STROUT1() = STRD1();
STROUT2() = STRD2();
}

void FORTE_STRING_DEMUX2N::alg_A_ESTRE(void){
STROUT1() = STRE1();
STROUT2() = STRE2();
}


void FORTE_STRING_DEMUX2N::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_STRING_DEMUX2N::enterStateESTRA(void){
  m_nECCState = scm_nStateESTRA;
  alg_A_ESTRA();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_STRING_DEMUX2N::enterStateESTRB(void){
  m_nECCState = scm_nStateESTRB;
  alg_A_ESTRB();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_STRING_DEMUX2N::enterStateESTRC(void){
  m_nECCState = scm_nStateESTRC;
  alg_A_ESTRC();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_STRING_DEMUX2N::enterStateESTRD(void){
  m_nECCState = scm_nStateESTRD;
  alg_A_ESTRD();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_STRING_DEMUX2N::enterStateESTRE(void){
  m_nECCState = scm_nStateESTRE;
  alg_A_ESTRE();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_STRING_DEMUX2N::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventEIAID == pa_nEIID)
          enterStateESTRA();
        else
        if(scm_nEventEIBID == pa_nEIID)
          enterStateESTRB();
        else
        if(scm_nEventEICID == pa_nEIID)
          enterStateESTRC();
        else
        if(scm_nEventEIDID == pa_nEIID)
          enterStateESTRD();
        else
        if(scm_nEventEIEID == pa_nEIID)
          enterStateESTRE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateESTRA:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateESTRB:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateESTRC:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateESTRD:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateESTRE:
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


