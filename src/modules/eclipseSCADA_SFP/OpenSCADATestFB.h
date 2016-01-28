/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: OpenSCADATestFB
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-07-06/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _OPENSCADATESTFB_H_
#define _OPENSCADATESTFB_H_

#include "openscadafb.h"
#include <forte_int.h>
#include <forte_string.h>
#include <forte_bool.h>

class FORTE_OpenSCADATestFB: public COpenSCADAFB{
  DECLARE_FIRMWARE_FB(FORTE_OpenSCADATestFB)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &BaseAddress() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_BOOL &TestBool() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_INT &TestINT() {
    return *static_cast<CIEC_INT*>(getDI(3));
  };

  CIEC_STRING &TestString() {
    return *static_cast<CIEC_STRING*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_INT &RD_INT() {
    return *static_cast<CIEC_INT*>(getDO(1));
  };

  CIEC_BOOL &RD_DINT() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  CIEC_STRING &RD_String() {
    return *static_cast<CIEC_STRING*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TEventID scm_nEventINDID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 5, 4, 0);

  void executeEvent(int pa_nEIID);

public:
  FORTE_OpenSCADATestFB(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);

  virtual ~FORTE_OpenSCADATestFB();

  bool writeDataPointDataRecieved(struct sfp_item * pa_pstItem, struct sfp_variant *pa_pstValue);

private:
  void initialize();
  void updateSCADAData();
};

#endif //close the ifdef sequence from the beginning of the file

