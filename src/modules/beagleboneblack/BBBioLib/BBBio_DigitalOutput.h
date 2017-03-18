/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_DigitalOutput
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-02-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _BBBIO_DIGITALOUTPUT_H_
#define _BBBIO_DIGITALOUTPUT_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_byte.h>
#include <forte_wstring.h>
#include "CBBBiolib.h"
#include "BBBiolib.h"

class FORTE_BBBio_DigitalOutput: public CFunctionBlock, public CBBBiolib{
  DECLARE_FIRMWARE_FB(FORTE_BBBio_DigitalOutput)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BYTE &PORT() {
    return *static_cast<CIEC_BYTE*>(getDI(1));
  };

  CIEC_BYTE &PIN() {
    return *static_cast<CIEC_BYTE*>(getDI(2));
  };

  CIEC_BOOL &OUTPUT() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_WSTRING &STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 4, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_BBBio_DigitalOutput){
  };

  virtual ~FORTE_BBBio_DigitalOutput(){};

};

#endif //close the ifdef sequence from the beginning of the file

