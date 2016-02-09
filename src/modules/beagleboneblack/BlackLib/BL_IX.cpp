/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_IX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "BL_IX.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BL_IX_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BL_IX, g_nStringIdBL_IX)

const CStringDictionary::TStringId FORTE_BL_IX::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS};

const CStringDictionary::TStringId FORTE_BL_IX::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_BL_IX::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdIN};

const CStringDictionary::TStringId FORTE_BL_IX::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_BL_IX::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_BL_IX::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_BL_IX::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BL_IX::scm_anEOWith[] = {0, 1, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_BL_IX::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BL_IX::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BL_IX::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};
bool FORTE_BL_IX::verifyInput(const char * pa_acValue, int pa_nLenght){
	if (pa_nLenght < 8 || pa_nLenght  > 10){
		//Possible values must be >= 8 and <= 10
		return false;
	}
	if(strncmp(pa_acValue, "\'GPIO_", 6) != 0){
		//GPIO name must be in \'GPIO_X\' format
		return false;
	}
	//Get pin number from input string
	int nPinNumber = (int) strtol(&pa_acValue[6],NULL,10);
	switch (nPinNumber){
	case 2:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_2, BlackLib::input);
		break;
	case 3:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_3, BlackLib::input);
		break;
	case 4:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_4, BlackLib::input);
		break;
	case 5:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_5, BlackLib::input);
		break;
	case 7:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_7, BlackLib::input);
		break;
	case 8:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_8, BlackLib::input);
		break;
	case 9:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_9, BlackLib::input);
		break;
	case 14:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_14, BlackLib::input);
		break;
	case 71:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_71, BlackLib::input);
		break;
	case 70:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_70, BlackLib::input);
		break;
	case 73:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_73, BlackLib::input);
		break;
	case 72:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_72, BlackLib::input);
		break;
	case 75:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_75, BlackLib::input);
		break;
	case 74:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_74, BlackLib::input);
		break;
	case 77:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_77, BlackLib::input);
		break;
	case 76:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_76, BlackLib::input);
		break;
	case 79:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_79, BlackLib::input);
		break;
	case 78:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_78, BlackLib::input);
		break;
	case 80:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_80, BlackLib::input);
		break;
	case 81:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_81, BlackLib::input);
		break;
	case 11:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_11, BlackLib::input);
		break;
	case 10:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_10, BlackLib::input);
		break;
	case 89:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_89, BlackLib::input);
		break;
	case 87:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_87, BlackLib::input);
		break;
	case 88:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_88, BlackLib::input);
		break;
	case 86:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_86, BlackLib::input);
		break;
	case 61:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_61, BlackLib::input);
		break;
	case 32:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_32, BlackLib::input);
		break;
	case 33:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_33, BlackLib::input);
		break;
	case 36:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_36, BlackLib::input);
		break;
	case 37:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_37, BlackLib::input);
		break;
	case 62:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_62, BlackLib::input);
		break;
	case 63:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_63, BlackLib::input);
		break;
	case 22:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_22, BlackLib::input);
		break;
	case 65:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_65, BlackLib::input);
		break;
	case 27:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_27, BlackLib::input);
		break;
	case 46:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_46, BlackLib::input);
		break;
	case 47:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_47, BlackLib::input);
		break;
	case 26:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_26, BlackLib::input);
		break;
	case 23:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_23, BlackLib::input);
		break;
	case 44:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_44, BlackLib::input);
		break;
	case 45:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_45, BlackLib::input);
		break;
	case 68:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_68, BlackLib::input);
		break;
	case 69:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_69, BlackLib::input);
		break;
	case 67:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_67, BlackLib::input);
		break;
	case 66:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_66, BlackLib::input);
		break;
	case 35:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_35, BlackLib::input);
		break;
	case 34:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_34, BlackLib::input);
		break;
	case 39:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_39, BlackLib::input);
		break;
	case 40:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_40, BlackLib::input);
		break;
	case 31:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_31, BlackLib::input);
		break;
	case 60:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_60, BlackLib::input);
		break;
	case 30:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_30, BlackLib::input);
		break;
	case 38:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_38, BlackLib::input);
		break;
	case 20:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_20, BlackLib::input);
		break;
	case 51:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_51, BlackLib::input);
		break;
	case 48:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_48, BlackLib::input);
		break;
	case 15:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_15, BlackLib::input);
		break;
	case 49:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_49, BlackLib::input);
		break;
	case 117:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_117, BlackLib::input);
		break;
	case 120:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_120, BlackLib::input);
		break;
	case 121:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_121, BlackLib::input);
		break;
	case 122:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_122, BlackLib::input);
		break;
	case 123:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_123, BlackLib::input);
		break;
	case 125:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_125, BlackLib::input);
		break;
	default:
		//Invalid input parameter
		return false;
	}
	return true;
}
void FORTE_BL_IX::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	delete m_poGPIO;
    	m_poGPIO = NULL;
		if(QI() == true){
			char * pacBuffer =  new char[PARAMS().length() + 3];
			PARAMS().toString(pacBuffer, sizeof(char)*(PARAMS().length() + 3));
			if (verifyInput(pacBuffer, PARAMS().length() + 2)){
				STATUS() = "OK";
				QO() = true;
			}else{
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
		if(m_poGPIO != NULL){
			IN() = m_poGPIO->isHigh();
			STATUS() = "OK";
		}else{
			IN() = false;
			STATUS() = "Not initialized";
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
  }
}



