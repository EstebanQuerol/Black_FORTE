/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SIFB_GENTXT_DNC
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-11-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SIFB_GENTXT_DNC.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SIFB_GENTXT_DNC_gen.cpp"
#endif

using namespace std;

DEFINE_FIRMWARE_FB(FORTE_SIFB_GENTXT_DNC, g_nStringIdSIFB_GENTXT_DNC)

const CStringDictionary::TStringId FORTE_SIFB_GENTXT_DNC::scm_anDataInputNames[] = {g_nStringIdSTRING1};

const CStringDictionary::TStringId FORTE_SIFB_GENTXT_DNC::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_SIFB_GENTXT_DNC::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SIFB_GENTXT_DNC::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_SIFB_GENTXT_DNC::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_SIFB_GENTXT_DNC::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_SIFB_GENTXT_DNC::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SIFB_GENTXT_DNC::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


void FORTE_SIFB_GENTXT_DNC::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
		char* histIN2 = new char[STRING1().length() + 5];
		STRING1().toString(histIN2, STRING1().length() + 5, 1);
		string histin2(histIN2);
		delete[]histIN2;


		char *trama2GENTXT = strdup(histin2.c_str());



		ofstream historial("historial02.txt", ios::app);


		if (CTimerHandler::sm_poFORTETimer != 0){
			historial << ": T#" + CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
			historial << CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue;
			historial << "ms" << endl;
			//fprintf(stderr, ": T#%ld%ldms: ", CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue, CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue);
		}
		//historial.open("historial01.dat", ios::out| ios::binary | ios::app);
		historial << "                          ";
		historial << (histin2) << endl;
		historial << "                          " << "-_____________________-" << endl;




		//escribimos histin2 en historial en dec y hex
		historial << "                          ";
		for (unsigned int i = 0; i <= histin2.length(); i++){

			historial << (unsigned int)trama2GENTXT[i] << "  ";
		}
		historial << endl << "                          " << "-*********************-" << endl;
		historial << resetiosflags(ios::dec);
		historial << setiosflags(ios::hex);
		historial << "                          ";
		for (unsigned int i = 0; i <= histin2.length(); i++){

			historial << (unsigned int)trama2GENTXT[i] << "  ";

		}
		historial << endl << "                          " << "-+++++++++++++++++++++-" << endl;




		historial << resetiosflags(ios::hex);
		historial << setiosflags(ios::dec);
		sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



