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

#ifndef _STRING_DEMUX2N_H_
#define _STRING_DEMUX2N_H_

#include <basicfb.h>
#include <forte_string.h>

class FORTE_STRING_DEMUX2N: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_STRING_DEMUX2N)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &STRA1() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_STRING &STRA2() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_STRING &STRB1() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_STRING &STRB2() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  };

  CIEC_STRING &STRC1() {
    return *static_cast<CIEC_STRING*>(getDI(4));
  };

  CIEC_STRING &STRC2() {
    return *static_cast<CIEC_STRING*>(getDI(5));
  };

  CIEC_STRING &STRD1() {
    return *static_cast<CIEC_STRING*>(getDI(6));
  };

  CIEC_STRING &STRD2() {
    return *static_cast<CIEC_STRING*>(getDI(7));
  };

  CIEC_STRING &STRE1() {
    return *static_cast<CIEC_STRING*>(getDI(8));
  };

  CIEC_STRING &STRE2() {
    return *static_cast<CIEC_STRING*>(getDI(9));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &STROUT1() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &STROUT2() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventEIAID = 0;
  static const TEventID scm_nEventEIBID = 1;
  static const TEventID scm_nEventEICID = 2;
  static const TEventID scm_nEventEIDID = 3;
  static const TEventID scm_nEventEIEID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 10, 2, 0, 0);
  void alg_A_ESTRA(void);
  void alg_A_ESTRB(void);
  void alg_A_ESTRC(void);
  void alg_A_ESTRD(void);
  void alg_A_ESTRE(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateESTRA = 1;
  static const TForteInt16 scm_nStateESTRB = 2;
  static const TForteInt16 scm_nStateESTRC = 3;
  static const TForteInt16 scm_nStateESTRD = 4;
  static const TForteInt16 scm_nStateESTRE = 5;

  void enterStateSTART(void);
  void enterStateESTRA(void);
  void enterStateESTRB(void);
  void enterStateESTRC(void);
  void enterStateESTRD(void);
  void enterStateESTRE(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_STRING_DEMUX2N(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_STRING_DEMUX2N(){};

};

#endif //close the ifdef sequence from the beginning of the file

