/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: UINT_DEMUX_N
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-11-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "UINT_DEMUX_N.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "UINT_DEMUX_N_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_UINT_DEMUX_N, g_nStringIdUINT_DEMUX_N)

const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anDataInputNames[] = {g_nStringIdUINT1, g_nStringIdUINT2, g_nStringIdUINT3, g_nStringIdUINT4, g_nStringIdUINT5, g_nStringIdUINT6, g_nStringIdUINT7, g_nStringIdUINT8};

const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anDataInputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anDataOutputTypeIds[] = {g_nStringIdUINT};

const TForteInt16 FORTE_UINT_DEMUX_N::scm_anEIWithIndexes[] = {0, 2, 4, 6, 8, 10, 12, 14};
const TDataIOID FORTE_UINT_DEMUX_N::scm_anEIWith[] = {0, 255, 1, 255, 2, 255, 3, 255, 4, 255, 5, 255, 6, 255, 7, 255};
const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anEventInputNames[] = {g_nStringIdE1, g_nStringIdE2, g_nStringIdE3, g_nStringIdE4, g_nStringIdE5, g_nStringIdE6, g_nStringIdE7, g_nStringIdE8};

const TDataIOID FORTE_UINT_DEMUX_N::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_UINT_DEMUX_N::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_UINT_DEMUX_N::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec FORTE_UINT_DEMUX_N::scm_stFBInterfaceSpec = {
  8,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_UINT_DEMUX_N::alg_Puint1(void){
OUT() = UINT1();

}

void FORTE_UINT_DEMUX_N::alg_Puint2(void){
OUT() = UINT2();
}

void FORTE_UINT_DEMUX_N::alg_Puint3(void){
OUT() = UINT3();
}

void FORTE_UINT_DEMUX_N::alg_Puint4(void){
OUT() = UINT4();
}

void FORTE_UINT_DEMUX_N::alg_Puint5(void){
OUT() = UINT5();
}

void FORTE_UINT_DEMUX_N::alg_Puint6(void){
OUT() = UINT6();
}

void FORTE_UINT_DEMUX_N::alg_Puint7(void){
OUT() = UINT7();
}

void FORTE_UINT_DEMUX_N::alg_Puint8(void){
OUT() = UINT8();
}


void FORTE_UINT_DEMUX_N::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT3(void){
  m_nECCState = scm_nStateP_UINT3;
  alg_Puint3();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT1(void){
  m_nECCState = scm_nStateP_UINT1;
  alg_Puint1();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT2(void){
  m_nECCState = scm_nStateP_UINT2;
  alg_Puint2();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT4(void){
  m_nECCState = scm_nStateP_UINT4;
  alg_Puint4();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT5(void){
  m_nECCState = scm_nStateP_UINT5;
  alg_Puint5();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT6(void){
  m_nECCState = scm_nStateP_UINT6;
  alg_Puint6();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT7(void){
  m_nECCState = scm_nStateP_UINT7;
  alg_Puint7();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::enterStateP_UINT8(void){
  m_nECCState = scm_nStateP_UINT8;
  alg_Puint8();
  sendOutputEvent( scm_nEventEOID);
}

void FORTE_UINT_DEMUX_N::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventE3ID == pa_nEIID)
          enterStateP_UINT3();
        else
        if(scm_nEventE1ID == pa_nEIID)
          enterStateP_UINT1();
        else
        if(scm_nEventE2ID == pa_nEIID)
          enterStateP_UINT2();
        else
        if(scm_nEventE4ID == pa_nEIID)
          enterStateP_UINT4();
        else
        if(scm_nEventE5ID == pa_nEIID)
          enterStateP_UINT5();
        else
        if(scm_nEventE6ID == pa_nEIID)
          enterStateP_UINT6();
        else
        if(scm_nEventE7ID == pa_nEIID)
          enterStateP_UINT7();
        else
        if(scm_nEventE8ID == pa_nEIID)
          enterStateP_UINT8();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT3:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT1:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT2:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT4:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT5:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT6:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT7:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateP_UINT8:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 8.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


