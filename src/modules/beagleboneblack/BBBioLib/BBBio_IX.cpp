/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_IX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-04-07/EQUEROL - EQUEROL - 
 *************************************************************************/

#include "BBBio_IX.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BBBio_IX_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BBBio_IX, g_nStringIdBBBio_IX)

const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPORT, g_nStringIdPIN};

const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdIN};

const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_BBBio_IX::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_BBBio_IX::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BBBio_IX::scm_anEOWith[] = {0, 1, 255, 2, 1, 255};
const TForteInt16 FORTE_BBBio_IX::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BBBio_IX::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdIND};

const SFBInterfaceSpec FORTE_BBBio_IX::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_BBBio_IX::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
	case scm_nEventINITID:
		if(QI() == true){
			if(joinBBBioLib() == 0){
				if (0 == BBBIO_sys_Enable_GPIO_PIN(PORT(), PIN())){
					if (0 == iolib_setdir(PORT(),PIN(),1)){
						STATUS() = "OK";
						QO() = true;
						m_bIsInit = true;
					}else{
						STATUS() = "GPIO configuration error";
						QO() = false;
						m_bIsInit = false;
						leaveBBBioLib();
					}
				}else{
					STATUS() = "GPIO configuration error";
					QO() = false;
					m_bIsInit = false;
					leaveBBBioLib();
				}
			}else{
				STATUS() = "BBBio Library initialization error";
				QO() = false;
				m_bIsInit = false;
			}
		}else{
			if(m_bIsInit == true){
				leaveBBBioLib();
			}
			STATUS() = "GPIO disabled";
			QO() = QI();
		}
		sendOutputEvent(scm_nEventINITOID);
		break;
	case scm_nEventREQID:
		if(m_bIsInit){
			IN() = (bool)is_high(PORT(),PIN());
		}else{
			STATUS() = "IO Pin not initialized";
		}
		sendOutputEvent(scm_nEventINDID);
		break;
	}
}



