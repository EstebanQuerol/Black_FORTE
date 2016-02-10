/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_TXTHISTORIAL
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2016-01-05/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SI_TXTHISTORIAL.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_TXTHISTORIAL_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_SI_TXTHISTORIAL, g_nStringIdSI_TXTHISTORIAL)

const CStringDictionary::TStringId FORTE_SI_TXTHISTORIAL::scm_anDataInputNames[] = {g_nStringIdINFORME, g_nStringIdI, g_nStringIdV};

const CStringDictionary::TStringId FORTE_SI_TXTHISTORIAL::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_SI_TXTHISTORIAL::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SI_TXTHISTORIAL::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_SI_TXTHISTORIAL::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_SI_TXTHISTORIAL::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_SI_TXTHISTORIAL::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SI_TXTHISTORIAL::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


void FORTE_SI_TXTHISTORIAL::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:

		char* tempdatainforme = new char[INFORME().length() + 5];
		INFORME().toString(tempdatainforme, INFORME().length() + 5, 1);
		string datainforme(tempdatainforme);
		delete[]tempdatainforme;

		char* tempdataI = new char[I().length() + 5];
		I().toString(tempdataI, I().length() + 5, 1);
		string dataI(tempdataI);
		delete[]tempdataI;

		char* tempdataV = new char[V().length() + 5];
		V().toString(tempdataV, V().length() + 5, 1);
		m_MyString = std::string(tempdataV);
		delete[]tempdataV;

		ofstream historialDATA("historialDATOS.txt", ios::app);


		if (CTimerHandler::sm_poFORTETimer != 0){
			historialDATA << ": T#" + CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
			historialDATA << CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue;
			historialDATA << "ms" << "	";
			//fprintf(stderr, ": T#%ld%ldms: ", CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue, CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
		}

		historialDATA << datainforme << "	";
		historialDATA << dataI << "	";
		historialDATA << m_MyString << endl;


		sendOutputEvent(scm_nEventCNFID);

      break;
  }
}



