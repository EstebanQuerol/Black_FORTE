/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_CLOCK
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2016-01-15/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SI_CLOCK.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_CLOCK_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_SI_CLOCK, g_nStringIdSI_CLOCK)

const CStringDictionary::TStringId FORTE_SI_CLOCK::scm_anDataOutputNames[] = {g_nStringIdTIME1, g_nStringIdSTRING1};

const CStringDictionary::TStringId FORTE_SI_CLOCK::scm_anDataOutputTypeIds[] = {g_nStringIdTIME, g_nStringIdSTRING};

const TForteInt16 FORTE_SI_CLOCK::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_SI_CLOCK::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_SI_CLOCK::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_SI_CLOCK::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_SI_CLOCK::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SI_CLOCK::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SI_CLOCK::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:

        TIME1().setFromMiliSeconds(clock()*1000/CLOCKS_PER_SEC);
        //isstream
        stringstream tempss;

    	if (CTimerHandler::sm_poFORTETimer != 0){
    		tempss << ": T#" + CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
    		tempss << CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue;
    		tempss << "ms" << "	";
    			//fprintf(stderr, ": T#%ld%ldms: ", CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue, CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
    		}

        string timeprint(tempss.str());
      /*  timeprint = ": TO#" + (string)CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
        timeprint.append("" + (string)CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
        timeprint.append("ms");*/
       // timeprint = timeprint + "ms";
        //timepri
        //timeprint << CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue; << "ms" << "	";
//        string sub1("T#");
//        string sub2( CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue);
//        string sub3( CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
//        string sub4 ("ms	");
//        timeprint = sub1 +sub2 +sub3 + "ms	";
        STRING1()=tempss.str().c_str();
        sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



