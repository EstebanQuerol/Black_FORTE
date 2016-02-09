/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CTRL_TPID_ALG
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-02-09/EQUEROL - UJI_ESID - 
 *************************************************************************/

#ifndef _CTRL_TPID_ALG_H_
#define _CTRL_TPID_ALG_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_CTRL_TPID_ALG: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CTRL_TPID_ALG)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &T() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &yref() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &ym() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &U_MAX() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &U_MIN() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &KP() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &TD() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &TI() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  CIEC_REAL &N() {
    return *static_cast<CIEC_REAL*>(getDI(8));
  };

  CIEC_REAL &BP() {
    return *static_cast<CIEC_REAL*>(getDI(9));
  };

  CIEC_REAL &BD() {
    return *static_cast<CIEC_REAL*>(getDI(10));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &Status() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_REAL &u() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventStopID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventEOID = 1;
  static const TEventID scm_nEventStartID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &INIT_OK() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  CIEC_REAL &pd() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &qd() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  CIEC_REAL &D() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_BOOL &I() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(4));
  };

  CIEC_REAL &qi() {
    return *static_cast<CIEC_REAL*>(getVarInternal(5));
  };

  CIEC_REAL &yref_old() {
    return *static_cast<CIEC_REAL*>(getVarInternal(6));
  };

  CIEC_REAL &ym_old() {
    return *static_cast<CIEC_REAL*>(getVarInternal(7));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 11, 3, 8, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_RST(void);
  static const TForteInt16 scm_nStateHALT = 0;
  static const TForteInt16 scm_nStateIDLE = 1;
  static const TForteInt16 scm_nStateINIT = 2;
  static const TForteInt16 scm_nStateREQ = 3;
  static const TForteInt16 scm_nStateRESET = 4;
  static const TForteInt16 scm_nStateSTART_SAMPLING = 5;

  void enterStateHALT(void);
  void enterStateIDLE(void);
  void enterStateINIT(void);
  void enterStateREQ(void);
  void enterStateRESET(void);
  void enterStateSTART_SAMPLING(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CTRL_TPID_ALG(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CTRL_TPID_ALG(){};

};

#endif //close the ifdef sequence from the beginning of the file

