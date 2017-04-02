/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_SPLIT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-03-18/EQUEROL - EQUEROL - 
 *************************************************************************/

#ifndef _XENO_RT_E_SPLIT_H_
#define _XENO_RT_E_SPLIT_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <XenomaiECET.h>
class FORTE_XENO_RT_E_SPLIT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_XENO_RT_E_SPLIT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &Policy_EO1() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_USINT &Priority_EO1() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  CIEC_USINT &Policy_EO2() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  CIEC_USINT &Priority_EO2() {
    return *static_cast<CIEC_USINT*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventUpdateID = 1;
  static const TEventID scm_nEventEIID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEO1ID = 1;
  static const TEventID scm_nEventEO2ID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 5, 1, 0);
  CXenomaiECET m_oECEO1,m_oECEO2;
  bool m_bInitialized;
  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_XENO_RT_E_SPLIT){
	  m_bInitialized = false;
  };

  virtual ~FORTE_XENO_RT_E_SPLIT(){};

};

#endif //close the ifdef sequence from the beginning of the file

