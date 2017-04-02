/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_CYCLE
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-03-19/EQUEROL - EQUEROL - 
 *************************************************************************/

#ifndef _XENO_RT_E_CYCLE_H_
#define _XENO_RT_E_CYCLE_H_

#include <esfb.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_time.h>
#include <XenomaiECET.h>
#include "../arch/timerha.h"

class FORTE_XENO_RT_E_CYCLE: public CEventSourceFB{
  DECLARE_FIRMWARE_FB(FORTE_XENO_RT_E_CYCLE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &DT() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_USINT &Policy_EO1() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  CIEC_USINT &Priority_EO1() {
    return *static_cast<CIEC_USINT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventUpdateID = 1;
  static const TEventID scm_nEventSTARTID = 2;
  static const TEventID scm_nEventSTOPID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEOID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 4, 1, 0);

  STimedFBListEntry m_stTimeListEntry;
  bool m_bActive; //!> flag to indicate that the timed fb is currently active
  bool m_bInitialized;
  CXenomaiECET m_oECEO;

  void executeEvent(int pa_nEIID);

public:
  FORTE_XENO_RT_E_CYCLE(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);

  virtual ~FORTE_XENO_RT_E_CYCLE(){};

};

#endif //close the ifdef sequence from the beginning of the file

