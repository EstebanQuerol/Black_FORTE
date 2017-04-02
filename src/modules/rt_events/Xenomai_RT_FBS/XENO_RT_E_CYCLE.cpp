/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: XENO_RT_E_CYCLE
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-03-19/EQUEROL - EQUEROL - 
 *************************************************************************/

#include "XENO_RT_E_CYCLE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "XENO_RT_E_CYCLE_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_XENO_RT_E_CYCLE, g_nStringIdXENO_RT_E_CYCLE)

const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdDT, g_nStringIdPolicy_EO1, g_nStringIdPriority_EO1};

const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_XENO_RT_E_CYCLE::scm_anEIWithIndexes[] = {0, 5, -1, -1};
const TDataIOID FORTE_XENO_RT_E_CYCLE::scm_anEIWith[] = {0, 2, 3, 1, 255, 2, 3, 255};
const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUpdate, g_nStringIdSTART, g_nStringIdSTOP};

const TDataIOID FORTE_XENO_RT_E_CYCLE::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_XENO_RT_E_CYCLE::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_XENO_RT_E_CYCLE::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO};

const SFBInterfaceSpec FORTE_XENO_RT_E_CYCLE::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

FORTE_XENO_RT_E_CYCLE::FORTE_XENO_RT_E_CYCLE(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
            CEventSourceFB( pa_poSrcRes, &scm_stFBInterfaceSpec,  pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){
  setEventChainExecutor(&m_oECEO);
  m_bActive = false;
  m_bInitialized = false;
  //Timeout value is correctly initialized by the constructor m_stTimeListEntry.m_nTimeOut = 0;
  m_stTimeListEntry.m_nInterval = 0;
  m_stTimeListEntry.m_pstNext = 0;
  m_stTimeListEntry.m_poTimedFB = this;
  m_stTimeListEntry.m_eType = e_Periodic;
}

void FORTE_XENO_RT_E_CYCLE::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
  	case cg_nExternalEventID:
  		sendOutputEvent(scm_nEventEOID);
  		break;
    case scm_nEventINITID:
		if(QI() == true){
			if(!m_bInitialized){
					m_oECEO.changeExecutionState(cg_nMGM_CMD_Start, Policy_EO1(), Priority_EO1());
					m_bInitialized = true;
				}
			}
		else{
			m_oECEO.changeExecutionState(cg_nMGM_CMD_Stop, 0, 0);
			m_bInitialized = false;
		}
		QO() = QI();
		sendOutputEvent(scm_nEventINITOID);
		break;
    case scm_nEventUpdateID:
    	if(m_bInitialized){
    		m_oECEO.changeThreadAttributes(Policy_EO1(), Priority_EO1());
    	}
		break;
    case scm_nEventSTARTID:
        if(m_bInitialized && !m_bActive){
          CTimerHandler::sm_poFORTETimer->registerTimedFB( &m_stTimeListEntry, DT());
          m_bActive = true;
        }
      break;
    case scm_nEventSTOPID:
        if(m_bActive){
          CTimerHandler::sm_poFORTETimer->unregisterTimedFB(this);
          m_bActive = false;
        }
      break;
  }
}



