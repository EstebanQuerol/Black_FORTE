/*************************************************************************
*** FORTE Library Element
***
*** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
***
*** Name: GET_AT_INDEX
*** Description: Service Interface Function Block Type
*** Version: 
***     0.0: 2014-07-11/4DIAC-IDE - 4DIAC-Consortium
*** Author: Matthias Plasch, matthias.plasch@profactor.at
*************************************************************************/

#ifndef _GET_AT_INDEX_H_
#define _GET_AT_INDEX_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_any.h>
#include <forte_uint.h>

class FORTE_GET_AT_INDEX: public CFunctionBlock{
	DECLARE_FIRMWARE_FB(FORTE_GET_AT_INDEX)

private:
	static const CStringDictionary::TStringId scm_anDataInputNames[];
	static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
	CIEC_ANY &IN_ARRAY() {
		return *static_cast<CIEC_ANY*>(getDI(0));
	};

	CIEC_UINT &INDEX() {
		return *static_cast<CIEC_UINT*>(getDI(1));
	};

	static const CStringDictionary::TStringId scm_anDataOutputNames[];
	static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
	CIEC_BOOL &QO() {
		return *static_cast<CIEC_BOOL*>(getDO(0));
	};

	CIEC_ANY &OUT() {
		return *static_cast<CIEC_ANY*>(getDO(1));
	};

	static const TEventID scm_nEventREQID = 0;
	static const TForteInt16 scm_anEIWithIndexes[];
	static const TDataIOID scm_anEIWith[];
	static const CStringDictionary::TStringId scm_anEventInputNames[];

	static const TEventID scm_nEventCNFID = 0;
	static const TForteInt16 scm_anEOWithIndexes[];
	static const TDataIOID scm_anEOWith[];
	static const CStringDictionary::TStringId scm_anEventOutputNames[];

	static const SFBInterfaceSpec scm_stFBInterfaceSpec;

	FORTE_FB_DATA_ARRAY(1, 2, 2, 0);

	void executeEvent(int pa_nEIID);

public:
	FUNCTION_BLOCK_CTOR(FORTE_GET_AT_INDEX){
	};

	virtual ~FORTE_GET_AT_INDEX(){};

};

#endif //close the ifdef sequence from the beginning of the file

