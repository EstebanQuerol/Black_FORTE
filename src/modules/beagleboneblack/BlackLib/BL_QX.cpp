/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_QX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-10-02/EQUEROL - UJI - 
 *************************************************************************/

#include "BL_QX.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BL_QX_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BL_QX, g_nStringIdBL_QX)

const CStringDictionary::TStringId FORTE_BL_QX::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_BL_QX::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_BL_QX::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_BL_QX::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_BL_QX::scm_anEIWithIndexes[] = {0, 3, -1};
const TDataIOID FORTE_BL_QX::scm_anEIWith[] = {0, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_BL_QX::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdToggle};

const TDataIOID FORTE_BL_QX::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_BL_QX::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BL_QX::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BL_QX::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

bool FORTE_BL_QX::verifyInput(const char * pa_acValue, int pa_nLenght){
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
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_2, BlackLib::output);
		break;
	case 3:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_3, BlackLib::output);
		break;
	case 4:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_4, BlackLib::output);
		break;
	case 5:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_5, BlackLib::output);
		break;
	case 7:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_7, BlackLib::output);
		break;
	case 8:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_8, BlackLib::output);
		break;
	case 9:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_9, BlackLib::output);
		break;
	case 14:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_14, BlackLib::output);
		break;
	case 71:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_71, BlackLib::output);
		break;
	case 70:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_70, BlackLib::output);
		break;
	case 73:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_73, BlackLib::output);
		break;
	case 72:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_72, BlackLib::output);
		break;
	case 75:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_75, BlackLib::output);
		break;
	case 74:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_74, BlackLib::output);
		break;
	case 77:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_77, BlackLib::output);
		break;
	case 76:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_76, BlackLib::output);
		break;
	case 79:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_79, BlackLib::output);
		break;
	case 78:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_78, BlackLib::output);
		break;
	case 80:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_80, BlackLib::output);
		break;
	case 81:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_81, BlackLib::output);
		break;
	case 11:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_11, BlackLib::output);
		break;
	case 10:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_10, BlackLib::output);
		break;
	case 89:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_89, BlackLib::output);
		break;
	case 87:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_87, BlackLib::output);
		break;
	case 88:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_88, BlackLib::output);
		break;
	case 86:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_86, BlackLib::output);
		break;
	case 61:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_61, BlackLib::output);
		break;
	case 32:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_32, BlackLib::output);
		break;
	case 33:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_33, BlackLib::output);
		break;
	case 36:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_36, BlackLib::output);
		break;
	case 37:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_37, BlackLib::output);
		break;
	case 62:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_62, BlackLib::output);
		break;
	case 63:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_63, BlackLib::output);
		break;
	case 22:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_22, BlackLib::output);
		break;
	case 65:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_65, BlackLib::output);
		break;
	case 27:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_27, BlackLib::output);
		break;
	case 46:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_46, BlackLib::output);
		break;
	case 47:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_47, BlackLib::output);
		break;
	case 26:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_26, BlackLib::output);
		break;
	case 23:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_23, BlackLib::output);
		break;
	case 44:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_44, BlackLib::output);
		break;
	case 45:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_45, BlackLib::output);
		break;
	case 68:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_68, BlackLib::output);
		break;
	case 69:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_69, BlackLib::output);
		break;
	case 67:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_67, BlackLib::output);
		break;
	case 66:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_66, BlackLib::output);
		break;
	case 35:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_35, BlackLib::output);
		break;
	case 34:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_34, BlackLib::output);
		break;
	case 39:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_39, BlackLib::output);
		break;
	case 40:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_40, BlackLib::output);
		break;
	case 31:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_31, BlackLib::output);
		break;
	case 60:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_60, BlackLib::output);
		break;
	case 30:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_30, BlackLib::output);
		break;
	case 38:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_38, BlackLib::output);
		break;
	case 20:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_20, BlackLib::output);
		break;
	case 51:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_51, BlackLib::output);
		break;
	case 48:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_48, BlackLib::output);
		break;
	case 15:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_15, BlackLib::output);
		break;
	case 49:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_49, BlackLib::output);
		break;
	case 117:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_117, BlackLib::output);
		break;
	case 120:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_120, BlackLib::output);
		break;
	case 121:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_121, BlackLib::output);
		break;
	case 122:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_122, BlackLib::output);
		break;
	case 123:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_123, BlackLib::output);
		break;
	case 125:
		m_poGPIO = new BlackLib::BlackGPIO(BlackLib::GPIO_125, BlackLib::output);
		break;
	default:
		//Invalid input parameter
		return false;
	}
	return true;
}

void FORTE_BL_QX::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	delete m_poGPIO;
		m_poGPIO = NULL;
		if(QI() == true){
			char * pacBuffer =  new char[PARAMS().length() + 3];
			PARAMS().toString(pacBuffer, PARAMS().length() + 3);
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
			if(OUT() == true){
				m_poGPIO->setValue(BlackLib::high);
			}else{
				m_poGPIO->setValue(BlackLib::low);
			}
			STATUS() = "OK";
		}else{
			STATUS() = "Not initialized";
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
    case scm_nEventToggleID:
		if(m_poGPIO != NULL){
			m_poGPIO->toggleValue();
			STATUS() = "OK";
		}else{
			STATUS() = "Not initialized";
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
  }
}



