/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_AIn
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-09-09/EQUEROL - UJI - 
 *************************************************************************/

#include "BL_AIn.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BL_AIn_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BL_AIn, g_nStringIdBL_AIn)

const CStringDictionary::TStringId FORTE_BL_AIn::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS};

const CStringDictionary::TStringId FORTE_BL_AIn::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_BL_AIn::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdRD};

const CStringDictionary::TStringId FORTE_BL_AIn::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdREAL};

const TForteInt16 FORTE_BL_AIn::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_BL_AIn::scm_anEIWith[] = {0, 1, 255, 0, 255};
const CStringDictionary::TStringId FORTE_BL_AIn::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BL_AIn::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_BL_AIn::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BL_AIn::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BL_AIn::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_BL_AIn::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	delete m_poADC;
    	m_poADC = NULL;
    	if(QI() == true){
			STATUS() = "OK";
			QO() = true;
        	char * pacBuffer =  new char[PARAMS().length() + 3];
			PARAMS().toString(pacBuffer, sizeof(char)*(PARAMS().length() + 3));
			if (strncmp(pacBuffer, "\'AIN0\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN0);
			} else if (strncmp(pacBuffer, "\'AIN1\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN1);
			} else if (strncmp(pacBuffer, "\'AIN2\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN2);
			} else if (strncmp(pacBuffer, "\'AIN3\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN3);
			} else if (strncmp(pacBuffer, "\'AIN4\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN4);
			} else if (strncmp(pacBuffer, "\'AIN5\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN5);
			} else if (strncmp(pacBuffer, "\'AIN6\'", 6) == 0) {
				m_poADC = new BlackLib::BlackADC(BlackLib::AIN6);
			} else {
				DEVLOG_ERROR("Invalid input PARAM in BL_AIn FB\n");
				STATUS() = "Input PARAM error";
				QO() = false;
			}
			delete[] pacBuffer;
		}else{
			STATUS() = "INIT- OK";
			QO() = false;
		}
    	sendOutputEvent(scm_nEventINITOID);
    	break;
    case scm_nEventREQID:
    	if (m_poADC != NULL){
        	RD() = m_poADC->getConvertedValue(BlackLib::dap3);
    		STATUS() = "OK";
        	if(RD() == BlackLib::FILE_COULD_NOT_OPEN_FLOAT){
            	RD() = 0.0;
            	STATUS() = "Read error";
        	}
    	}else{
			RD() = 0.0;
			STATUS() = "Not initialized";
		}
    	sendOutputEvent(scm_nEventCNFID);
    	break;
  }
}



