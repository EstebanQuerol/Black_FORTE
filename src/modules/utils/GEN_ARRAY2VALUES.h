/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: VALUES2ARRAY_LREAL_6
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-06-13/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _GEN_ARRAY2VALUES_H_
#define _GEN_ARRAY2VALUES_H_

#include <funcbloc.h>
#include <forte_array.h>

class GEN_ARRAY2VALUES : public CFunctionBlock{
  DECLARE_GENERIC_FIRMWARE_FB(GEN_ARRAY2VALUES)

  private:
    CStringDictionary::TStringId *m_anDataOutputNames;
    CStringDictionary::TStringId *m_anDataOutputTypeIds;

    static const CStringDictionary::TStringId scm_anDataInputNames[];
    CStringDictionary::TStringId *m_anDataInputTypeIds;

    CIEC_ARRAY &IN_Array(){
      return *static_cast<CIEC_ARRAY *>(getDI(0));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    TDataIOID *m_anEOWith;
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    //self-defined members
    int m_nDOutputs;
    CStringDictionary::TStringId m_ValueTypeID;

    CStringDictionary::TStringId m_nConfiguredFBTypeNameId;
    virtual void executeEvent(int pa_nEIID);

    GEN_ARRAY2VALUES(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_ARRAY2VALUES();

  public:
    CStringDictionary::TStringId getFBTypeId(void) const{
      return m_nConfiguredFBTypeNameId;
    }

    bool configureFB(const char *pa_acConfigString);
};

#endif //close the ifdef sequence from the beginning of the file

