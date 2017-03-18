/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Time_driven_PID
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-11-02/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _TIME_DRIVEN_PID_H_
#define _TIME_DRIVEN_PID_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>

class FORTE_Time_driven_PID: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Time_driven_PID)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &Ym() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &Yref() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &K() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &Ti() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &Td() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &Interval() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &LIM_H() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &LIM_L() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  CIEC_REAL &beta() {
    return *static_cast<CIEC_REAL*>(getDI(8));
  };

  CIEC_REAL &N() {
    return *static_cast<CIEC_REAL*>(getDI(9));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &u() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_BOOL &LIM() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventRSTID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_REAL &yold() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_REAL &ud() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &ui() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 10, 2, 3, 0);
  void alg_RESET(void);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;
  static const TForteInt16 scm_nStateRST = 2;
  static const TForteInt16 scm_nStateREQ = 3;

  void enterStateSTART(void);
  void enterStateINIT(void);
  void enterStateRST(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Time_driven_PID(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Time_driven_PID(){};

};

#endif //close the ifdef sequence from the beginning of the file

