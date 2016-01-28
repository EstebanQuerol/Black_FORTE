/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ST_REC_CONN
 *** Description: Reconnects an event or data connection between two FB instances
 *** Version: 
 ***     1.0: 2014-05-05/Gerhard Ebenhofer, Matthias Plasch - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ST_REC_CONN_H_
#define _ST_REC_CONN_H_

#include <funcbloc.h>
#include <forte_wstring.h>
#include <forte_bool.h>
#include "core/resource.h"

class FORTE_ST_REC_CONN: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_ST_REC_CONN)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_WSTRING &OLD_SRC_FB() {
    return *static_cast<CIEC_WSTRING*>(getDI(1));
  };

  CIEC_WSTRING &OLD_SRC_FB_OUT() {
    return *static_cast<CIEC_WSTRING*>(getDI(2));
  };

  CIEC_WSTRING &OLD_DST_FB() {
    return *static_cast<CIEC_WSTRING*>(getDI(3));
  };

  CIEC_WSTRING &OLD_DST_FB_IN() {
    return *static_cast<CIEC_WSTRING*>(getDI(4));
  };

  CIEC_WSTRING &NEW_SRC_FB() {
    return *static_cast<CIEC_WSTRING*>(getDI(5));
  };

  CIEC_WSTRING &NEW_SRC_FB_OUT() {
    return *static_cast<CIEC_WSTRING*>(getDI(6));
  };

  CIEC_WSTRING &NEW_DST_FB() {
    return *static_cast<CIEC_WSTRING*>(getDI(7));
  };

  CIEC_WSTRING &NEW_DST_FB_IN() {
    return *static_cast<CIEC_WSTRING*>(getDI(8));
  };

  CIEC_WSTRING &DST() {
    return *static_cast<CIEC_WSTRING*>(getDI(9));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_WSTRING &STATUS() {
    return *static_cast<CIEC_WSTRING*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  //! The device the block is contained in
  CDevice &m_poDevice;
  
  FORTE_FB_DATA_ARRAY(1, 10, 2, 0);

  void executeEvent(int pa_nEIID);
  void executeRQST(void);

public:
  FUNCTION_BLOCK_CTOR(FORTE_ST_REC_CONN), m_poDevice(pa_poSrcRes->getDevice()){
  };

  virtual ~FORTE_ST_REC_CONN(){};

};

#endif //close the ifdef sequence from the beginning of the file

