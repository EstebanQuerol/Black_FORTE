/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "cfb.h"
#include "adapter.h"
#include "resource.h"
#include "utils/criticalregion.h"

CCompositeFB::CCompositeFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
    const CStringDictionary::TStringId pa_nInstanceNameId, const SCFB_FBNData * const pa_cpoFBNData,
    TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
        CFunctionBlock(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_acFBConnData, pa_acFBVarsData),
        cm_cpoFBNData(pa_cpoFBNData){

  createInternalFBs();

  createEventConnections();
  createDataConnections();
  setParams();

  //remove adapter-references for CFB
  for(TForteUInt8 i = 0; i < pa_pstInterfaceSpec->m_nNumAdapters; i++){
    if(0 != m_apoAdapters){
      ((CAdapter*) m_apoAdapters[i])->setParentFB(0, 0);
    }
  }

}

CCompositeFB::~CCompositeFB(){
  //CTypeLib &roTypeLib(CTypeLib::getInstance());
  if(cm_cpoFBNData->m_nNumFBs){
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i){
      delete m_apoInternalFBs[i];
    }
    delete[] m_apoInternalFBs;
  }
  if(cm_cpoFBNData->m_nNumEventConnections){
    //only delet the interface to internal event connections all other connections are managed by their source's FBs
    for(unsigned int i = 0; i < m_pstInterfaceSpec->m_nNumEIs; ++i){
      delete mInterface2InternalEventCons[i];
    }
    delete[] m_apoEventConnections;
    delete[] mInterface2InternalEventCons;
  }
  if(cm_cpoFBNData->m_nNumDataConnections){
    delete[] m_apoDataConnections;
    delete[] mIf2InDConns;
    delete[] m_apoIn2IfDConns;
  }
}

bool CCompositeFB::connectDI(TPortId paDIPortId, CDataConnection *paDataCon){
  bool retVal = false;

  if(cgInternal2InterfaceMarker & paDIPortId){
    paDIPortId &= cgInternal2InterfaceRemovalMask;
    if(paDIPortId < m_pstInterfaceSpec->m_nNumDOs){
      m_apoIn2IfDConns[paDIPortId] = paDataCon;
      retVal = true;
    }
  }
  else if(paDIPortId < m_pstInterfaceSpec->m_nNumDIs){
    bool needsCloning = (getDI(paDIPortId)->getDataTypeID() == CIEC_ANY::e_ANY);
    retVal = CFunctionBlock::connectDI(paDIPortId, paDataCon);
    if((true == retVal) && (true == needsCloning) && (0 != paDataCon)
        && (0 != paDataCon->getValue())){
      //if internal connected update the connections data type and maybe internal further connection points
      (mIf2InDConns + paDIPortId)->setValue(getDI(paDIPortId));
      (mIf2InDConns + paDIPortId)->cloneInputInterfaceValue();
    }
  }
  return retVal;
}

bool CCompositeFB::configureGenericDO(TPortId paDOPortId, const CIEC_ANY &paRefValue){
  bool bRetVal = CFunctionBlock::configureGenericDO(paDOPortId, paRefValue);
  if(true == bRetVal){
    if(0 != m_apoIn2IfDConns[paDOPortId]){
      //issue a reconfiguration attempt so that all connection end points in this connection are also correctly configured
      m_apoIn2IfDConns[paDOPortId]->connectToCFBInterface(this, paDOPortId);
    }
  }
  return bRetVal;
}

EMGMResponse CCompositeFB::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse nRetVal = CFunctionBlock::changeFBExecutionState(pa_unCommand);
  for(unsigned int i = 0; ((i < cm_cpoFBNData->m_nNumFBs) && (e_RDY == nRetVal)); ++i){
    if(m_apoInternalFBs[i]){
      nRetVal = m_apoInternalFBs[i]->changeFBExecutionState(pa_unCommand);
    }
  }
  //Update FB parameters that maybe got overwritten by default values of the FB
  if((cg_nMGM_CMD_Reset == pa_unCommand) && (e_IDLE == getState())){
    setParams();
  }
  return nRetVal;
}

#ifdef FORTE_SUPPORT_MONITORING

CFunctionBlock *CCompositeFB::getFB(forte::core::TNameIdentifier::CIterator &paNameListIt){
  CFunctionBlock *retVal = 0;
  for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i){
    if(m_apoInternalFBs[i]->getInstanceNameId() == *paNameListIt){
      if(paNameListIt.isLastEntry()){
        retVal = m_apoInternalFBs[i];
      } else {
         //we are looking for a child of this fB
        ++paNameListIt;
        retVal = m_apoInternalFBs[i]->getFB(paNameListIt);
      }
    }
  }
  if(0 == retVal){
    //check if it is an adapter of the function block
    retVal = CFunctionBlock::getFB(paNameListIt);
  }
  return retVal;
}

#endif

CIEC_ANY *CCompositeFB::getVar(CStringDictionary::TStringId *paNameList,
    unsigned int paNameListSize){
  CIEC_ANY *retVal = 0;

  if(1 > paNameListSize){
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i){
      if(*paNameList == m_apoInternalFBs[i]->getInstanceNameId()){
        paNameList++;
        paNameListSize--;
        retVal = m_apoInternalFBs[i]->getVar(paNameList, paNameListSize);
        break;
      }
    }
  }
  else{
    retVal = CFunctionBlock::getVar(paNameList, paNameListSize);
  }

  return retVal;
}

void CCompositeFB::executeEvent(int pa_nEIID){
  if(cgInternal2InterfaceMarker & pa_nEIID){
    sendInternal2InterfaceOutputEvent(static_cast<TEventID>(pa_nEIID
        & cgInternal2InterfaceRemovalMask));
  }
  else{
    if(pa_nEIID < m_pstInterfaceSpec->m_nNumEIs){
      if(0 != mInterface2InternalEventCons[pa_nEIID]){
        mInterface2InternalEventCons[pa_nEIID]->triggerEvent(*m_poInvokingExecEnv);
      }
    }
  }
}

void CCompositeFB::sendInternal2InterfaceOutputEvent(int pa_nEOID){
  //handle sampling of internal 2 interface data connections
  if((pa_nEOID < m_pstInterfaceSpec->m_nNumEOs) && (0 != m_pstInterfaceSpec->m_anEOWithIndexes)){
    if(-1 != m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEOID]){
      const TDataIOID *poEOWithStart =
          &(m_pstInterfaceSpec->m_anEOWith[m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEOID]]);

      // TODO think on this lock
      {
        CCriticalRegion criticalRegion(getResource().m_oResDataConSync);
        for(int i = 0; poEOWithStart[i] != 255; ++i){
          if(0 != m_apoIn2IfDConns[poEOWithStart[i]]){
            m_apoIn2IfDConns[poEOWithStart[i]]->readData(getDO(poEOWithStart[i]));
          }
        }
      }
    }
  }

  sendOutputEvent(pa_nEOID);
}

void CCompositeFB::createInternalFBs(){
  if(cm_cpoFBNData->m_nNumFBs){
    m_apoInternalFBs = new TFunctionBlockPtr[cm_cpoFBNData->m_nNumFBs];
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFBs; ++i){
      m_apoInternalFBs[i] =
          CTypeLib::createFB(cm_cpoFBNData->m_pstFBInstances[i].m_nFBInstanceNameId, cm_cpoFBNData->m_pstFBInstances[i].m_nFBTypeNameId, getResourcePtr());
#ifdef FORTE_SUPPORT_MONITORING
      m_apoInternalFBs[i]->setContainer(this);
#endif
    }
  }
}

void CCompositeFB::createEventConnections(){
  if(0 != cm_cpoFBNData->m_nNumEventConnections){
    prepareIf2InEventCons();
    m_apoEventConnections = new CEventConnection *[cm_cpoFBNData->m_nNumEventConnections]; //TODO for a major revison this list could be ommited but requires a change in the faned out connections
    const SCFB_FBConnectionData *cpstCurrentConn;
    CFunctionBlock *poSrcFB;
    CFunctionBlock *poDstFB;
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumEventConnections; ++i){
      cpstCurrentConn = &(cm_cpoFBNData->m_pstEventConnections[i]);
      //FIXME implement way to inform FB creator that creation failed
      poSrcFB = getFunctionBlock(cpstCurrentConn->m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentConn->m_nDstFBNum);

      if((0 != poSrcFB) && (0 != poDstFB)){
        if(this == poSrcFB){
          m_apoEventConnections[i] =
              mInterface2InternalEventCons[getEIID(cpstCurrentConn->m_nSrcId)];
        }
        else{
          m_apoEventConnections[i] = poSrcFB->getEOConection(cpstCurrentConn->m_nSrcId);
        }
        establishConnection(m_apoEventConnections[i], poDstFB, cpstCurrentConn->m_nDstId);
      }
      else{
        DEVLOG_ERROR("Could not create event connection in CFB");
      }
    }
    //now handle the fanned out connections
    const SCFB_FBFannedOutConnectionData *cpstCurrentFannedConn;
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFannedOutEventConnections; ++i){
      cpstCurrentFannedConn = &(cm_cpoFBNData->m_pstFannedOutEventConnections[i]);
      poDstFB = getFunctionBlock(cpstCurrentFannedConn->m_nDstFBNum);
      establishConnection(m_apoEventConnections[cpstCurrentFannedConn->m_nConnectionNum],
          poDstFB, cpstCurrentFannedConn->m_nDstId);
    }
  }
}

void CCompositeFB::prepareIf2InEventCons(){
  if(0 != m_pstInterfaceSpec->m_nNumEIs){
    mInterface2InternalEventCons = new TEventConnectionPtr[m_pstInterfaceSpec->m_nNumEIs];
    //FIXME find a way to avoid that each connection has to be allocated separately
    for(TPortId i = 0; i < m_pstInterfaceSpec->m_nNumEIs; i++){
      mInterface2InternalEventCons[i] = new CEventConnection(this, i);
    }
  }
}

void CCompositeFB::establishConnection(CConnection *paCon, CFunctionBlock *paDstFb,
    CStringDictionary::TStringId paDstNameId){
  if(this == paDstFb){
    paCon->connectToCFBInterface(paDstFb, paDstNameId);
  }
  else{
    paCon->connect(paDstFb, paDstNameId);
  }
}

void CCompositeFB::createDataConnections(){
  if(cm_cpoFBNData->m_nNumDataConnections){
    if(m_pstInterfaceSpec->m_nNumDIs){
      prepareIf2InDataCons();
    }
    if(m_pstInterfaceSpec->m_nNumDOs){
      m_apoIn2IfDConns = new CDataConnection *[m_pstInterfaceSpec->m_nNumDOs];
      for(TPortId i = 0; i < m_pstInterfaceSpec->m_nNumDOs; i++){
        m_apoIn2IfDConns[i] = 0;
      }
    }

    m_apoDataConnections = new CDataConnection *[cm_cpoFBNData->m_nNumDataConnections];
    const SCFB_FBConnectionData *cpstCurrentConn;
    CFunctionBlock *poSrcFB;
    CFunctionBlock *poDstFB;
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumDataConnections; ++i){
      cpstCurrentConn = &(cm_cpoFBNData->m_pstDataConnections[i]);
      //FIXME implement way to inform FB creator that creation failed
      poSrcFB = getFunctionBlock(cpstCurrentConn->m_nSrcFBNum);
      poDstFB = getFunctionBlock(cpstCurrentConn->m_nDstFBNum);

      if((0 != poSrcFB) && (0 != poDstFB)){
        if(this == poSrcFB){
          m_apoDataConnections[i] = &(mIf2InDConns[getDIID(cpstCurrentConn->m_nSrcId)]);
        }
        else{
          m_apoDataConnections[i] = poSrcFB->getDOConnection(cpstCurrentConn->m_nSrcId);
        }
        establishConnection(m_apoDataConnections[i], poDstFB, cpstCurrentConn->m_nDstId);
      }
      else{
        DEVLOG_ERROR("Could not create event connection in CFB");
      }
    }
    //now handle the fanned out connections
    const SCFB_FBFannedOutConnectionData *cpstCurrentFannedConn;
    for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumFannedOutDataConnections; ++i){
      cpstCurrentFannedConn = &(cm_cpoFBNData->m_pstFannedOutDataConnections[i]);
      poDstFB = getFunctionBlock(cpstCurrentFannedConn->m_nDstFBNum);

      establishConnection(m_apoDataConnections[cpstCurrentFannedConn->m_nConnectionNum],
          poDstFB, cpstCurrentFannedConn->m_nDstId);
    }
  }
}

void CCompositeFB::prepareIf2InDataCons(){
  mIf2InDConns = new CInterface2InternalDataConnection[m_pstInterfaceSpec->m_nNumDIs];
  for(TPortId i = 0; i < m_pstInterfaceSpec->m_nNumDIs; i++){
    (mIf2InDConns + i)->setSource(this, i);
  }
}

void CCompositeFB::setParams(){
  const SCFB_FBParameter *pstCurrentParam;
  for(unsigned int i = 0; i < cm_cpoFBNData->m_nNumParams; ++i){
    pstCurrentParam = &(cm_cpoFBNData->m_pstParams[i]);
    CIEC_ANY *poDI =
        m_apoInternalFBs[pstCurrentParam->m_nFBNum]->getDataInput(pstCurrentParam->m_nDINameID);
    if(0 != poDI){
      poDI->fromString(pstCurrentParam->m_acParamValue);
    }
    else{
      DEVLOG_ERROR("Could not get date input for setting a parameter");
    }
  }
}

CFunctionBlock *CCompositeFB::getFunctionBlock(int pa_nFBNum){
  CFunctionBlock *poRetVal = 0;
  if(-1 == pa_nFBNum){
    poRetVal = this;
  }
  else if(0 <= pa_nFBNum){
    if(scm_nAdapterMarker == (scm_nAdapterMarker & pa_nFBNum)){
      pa_nFBNum &= scm_nAdapterFBRange;
      if(pa_nFBNum < m_pstInterfaceSpec->m_nNumAdapters){
        poRetVal = m_apoAdapters[pa_nFBNum];
      }
    }
    else{
      if(static_cast<unsigned int>(pa_nFBNum) < cm_cpoFBNData->m_nNumFBs){
        poRetVal = m_apoInternalFBs[pa_nFBNum];
      }
    }
  }
  return poRetVal;
}
