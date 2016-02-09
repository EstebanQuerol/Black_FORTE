/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EG_SSOD
 *** Description: Regular quantifier event generator
 *** Version: 
 ***     0.0: 2016-02-02/EQUEROL - UJI-ESID - 
 *************************************************************************/

#ifndef _EG_SSOD_H_
#define _EG_SSOD_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_EG_SSOD: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_EG_SSOD)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &delta() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &OUT() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventEIID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &i() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_BOOL &SendOutput() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(1));
  };

  CIEC_REAL &LastOut() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 3, 0);

virtual void setInitialValues();
  void alg_EI(void);
  void alg_EO(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateCHECK_INPUT = 1;
  static const TForteInt16 scm_nStateSEND_OUTPUT = 2;

  void enterStateSTART(void);
  void enterStateCHECK_INPUT(void);
  void enterStateSEND_OUTPUT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_EG_SSOD(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_EG_SSOD(){};

};

#endif //close the ifdef sequence from the beginning of the file

