/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: OpenSCADATestFB
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2013-07-06/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "OpenSCADATestFB.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "OpenSCADATestFB_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_OpenSCADATestFB, g_nStringIdOpenSCADATestFB)

const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anDataInputNames[] = { g_nStringIdQI,
    g_nStringIdBaseAddress, g_nStringIdTestBool, g_nStringIdTestINT, g_nStringIdTestString };

const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anDataInputTypeIds[] = {
    g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdSTRING };

const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anDataOutputNames[] = { g_nStringIdQO,
    g_nStringIdRD_INT, g_nStringIdRD_DINT, g_nStringIdRD_String };

const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anDataOutputTypeIds[] = {
    g_nStringIdBOOL, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdSTRING };

const TForteInt16 FORTE_OpenSCADATestFB::scm_anEIWithIndexes[] = { 0, 3 };
const TDataIOID FORTE_OpenSCADATestFB::scm_anEIWith[] = { 0, 1, 255, 0, 2, 3, 4, 255 };
const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anEventInputNames[] = {
    g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_OpenSCADATestFB::scm_anEOWith[] = { 0, 255, 0, 255, 0, 1, 2, 3, 255 };
const TForteInt16 FORTE_OpenSCADATestFB::scm_anEOWithIndexes[] = { 0, 2, 4, -1 };
const CStringDictionary::TStringId FORTE_OpenSCADATestFB::scm_anEventOutputNames[] = {
    g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND };

const SFBInterfaceSpec FORTE_OpenSCADATestFB::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames,
    scm_anEIWith, scm_anEIWithIndexes, 3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
    5, scm_anDataInputNames, scm_anDataInputTypeIds, 4, scm_anDataOutputNames,
    scm_anDataOutputTypeIds, 0, 0 };

FORTE_OpenSCADATestFB::FORTE_OpenSCADATestFB(const CStringDictionary::TStringId pa_nInstanceNameId,
    CResource *pa_poSrcRes) :
        COpenSCADAFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){

}

FORTE_OpenSCADATestFB::~FORTE_OpenSCADATestFB(){
  unregisterDataPoints(scm_stFBInterfaceSpec.m_nNumDIs, scm_stFBInterfaceSpec.m_nNumDOs);
}

void FORTE_OpenSCADATestFB::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:
      QO() = QI();
      if(true == QI()){
        initialize();
      }
      else{
        unregisterDataPoints(scm_stFBInterfaceSpec.m_nNumDIs, scm_stFBInterfaceSpec.m_nNumDOs);
      }
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      QO() = QI();
      updateSCADAData();
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

void FORTE_OpenSCADATestFB::initialize(){
  if(!m_bInitialized){
    m_bInitialized =
        registerDataPoints(BaseAddress(), scm_stFBInterfaceSpec.m_nNumDIs, scm_anDataInputNames, getDI(0),
            scm_stFBInterfaceSpec.m_nNumDOs, scm_anDataOutputNames, getDI(0));
  }
}

void FORTE_OpenSCADATestFB::updateSCADAData(){
  if(m_bInitialized){
    if(0 != m_ppstInputItemList){
      COpenSCADASFPServerHandler::getInstance().updateDataPoints(m_ppstInputItemList, getDI(0), scm_stFBInterfaceSpec.m_nNumDIs);
    }
  }
}

bool FORTE_OpenSCADATestFB::writeDataPointDataRecieved(struct sfp_item * pa_pstItem,
    struct sfp_variant *pa_pstValue){
  bool bRetVal = false;
  for(unsigned int i = 0; i < scm_stFBInterfaceSpec.m_nNumDOs; i++){
    if(m_ppstOutputItemList[i].m_pstItem == pa_pstItem){
      bRetVal = COpenSCADASFPServerHandler::getInstance().readBackDataPoint(pa_pstValue, *getDO(i));
      break;
    }
  }
  return bRetVal;
}
