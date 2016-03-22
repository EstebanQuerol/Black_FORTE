/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_PWM
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-09-10/EQUEROL - UJI - 
 *************************************************************************/

#include "BBBio_PWM.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BBBio_PWM_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BBBio_PWM, g_nStringIdBBBio_PWM)

const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdDutyA, g_nStringIdDutyB, g_nStringIdFrequency};

const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_BBBio_PWM::scm_anEIWithIndexes[] = {0, 6, -1, -1};
const TDataIOID FORTE_BBBio_PWM::scm_anEIWith[] = {0, 1, 2, 4, 3, 255, 0, 2, 4, 3, 255};
const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdStart, g_nStringIdStop};

const TDataIOID FORTE_BBBio_PWM::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_BBBio_PWM::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BBBio_PWM::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BBBio_PWM::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_BBBio_PWM::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
	case scm_nEventINITID:
		if(QI() == true){
			int retVal = 0;
			if(this->joinBBBioLib() == 0){
				STATUS() = "OK";
				QO() = true;
				m_bIsInit = true;
				char * pacBuffer =  new char[PARAMS().length() + 3];
				PARAMS().toString(pacBuffer, sizeof(char)*(PARAMS().length() + 3));
				if (strncmp(pacBuffer, "\'EHRPWM0\'", 9) == 0) {
					retVal = BBBIO_PWMSS_Setting(BBBIO_PWMSS0, Frequency(), DutyA() , DutyB());
					m_nPWMID = BBBIO_PWMSS0;
				} else if (strncmp(pacBuffer, "\'EHRPWM1\'", 9) == 0) {
					retVal = BBBIO_PWMSS_Setting(BBBIO_PWMSS1, Frequency(), DutyA() , DutyB());
					m_nPWMID = BBBIO_PWMSS1;
				} else if (strncmp(pacBuffer, "\'EHRPWM2\'", 9) == 0) {
					retVal = BBBIO_PWMSS_Setting(BBBIO_PWMSS2, Frequency(), DutyA() , DutyB());
					m_nPWMID = BBBIO_PWMSS2;
				} else {
					DEVLOG_ERROR("Invalid input PARAM in BBBio_PWM FB\n");
					STATUS() = "Input PARAM error";
					m_bIsInit = false;
					leaveBBBioLib();
					QO() = false;
				}
				delete[] pacBuffer;
				if (retVal != 1){
					STATUS() = "PWM Initialization error";
					QO() = false;
					m_bIsInit = false;
				}
			}else{
				STATUS() = "BBBio Library initialization error";
				QO() = false;
				m_bIsInit = false;
			}
		}else{
			if(m_bIsInit == true){
				BBBIO_ehrPWM_Disable(m_nPWMID);
				leaveBBBioLib();
				m_bIsRunning = false;
				m_bIsInit = false;
			}
			STATUS() = "PWM disabled";
			QO() = QI();
		}
		sendOutputEvent(scm_nEventINITOID);
		break;
	case scm_nEventUpdateID:
		if (m_bIsInit){
			BBBIO_PWMSS_Setting(m_nPWMID, Frequency(), DutyA() , DutyB());
			if(m_bIsRunning){
				BBBIO_ehrPWM_Enable(m_nPWMID);
			}
			STATUS() = "OK";
			QO() = true;
		}else{
			STATUS() = "Not initialized";
			QO() = false;
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	case scm_nEventStartID:
		if(m_bIsInit){
			BBBIO_ehrPWM_Enable(m_nPWMID);
			m_bIsRunning = true;
			STATUS() = "PWM started";
			QO() = true;
		}else{
			STATUS() = "Not initialized";
			QO() = false;
		}

		sendOutputEvent(scm_nEventCNFID);
		break;
	case scm_nEventStopID:
		if(m_bIsInit){
			BBBIO_ehrPWM_Disable(m_nPWMID);
			m_bIsRunning = false;
			STATUS() = "PWM Stopped";
			QO() = true;
		}else{
			STATUS() = "Not initialized";
			QO() = false;
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	}
}



