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

#ifndef _B_SECCOM_CONTROLREMOTO_H_
#define _B_SECCOM_CONTROLREMOTO_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_uint.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_B_SECCOM_CONTROLREMOTO: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_B_SECCOM_CONTROLREMOTO)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &Q() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &INSTRING() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_UINT &UINT1() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_STRING &CRCSTRIN() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  };

  CIEC_STRING &RDATA() {
    return *static_cast<CIEC_STRING*>(getDI(4));
  };

  CIEC_STRING &TXTSTRING() {
    return *static_cast<CIEC_STRING*>(getDI(5));
  };

  CIEC_BOOL &FINALTXT() {
    return *static_cast<CIEC_BOOL*>(getDI(6));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &STRING1() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &STRING2() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_STRING &CRCSTROUT() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  CIEC_STRING &DATA() {
    return *static_cast<CIEC_STRING*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventCRCIID = 2;
  static const TEventID scm_nEventCNFTXTID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventCRCOID = 2;
  static const TEventID scm_nEventEDATAID = 3;
  static const TEventID scm_nEventREQTXTID = 4;
  static const TEventID scm_nEventREADYID = 5;
  static const TEventID scm_nEventBUSYID = 6;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_STRING &STRSUB1() {
    return *static_cast<CIEC_STRING*>(getVarInternal(0));
  };

  CIEC_STRING &STRSUB2() {
    return *static_cast<CIEC_STRING*>(getVarInternal(1));
  };

  CIEC_STRING &STRSUB3() {
    return *static_cast<CIEC_STRING*>(getVarInternal(2));
  };

  CIEC_BOOL &INITCONTROL() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(3));
  };

  CIEC_UINT &UINTCPY() {
    return *static_cast<CIEC_UINT*>(getVarInternal(4));
  };

  CIEC_STRING &LASTDLE() {
    return *static_cast<CIEC_STRING*>(getVarInternal(5));
  };

  CIEC_STRING &STRINGSPACE() {
    return *static_cast<CIEC_STRING*>(getVarInternal(6));
  };

  CIEC_INT &SPACEINT() {
    return *static_cast<CIEC_INT*>(getVarInternal(7));
  };

  CIEC_INT &AUXINT1() {
    return *static_cast<CIEC_INT*>(getVarInternal(8));
  };

  CIEC_BOOL &INTERNALVAR2() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(9));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(7, 7, 4, 10, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_ST0(void);
  void alg_ST1(void);
  void alg_ST2(void);
  void alg_ST3(void);
  void alg_ST4(void);
  void alg_ST5(void);
  void alg_EP0(void);
  void alg_PE0(void);
  void alg_LE0(void);
  void alg_IT0(void);
  void alg_IE0(void);
  void alg_IE1(void);
  void alg_IE2(void);
  void alg_IE3(void);
  void alg_IE4(void);
  void alg_start(void);
  void alg_PE1(void);
  void alg_PE2(void);
  void alg_PE3(void);
  void alg_PE4(void);
  void alg_PE5(void);
  void alg_IT1(void);
  void alg_LE1(void);
  void alg_IE40(void);
  void alg_IT50(void);
  void alg_LE50(void);
  void alg_PE50(void);
  void alg_CP1(void);
  void alg_CP2(void);
  void alg_CP4(void);
  void alg_CP5(void);
  void alg_CP6(void);
  void alg_EP1(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateState1 = 1;
  static const TForteInt16 scm_nStateSIMULACIONTECLADO = 2;
  static const TForteInt16 scm_nStateEJECUCIONPROGRAMA = 3;
  static const TForteInt16 scm_nStatePETICIONERRORES = 4;
  static const TForteInt16 scm_nStateLECTURAEJES = 5;
  static const TForteInt16 scm_nStateINFORMETIPO = 6;
  static const TForteInt16 scm_nStateST1 = 7;
  static const TForteInt16 scm_nStateST2 = 8;
  static const TForteInt16 scm_nStateExit_ST = 9;
  static const TForteInt16 scm_nStateST3 = 10;
  static const TForteInt16 scm_nStateST4 = 11;
  static const TForteInt16 scm_nStateST5 = 12;
  static const TForteInt16 scm_nStateINFOREESTADO = 13;
  static const TForteInt16 scm_nStateIE1 = 14;
  static const TForteInt16 scm_nStateIE2 = 15;
  static const TForteInt16 scm_nStateIE3 = 16;
  static const TForteInt16 scm_nStateIE4 = 17;
  static const TForteInt16 scm_nStateExit_IE = 18;
  static const TForteInt16 scm_nStateInitEP = 19;
  static const TForteInt16 scm_nStateInitPE = 20;
  static const TForteInt16 scm_nStateInit_ST = 21;
  static const TForteInt16 scm_nStateInit_LE = 22;
  static const TForteInt16 scm_nStateInit_IT = 23;
  static const TForteInt16 scm_nStateInit_IE = 24;
  static const TForteInt16 scm_nStatePE1 = 25;
  static const TForteInt16 scm_nStatePE2 = 26;
  static const TForteInt16 scm_nStateExit_PE = 27;
  static const TForteInt16 scm_nStatePE3 = 28;
  static const TForteInt16 scm_nStatePE4 = 29;
  static const TForteInt16 scm_nStatePE5 = 30;
  static const TForteInt16 scm_nStateExit_IT = 31;
  static const TForteInt16 scm_nStateIT1 = 32;
  static const TForteInt16 scm_nStateIT2 = 33;
  static const TForteInt16 scm_nStateIT3 = 34;
  static const TForteInt16 scm_nStateIT4 = 35;
  static const TForteInt16 scm_nStateIT5 = 36;
  static const TForteInt16 scm_nStateExit_LE = 37;
  static const TForteInt16 scm_nStateLE1 = 38;
  static const TForteInt16 scm_nStateLE2 = 39;
  static const TForteInt16 scm_nStateLE3 = 40;
  static const TForteInt16 scm_nStateLE4 = 41;
  static const TForteInt16 scm_nStateLE5 = 42;
  static const TForteInt16 scm_nStateCARGAPROGRAMA = 43;
  static const TForteInt16 scm_nStateExit_CP = 44;
  static const TForteInt16 scm_nStateInit_CP = 45;
  static const TForteInt16 scm_nStateCP1 = 46;
  static const TForteInt16 scm_nStateCP4 = 47;
  static const TForteInt16 scm_nStateCP2 = 48;
  static const TForteInt16 scm_nStateCP3 = 49;
  static const TForteInt16 scm_nStateCP6 = 50;
  static const TForteInt16 scm_nStateCP5 = 51;
  static const TForteInt16 scm_nStateEP1 = 52;
  static const TForteInt16 scm_nStateEP2 = 53;
  static const TForteInt16 scm_nStateEP3 = 54;
  static const TForteInt16 scm_nStateExit_PE_1 = 55;
  static const TForteInt16 scm_nStateEP4 = 56;
  static const TForteInt16 scm_nStateEP5 = 57;

  void enterStateSTART(void);
  void enterStateState1(void);
  void enterStateSIMULACIONTECLADO(void);
  void enterStateEJECUCIONPROGRAMA(void);
  void enterStatePETICIONERRORES(void);
  void enterStateLECTURAEJES(void);
  void enterStateINFORMETIPO(void);
  void enterStateST1(void);
  void enterStateST2(void);
  void enterStateExit_ST(void);
  void enterStateST3(void);
  void enterStateST4(void);
  void enterStateST5(void);
  void enterStateINFOREESTADO(void);
  void enterStateIE1(void);
  void enterStateIE2(void);
  void enterStateIE3(void);
  void enterStateIE4(void);
  void enterStateExit_IE(void);
  void enterStateInitEP(void);
  void enterStateInitPE(void);
  void enterStateInit_ST(void);
  void enterStateInit_LE(void);
  void enterStateInit_IT(void);
  void enterStateInit_IE(void);
  void enterStatePE1(void);
  void enterStatePE2(void);
  void enterStateExit_PE(void);
  void enterStatePE3(void);
  void enterStatePE4(void);
  void enterStatePE5(void);
  void enterStateExit_IT(void);
  void enterStateIT1(void);
  void enterStateIT2(void);
  void enterStateIT3(void);
  void enterStateIT4(void);
  void enterStateIT5(void);
  void enterStateExit_LE(void);
  void enterStateLE1(void);
  void enterStateLE2(void);
  void enterStateLE3(void);
  void enterStateLE4(void);
  void enterStateLE5(void);
  void enterStateCARGAPROGRAMA(void);
  void enterStateExit_CP(void);
  void enterStateInit_CP(void);
  void enterStateCP1(void);
  void enterStateCP4(void);
  void enterStateCP2(void);
  void enterStateCP3(void);
  void enterStateCP6(void);
  void enterStateCP5(void);
  void enterStateEP1(void);
  void enterStateEP2(void);
  void enterStateEP3(void);
  void enterStateExit_PE_1(void);
  void enterStateEP4(void);
  void enterStateEP5(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_B_SECCOM_CONTROLREMOTO(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_B_SECCOM_CONTROLREMOTO(){};

};

#endif //close the ifdef sequence from the beginning of the file

