/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_TXTREADER
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-12-17/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SI_TXTREADER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_TXTREADER_gen.cpp"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#endif

using namespace std;

DEFINE_FIRMWARE_FB(FORTE_SI_TXTREADER, g_nStringIdSI_TXTREADER)

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataOutputNames[] = {g_nStringIdTXTSTRING, g_nStringIdFINALTXT};

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_SI_TXTREADER::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_SI_TXTREADER::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_SI_TXTREADER::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SI_TXTREADER::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SI_TXTREADER::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
	/*
		char trozotxt[100] = "\x00";
		fstream myISOFILE;
		clock_t timestop = 6 * CLOCKS_PER_SEC;
		clock_t timetxt = clock() - startTime;

		if (startTime!=0){
			if (timetxt >= timestop){
			myISOFILE.seekg(0, ios::beg);
			lastreadpos = myISOFILE.tellg();
			myISOFILE.close();
			control = false;
			}
		}

		if (!myISOFILE.is_open()){
			myISOFILE.open("text.bin", ios::binary);
			startTime = clock();
		}

		if (!control){
			lastreadpos = myISOFILE.tellg();
			control = true;
		}

		myISOFILE.seekg(lastreadpos, ios::beg);

		if (!myISOFILE.eof()){
			myISOFILE.read(trozotxt, 99);
			lastreadpos = myISOFILE.tellg();
			TXTSTRING() = trozotxt;
			FINALTXT() = false;
		}


		if (myISOFILE.eof()){
			FINALTXT() = true;
			control = false;
			myISOFILE.close();
		}
*/
      sendOutputEvent(scm_nEventCNFID);

      break;
  }
}

