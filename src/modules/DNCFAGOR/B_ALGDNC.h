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

#ifndef _B_ALGDNC_H_
#define _B_ALGDNC_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_uint.h>

class FORTE_B_ALGDNC: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_B_ALGDNC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &DTS() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_STRING &DTR() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_STRING &RDC() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &SDC() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_BOOL &Q() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_STRING &DATA() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventCNFCID = 2;
  static const TEventID scm_nEventTID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventREQCID = 2;
  static const TEventID scm_nEventSTID = 3;
  static const TEventID scm_nEventRTID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &OK() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  CIEC_BOOL &NAK() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(1));
  };

  CIEC_UINT &NT() {
    return *static_cast<CIEC_UINT*>(getVarInternal(2));
  };

  CIEC_UINT &NE() {
    return *static_cast<CIEC_UINT*>(getVarInternal(3));
  };

  CIEC_STRING &STRINGNAK() {
    return *static_cast<CIEC_STRING*>(getVarInternal(4));
  };

  CIEC_BOOL &STX() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(5));
  };

  CIEC_STRING &STRINGSTX() {
    return *static_cast<CIEC_STRING*>(getVarInternal(6));
  };

  CIEC_STRING &STRINGCMP() {
    return *static_cast<CIEC_STRING*>(getVarInternal(7));
  };

  CIEC_BOOL &EOTDEL() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(8));
  };

  CIEC_STRING &COMPOSITESTRING() {
    return *static_cast<CIEC_STRING*>(getVarInternal(9));
  };

  CIEC_UINT &CMPSTRINGLENGHT() {
    return *static_cast<CIEC_UINT*>(getVarInternal(10));
  };

  CIEC_STRING &STRINGETB() {
    return *static_cast<CIEC_STRING*>(getVarInternal(11));
  };

  CIEC_STRING &STRINGETX() {
    return *static_cast<CIEC_STRING*>(getVarInternal(12));
  };

  CIEC_BOOL &TRUNCADA() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(13));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(5, 3, 3, 14, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_S2(void);
  void alg_S4(void);
  void alg_S6(void);
  void alg_S1(void);
  void alg_S10(void);
  void alg_S7(void);
  void alg_S11(void);
  void alg_S12(void);
  void alg_S3(void);
  void alg_S8(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateState = 1;
  static const TForteInt16 scm_nStateState_1 = 2;
  static const TForteInt16 scm_nStateState_2 = 3;
  static const TForteInt16 scm_nStateState_3 = 4;
  static const TForteInt16 scm_nStateState_4 = 5;
  static const TForteInt16 scm_nStateState_6 = 6;
  static const TForteInt16 scm_nStateState_7 = 7;
  static const TForteInt16 scm_nStateState_10 = 8;
  static const TForteInt16 scm_nStateState_11 = 9;
  static const TForteInt16 scm_nStateState_12 = 10;
  static const TForteInt16 scm_nStateState_5 = 11;
  static const TForteInt16 scm_nStateState_8 = 12;
  static const TForteInt16 scm_nStateState_9 = 13;

  void enterStateSTART(void);
  void enterStateState(void);
  void enterStateState_1(void);
  void enterStateState_2(void);
  void enterStateState_3(void);
  void enterStateState_4(void);
  void enterStateState_6(void);
  void enterStateState_7(void);
  void enterStateState_10(void);
  void enterStateState_11(void);
  void enterStateState_12(void);
  void enterStateState_5(void);
  void enterStateState_8(void);
  void enterStateState_9(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_B_ALGDNC(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_B_ALGDNC(){};

};

#endif //close the ifdef sequence from the beginning of the file

