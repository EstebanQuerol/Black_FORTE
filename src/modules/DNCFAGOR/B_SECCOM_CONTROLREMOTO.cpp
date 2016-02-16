/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_SECCOM_CONTROLREMOTO
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-12-09/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "B_SECCOM_CONTROLREMOTO.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "B_SECCOM_CONTROLREMOTO_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_B_SECCOM_CONTROLREMOTO, g_nStringIdB_SECCOM_CONTROLREMOTO)

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anDataInputNames[] = {g_nStringIdQ, g_nStringIdINSTRING, g_nStringIdUINT1, g_nStringIdCRCSTRIN, g_nStringIdRDATA, g_nStringIdTXTSTRING, g_nStringIdFINALTXT};

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anDataOutputNames[] = {g_nStringIdSTRING1, g_nStringIdSTRING2, g_nStringIdCRCSTROUT, g_nStringIdDATA};

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_B_SECCOM_CONTROLREMOTO::scm_anEIWithIndexes[] = {0, 4, 8, 10};
const TDataIOID FORTE_B_SECCOM_CONTROLREMOTO::scm_anEIWith[] = {0, 2, 1, 255, 0, 1, 4, 255, 3, 255, 5, 6, 255};
const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdCRCI, g_nStringIdCNFTXT};

const TDataIOID FORTE_B_SECCOM_CONTROLREMOTO::scm_anEOWith[] = {0, 1, 255, 2, 255, 3, 255};
const TForteInt16 FORTE_B_SECCOM_CONTROLREMOTO::scm_anEOWithIndexes[] = {-1, 0, 3, 5, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdCRCO, g_nStringIdEDATA, g_nStringIdREQTXT, g_nStringIdREADY, g_nStringIdBUSY};

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anInternalsNames[] = {g_nStringIdSTRSUB1, g_nStringIdSTRSUB2, g_nStringIdSTRSUB3, g_nStringIdINITCONTROL, g_nStringIdUINTCPY, g_nStringIdLASTDLE, g_nStringIdSTRINGSPACE, g_nStringIdSPACEINT, g_nStringIdAUXINT1, g_nStringIdINTERNALVAR2};

const CStringDictionary::TStringId FORTE_B_SECCOM_CONTROLREMOTO::scm_anInternalsTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_B_SECCOM_CONTROLREMOTO::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  7,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  7,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_B_SECCOM_CONTROLREMOTO::scm_stInternalVars = {10, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_B_SECCOM_CONTROLREMOTO::setInitialValues(){
  INITCONTROL() = false;
  UINTCPY() = 0;
  SPACEINT() = 0;
  AUXINT1() = 0;
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_INIT(void){
STRING1() = "\x04\x7f";
STRING2() = "\x01\x02\x03\x04";
INITCONTROL() = false;
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_REQ(void){

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST0(void){
STRING1() = "\x05";
STRING2() = "\x10\x30";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST1(void){
STRSUB1() = "\x01\x52\x43\x4b\x02";
STRSUB2() = "\x30\x32\x09";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = INSTRING();
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

STRSUB2() = "\x09\x03";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));




CRCSTROUT() = STRSUB3();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST2(void){
STRING1() = CRCSTRIN();
STRING2() = "\x10\x31";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST3(void){
STRING1() = "\x04";
STRING2() = "\x05\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST4(void){
STRING1() = "\x10\x30";
STRING2() = "\x02\x03";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_ST5(void){
STRING1() = "\x10\x31";
STRING2() = "\x04\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_EP0(void){
STRING1() = "\x05";
STRING2() = "\x10\x30";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE0(void){
STRING1() = "\x05";
STRING2() = "\x10\x30";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_LE0(void){
STRING1() = "\x04\x33\x33\x7f";
STRING2() = "\x01\x02\x03\x04";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IT0(void){
STRING1() = "\x04\x34\x34\x7f";
STRING2() = "\x01\x02\x03\x04";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE0(void){
STRING1() = "\x05";
STRING2() = "\x10\x30";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE1(void){
STRING1() = "\x01\x52\x43\x4c\x02\x03\xfe\x2c";
STRING2() = "\x10\x31";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE2(void){
STRING1() = "\x04";
STRING2() = "\x05\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE3(void){
STRING1() = "\x10\x30";
STRING2() = "\x02\x03";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE4(void){
STRING1() = "\x10\x31";
STRING2() = "\x04\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_start(void){
UINTCPY() = UINT1();
INITCONTROL() = true;

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE1(void){
STRSUB1() = "\x01\x52\x43\x4b\x02";
STRSUB2() = "\x30\x31";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = "\x03";
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

CRCSTROUT() = STRSUB1();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE2(void){
STRING1() = CRCSTRIN();
STRING2() = "\x10\x31";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE3(void){
STRING1() = "\x04";
STRING2() = "\x05\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE4(void){
STRING1() = "\x10\x30";
STRING2() = "\x02\x03";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE5(void){
STRING1() = "\x10\x31";
STRING2() = "\x04\x7f";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IT1(void){
STRSUB1() = "\x01\x52\x43\x4b\x02";
STRSUB2() = "\x31\x31";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = "\x03";
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

CRCSTROUT() = STRSUB1();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_LE1(void){
STRSUB1() = "\x01\x52\x43\x4b\x02";
STRSUB2() = "\x31\x30";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = "\x03";
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

CRCSTROUT() = STRSUB1();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IE40(void){
DATA() = RDATA();
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_IT50(void){
DATA() = RDATA();
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_LE50(void){
DATA() = RDATA();
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_PE50(void){
DATA() = RDATA();
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_CP1(void){
STRSUB1() = "\x01\x53\x43\x53\x02";
STRSUB2() = "\x25\x36\x31\x34\x39\x39";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = "\x09\x44";
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

STRSUB2() = "\x17";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

CRCSTROUT() = STRSUB3();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_CP2(void){
STRING1() = CRCSTRIN();
LASTDLE() = "\x10\x31";
STRING2() = "\x10\x31";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_CP4(void){
STRSUB1() = "\x02";
STRSUB2() = TXTSTRING();
STRINGSPACE() = "\x20";

SPACEINT() = 0;
AUXINT1() = LEN((STRSUB2()));
while((SPACEINT() <= AUXINT1())){

	STRSUB3() = MID((STRSUB2()), (1), (SPACEINT()));
	if((STRSUB3() == STRINGSPACE())){
		STRSUB2() = DELETE((STRSUB2()), (1), (SPACEINT()));
		AUXINT1() = LEN((STRSUB2()));
	}
else{
	SPACEINT() = SPACEINT()+1;
	
	};
	
};

STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

if((FINALTXT() == true)){
	STRSUB2() = "\x03";
}
else{
	STRSUB2() = "\x17";
};

STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

CRCSTROUT() = STRSUB1();

}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_CP5(void){
STRING1() = CRCSTRIN();

if((LASTDLE() == "\x10\x30")){
STRING2() = "\x10\x31";
LASTDLE() = "\x10\x31";
}
else{
STRING2() = "\x10\x30";
LASTDLE() = "\x10\x30";
};
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_CP6(void){
STRING1() = "\x04";
STRING2() = "\x01\x02\x03\x04";
}

void FORTE_B_SECCOM_CONTROLREMOTO::alg_EP1(void){
STRSUB1() = "\x01\x52\x43\x4b\x02";
STRSUB2() = "\x30\x30";
STRSUB3() = CONCAT((STRSUB1()), (STRSUB2()));

STRSUB2() = "\x25\x36\x31\x34\x39\x39\x4e\x30\x30\x30\x30\x03";
STRSUB1() = CONCAT((STRSUB3()), (STRSUB2()));

CRCSTROUT() = STRSUB1();




}


void FORTE_B_SECCOM_CONTROLREMOTO::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateState1(void){
  m_nECCState = scm_nStateState1;
  alg_start();
  sendOutputEvent( scm_nEventBUSYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateSIMULACIONTECLADO(void){
  m_nECCState = scm_nStateSIMULACIONTECLADO;
  alg_ST0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEJECUCIONPROGRAMA(void){
  m_nECCState = scm_nStateEJECUCIONPROGRAMA;
  alg_EP0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePETICIONERRORES(void){
  m_nECCState = scm_nStatePETICIONERRORES;
  alg_PE0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLECTURAEJES(void){
  m_nECCState = scm_nStateLECTURAEJES;
  alg_ST0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateINFORMETIPO(void){
  m_nECCState = scm_nStateINFORMETIPO;
  alg_ST0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateST1(void){
  m_nECCState = scm_nStateST1;
  alg_ST1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateST2(void){
  m_nECCState = scm_nStateST2;
  alg_ST2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_ST(void){
  m_nECCState = scm_nStateExit_ST;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateST3(void){
  m_nECCState = scm_nStateST3;
  alg_ST3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateST4(void){
  m_nECCState = scm_nStateST4;
  alg_ST4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateST5(void){
  m_nECCState = scm_nStateST5;
  alg_ST5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateINFOREESTADO(void){
  m_nECCState = scm_nStateINFOREESTADO;
  alg_IE0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIE1(void){
  m_nECCState = scm_nStateIE1;
  alg_IE1();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIE2(void){
  m_nECCState = scm_nStateIE2;
  alg_IE2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIE3(void){
  m_nECCState = scm_nStateIE3;
  alg_IE3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIE4(void){
  m_nECCState = scm_nStateIE4;
  alg_IE40();
  sendOutputEvent( scm_nEventEDATAID);
  alg_IE4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_IE(void){
  m_nECCState = scm_nStateExit_IE;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInitEP(void){
  m_nECCState = scm_nStateInitEP;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInitPE(void){
  m_nECCState = scm_nStateInitPE;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInit_ST(void){
  m_nECCState = scm_nStateInit_ST;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInit_LE(void){
  m_nECCState = scm_nStateInit_LE;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInit_IT(void){
  m_nECCState = scm_nStateInit_IT;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInit_IE(void){
  m_nECCState = scm_nStateInit_IE;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePE1(void){
  m_nECCState = scm_nStatePE1;
  alg_PE1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePE2(void){
  m_nECCState = scm_nStatePE2;
  alg_PE2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_PE(void){
  m_nECCState = scm_nStateExit_PE;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePE3(void){
  m_nECCState = scm_nStatePE3;
  alg_PE3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePE4(void){
  m_nECCState = scm_nStatePE4;
  alg_PE4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStatePE5(void){
  m_nECCState = scm_nStatePE5;
  alg_PE50();
  sendOutputEvent( scm_nEventEDATAID);
  alg_PE5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_IT(void){
  m_nECCState = scm_nStateExit_IT;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIT1(void){
  m_nECCState = scm_nStateIT1;
  alg_IT1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIT2(void){
  m_nECCState = scm_nStateIT2;
  alg_ST2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIT3(void){
  m_nECCState = scm_nStateIT3;
  alg_ST3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIT4(void){
  m_nECCState = scm_nStateIT4;
  alg_ST4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateIT5(void){
  m_nECCState = scm_nStateIT5;
  alg_IT50();
  sendOutputEvent( scm_nEventEDATAID);
  alg_ST5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_LE(void){
  m_nECCState = scm_nStateExit_LE;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLE1(void){
  m_nECCState = scm_nStateLE1;
  alg_LE1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLE2(void){
  m_nECCState = scm_nStateLE2;
  alg_ST2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLE3(void){
  m_nECCState = scm_nStateLE3;
  alg_ST3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLE4(void){
  m_nECCState = scm_nStateLE4;
  alg_ST4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateLE5(void){
  m_nECCState = scm_nStateLE5;
  alg_LE50();
  sendOutputEvent( scm_nEventEDATAID);
  alg_ST5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCARGAPROGRAMA(void){
  m_nECCState = scm_nStateCARGAPROGRAMA;
  alg_IE0();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_CP(void){
  m_nECCState = scm_nStateExit_CP;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateInit_CP(void){
  m_nECCState = scm_nStateInit_CP;
  alg_INIT();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP1(void){
  m_nECCState = scm_nStateCP1;
  alg_CP1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP4(void){
  m_nECCState = scm_nStateCP4;
  alg_CP4();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP2(void){
  m_nECCState = scm_nStateCP2;
  alg_CP2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP3(void){
  m_nECCState = scm_nStateCP3;
  sendOutputEvent( scm_nEventREQTXTID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP6(void){
  m_nECCState = scm_nStateCP6;
  alg_CP6();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateCP5(void){
  m_nECCState = scm_nStateCP5;
  alg_CP5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEP1(void){
  m_nECCState = scm_nStateEP1;
  alg_EP1();
  sendOutputEvent( scm_nEventCRCOID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEP2(void){
  m_nECCState = scm_nStateEP2;
  alg_PE2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEP3(void){
  m_nECCState = scm_nStateEP3;
  alg_PE3();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateExit_PE_1(void){
  m_nECCState = scm_nStateExit_PE_1;
  sendOutputEvent( scm_nEventREADYID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEP4(void){
  m_nECCState = scm_nStateEP4;
  alg_PE4();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::enterStateEP5(void){
  m_nECCState = scm_nStateEP5;
  alg_PE50();
  sendOutputEvent( scm_nEventEDATAID);
  alg_PE5();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_B_SECCOM_CONTROLREMOTO::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateState1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState1:
        if((UINTCPY() == 0) && (INITCONTROL()))
          enterStateInitEP();
        else
        if((UINTCPY() == 1) && (INITCONTROL()))
          enterStateInitPE();
        else
        if((UINTCPY() == 2) && (INITCONTROL()))
          enterStateInit_ST();
        else
        if((UINTCPY() == 3) && (INITCONTROL()))
          enterStateInit_LE();
        else
        if((UINTCPY() == 4) && (INITCONTROL()))
          enterStateInit_IT();
        else
        if((UINTCPY() == 5) && (INITCONTROL()))
          enterStateInit_IE();
        else
        if(UINTCPY() > 6)
          enterStateSTART();
        else
        if((UINTCPY() == 6) && (INITCONTROL()))
          enterStateInit_CP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSIMULACIONTECLADO:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateST1();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_ST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEJECUCIONPROGRAMA:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE_1();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateEP1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePETICIONERRORES:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStatePE1();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLECTURAEJES:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_LE();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateLE1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINFORMETIPO:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIT1();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateST1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateST2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateST2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateST3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_ST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_ST:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateST3:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateST4();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_ST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateST4:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateST5();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_ST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateST5:
        if(1)
          enterStateExit_ST();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINFOREESTADO:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIE1();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIE1:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIE2();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIE2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIE3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIE3:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIE4();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIE4:
        if(1)
          enterStateExit_IE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_IE:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitEP:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateEJECUCIONPROGRAMA();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitPE:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStatePETICIONERRORES();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_ST:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateSIMULACIONTECLADO();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_LE:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateLECTURAEJES();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_IT:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateINFORMETIPO();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_IE:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateINFOREESTADO();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePE1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStatePE2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePE2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStatePE3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_PE:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePE3:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStatePE4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePE4:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStatePE5();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePE5:
        if(1)
          enterStateExit_PE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_IT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIT1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateIT2();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIT2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIT3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIT3:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIT4();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIT4:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateIT5();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIT5:
        if(1)
          enterStateExit_IT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_LE:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLE1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateLE2();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_LE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLE2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateLE3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_LE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLE3:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateLE4();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_LE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLE4:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateLE5();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_LE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateLE5:
        if(1)
          enterStateExit_LE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCARGAPROGRAMA:
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_CP();
        else
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateCP1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_CP:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_CP:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateCARGAPROGRAMA();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateCP2();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_CP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP4:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateCP5();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateCP3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_CP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP3:
        if(scm_nEventCNFTXTID == pa_nEIID)
          enterStateCP4();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP6:
        if(scm_nEventREQID == pa_nEIID)
          enterStateExit_CP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCP5:
        if((scm_nEventREQID == pa_nEIID) && ((Q()) && (!FINALTXT())))
          enterStateCP3();
        else
        if((scm_nEventREQID == pa_nEIID) && ((Q()) && (FINALTXT())))
          enterStateCP6();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_CP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEP1:
        if(scm_nEventCRCIID == pa_nEIID)
          enterStateEP2();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEP2:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateEP3();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE_1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEP3:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateEP4();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE_1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateExit_PE_1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEP4:
        if((scm_nEventREQID == pa_nEIID) && (Q()))
          enterStateEP5();
        else
        if((scm_nEventREQID == pa_nEIID) && (!Q()))
          enterStateExit_PE_1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateEP5:
        if(1)
          enterStateExit_PE_1();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 57.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


