/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_STRINGERASESPACES
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-04-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_STRINGERASESPACES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_STRINGERASESPACES_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_STRINGERASESPACES, g_nStringIdB_STRINGERASESPACES)

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_B_STRINGERASESPACES::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_B_STRINGERASESPACES::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_B_STRINGERASESPACES::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_B_STRINGERASESPACES::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anEventOutputNames[] = {g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anInternalsNames[] = {g_nStringIdSPACECHARACTER, g_nStringIdCRCHARACTER, g_nStringIdSTRSUB1, g_nStringIdSTRSUB2, g_nStringIdSTRSUB3, g_nStringIdPOINTER, g_nStringIdINLENGHT};

const CStringDictionary::TStringId FORTE_B_STRINGERASESPACES::scm_anInternalsTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdULINT, g_nStringIdULINT};

const SFBInterfaceSpec FORTE_B_STRINGERASESPACES::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_B_STRINGERASESPACES::scm_stInternalVars = {7, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_B_STRINGERASESPACES::alg_REQ(void){
STRSUB1() = IN();
STRSUB3() = IN();
STRSUB1() = "\x02";
STRSUB2() = IN();
SPACECHARACTER() = "\x20";

POINTER() = 1;
INLENGHT() = LEN((STRSUB2()));
while((POINTER() < INLENGHT()) && (INLENGHT() >= 1)){

	STRSUB3() = MID((STRSUB2()), (1), (POINTER()));
	if((STRSUB3() == SPACECHARACTER())){
		STRSUB1() = DELETE((STRSUB2()), (1), (POINTER()));
		STRSUB2() = STRSUB1();
		INLENGHT() = LEN((STRSUB2()));
	}
else{
	POINTER() = POINTER()+1;
	
	};
	
};

SPACECHARACTER() = "\x0d";

POINTER() = 1;
INLENGHT() = LEN((STRSUB2()));
while((POINTER() < INLENGHT()) && (INLENGHT() >= 1)){

	STRSUB3() = MID((STRSUB2()), (1), (POINTER()));
	if((STRSUB3() == SPACECHARACTER())){
		STRSUB1() = DELETE((STRSUB2()), (1), (POINTER()));
		STRSUB2() = STRSUB1();
		INLENGHT() = LEN((STRSUB2()));
	}
else{
	POINTER() = POINTER()+1;

	};

};
OUT() = STRSUB2();
}


void FORTE_B_STRINGERASESPACES::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_STRINGERASESPACES::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_STRINGERASESPACES::executeEvent(int pa_nEIID){
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


