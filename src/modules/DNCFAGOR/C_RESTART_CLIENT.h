/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: C_RESTART_CLIENT
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.0: 2016-02-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _C_RESTART_CLIENT_H_
#define _C_RESTART_CLIENT_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_time.h>
#include <forte_wstring.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_C_RESTART_CLIENT: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_C_RESTART_CLIENT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_TIME &TIME1() {
    return *static_cast<CIEC_TIME*>(getDI(0));
  };

  CIEC_WSTRING &WSTRING1() {
    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_UINT &N() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &Q() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &EQ() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINITCLIENTID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 3, 2, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBParameter scm_astParamters[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_C_RESTART_CLIENT){
  };

  virtual ~FORTE_C_RESTART_CLIENT(){};

};

#endif //close the ifdef sequence from the beginning of the file

