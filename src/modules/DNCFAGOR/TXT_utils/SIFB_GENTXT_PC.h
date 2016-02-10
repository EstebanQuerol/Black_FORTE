/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SIFB_GENTXT_PC
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-11-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _SIFB_GENTXT_PC_H_
#define _SIFB_GENTXT_PC_H_

#include <funcbloc.h>
#include <forte_string.h>

class FORTE_SIFB_GENTXT_PC: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SIFB_GENTXT_PC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &STRING1() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 1, 0, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_SIFB_GENTXT_PC){
  };

  virtual ~FORTE_SIFB_GENTXT_PC(){};

};

#endif //close the ifdef sequence from the beginning of the file

