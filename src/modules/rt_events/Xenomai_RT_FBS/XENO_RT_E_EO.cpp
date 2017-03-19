/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_EO
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-03-18/EQUEROL - EQUEROL - 
 *************************************************************************/

#include "XENO_RT_E_EO.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "XENO_RT_E_EO_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_XENO_RT_E_EO, g_nStringIdXENO_RT_E_EO)

const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPolicy_EO1, g_nStringIdPriority_EO1};

const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_XENO_RT_E_EO::scm_anEIWithIndexes[] = {0, 4, -1};
const TDataIOID FORTE_XENO_RT_E_EO::scm_anEIWith[] = {0, 1, 2, 255, 2, 1, 255};
const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdEI};

const TDataIOID FORTE_XENO_RT_E_EO::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_XENO_RT_E_EO::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_XENO_RT_E_EO::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO};

const SFBInterfaceSpec FORTE_XENO_RT_E_EO::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_XENO_RT_E_EO::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
	case scm_nEventINITID:
		if(QI() == true){
			if(!m_bInitialized){
				m_oECEO1.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO1(), Priority_EO1());
				m_bInitialized = true;
			}
		}
		else{
			m_oECEO1.changeExecutionState(cg_nMGM_CMD_Stop, 0, 0);
			m_bInitialized = false;
		}
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
	case scm_nEventUpdateID:
		m_oECEO1.changeThreadAttributes(Policy_EO1(), Priority_EO1());
		break;
	case scm_nEventEIID:
		if(m_bInitialized){
			CEventConnection *eoCon;
			eoCon = getEOConUnchecked(scm_nEventEOID);
			if(eoCon->isConnected()){
				eoCon->triggerEvent(m_oECEO1);
				m_oECEO1.resumeSelfSuspend();
			}
		}
		break;
	}
}



