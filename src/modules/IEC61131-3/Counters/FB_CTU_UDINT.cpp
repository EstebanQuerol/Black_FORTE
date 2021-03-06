/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_CTU_UDINT
 *** Description: counters (up-counter)
 *** Version:
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/

#include "FB_CTU_UDINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_CTU_UDINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FB_CTU_UDINT, g_nStringIdFB_CTU_UDINT)

const CStringDictionary::TStringId FB_CTU_UDINT::scm_anDataInputNames[] = {g_nStringIdCU, g_nStringIdR, g_nStringIdPV};

const CStringDictionary::TStringId FB_CTU_UDINT::scm_anDataOutputNames[] = {g_nStringIdQ, g_nStringIdCV};
const CStringDictionary::TStringId FB_CTU_UDINT::scm_aunDIDataTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdUDINT};
const CStringDictionary::TStringId FB_CTU_UDINT::scm_aunDODataTypeIds[] = {g_nStringIdBOOL, g_nStringIdUDINT};

const TForteInt16 FB_CTU_UDINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FB_CTU_UDINT::scm_anEIWith[] = {0, 2, 1, 255};
const CStringDictionary::TStringId FB_CTU_UDINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FB_CTU_UDINT::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FB_CTU_UDINT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FB_CTU_UDINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FB_CTU_UDINT::scm_stFBInterfaceSpec = {
  1,
  scm_anEventInputNames,
  scm_anEIWith,
  scm_anEIWithIndexes,
  1,
  scm_anEventOutputNames,
  scm_anEOWith,
  scm_anEOWithIndexes,
  3,
  scm_anDataInputNames, scm_aunDIDataTypeIds,
  2,
  scm_anDataOutputNames, scm_aunDODataTypeIds,
  0,
  0
};

void FB_CTU_UDINT::executeEvent(int pa_nEIID){
  if(pa_nEIID == scm_nEventREQID){
    if(true == R()){
      CV() = 0;
    }
    else if( (true == CU()) && (CV() < CIEC_UDINT::scm_nMaxVal)){
      CV() = CV() + 1;
    }
    Q() = (CV() >= PV());
    sendOutputEvent(scm_nEventCNFID);
  }
}
