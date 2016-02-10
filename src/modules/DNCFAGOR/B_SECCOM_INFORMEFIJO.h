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

#ifndef _B_SECCOM_INFORMEFIJO_H_
#define _B_SECCOM_INFORMEFIJO_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>

class FORTE_B_SECCOM_INFORMEFIJO: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_B_SECCOM_INFORMEFIJO)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &Q() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &STRING1() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_STRING &STRING2() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 2, 0, 0);
  void alg_ALG_INIT(void);
  void alg_ALG_S1(void);
  void alg_ALG_S2(void);
  void alg_ALG_S3(void);
  void alg_ALG_S4(void);
  void alg_ALG_S5(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateS1 = 2;
  static const TForteInt16 scm_nStateS2 = 3;
  static const TForteInt16 scm_nStateS3 = 4;
  static const TForteInt16 scm_nStateS4 = 5;
  static const TForteInt16 scm_nStateS5 = 6;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateS1(void);
  void enterStateS2(void);
  void enterStateS3(void);
  void enterStateS4(void);
  void enterStateS5(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_B_SECCOM_INFORMEFIJO(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_B_SECCOM_INFORMEFIJO(){};

};

#endif //close the ifdef sequence from the beginning of the file

