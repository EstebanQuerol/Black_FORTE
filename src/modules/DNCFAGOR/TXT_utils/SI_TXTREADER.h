/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_TXTREADER
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-12-17/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _SI_TXTREADER_H_
#define _SI_TXTREADER_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <fstream>

using namespace std;

class FORTE_SI_TXTREADER: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SI_TXTREADER)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  streampos lastreadpos;
  clock_t startTime = 0;

  bool control=false;
  CIEC_STRING &TXTSTRING() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_BOOL &FINALTXT() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
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
  FUNCTION_BLOCK_CTOR(FORTE_SI_TXTREADER){
  };

  virtual ~FORTE_SI_TXTREADER(){};

};

#endif //close the ifdef sequence from the beginning of the file

