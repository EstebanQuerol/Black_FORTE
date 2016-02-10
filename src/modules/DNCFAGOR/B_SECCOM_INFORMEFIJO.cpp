/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_SECCOM_INFORMEFIJO
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-11-24/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_SECCOM_INFORMEFIJO.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_SECCOM_INFORMEFIJO_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_SECCOM_INFORMEFIJO, g_nStringIdB_SECCOM_INFORMEFIJO)

const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anDataInputNames[] = {g_nStringIdQ};

const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anDataOutputNames[] = {g_nStringIdSTRING1, g_nStringIdSTRING2};

const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_B_SECCOM_INFORMEFIJO::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_B_SECCOM_INFORMEFIJO::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_B_SECCOM_INFORMEFIJO::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_B_SECCOM_INFORMEFIJO::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_B_SECCOM_INFORMEFIJO::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_B_SECCOM_INFORMEFIJO::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_INIT(void){
STRING1() = "\x04\x7f";
STRING2() = "\x01\x02\x03\x04";
}

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_S1(void){
STRING1() = "\x05";
STRING2() = "\x10\x30";
}

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_S2(void){
STRING1() = "\x01\x52\x43\x4c\x02\x03\xfe\x2c";
STRING2() = "\x10\x31";
}

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_S3(void){
STRING1() = "\x04";
STRING2() = "\x05\x7f";
}

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_S4(void){
STRING1() = "\x10\x30";
STRING2() = "\x02\x03";
}

void FORTE_B_SECCOM_INFORMEFIJO::alg_ALG_S5(void){
STRING1() = "\x10\x31";
STRING2() = "\x04\x7f";
}


void FORTE_B_SECCOM_INFORMEFIJO::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_ALG_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateS1(void){
  m_nECCState = scm_nStateS1;
  alg_ALG_S1();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateS2(void){
  m_nECCState = scm_nStateS2;
  alg_ALG_S2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateS3(void){
  m_nECCState = scm_nStateS3;
  alg_ALG_S3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateS4(void){
  m_nECCState = scm_nStateS4;
  alg_ALG_S4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::enterStateS5(void){
  m_nECCState = scm_nStateS5;
  alg_ALG_S5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_INFORMEFIJO::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateS1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateS1:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateSTART();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateS2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateS2:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateSTART();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateS3();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateS3:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateSTART();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateS4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateS4:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateSTART();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateS5();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateS5:
        if(1)
          enterStateSTART();
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


