/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EC_STOP_ELEM
 *** Description: Stops the instance of a FB, Connection (Event/Data), Resource or Device according as the state machine of IEC 61499 FBs
 *** Version: 
 ***     1.0: 2014-05-05/Gerhard Ebenhofer, Matthias Plasch - 4DIAC-Consortium - null
 *************************************************************************/

#include "EC_STOP_ELEM.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EC_STOP_ELEM_gen.cpp"
#endif
#include "DEV_MGR.h"
#include "core/device.h"

DEFINE_FIRMWARE_FB(FORTE_EC_STOP_ELEM, g_nStringIdEC_STOP_ELEM)

const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdELEM_NAME, g_nStringIdDST};

const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING};

const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};

const TForteInt16 FORTE_EC_STOP_ELEM::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_EC_STOP_ELEM::scm_anEIWith[] = {1, 2, 0, 255};
const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_EC_STOP_ELEM::scm_anEOWith[] = {1, 0, 255};
const TForteInt16 FORTE_EC_STOP_ELEM::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_EC_STOP_ELEM::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_EC_STOP_ELEM::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_EC_STOP_ELEM::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      QO() = QI();
      if(true == QI()) {
        executeRQST();
      } else {
		  STATUS() = "Not Ready";
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}


void FORTE_EC_STOP_ELEM::executeRQST(void){
  forte::core::SManagementCMD theCommand;
  
  theCommand.mDestination = CStringDictionary::getInstance().getId(DST().getValue());
  theCommand.mFirstParam.pushBack(CStringDictionary::getInstance().getId(ELEM_NAME().getValue()));
  theCommand.mCMD = cg_nMGM_CMD_Stop;
  
  EMGMResponse resp = m_poDevice.executeMGMCommand(theCommand);

  //calculate return value
  CIEC_STRING retVal(DEV_MGR::scm_sMGMResponseTexts[resp]);
  CIEC_STRING compareVal(DEV_MGR::scm_sMGMResponseTexts[e_RDY]);
  QO() = retVal == compareVal;

  DEVLOG_DEBUG("%s\n", DEV_MGR::scm_sMGMResponseTexts[resp]);
  STATUS() = (DEV_MGR::scm_sMGMResponseTexts[resp]);
}
