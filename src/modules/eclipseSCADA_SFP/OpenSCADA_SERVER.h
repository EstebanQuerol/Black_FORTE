/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: OpenSCADA_SERVER
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-07-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _OPENSCADA_SERVER_H_
#define _OPENSCADA_SERVER_H_

#include "openscadafb.h"
#include <forte_string.h>
#include <forte_bool.h>
#include "anyadapter.h"

class FORTE_OpenSCADA_SERVER: public COpenSCADAFB{
  DECLARE_FIRMWARE_FB(FORTE_OpenSCADA_SERVER)

public:
  FORTE_OpenSCADA_SERVER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);

  virtual ~FORTE_OpenSCADA_SERVER();

  virtual bool writeDataPointDataRecieved(struct sfp_item * pa_pstItem, struct sfp_variant *pa_pstValue);

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &BaseAddress() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SAdapterInstanceDef scm_astAdapterInstances[];

  CAnyAdapter& ANY_ADAPTER() {
    return (*static_cast<CAnyAdapter*>(m_apoAdapters[0]));
  };
  static const int scm_nANY_ADAPTERAdpNum = 0;
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 2, 1, 1);

  void executeEvent(int pa_nEIID);

  void initialize();
  void updateDataPoints(int pa_nEIID);

};

#endif //close the ifdef sequence from the beginning of the file

