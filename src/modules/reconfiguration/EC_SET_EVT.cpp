/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: EC_SET_EVT
 *** Description: Sets an event in- or output event of a FB instance (e.g. like an event sniffer)
 *** Version: 
 ***     1.0: 2014-05-05/Gerhard Ebenhofer, Matthias Plasch - 4DIAC-Consortium - null
 *************************************************************************/

#include "EC_SET_EVT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EC_SET_EVT_gen.cpp"
#endif
#include "DEV_MGR.h"
#include <mgmcmdstruct.h>
#include "core/device.h"

DEFINE_FIRMWARE_FB(FORTE_EC_SET_EVT, g_nStringIdEC_SET_EVT)

const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFB_NAME, g_nStringIdFB_EVENT_IO, g_nStringIdDST};

const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdWSTRING, g_nStringIdWSTRING};

const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};

const TForteInt16 FORTE_EC_SET_EVT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_EC_SET_EVT::scm_anEIWith[] = {0, 3, 1, 2, 255};
const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_EC_SET_EVT::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_EC_SET_EVT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_EC_SET_EVT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_EC_SET_EVT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_EC_SET_EVT::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
      QO() = QI();
      if(true == QI()){
        executeRQST();
      }else{
        STATUS() = "NOT Ready";
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

void FORTE_EC_SET_EVT::executeRQST(void){
  forte::core::SManagementCMD theCommand;
  theCommand.mDestination = CStringDictionary::getInstance().getId(DST().getValue());
  theCommand.mFirstParam.pushBack(CStringDictionary::getInstance().getId(FB_NAME().getValue()));
  theCommand.mFirstParam.pushBack(CStringDictionary::getInstance().getId(FB_EVENT_IO().getValue()));
  theCommand.mCMD = cg_nMGM_CMD_Monitoring_Trigger_Event;
  
  EMGMResponse resp =  m_poDevice.executeMGMCommand(theCommand);

  //calculate return value
  CIEC_STRING retVal(DEV_MGR::scm_sMGMResponseTexts[resp]);
  CIEC_STRING compareVal(DEV_MGR::scm_sMGMResponseTexts[e_RDY]);
  QO() = retVal == compareVal;

  DEVLOG_DEBUG("%s\n", DEV_MGR::scm_sMGMResponseTexts[resp]);
  STATUS() = (DEV_MGR::scm_sMGMResponseTexts[resp]);
}



