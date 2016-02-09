/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CTRL_TPID
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2016-02-08/EQUEROL - UJI_ESID - 
 *************************************************************************/

#ifndef _CTRL_TPID_H_
#define _CTRL_TPID_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_real.h>
#include <forte_time.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_CTRL_TPID: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_CTRL_TPID)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_TIME &T() {
    return *static_cast<CIEC_TIME*>(getDI(0));
  };

  CIEC_REAL &Yref() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &Ym() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &U_MAX() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &U_MIN() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &KP() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &TD() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &TI() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  CIEC_REAL &N() {
    return *static_cast<CIEC_REAL*>(getDI(8));
  };

  CIEC_REAL &BP() {
    return *static_cast<CIEC_REAL*>(getDI(9));
  };

  CIEC_REAL &BD() {
    return *static_cast<CIEC_REAL*>(getDI(10));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &Status() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_REAL &u() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventStopID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventINDID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 11, 3, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_CTRL_TPID){
  };

  virtual ~FORTE_CTRL_TPID(){};

};

#endif //close the ifdef sequence from the beginning of the file

