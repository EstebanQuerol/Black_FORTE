/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SIFB_GENTXT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-11-19/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SIFB_GENTXT.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SIFB_GENTXT_gen.cpp"
#endif
using namespace std;
DEFINE_FIRMWARE_FB(FORTE_SIFB_GENTXT, g_nStringIdSIFB_GENTXT)

const CStringDictionary::TStringId FORTE_SIFB_GENTXT::scm_anDataInputNames[] = {g_nStringIdSTRING1, g_nStringIdSTRING2};

const CStringDictionary::TStringId FORTE_SIFB_GENTXT::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_SIFB_GENTXT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SIFB_GENTXT::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_SIFB_GENTXT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_SIFB_GENTXT::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_SIFB_GENTXT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SIFB_GENTXT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


void FORTE_SIFB_GENTXT::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
		
		char* histIN1 = new char[STRING1().length() + 5];
		STRING1().toString(histIN1, STRING1().length() + 5,1);
		string histin1(histIN1);
		delete[]histIN1; 

		char* histIN2 = new char[STRING2().length() + 5];
		STRING2().toString(histIN2, STRING2().length() + 5,1);
		string histin2(histIN2);
		delete[]histIN2;

		char *trama1GENTXT = strdup(histin1.c_str());
		char *trama2GENTXT = strdup(histin2.c_str());
		
	

		ofstream historial("historial01.txt", ios::app);
		//historial.open("historial01.dat", ios::out| ios::binary | ios::app);
		historial << (histin1) << endl;
		historial << "                          " ;
		historial << (histin2) << endl;
		historial << "-_____________________-" << endl;


		//escribimos histin1 en historial en dec y hex

		for (unsigned int i = 0; i <= histin1.length(); i++){

			historial << (unsigned int)trama1GENTXT[i] << "  ";
		}
		historial << endl << "-*********************-" << endl;
		historial << resetiosflags(ios::dec);
		historial << setiosflags(ios::hex);	
		for (unsigned int i = 0; i <= histin1.length(); i++){

			historial << (unsigned int)trama1GENTXT[i] << "  ";

		}
		historial << endl << "-+++++++++++++++++++++-" << endl;

		historial << resetiosflags(ios::hex);
		historial << setiosflags(ios::dec);

		//escribimos histin2 en historial en dec y hex
		historial << "                          ";
		for (unsigned int i = 0; i <= histin2.length();i++){
			
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



