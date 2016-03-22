/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: RT_E_SPLIT_6
 *** Description: Split an event to two event chain branches
 *** Version: 
 ***     0.0: 2016-15-03/EQUEROL - UJI-ESDID - 
 *************************************************************************/

#include "RT_E_SPLIT_6.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RT_E_SPLIT_6_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_RT_E_SPLIT_6, g_nStringIdRT_E_SPLIT_6)

const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdTmin, g_nStringIdDeadline_EO1, g_nStringIdWCET_EO1, g_nStringIdDeadline_EO2, g_nStringIdWCET_EO2, g_nStringIdDeadline_EO3, g_nStringIdWCET_EO3, g_nStringIdDeadline_EO4, g_nStringIdWCET_EO4, g_nStringIdDeadline_EO5, g_nStringIdWCET_EO5, g_nStringIdDeadline_EO6, g_nStringIdWCET_EO6};

const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME, g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_RT_E_SPLIT_6::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_RT_E_SPLIT_6::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 255};
const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdEI};

const TDataIOID FORTE_RT_E_SPLIT_6::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_RT_E_SPLIT_6::scm_anEOWithIndexes[] = {0, -1, -1, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_RT_E_SPLIT_6::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdEO1, g_nStringIdEO2, g_nStringIdEO3, g_nStringIdEO4, g_nStringIdEO5, g_nStringIdEO6};

const SFBInterfaceSpec FORTE_RT_E_SPLIT_6::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  7,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  14,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_RT_E_SPLIT_6::executeEvent(int pa_nEIID){
  if(scm_nEventEIID == pa_nEIID){
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
		eoCon = getEOConUnchecked(scm_nEventEO5ID);
		if(eoCon->isConnected()){
		  eoCon->triggerEvent(m_oECEO5);
		  m_oECEO5.resumeSelfSuspend();
		}
		eoCon = getEOConUnchecked(scm_nEventEO6ID);
		if(eoCon->isConnected()){
		  eoCon->triggerEvent(m_oECEO6);
		  m_oECEO6.resumeSelfSuspend();
		}
    }
  }
  else
    if(scm_nEventINITID == pa_nEIID){
      if(QI() == true){
        if(!m_bInitialized){
          m_oECEO1.changeExecutionState(cg_nMGM_CMD_Start);
          m_oECEO2.changeExecutionState(cg_nMGM_CMD_Start);
          m_oECEO3.changeExecutionState(cg_nMGM_CMD_Start);
          m_oECEO4.changeExecutionState(cg_nMGM_CMD_Start);
          m_oECEO5.changeExecutionState(cg_nMGM_CMD_Start);
          m_oECEO6.changeExecutionState(cg_nMGM_CMD_Start);
          m_bInitialized = true;
        }
        m_oECEO1.setDeadline(Deadline_EO1());
        m_oECEO2.setDeadline(Deadline_EO2());
        m_oECEO3.setDeadline(Deadline_EO2());
        m_oECEO4.setDeadline(Deadline_EO1());
        m_oECEO5.setDeadline(Deadline_EO2());
        m_oECEO6.setDeadline(Deadline_EO2());
      }
      else{
        m_oECEO1.changeExecutionState(cg_nMGM_CMD_Stop);
        m_oECEO2.changeExecutionState(cg_nMGM_CMD_Stop);
        m_oECEO3.changeExecutionState(cg_nMGM_CMD_Stop);
        m_oECEO4.changeExecutionState(cg_nMGM_CMD_Stop);
        m_oECEO5.changeExecutionState(cg_nMGM_CMD_Stop);
        m_oECEO6.changeExecutionState(cg_nMGM_CMD_Stop);
        m_bInitialized = false;
      }
      QO() = QI();
      sendOutputEvent(scm_nEventINITOID);
    }
}


