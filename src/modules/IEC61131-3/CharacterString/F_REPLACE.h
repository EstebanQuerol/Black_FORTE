/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_REPLACE
 *** Description: replace L characters of IN1 by IN2 starting at the P-th character position
 *** Version: 
 ***     0.0: 2013-04-25/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _F_REPLACE_H_
#define _F_REPLACE_H_

#include <funcbloc.h>
#include <forte_any_int.h>
#include <forte_any_string.h>

class FORTE_F_REPLACE: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_REPLACE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_ANY_STRING &IN1() {
    return *static_cast<CIEC_ANY_STRING*>(getDI(0));
  };

  CIEC_ANY_STRING &IN2() {
    return *static_cast<CIEC_ANY_STRING*>(getDI(1));
  };

  CIEC_ANY_INT &L() {
    return *static_cast<CIEC_ANY_INT*>(getDI(2));
  };

  CIEC_ANY_INT &P() {
    return *static_cast<CIEC_ANY_INT*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_ANY_STRING &OUT() {
    return *static_cast<CIEC_ANY_STRING*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 4, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_REPLACE){
  };

  template<typename T> void calculateValueString(){
     T oIn1;
     oIn1.saveAssign(IN1());
     T oIn2;
     oIn2.saveAssign(IN2());
     OUT().saveAssign(REPLACE(oIn1,oIn2,L(),P()));
   }

  virtual ~FORTE_F_REPLACE(){};

};

#endif //close the ifdef sequence from the beginning of the file

