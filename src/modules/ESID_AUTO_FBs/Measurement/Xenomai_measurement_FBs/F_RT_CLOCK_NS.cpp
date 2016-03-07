/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_RT_CLOCK_NS
 *** Description: Reads the internal real time clock
 *** Version: 
 ***     0.0: 2011-06-21/EQUEROL - UJI - 
 *************************************************************************/

#include "F_RT_CLOCK_NS.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_RT_CLOCK_NS_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_RT_CLOCK_NS, g_nStringIdF_RT_CLOCK_NS)

const CStringDictionary::TStringId FORTE_F_RT_CLOCK_NS::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_RT_CLOCK_NS::scm_anDataOutputTypeIds[] = {g_nStringIdLWORD};

const TForteInt16 FORTE_F_RT_CLOCK_NS::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_F_RT_CLOCK_NS::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_RT_CLOCK_NS::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_RT_CLOCK_NS::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_RT_CLOCK_NS::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_RT_CLOCK_NS::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_RT_CLOCK_NS::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  clock_gettime(CLOCK_MONOTONIC, &m_stAuxTime);
	  TForteUInt64 l_nTime = static_cast<TForteUInt64> (m_stAuxTime.tv_sec) * 1000000000 + static_cast<TForteUInt64> (m_stAuxTime.tv_nsec);
	  OUT() = static_cast<CIEC_LWORD::TValueType>(l_nTime);
      sendOutputEvent(scm_nEventCNFID);
  }
}



