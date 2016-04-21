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

#ifndef _SI_TXTREADER_H_
#define _SI_TXTREADER_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <stdio.h>

class FORTE_SI_TXTREADER: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SI_TXTREADER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &FILE_NAME() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_INT &STRING_LENGHT() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_STRING &TXTSTRING() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  };

  CIEC_BOOL &FILE_END() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 3, 4, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_SI_TXTREADER){
  };

  virtual ~FORTE_SI_TXTREADER(){};

private:
  void openTXTFile();
  void closeTXTFile();
  void readTXTFile();

  FILE *m_pstTXTFile;
};

#endif //close the ifdef sequence from the beginning of the file

