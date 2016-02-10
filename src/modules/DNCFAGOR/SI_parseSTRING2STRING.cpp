/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SI_parseSTRING2STRING
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-11-26/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "SI_parseSTRING2STRING.h"


#include <iostream>

#include <string>
#include <cstring>
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_parseSTRING2STRING_gen.cpp"
#endif

using namespace std;

DEFINE_FIRMWARE_FB(FORTE_SI_parseSTRING2STRING, g_nStringIdSI_parseSTRING2STRING)

const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_SI_parseSTRING2STRING::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SI_parseSTRING2STRING::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_SI_parseSTRING2STRING::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_SI_parseSTRING2STRING::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_SI_parseSTRING2STRING::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SI_parseSTRING2STRING::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SI_parseSTRING2STRING::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventREQID:
		char* stoparse = new char[IN().length() + 5];
		IN().toString(stoparse, IN().length() + 5,1);
		string parsestring(stoparse);
		delete[]stoparse;
		int i = 0;
		int chvalue;
		string subst1 = parsestring.substr(i, 1);
		string subst2;

		if (subst1 == "\x27"){

			i++;
			subst1 = parsestring.substr(i, 1);
		}

		while (subst1 != "\x0"){
			/**/
			if (subst1 == "\x2f"){
				i++;
				subst1 = parsestring.substr(i, 1);
				if (subst1 == "\x78"){
					i++;
					subst1 = parsestring.substr(i, 1);
					if (isxdigit(subst1.c_str()[0])){
						i++;
						subst1 = parsestring.substr(i, 1);
						i--;
						if (isxdigit(subst1.c_str()[0])){

							subst1 = parsestring.substr(i, 2);
							chvalue = strtol(subst1.c_str(), NULL, 16);
							subst1 = (unsigned char)chvalue;
							i++;
						}

					}
					else{
						i -= 2;
						subst1 = parsestring.substr(i, 1);
					}
				}
				else{
					i--;
					subst1 = parsestring.substr(i, 1);
				}
			}

			subst2 = subst2 + subst1;
			i++;
			subst1 = parsestring.substr(i, 1);
			
		}

		subst1 = subst2.substr(subst2.length()-1, 1);

		if ( subst1 == "\x27"){
			if(subst2.length()>1){
				subst2=subst2.substr(0,subst2.length()-1);
			}
			else{
				subst2="\x00";
			}
		}
		OUT() = subst2.c_str();
		sendOutputEvent(scm_nEventCNFID);
      break;
  }
}



