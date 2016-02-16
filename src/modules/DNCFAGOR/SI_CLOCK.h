/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_CLOCK
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2016-01-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _SI_CLOCK_H_
#define _SI_CLOCK_H_

#include <funcbloc.h>
#include <forte_time.h>
#include <forte_string.h>
#include <string>
#include <sstream>


using namespace std;

class FORTE_SI_CLOCK: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SI_CLOCK)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_TIME &TIME1() {
    return *static_cast<CIEC_TIME*>(getDO(0));
  };

  CIEC_STRING &STRING1() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 0, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_SI_CLOCK){
  };

  virtual ~FORTE_SI_CLOCK(){};

};

#endif //close the ifdef sequence from the beginning of the file

