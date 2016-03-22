/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: RT_E_SPLIT_6
 *** Description: Split an event to two event chain branches
 *** Version: 
 ***     0.0: 2016-15-03/EQUEROL - UJI-ESDID - 
 *************************************************************************/

#ifndef _RT_E_SPLIT_6_H_
#define _RT_E_SPLIT_6_H_

#include <funcbloc.h>
#include <ecet.h>
#include <forte_time.h>
#include <forte_bool.h>


class FORTE_RT_E_SPLIT_6: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_RT_E_SPLIT_6)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_TIME &Tmin() {
    return *static_cast<CIEC_TIME*>(getDI(1));
  };

  CIEC_TIME &Deadline_EO1() {
    return *static_cast<CIEC_TIME*>(getDI(2));
  };

  CIEC_TIME &WCET_EO1() {
    return *static_cast<CIEC_TIME*>(getDI(3));
  };

  CIEC_TIME &Deadline_EO2() {
    return *static_cast<CIEC_TIME*>(getDI(4));
  };

  CIEC_TIME &WCET_EO2() {
    return *static_cast<CIEC_TIME*>(getDI(5));
  };

  CIEC_TIME &Deadline_EO3() {
    return *static_cast<CIEC_TIME*>(getDI(6));
  };

  CIEC_TIME &WCET_EO3() {
    return *static_cast<CIEC_TIME*>(getDI(7));
  };

  CIEC_TIME &Deadline_EO4() {
    return *static_cast<CIEC_TIME*>(getDI(8));
  };

  CIEC_TIME &WCET_EO4() {
    return *static_cast<CIEC_TIME*>(getDI(9));
  };

  CIEC_TIME &Deadline_EO5() {
    return *static_cast<CIEC_TIME*>(getDI(10));
  };

  CIEC_TIME &WCET_EO5() {
    return *static_cast<CIEC_TIME*>(getDI(11));
  };

  CIEC_TIME &Deadline_EO6() {
    return *static_cast<CIEC_TIME*>(getDI(12));
  };

  CIEC_TIME &WCET_EO6() {
    return *static_cast<CIEC_TIME*>(getDI(13));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventEIID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEO1ID = 1;
  static const TEventID scm_nEventEO2ID = 2;
  static const TEventID scm_nEventEO3ID = 3;
  static const TEventID scm_nEventEO4ID = 4;
  static const TEventID scm_nEventEO5ID = 5;
  static const TEventID scm_nEventEO6ID = 6;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(7, 14, 1, 0);

   CEventChainExecutionThread m_oECEO1, m_oECEO2, m_oECEO3, m_oECEO4, m_oECEO5, m_oECEO6;
   bool m_bInitialized;

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_RT_E_SPLIT_6){
	  m_bInitialized = false;
  };

  virtual ~FORTE_RT_E_SPLIT_6(){};

};

#endif //close the ifdef sequence from the beginning of the file

