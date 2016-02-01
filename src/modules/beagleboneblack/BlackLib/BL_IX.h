/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BL_IX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-10-02/EQUEROL - UJI - 
 *************************************************************************/

#ifndef _BL_IX_H_
#define _BL_IX_H_

#include <funcbloc.h>
#include <forte_string.h>
#include <forte_bool.h>
#include "BlackLib.h"

class FORTE_BL_IX: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_BL_IX)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &PARAMS() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  CIEC_BOOL &IN() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
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

  BlackLib::BlackGPIO * m_poGPIO;

   FORTE_FB_DATA_ARRAY(2, 2, 3, 0);

  void executeEvent(int pa_nEIID);

  /*! \brief verifies if the input parameter is correct or not
   *
   *  This functions checks if the character string contained in pa_acValue matches any GPIO pin name
   *  according to BlackGPIO::gpioName enum. If any input matches a BlackLib::BlackGPIO object is created
   *  and is referenced using m_poGPIO pointer
   *  @param pa_acValue character string to check
   *  @param pa_nLength Length of the string to compare
   *  \return true if it matches a GPIO pin name; false otherwise
   */
  bool verifyInput(const char * pa_acValue, int pa_nLenght);

public:
  FUNCTION_BLOCK_CTOR(FORTE_BL_IX){
	  m_poGPIO = NULL;
  };

  virtual ~FORTE_BL_IX(){
	  delete m_poGPIO;
  };

};

#endif //close the ifdef sequence from the beginning of the file

