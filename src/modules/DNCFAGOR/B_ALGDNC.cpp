/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_ALGDNC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-11-24/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_ALGDNC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_ALGDNC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_ALGDNC, g_nStringIdB_ALGDNC)

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anDataInputNames[] = {g_nStringIdDTS, g_nStringIdDTR, g_nStringIdRDC};

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anDataOutputNames[] = {g_nStringIdSDC, g_nStringIdQ, g_nStringIdDATA};

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_B_ALGDNC::scm_anEIWithIndexes[] = {-1, 0, 3, -1};
const TDataIOID FORTE_B_ALGDNC::scm_anEIWith[] = {1, 0, 255, 2, 255};
const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdCNFC, g_nStringIdT};

const TDataIOID FORTE_B_ALGDNC::scm_anEOWith[] = {1, 2, 255, 0, 255};
const TForteInt16 FORTE_B_ALGDNC::scm_anEOWithIndexes[] = {-1, 0, 3, -1, -1, -1};
const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdREQC, g_nStringIdST, g_nStringIdRT};

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anInternalsNames[] = {g_nStringIdOK, g_nStringIdNAK, g_nStringIdNT, g_nStringIdNE, g_nStringIdSTRINGNAK, g_nStringIdSTX, g_nStringIdSTRINGSTX, g_nStringIdSTRINGCMP, g_nStringIdEOTDEL, g_nStringIdCOMPOSITESTRING, g_nStringIdCMPSTRINGLENGHT, g_nStringIdSTRINGETB, g_nStringIdSTRINGETX, g_nStringIdTRUNCADA};

const CStringDictionary::TStringId FORTE_B_ALGDNC::scm_anInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_B_ALGDNC::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_B_ALGDNC::scm_stInternalVars = {14, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_B_ALGDNC::setInitialValues(){
  OK() = false;
  NAK() = false;
  NT() = 0;
  NE() = 0;
  STX() = false;
  EOTDEL() = false;
  TRUNCADA() = false;
}

void FORTE_B_ALGDNC::alg_INIT(void){

}

void FORTE_B_ALGDNC::alg_REQ(void){

}

void FORTE_B_ALGDNC::alg_S2(void){
SDC() = DTS();
STRINGCMP() = "\x01\x02\x03\x04";

if((STRINGCMP() == DTR())){
EOTDEL() = true;
}
else{
EOTDEL() = false;
};
}

void FORTE_B_ALGDNC::alg_S4(void){
STRINGNAK() = "\x15\x7f";
STRINGSTX() = "\x02";
STRINGETB() = "\x17";
STRINGETX() = "\x03";
STRINGCMP() = MID((RDC()), (1), (1));




if((RDC() == DTR())){
	OK() = true;
}
else
  if((RDC() == STRINGNAK())){
	NAK() = true;
}
else{
	NAK() = false;
	OK() = false;
	STX() = false;
};

if((!TRUNCADA())){
	COMPOSITESTRING() = "\x00";	
	STRINGCMP() = "\x02\x03";
	if((STRINGCMP() == DTR())){
		STRINGCMP() = MID((RDC()), (1), (1));
		if((STRINGCMP() == STRINGSTX())){
			CMPSTRINGLENGHT() = LEN((RDC()))-2;
			STRINGCMP() = MID((RDC()), (1), (CMPSTRINGLENGHT()));
			if((STRINGCMP() == STRINGETX()) || (STRINGCMP() == STRINGETB())){
				COMPOSITESTRING() = RDC();
				STX() = true;
				OK() = true;
				TRUNCADA() = false;
			}
else{
				COMPOSITESTRING() = RDC();
				TRUNCADA() = true;	
				STX() = false;
				OK() = false;
			};
		}
else{
			STX() = false;
			OK() = false;
			TRUNCADA() = false;
		};
	};	
}
else{
	COMPOSITESTRING() = CONCAT((COMPOSITESTRING()), (RDC()));
	CMPSTRINGLENGHT() = LEN((COMPOSITESTRING()))-2;
	STRINGCMP() = MID((COMPOSITESTRING()), (1), (CMPSTRINGLENGHT()));
	if((STRINGCMP() == STRINGETX()) || (STRINGCMP() == STRINGETB())){
		STX() = true;
		OK() = true;
		TRUNCADA() = false;
	}
else{
		TRUNCADA() = true;	
		STX() = false;
		OK() = false;
	};
};
	


}

void FORTE_B_ALGDNC::alg_S6(void){
Q() = true;

}

void FORTE_B_ALGDNC::alg_S1(void){
NT() = 0;
NE() = 0;
OK() = false;
NAK() = false;
STX() = false;
EOTDEL() = false;

}

void FORTE_B_ALGDNC::alg_S10(void){
SDC() = "\x04";
Q() = false;

}

void FORTE_B_ALGDNC::alg_S7(void){
NE() = NE()+1;
}

void FORTE_B_ALGDNC::alg_S11(void){
NT() = NT()+1;
}

void FORTE_B_ALGDNC::alg_S12(void){
SDC() = "\x05";
}

void FORTE_B_ALGDNC::alg_S3(void){

}

void FORTE_B_ALGDNC::alg_S8(void){
DATA() = COMPOSITESTRING();
Q() = true;

}


void FORTE_B_ALGDNC::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_ALGDNC::enterStateState(void){
  m_nECCState = scm_nStateState;
}

void FORTE_B_ALGDNC::enterStateState_1(void){
  m_nECCState = scm_nStateState_1;
  alg_S1();
  sendOutputEvent( scm_nEventRTID);
}

void FORTE_B_ALGDNC::enterStateState_2(void){
  m_nECCState = scm_nStateState_2;
  alg_S2();
  sendOutputEvent( scm_nEventREQCID);
}

void FORTE_B_ALGDNC::enterStateState_3(void){
  m_nECCState = scm_nStateState_3;
  sendOutputEvent( scm_nEventSTID);
}

void FORTE_B_ALGDNC::enterStateState_4(void){
  m_nECCState = scm_nStateState_4;
  alg_S4();
  sendOutputEvent( scm_nEventRTID);
}

void FORTE_B_ALGDNC::enterStateState_6(void){
  m_nECCState = scm_nStateState_6;
  alg_S6();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_ALGDNC::enterStateState_7(void){
  m_nECCState = scm_nStateState_7;
  alg_S7();
}

void FORTE_B_ALGDNC::enterStateState_10(void){
  m_nECCState = scm_nStateState_10;
  alg_S10();
  sendOutputEvent( scm_nEventREQCID);
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_ALGDNC::enterStateState_11(void){
  m_nECCState = scm_nStateState_11;
  alg_S11();
}

void FORTE_B_ALGDNC::enterStateState_12(void){
  m_nECCState = scm_nStateState_12;
  alg_S12();
  sendOutputEvent( scm_nEventREQCID);
}

void FORTE_B_ALGDNC::enterStateState_5(void){
  m_nECCState = scm_nStateState_5;
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_B_ALGDNC::enterStateState_8(void){
  m_nECCState = scm_nStateState_8;
  alg_S8();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_ALGDNC::enterStateState_9(void){
  m_nECCState = scm_nStateState_9;
}

void FORTE_B_ALGDNC::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateState_5();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState:
        if(scm_nEventREQID == pa_nEIID)
          enterStateState_1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_1:
        if(1)
          enterStateState_2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_2:
        if(!EOTDEL())
          enterStateState_3();
        else
        if(EOTDEL())
          enterStateState_6();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_3:
        if(scm_nEventCNFCID == pa_nEIID)
          enterStateState_4();
        else
        if(scm_nEventTID == pa_nEIID)
          enterStateState_11();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_4:
        if((OK()) && (!STX()))
          enterStateState_6();
        else
        if(NAK())
          enterStateState_7();
        else
        if((!OK()) && (!NAK()) && (!TRUNCADA()))
          enterStateState_11();
        else
        if((STX()) && (OK()))
          enterStateState_8();
        else
        if(TRUNCADA())
          enterStateState_9();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_6:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_7:
        if(NE() >= 3)
          enterStateState_10();
        else
        if(NE() < 3)
          enterStateState_2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_10:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_11:
        if(NT() == 3)
          enterStateState_10();
        else
        if(NT() < 3)
          enterStateState_12();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_12:
        if(1)
          enterStateState_3();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_5:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_8:
        if(1)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState_9:
        if(scm_nEventCNFCID == pa_nEIID)
          enterStateState_4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 13.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


