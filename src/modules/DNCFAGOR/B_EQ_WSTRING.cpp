/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_EQ_WSTRING
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-02-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_EQ_WSTRING.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_EQ_WSTRING_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_EQ_WSTRING, g_nStringIdB_EQ_WSTRING)

const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anDataInputNames[] = {g_nStringIdWSTRING1, g_nStringIdWSTRING2};

const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anDataInputTypeIds[] = {g_nStringIdWSTRING, g_nStringIdWSTRING};

const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anDataOutputNames[] = {g_nStringIdBOOL1};

const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_B_EQ_WSTRING::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_B_EQ_WSTRING::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_B_EQ_WSTRING::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_B_EQ_WSTRING::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_B_EQ_WSTRING::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_B_EQ_WSTRING::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_B_EQ_WSTRING::setInitialValues(){
  BOOL1() = false;
}

void FORTE_B_EQ_WSTRING::alg_REQ(void){
if((WSTRING1() == WSTRING2())){;
BOOL1() = true;
}
else{
BOOL1() = false;
};
}


void FORTE_B_EQ_WSTRING::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_EQ_WSTRING::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_EQ_WSTRING::executeEvent(int pa_nEIID){
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


