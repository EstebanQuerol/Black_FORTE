/*************************************************************************
*** FORTE Library Element
***
*** This file was generated using the 4DIAC FORTE Export Filter V0.4!
***
*** Name: OUT_ANY_CONSOLE
*** Description: Service Interface Function Block Type for debugging, tracing, etc.
*** Version: 
***     0.0: 2011-08-29/4DIAC-IDE - 4DIAC-Consortium - null
*************************************************************************/

#include "OUT_ANY_CONSOLE.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "OUT_ANY_CONSOLE_gen.cpp"
#endif

#include <forte_array.h>

DEFINE_FIRMWARE_FB(FORTE_OUT_ANY_CONSOLE, g_nStringIdOUT_ANY_CONSOLE)

	const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataInputNames[] =
{ g_nStringIdQI, g_nStringIdLABEL, g_nStringIdIN };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataInputTypeIds[] =
{ g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdANY };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataOutputNames[] =
{ g_nStringIdQO };

const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anDataOutputTypeIds[] =
{ g_nStringIdBOOL };

const TForteInt16 FORTE_OUT_ANY_CONSOLE::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_OUT_ANY_CONSOLE::scm_anEIWith[] = { 0, 2, 1, 255 };
const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anEventInputNames[] =
{ g_nStringIdREQ };

const TDataIOID FORTE_OUT_ANY_CONSOLE::scm_anEOWith[] = { 0, 255 };
const TForteInt16 FORTE_OUT_ANY_CONSOLE::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_OUT_ANY_CONSOLE::scm_anEventOutputNames[] =
{ g_nStringIdCNF };

const SFBInterfaceSpec FORTE_OUT_ANY_CONSOLE::scm_stFBInterfaceSpec = { 1,
	scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1,
	scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3,
	scm_anDataInputNames, scm_anDataInputTypeIds, 1, scm_anDataOutputNames,
	scm_anDataOutputTypeIds, 0, 0 };

//default value is set to 100 (sufficient for several data types)
const TForteInt16 FORTE_OUT_ANY_CONSOLE::scm_maxStringBufSize = 100;

void FORTE_OUT_ANY_CONSOLE::executeEvent(int pa_nEIID) {
	switch (pa_nEIID) {
	case scm_nEventREQID:
		QO() = QI();
		if (true == QI()) {
			TForteUInt16 nRequiredBytes;
			TForteUInt16 nUsedBytes;
			TForteUInt16 nStringLength;
			CIEC_WSTRING sOutput;
			char strbuf1[scm_maxStringBufSize];
			LABEL().toString(strbuf1, sizeof(strbuf1));

			if(IN().getDataTypeID() == CIEC_ANY::e_STRING || IN().getDataTypeID() == CIEC_ANY::e_WSTRING){
				//obtain length of string value
				nStringLength = (static_cast<CIEC_ANY_STRING*>(&IN()))->length();
				//assign value
				sOutput.assign((static_cast<CIEC_ANY_STRING*>(&IN()))->getValue(), nStringLength);
			}
			else{
				//values other than strings
				//for arrays
				if(IN().getDataTypeID() == CIEC_ANY::e_ARRAY){
					//get number of array elements
					TForteUInt16 nArrayElements = (static_cast<CIEC_ARRAY*>(&IN()))->size();
					//number of required bytes (including brackets '[' ']' and ',' separators
					nRequiredBytes = nArrayElements * scm_maxStringBufSize + nArrayElements + static_cast<TForteUInt16>(1);
				}
				else{
					//size for single data values
					nRequiredBytes = scm_maxStringBufSize;
				}

				sOutput.reserve(nRequiredBytes);
				//write StringValue
				nUsedBytes = IN().toString(sOutput.getValue(), nRequiredBytes);
				//maintain the state of the output data value string
				sOutput.assign(sOutput.getValue(), nUsedBytes);
			}

			DEVLOG_INFO(" %s = %s\n", strbuf1, sOutput.getValue());
		}
		sendOutputEvent(scm_nEventCNFID);
		break;
	}
}

