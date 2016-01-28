/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ARTimeOut
 *** Description: Interface for a resetable time out service
 *** Version: 
 *************************************************************************/

#ifndef _ARTIMEOUT_H_
#define _ARTIMEOUT_H_

#include <adapter.h>
#include <typelib.h>
#include <forte_time.h>

class FORTE_ARTimeOut: public CAdapter{
  DECLARE_ADAPTER_TYPE(FORTE_ARTimeOut)

private:
 private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
 public:
  CIEC_TIME &DT() {
    return *static_cast<CIEC_TIME*>((isSocket()) ? getDO(0) : getDI(0));
  };

 public:
  static const TEventID scm_nEventTimeOutID = 0;
  int TimeOut() {
    return m_nParentAdapterListEventID + scm_nEventTimeOutID;
  }
 private:
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

 public:
  static const TEventID scm_nEventSTARTID = 0;
  int START() {
    return m_nParentAdapterListEventID + scm_nEventSTARTID;
  }
  static const TEventID scm_nEventSTOPID = 1;
  int STOP() {
    return m_nParentAdapterListEventID + scm_nEventSTOPID;
  }
 private:
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpecSocket;

  static const SFBInterfaceSpec scm_stFBInterfaceSpecPlug;

   FORTE_ADAPTER_DATA_ARRAY(1, 2, 0, 1, 0);

public:
  ADAPTER_CTOR(FORTE_ARTimeOut){
  };

  virtual ~FORTE_ARTimeOut(){};

};

#endif //close the ifdef sequence from the beginning of the file

