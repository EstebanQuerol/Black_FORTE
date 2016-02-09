/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EG_SSOD
 *** Description: Regular quantifier event generator
 *** Version: 
 ***     0.0: 2016-02-02/EQUEROL - UJI-ESID - 
 *************************************************************************/

#include "EG_SSOD.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EG_SSOD_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_EG_SSOD, g_nStringIdEG_SSOD)

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anDataInputNames[] = {g_nStringIddelta, g_nStringIdIN};

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_EG_SSOD::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_EG_SSOD::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anEventInputNames[] = {g_nStringIdEI};

const TDataIOID FORTE_EG_SSOD::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_EG_SSOD::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anEventOutputNames[] = {g_nStringIdEO};

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdSendOutput, g_nStringIdLastOut};

const CStringDictionary::TStringId FORTE_EG_SSOD::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdBOOL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_EG_SSOD::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_EG_SSOD::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_EG_SSOD::setInitialValues(){
  i() = 0;
  LastOut() = 0.0;
}

void FORTE_EG_SSOD::alg_EI(void){
/* : when exporting this FB for FORTE 1.7.3 or inferior a compilation error
 * will appear, saying that TRUNC() is ambiguous, this is a FORTE implementation
 * problem not related with this block. To solve it either make an explicit cast to
 * REAL (CIEC_REAL) or LREAL (CIEC_LREAL) when calling TRUNC or change the 
 * TRUNC for an explicit int cast (int)
 */
/*  Output flag */
SendOutput() = false;

/*  input signal exceeds the thresholds update the index (i) and rise output flag */
if((ABS((IN()-LastOut())) >= delta())){
	SendOutput() = true;
	/*  the index increase; TRUNC does floor() when IN>LastOut and ceil() when IN<LastOut*/
	i() = TRUNC((CIEC_REAL)(((IN()-LastOut()))/delta()));
	LastOut() = LastOut()+i()*delta();
};
}

void FORTE_EG_SSOD::alg_EO(void){
OUT() = LastOut();
}


void FORTE_EG_SSOD::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_EG_SSOD::enterStateCHECK_INPUT(void){
  m_nECCState = scm_nStateCHECK_INPUT;
  alg_EI();
}

void FORTE_EG_SSOD::enterStateSEND_OUTPUT(void){
  m_nECCState = scm_nStateSEND_OUTPUT;
  alg_EO();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_EG_SSOD::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventEIID == pa_nEIID)
          enterStateCHECK_INPUT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCHECK_INPUT:
        if(SendOutput() == true)
          enterStateSEND_OUTPUT();
        else
        if(SendOutput() == false)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSEND_OUTPUT:
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


