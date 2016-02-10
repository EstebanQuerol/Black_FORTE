/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_CRC16
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-12-04/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SI_CRC16.h"

//#include <string.h>
#include <iostream>
#include "crc.h"
#include <string>

//#include <cstring>
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_CRC16_gen.cpp"
#endif

using namespace std;

DEFINE_FIRMWARE_FB(FORTE_SI_CRC16, g_nStringIdSI_CRC16)

const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_SI_CRC16::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SI_CRC16::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anEventInputNames[] = {g_nStringIdEI};

const TDataIOID FORTE_SI_CRC16::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_SI_CRC16::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_SI_CRC16::scm_anEventOutputNames[] = {g_nStringIdEO};

const SFBInterfaceSpec FORTE_SI_CRC16::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SI_CRC16::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventEIID:
		char* tempcrc = new char[IN().length() + 5];
		IN().toString(tempcrc, IN().length() + 5, 1);
		string crcstring(tempcrc);
		delete[]tempcrc;
		int i = 0;
		int chvalue;
		string subst1 = crcstring.c_str();
		string subst2;
		if (subst1[0] == '\x27'){
			subst1.erase(subst1.begin());
		}

//		if (subst1.back() == '\x27'){
//			subst1.pop_back();
//		}

		subst2 = subst1.substr(subst1.length()-1, 1);

						if ( subst2 == "\x27"){
							if(subst1.length()>1){
								subst1=subst1.substr(0,subst1.length()-1);
							}
							else{
								subst1="\x00";
							}
						}


		crcstring = subst1;

		if (subst1[0] == '\x01'){
			subst1.erase(subst1.begin());
		}

		if (subst1[0] == '\x02'){
			subst1.erase(subst1.begin());
		}

		char  testcrc[255];
		strcpy(testcrc, subst1.c_str());
		


		crcInit();
		crc pruebacrc = crcFast((const unsigned char*)testcrc, strlen((const char*)(testcrc)));
		crc pruebacrc1 = pruebacrc & 0x00ff;
		crc pruebacrc2 = (pruebacrc) >> 8;

		
		char p[3];
		p[0] = (unsigned int)pruebacrc2;
		p[1] = (unsigned int)pruebacrc1;
		p[2] = '\x0';
	

		string in1(crcstring);
		string in2(p);
		string in3;
		in3 = in1 + in2;

		OUT() = in3.c_str();      
		sendOutputEvent(scm_nEventEOID);

      break;
  }
}



