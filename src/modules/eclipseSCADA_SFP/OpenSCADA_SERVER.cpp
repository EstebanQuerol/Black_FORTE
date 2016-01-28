/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: OpenSCADA_SERVER
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-07-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "OpenSCADA_SERVER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "OpenSCADA_SERVER_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_OpenSCADA_SERVER, g_nStringIdOpenSCADA_SERVER)

const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anDataInputNames[] = { g_nStringIdQI,
    g_nStringIdBaseAddress };

const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anDataInputTypeIds[] = {
    g_nStringIdBOOL, g_nStringIdSTRING };

const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anDataOutputNames[] =
    { g_nStringIdQO };

const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anDataOutputTypeIds[] = {
    g_nStringIdBOOL };

const TForteInt16 FORTE_OpenSCADA_SERVER::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_OpenSCADA_SERVER::scm_anEIWith[] = { 0, 1, 255 };
const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anEventInputNames[] = {
    g_nStringIdINIT };

const TDataIOID FORTE_OpenSCADA_SERVER::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_OpenSCADA_SERVER::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_OpenSCADA_SERVER::scm_anEventOutputNames[] = {
    g_nStringIdINITO };

const SAdapterInstanceDef FORTE_OpenSCADA_SERVER::scm_astAdapterInstances[] = {
    { g_nStringIdANY_ADAPTER, g_nStringIdANY_ADAPTER, true } };

const SFBInterfaceSpec FORTE_OpenSCADA_SERVER::scm_stFBInterfaceSpec = {
    1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
    1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 2, scm_anDataInputNames,
    scm_anDataInputTypeIds,
    1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
    1, scm_astAdapterInstances };

FORTE_OpenSCADA_SERVER::FORTE_OpenSCADA_SERVER(
    const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
        COpenSCADAFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){

}

FORTE_OpenSCADA_SERVER::~FORTE_OpenSCADA_SERVER(){
  unregisterDataPoints(ANY_ADAPTER().getNumDIs(), ANY_ADAPTER().getNumDOs());
}

bool FORTE_OpenSCADA_SERVER::writeDataPointDataRecieved(struct sfp_item * pa_pstItem,
    struct sfp_variant *pa_pstValue){
  bool bRetVal = false;
  for(unsigned int i = 0; i < ANY_ADAPTER().getNumDOs(); i++){
    if(m_ppstOutputItemList[i].m_pstItem == pa_pstItem){
      bRetVal =
          COpenSCADASFPServerHandler::getInstance().readBackDataPoint(pa_pstValue, ANY_ADAPTER().getDataOutputs()[i]);
      break;
    }
  }
  return bRetVal;
}

void FORTE_OpenSCADA_SERVER::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:
      QO() = QI();
      if(true == QI()){
        initialize();
      }
      else{
        unregisterDataPoints(ANY_ADAPTER().getNumDIs(), ANY_ADAPTER().getNumDOs());
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case cg_nExternalEventID:
      //TODO handle data reception
      break;
    default:
      //handle adapter events
      updateDataPoints(pa_nEIID);
      break;
  }
}

void FORTE_OpenSCADA_SERVER::initialize(){
  if((!m_bInitialized) && (0 != ANY_ADAPTER().getPeer())){
    m_bInitialized =
        registerDataPoints(BaseAddress(), ANY_ADAPTER().getNumDIs(), ANY_ADAPTER().getDataInputNames(), ANY_ADAPTER().getDataInputs(),
            ANY_ADAPTER().getNumDOs(), ANY_ADAPTER().getDataOutputNames(), ANY_ADAPTER().getDataOutputs());
  }
}

void FORTE_OpenSCADA_SERVER::updateDataPoints(int pa_nEIID){
  pa_nEIID &= 0xFF;

  if((pa_nEIID & 0xFF) < ANY_ADAPTER().getNumEIs()){
    if(0 != ANY_ADAPTER().getEIWithIndexes()){
      if(-1 != ANY_ADAPTER().getEIWithIndexes()[pa_nEIID]){
        const TDataIOID *poEIWithStart =
            &(ANY_ADAPTER().getEIWiths()[ANY_ADAPTER().getEIWithIndexes()[pa_nEIID]]);

        for(int i = 0; poEIWithStart[i] != 255; ++i){
          COpenSCADASFPServerHandler::updateDataPoint(m_ppstInputItemList[i], ANY_ADAPTER().getDataInputs()[i]);
        }
      }
    }
  }
}
