/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_PWM
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-09-10/EQUEROL - UJI - 
 *************************************************************************/

#include "BL_PWM.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BL_PWM_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BL_PWM, g_nStringIdBL_PWM)

const CStringDictionary::TStringId FORTE_BL_PWM::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdDuty, g_nStringIdPeriod, g_nStringIdPolarity};

const CStringDictionary::TStringId FORTE_BL_PWM::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL, g_nStringIdTIME, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_BL_PWM::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_BL_PWM::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_BL_PWM::scm_anEIWithIndexes[] = {0, 6, -1, -1};
const TDataIOID FORTE_BL_PWM::scm_anEIWith[] = {0, 1, 2, 3, 4, 255, 0, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_BL_PWM::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdStart, g_nStringIdStop};

const TDataIOID FORTE_BL_PWM::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_BL_PWM::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BL_PWM::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BL_PWM::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_BL_PWM::executeEvent(int pa_nEIID){
	bool bRet = true;
	switch(pa_nEIID){
    case scm_nEventINITID:
    	if(m_poPWM != NULL){
    		m_poPWM->setRunState(BlackLib::stop);
    		delete m_poPWM;
    		m_poPWM = NULL;
    	}
    	if(QI() == true){
    		char * pacBuffer =  new char[PARAMS().length() + 3];
			PARAMS().toString(pacBuffer, sizeof(char)*(PARAMS().length() + 3));
			if (strncmp(pacBuffer, "\'EHRPWM2B\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM2B);
			} else if (strncmp(pacBuffer, "\'EHRPWM2A\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM2A);
			} else if (strncmp(pacBuffer, "\'EHRPWM1A\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM1A);
			} else if (strncmp(pacBuffer, "\'EHRPWM1B\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM1B);
			} else if (strncmp(pacBuffer, "\'EHRPWM0B\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM0B);
			} else if (strncmp(pacBuffer, "\'EHRPWM0A\'", 10) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::EHRPWM0A);
			} else if (strncmp(pacBuffer, "\'ECAP0\'", 7) == 0) {
				m_poPWM = new BlackLib::BlackPWM(BlackLib::ECAP0);
			} else {
				delete[] pacBuffer;
				DEVLOG_ERROR("Invalid input PARAM in BL_PWM FB\n");
				STATUS() = "Input PARAM error";
				QO() = false;
				sendOutputEvent(scm_nEventINITOID);
				break;
			}
            delete[] pacBuffer;
            bRet = m_poPWM->setDutyPercent(0.0);
			bRet = bRet && m_poPWM->setPeriodTime(Period().getInMicroSeconds(), BlackLib::microsecond);
			bRet = bRet && m_poPWM->setDutyPercent(Duty());
			if(Polarity() == true){
				bRet = bRet && m_poPWM->setPolarity(BlackLib::straight);
			}else{
				bRet = bRet && m_poPWM->setPolarity(BlackLib::reverse);
			}
			bRet = bRet && m_poPWM->setRunState(BlackLib::run);
			if(bRet == true){
				//PWM configuration OK
				STATUS() ="OK";
				QO() = true;
			}else{
				//PWM configuration Error
				DEVLOG_DEBUG("Invalid configuration parameters in BL_PWM FB\n");
				STATUS() ="Configuration Error";
				QO() = false;
			}
    	}else{
			STATUS() = "INIT- OK";
			QO() = false;
    	}
    	sendOutputEvent(scm_nEventINITOID);
    	break;
    case scm_nEventUpdateID:
    	if (m_poPWM == NULL){
    		//PWM must be initialized before updating configuration
    		DEVLOG_ERROR("Trying to update before initializing PWM\n");
    		STATUS() = "ERROR updating PWM";
    		QO()=false;
    	    sendOutputEvent(scm_nEventCNFID);
    	    break;
    	}
    	bRet = m_poPWM->setDutyPercent(0.0);
    	bRet = bRet && m_poPWM->setPeriodTime(Period().getInMicroSeconds(), BlackLib::microsecond);
    	bRet = bRet && m_poPWM->setDutyPercent(Duty());
    	if(Polarity() == true){
    		bRet = bRet && m_poPWM->setPolarity(BlackLib::straight);
    	}else{
    		bRet = bRet && m_poPWM->setPolarity(BlackLib::reverse);
    	}
    	if(bRet == true){
    		//PWM configuration OK
    		STATUS() ="OK";
    		QO() = true;
    	}else{
    		//PWM configuration Error
    		DEVLOG_DEBUG("Invalid configuration parameters in BL_PWM FB\n");
    		STATUS() ="Configuration Error";
    		QO() = false;
    	}
    	sendOutputEvent(scm_nEventCNFID);
    	break;
    case scm_nEventStartID:
    	if (m_poPWM != NULL && !m_poPWM->setRunState(BlackLib::run)){
    		//Could not start PWM
    		DEVLOG_ERROR("Unable to run PWM\n");
    		STATUS() = "ERROR running PWM";
    		QO()=false;
    	}
    	sendOutputEvent(scm_nEventCNFID);
    	break;
    case scm_nEventStopID:
    	if (m_poPWM != NULL && !m_poPWM->setRunState(BlackLib::stop)){
    		//Could not stop PWM
    		DEVLOG_ERROR("Unable to stop PWM\n");
    		STATUS() = "ERROR stopping PWM";
    		QO()=false;
    	}
    	sendOutputEvent(scm_nEventCNFID);
    	break;
  }
}



