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

#ifndef _B_STRINGERASESPACES_H_
#define _B_STRINGERASESPACES_H_

#include <basicfb.h>
#include <forte_ulint.h>
#include <forte_string.h>

class FORTE_B_STRINGERASESPACES: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_B_STRINGERASESPACES)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &IN() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &OUT() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_STRING &SPACECHARACTER() {
    return *static_cast<CIEC_STRING*>(getVarInternal(0));
  };

  CIEC_STRING &CRCHARACTER() {
    return *static_cast<CIEC_STRING*>(getVarInternal(1));
  };

  CIEC_STRING &STRSUB1() {
    return *static_cast<CIEC_STRING*>(getVarInternal(2));
  };

  CIEC_STRING &STRSUB2() {
    return *static_cast<CIEC_STRING*>(getVarInternal(3));
  };

  CIEC_STRING &STRSUB3() {
    return *static_cast<CIEC_STRING*>(getVarInternal(4));
  };

  CIEC_ULINT &POINTER() {
    return *static_cast<CIEC_ULINT*>(getVarInternal(5));
  };

  CIEC_ULINT &INLENGHT() {
    return *static_cast<CIEC_ULINT*>(getVarInternal(6));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 1, 7, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_B_STRINGERASESPACES(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_B_STRINGERASESPACES(){};

};

#endif //close the ifdef sequence from the beginning of the file

