/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: B_CURRENTCALC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2016-04-06/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _B_CURRENTCALC_H_
#define _B_CURRENTCALC_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>

class FORTE_B_CURRENTCALC: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_B_CURRENTCALC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &RT() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_INT &PERIODOMUESTREO() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  CIEC_INT &PERIODOCALCULO() {
    return *static_cast<CIEC_INT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Irms() {
    return *static_cast<CIEC_REAL*>(getDO(0));
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
  CIEC_INT &N() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_REAL &SUMATORIO() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 4, 1, 2, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  void alg_CALCULO(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateState = 2;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateState(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_B_CURRENTCALC(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_B_CURRENTCALC(){};

};

#endif //close the ifdef sequence from the beginning of the file

