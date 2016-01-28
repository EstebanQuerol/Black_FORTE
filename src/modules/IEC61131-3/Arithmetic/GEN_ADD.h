/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: GEN_ADD
 *** Description: Calculate arithmetical sum of magnitude inputs (generic FB)
 *** Version:
 ***     1.0: 2014-10-20/4DIAC-IDE - 4DIAC-Consortium
 *** Author: Matthias Plasch, matthias.plasch@profactor.at
 *************************************************************************/

#ifndef _GEN_ADD_H_
#define _GEN_ADD_H_

#include <funcbloc.h>
#include <forte_any_magnitude.h>

class GEN_ADD: public CFunctionBlock {
DECLARE_GENERIC_FIRMWARE_FB(GEN_ADD)

private:
	CStringDictionary::TStringId *m_anDataInputNames;
	CStringDictionary::TStringId *m_anDataInputTypeIds;

	static const CStringDictionary::TStringId scm_anDataOutputNames[];
	static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
	CIEC_ANY_MAGNITUDE &OUT() {
		return *static_cast<CIEC_ANY_MAGNITUDE*>(getDO(0));
	}
	;

	static const TEventID scm_nEventREQID = 0;
	static const TForteInt16 scm_anEIWithIndexes[];
	TDataIOID *m_anEIWith;
	static const CStringDictionary::TStringId scm_anEventInputNames[];

	static const TEventID scm_nEventCNFID = 0;
	static const TForteInt16 scm_anEOWithIndexes[];
	static const TDataIOID scm_anEOWith[];
	static const CStringDictionary::TStringId scm_anEventOutputNames[];

	//self-defined members
	int m_nDInputs;

	CStringDictionary::TStringId m_nConfiguredFBTypeNameId;

	virtual void executeEvent(int pa_nEIID);

	GEN_ADD(const CStringDictionary::TStringId pa_nInstanceNameId,
			CResource *pa_poSrcRes);
	virtual ~GEN_ADD();

public:

	CStringDictionary::TStringId getFBTypeId(void) const {
		return m_nConfiguredFBTypeNameId;
	}

	bool configureFB(const char *pa_acConfigString);

	template<typename T> void calculateValue() {
		T oIn, oOut;

		for (int nInputIndex = 0; nInputIndex < m_nDInputs; nInputIndex++) {

			oIn.saveAssign(*static_cast<T*>(getDI(nInputIndex)));

			if (0 == nInputIndex) {
				OUT().saveAssign(oIn);
			} else {
				oOut.saveAssign(OUT());
				OUT().saveAssign(ADD(oOut, oIn));
			}
		}
	}
};

#endif //close the ifdef sequence from the beginning of the file

