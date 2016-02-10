/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: UINT_DEMUX_N
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-11-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _UINT_DEMUX_N_H_
#define _UINT_DEMUX_N_H_

#include <basicfb.h>
#include <forte_uint.h>

class FORTE_UINT_DEMUX_N: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_UINT_DEMUX_N)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &UINT1() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  CIEC_UINT &UINT2() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_UINT &UINT3() {
    return *static_cast<CIEC_UINT*>(getDI(2));
  };

  CIEC_UINT &UINT4() {
    return *static_cast<CIEC_UINT*>(getDI(3));
  };

  CIEC_UINT &UINT5() {
    return *static_cast<CIEC_UINT*>(getDI(4));
  };

  CIEC_UINT &UINT6() {
    return *static_cast<CIEC_UINT*>(getDI(5));
  };

  CIEC_UINT &UINT7() {
    return *static_cast<CIEC_UINT*>(getDI(6));
  };

  CIEC_UINT &UINT8() {
    return *static_cast<CIEC_UINT*>(getDI(7));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &OUT() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  static const TEventID scm_nEventE1ID = 0;
  static const TEventID scm_nEventE2ID = 1;
  static const TEventID scm_nEventE3ID = 2;
  static const TEventID scm_nEventE4ID = 3;
  static const TEventID scm_nEventE5ID = 4;
  static const TEventID scm_nEventE6ID = 5;
  static const TEventID scm_nEventE7ID = 6;
  static const TEventID scm_nEventE8ID = 7;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 8, 1, 0, 0);
  void alg_Puint1(void);
  void alg_Puint2(void);
  void alg_Puint3(void);
  void alg_Puint4(void);
  void alg_Puint5(void);
  void alg_Puint6(void);
  void alg_Puint7(void);
  void alg_Puint8(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateP_UINT3 = 1;
  static const TForteInt16 scm_nStateP_UINT1 = 2;
  static const TForteInt16 scm_nStateP_UINT2 = 3;
  static const TForteInt16 scm_nStateP_UINT4 = 4;
  static const TForteInt16 scm_nStateP_UINT5 = 5;
  static const TForteInt16 scm_nStateP_UINT6 = 6;
  static const TForteInt16 scm_nStateP_UINT7 = 7;
  static const TForteInt16 scm_nStateP_UINT8 = 8;

  void enterStateSTART(void);
  void enterStateP_UINT3(void);
  void enterStateP_UINT1(void);
  void enterStateP_UINT2(void);
  void enterStateP_UINT4(void);
  void enterStateP_UINT5(void);
  void enterStateP_UINT6(void);
  void enterStateP_UINT7(void);
  void enterStateP_UINT8(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_UINT_DEMUX_N(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_UINT_DEMUX_N(){};

};

#endif //close the ifdef sequence from the beginning of the file

