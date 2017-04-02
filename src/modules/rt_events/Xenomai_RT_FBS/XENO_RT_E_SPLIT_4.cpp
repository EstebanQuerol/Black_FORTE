/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_SPLIT_4
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-04-01/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "XENO_RT_E_SPLIT_4.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "XENO_RT_E_SPLIT_4_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_XENO_RT_E_SPLIT_4, g_nStringIdXENO_RT_E_SPLIT_4)

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPolicy_EO1, g_nStringIdPriority_EO1, g_nStringIdPolicy_EO2, g_nStringIdPriority_EO2, g_nStringIdPolicy_EO3, g_nStringIdPriority_EO3, g_nStringIdPolicy_EO4, g_nStringIdPriority_EO4};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_XENO_RT_E_SPLIT_4::scm_anEIWithIndexes[] = {0, 10, -1};
const TDataIOID FORTE_XENO_RT_E_SPLIT_4::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 255, 2, 1, 3, 4, 5, 6, 7, 8, 255};
const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdEI};

const TDataIOID FORTE_XENO_RT_E_SPLIT_4::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_XENO_RT_E_SPLIT_4::scm_anEOWithIndexes[] = {0, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_XENO_RT_E_SPLIT_4::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO1, g_nStringIdEO2, g_nStringIdEO3, g_nStringIdEO4};

const SFBInterfaceSpec FORTE_XENO_RT_E_SPLIT_4::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  9,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_XENO_RT_E_SPLIT_4::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		if(QI() == true){
			if(!m_bInitialized){
				m_oECEO1.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO1(), Priority_EO1());
				m_oECEO2.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO2(), Priority_EO2());
				m_oECEO3.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO3(), Priority_EO3());
				m_oECEO4.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO4(), Priority_EO4());
				m_bInitialized = true;
			}
		}
		else{
			m_oECEO1.changeExecutionState(cg_nMGM_CMD_Stop, 0 ,0);
			m_oECEO2.changeExecutionState(cg_nMGM_CMD_Stop, 0, 0);
			m_oECEO3.changeExecutionState(cg_nMGM_CMD_Stop, 0 ,0);
			m_oECEO4.changeExecutionState(cg_nMGM_CMD_Stop, 0, 0);
			m_bInitialized = false;
		}
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventUpdateID:
		if(m_bInitialized){
			m_oECEO1.changeThreadAttributes(Policy_EO1(), Priority_EO1());
			m_oECEO2.changeThreadAttributes(Policy_EO2(), Priority_EO2());
			m_oECEO3.changeThreadAttributes(Policy_EO3(), Priority_EO3());
			m_oECEO4.changeThreadAttributes(Policy_EO4(), Priority_EO4());
		}
		
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
			eoCon = getEOConUnchecked(scm_nEventEO3ID);
			if(eoCon->isConnected()){
				eoCon->triggerEvent(m_oECEO3);
				m_oECEO3.resumeSelfSuspend();
			}
			eoCon = getEOConUnchecked(scm_nEventEO4ID);
			if(eoCon->isConnected()){
				eoCon->triggerEvent(m_oECEO4);
				m_oECEO4.resumeSelfSuspend();
			}
		}
    break;
  }
}



