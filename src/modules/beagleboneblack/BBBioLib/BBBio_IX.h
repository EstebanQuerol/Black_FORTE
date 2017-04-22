/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_IX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-04-07/EQUEROL - EQUEROL - 
 *************************************************************************/

#ifndef _BBBIO_IX_H_
#define _BBBIO_IX_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_usint.h>
#include <forte_string.h>
#include "CBBBiolib.h"
#include "BBBiolib.h"

class FORTE_BBBio_IX: public CFunctionBlock, public CBBBiolib{
  DECLARE_FIRMWARE_FB(FORTE_BBBio_IX)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_USINT &PORT() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_USINT &PIN() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_BOOL &IN() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  bool m_bIsInit;
   FORTE_FB_DATA_ARRAY(2, 3, 3, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_BBBio_IX){
	  m_bIsInit = false;
  };

  virtual ~FORTE_BBBio_IX(){};

};

#endif //close the ifdef sequence from the beginning of the file

