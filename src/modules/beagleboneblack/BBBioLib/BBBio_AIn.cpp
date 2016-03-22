/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_AIn
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-09-09/EQUEROL - UJI - 
 *************************************************************************/

#include "BBBio_AIn.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BBBio_AIn_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BBBio_AIn, g_nStringIdBBBio_AIn)

const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS};

const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL};

const TForteInt16 FORTE_BBBio_AIn::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_BBBio_AIn::scm_anEIWith[] = {0, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BBBio_AIn::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_BBBio_AIn::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BBBio_AIn::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BBBio_AIn::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_BBBio_AIn::configADC(unsigned int pa_nChnID){
	const int clk_div = 1;
	const int open_dly = 0;
	const int sample_dly = 1;
	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_BUSY_POLLING, clk_div);
	BBBIO_ADCTSC_channel_ctrl(pa_nChnID, BBBIO_ADC_STEP_MODE_SW_ONE_SHOOT, open_dly, sample_dly, \
					BBBIO_ADC_STEP_AVG_1, m_nADCBuffer, scm_nADCBufferSize);
	m_nADCID = pa_nChnID;
}

void FORTE_BBBio_AIn::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	if(QI() == true){
    		if(this->joinBBBioLib() == 0){
    			STATUS() = "OK";
    			QO() = true;
    			char * pacBuffer =  new char[PARAMS().length() + 3];
				PARAMS().toString(pacBuffer, sizeof(char)*(PARAMS().length() + 3));
				if (strncmp(pacBuffer, "\'AIN0\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN0);
				} else if (strncmp(pacBuffer, "\'AIN1\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN1);
				} else if (strncmp(pacBuffer, "\'AIN2\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN2);
				} else if (strncmp(pacBuffer, "\'AIN3\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN3);
				} else if (strncmp(pacBuffer, "\'AIN4\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN4);
				} else if (strncmp(pacBuffer, "\'AIN5\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN5);
				} else if (strncmp(pacBuffer, "\'AIN6\'", 6) == 0) {
					configADC(BBBIO_ADC_AIN6);
				} else {
					DEVLOG_ERROR("Invalid input PARAM in BBBio_AIn FB\n");
					STATUS() = "Input PARAM error";
					leaveBBBioLib();
					QO() = false;
				}
				delete[] pacBuffer;
    		}else{
				QO() = false;
			}
    	}else{
    		leaveBBBioLib();
    		m_nADCID = 9;
    		QO() = QI();
    	}
		sendOutputEvent(scm_nEventINITOID);
		break;
    case scm_nEventREQID:
    	if(m_nADCID <= BBBIO_ADC_AIN6 && m_nADCID >= BBBIO_ADC_AIN0){
        	BBBIO_ADCTSC_one_shoot_read(m_nADCID);
        	RD() = ((float)m_nADCBuffer[0] / 4095.0f) * 1.8f;
        	STATUS() = "OK";
        	QO() = true;
    	}else{
    		STATUS() = "Not initialized";
    		QO() = false;
    	}
    	sendOutputEvent(scm_nEventCNFID);
    	break;
  }
}



