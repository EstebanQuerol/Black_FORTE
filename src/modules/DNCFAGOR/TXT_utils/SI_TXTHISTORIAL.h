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

#ifndef _SI_TXTHISTORIAL_H_
#define _SI_TXTHISTORIAL_H_

#include <funcbloc.h>
#include <forte_string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;
class FORTE_SI_TXTHISTORIAL: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SI_TXTHISTORIAL)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &INFORME() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_STRING &I() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_STRING &V() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 3, 0, 0);

  void executeEvent(int pa_nEIID);
  std::string m_MyString =  "";
public:
  FUNCTION_BLOCK_CTOR(FORTE_SI_TXTHISTORIAL){
	  m_MyString = "";
  };

  virtual ~FORTE_SI_TXTHISTORIAL(){};

};

#endif //close the ifdef sequence from the beginning of the file

