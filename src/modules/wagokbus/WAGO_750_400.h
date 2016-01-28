/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WAGO_750_400
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-09-11/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _WAGO_750_400_H_
#define _WAGO_750_400_H_

#include "kbusfb.h"
#include <forte_usint.h>
#include <forte_bool.h>

class FORTE_WAGO_750_400 : public CKBusFB{
  DECLARE_FIRMWARE_FB(FORTE_WAGO_750_400)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_USINT &SLOT(){
      return *static_cast<CIEC_USINT*>(getDI(1));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_BOOL &IN1(){
      return *static_cast<CIEC_BOOL*>(getDO(1));
    }
    ;

    CIEC_BOOL &IN2(){
      return *static_cast<CIEC_BOOL*>(getDO(2));
    }
    ;

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

    FORTE_FB_DATA_ARRAY(3, 2, 3, 0)
    ;

  public:
    FUNCTION_BLOCK_CTOR_WITH_BASE_CLASS(FORTE_WAGO_750_400, CKBusFB){
    };

    virtual ~FORTE_WAGO_750_400(){};

  protected:
    virtual void applyKBusInputData();
    virtual void udpateKBusOutputData();
    virtual bool checkTerminalId(u16 pa_unTerminalId);

};

#endif //close the ifdef sequence from the beginning of the file
