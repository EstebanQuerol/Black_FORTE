/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_RT_CLOCK_NS
 *** Description: Reads the internal real time clock
 *** Version: 
 ***     0.0: 2011-06-21/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _F_RT_CLOCK_NS_H_
#define _F_RT_CLOCK_NS_H_

#include <funcbloc.h>
#include <forte_lword.h>
#include <time.h>

class FORTE_F_RT_CLOCK_NS: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_RT_CLOCK_NS)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_LWORD &OUT() {
    return *static_cast<CIEC_LWORD*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  struct timespec m_stAuxTime;
   FORTE_FB_DATA_ARRAY(1, 0, 1, 0);

  void executeEvent(int pa_nEIID);
public:
  FUNCTION_BLOCK_CTOR(FORTE_F_RT_CLOCK_NS){
  };

  virtual ~FORTE_F_RT_CLOCK_NS(){};

};

#endif //close the ifdef sequence from the beginning of the file

