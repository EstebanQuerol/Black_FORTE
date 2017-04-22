/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_QX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-04-07/EQUEROL - EQUEROL - 
 *************************************************************************/

#include "BBBio_QX.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BBBio_QX_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BBBio_QX, g_nStringIdBBBio_QX)

const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPORT, g_nStringIdPIN, g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_BBBio_QX::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_BBBio_QX::scm_anEIWith[] = {0, 1, 2, 255, 3, 255};
const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BBBio_QX::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_BBBio_QX::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BBBio_QX::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BBBio_QX::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_BBBio_QX::executeEvent(int pa_nEIID){
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
			if(OUT()){
				pin_high((char)PORT(), (char)PIN());
			}else{
				pin_low((char)PORT(), (char)PIN());
			}
		}else{
			STATUS() = "IO Pin not initialized";
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	}
}



