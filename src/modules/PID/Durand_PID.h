/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Durand_PID
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2017-02-20/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#ifndef _DURAND_PID_H_
#define _DURAND_PID_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_int.h>

class FORTE_Durand_PID: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Durand_PID)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_REAL &yref() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &ym() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &hnom() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &e_lim() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &precision() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &K() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &Ti() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  CIEC_REAL &Td() {
    return *static_cast<CIEC_REAL*>(getDI(8));
  };

  CIEC_INT &choice() {
    return *static_cast<CIEC_INT*>(getDI(9));
  };

  CIEC_REAL &hmax() {
    return *static_cast<CIEC_REAL*>(getDI(10));
  };

  CIEC_REAL &N() {
    return *static_cast<CIEC_REAL*>(getDI(11));
  };

  CIEC_REAL &beta() {
    return *static_cast<CIEC_REAL*>(getDI(12));
  };

  CIEC_REAL &LIM_H() {
    return *static_cast<CIEC_REAL*>(getDI(13));
  };

  CIEC_REAL &LIM_L() {
    return *static_cast<CIEC_REAL*>(getDI(14));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_REAL &u() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventNOEJECID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_REAL &error() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_REAL &hact() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &error_old() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  CIEC_REAL &ui() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_REAL &ud() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  CIEC_REAL &y_old() {
    return *static_cast<CIEC_REAL*>(getVarInternal(5));
  };

  CIEC_REAL &he() {
    return *static_cast<CIEC_REAL*>(getVarInternal(6));
  };

  CIEC_REAL &hact_i() {
    return *static_cast<CIEC_REAL*>(getVarInternal(7));
  };

  CIEC_REAL &up() {
    return *static_cast<CIEC_REAL*>(getVarInternal(8));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 15, 2, 9, 0);

virtual void setInitialValues();
  void alg_initialize(void);
  void alg_deInitialize(void);
  void alg_Calculos_previos(void);
  void alg_Calculo_PID(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateNormalOp = 2;
  static const TForteInt16 scm_nStateInitialized = 3;
  static const TForteInt16 scm_nStateDeInit = 4;
  static const TForteInt16 scm_nStateEjecucion = 5;
  static const TForteInt16 scm_nStateNoejecucion = 6;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateNormalOp(void);
  void enterStateInitialized(void);
  void enterStateDeInit(void);
  void enterStateEjecucion(void);
  void enterStateNoejecucion(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Durand_PID(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Durand_PID(){};

};

#endif //close the ifdef sequence from the beginning of the file

