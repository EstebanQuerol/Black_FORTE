/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_SPLIT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-03-18/EQUEROL - EQUEROL - 
 *************************************************************************/

#include "XENO_RT_E_SPLIT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "XENO_RT_E_SPLIT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_XENO_RT_E_SPLIT, g_nStringIdXENO_RT_E_SPLIT)

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPolicy_EO1, g_nStringIdPriority_EO1, g_nStringIdPolicy_EO2, g_nStringIdPriority_EO2};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_XENO_RT_E_SPLIT::scm_anEIWithIndexes[] = {0, 6, -1};
const TDataIOID FORTE_XENO_RT_E_SPLIT::scm_anEIWith[] = {0, 1, 2, 4, 3, 255, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdEI};

const TDataIOID FORTE_XENO_RT_E_SPLIT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_XENO_RT_E_SPLIT::scm_anEOWithIndexes[] = {0, -1, -1, -1};
const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO1, g_nStringIdEO2};

const SFBInterfaceSpec FORTE_XENO_RT_E_SPLIT::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_XENO_RT_E_SPLIT::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
	case scm_nEventINITID:
		if(QI() == true){
			if(!m_bInitialized){
				m_oECEO1.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO1(), Priority_EO1());
				m_oECEO2.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO2(), Priority_EO2());
				m_bInitialized = true;
			}
		}
		else{
			m_oECEO1.changeExecutionState(cg_nMGM_CMD_Stop, 0 ,0);
			m_oECEO2.changeExecutionState(cg_nMGM_CMD_Stop, 0, 0);
			m_bInitialized = false;
		}
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
	case scm_nEventEIID:
		if(m_bInitialized){
			CEventConnection *eoCon;
			eoCon = getEOConUnchecked(scm_nEventEO1ID);
			if(eoCon->isConnected()){
				eoCon->triggerEvent(m_oECEO1);
				m_oECEO1.resumeSelfSuspend();
			}
			eoCon = getEOConUnchecked(scm_nEventEO2ID);
			if(eoCon->isConnected()){
				eoCon->triggerEvent(m_oECEO2);
				m_oECEO2.resumeSelfSuspend();
			}
		}
		break;
	case scm_nEventUpdateID:
		if(m_bInitialized){
			m_oECEO1.changeThreadAttributes(Policy_EO1(), Priority_EO1());
			m_oECEO2.changeThreadAttributes(Policy_EO2(), Priority_EO2());
		}
      break;
  }
}



