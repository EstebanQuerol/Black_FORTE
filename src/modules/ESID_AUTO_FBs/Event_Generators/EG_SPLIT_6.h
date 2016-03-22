/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EG_SPLIT_6
 *** Description: Split an event
 *** Version: 
 ***     0.0: 2016-03-16/EQUEROL - ESID-UJI - 
 *************************************************************************/

#ifndef _EG_SPLIT_6_H_
#define _EG_SPLIT_6_H_

#include <basicfb.h>

class FORTE_EG_SPLIT_6: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_EG_SPLIT_6)

private:
  static const TEventID scm_nEventEIID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEO1ID = 0;
  static const TEventID scm_nEventEO2ID = 1;
  static const TEventID scm_nEventEO3ID = 2;
  static const TEventID scm_nEventEO4ID = 3;
  static const TEventID scm_nEventEO5ID = 4;
  static const TEventID scm_nEventEO6ID = 5;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(6, 0, 0, 0, 0);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateEO = 1;

  void enterStateSTART(void);
  void enterStateEO(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_EG_SPLIT_6(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_EG_SPLIT_6(){};

};

#endif //close the ifdef sequence from the beginning of the file

