/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_AIn
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-09-09/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _BL_AIN_H_
#define _BL_AIN_H_

#include <funcbloc.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <devlog.h>
#include "BlackLib.h"
#include <string>
#include <iostream>

class FORTE_BL_AIn: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_BL_AIn)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &PARAMS() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_REAL &RD() {
    return *static_cast<CIEC_REAL*>(getDO(2));
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

  BlackLib::BlackADC  * m_poADC;

   FORTE_FB_DATA_ARRAY(2, 2, 3, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_BL_AIn){
	  m_poADC = NULL;
  };

  virtual ~FORTE_BL_AIn(){
	  delete m_poADC;
  };
};

#endif //close the ifdef sequence from the beginning of the file

