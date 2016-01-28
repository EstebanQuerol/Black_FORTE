/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: QX
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-08-26/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _QX_H_
#define _QX_H_

#include <processinterface.h> 
#include <forte_wstring.h>
#include <forte_string.h>
#include <forte_bool.h>

//TODO add compile time check that CProcessInterface inherits from CProcessInterfaceBase

/*! /brief generic class for QX function blocks providing access to one boolean physical output
 *
 * In order that this FB can be used implementations need to provide a class CProcessInterface
 * this class needs to inherit from CProcessInterfaceBase and provide the following functions
 *
 *   - bool initialise(bool paInput)
 *     Initialize the physical output identified with the value of the PARAMS FB input
 *       - @param paInput: if true it should be an input, if false it should be an output
 *       - @return true on success, false on error
 *
 *   - bool deinitialise()
 *     Deinitalize the physical port
 *       - @return true on success, false on error
 *
 *   - bool writePin()
 *     Write the value of function block's IN() data input to the physical input
 *       - @return true on success, false on error
 *
 * TODO a higher flexibility and easier use could be achieve if the base class would be a template parameter. However
 *   currently it is very hard to templatize a function block class.
 */
class FORTE_QX: public CProcessInterface{
  DECLARE_FIRMWARE_FB(FORTE_QX)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &PARAMS() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_BOOL &OUT() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
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

   FORTE_FB_DATA_ARRAY(2, 3, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR_WITH_BASE_CLASS(FORTE_QX, CProcessInterface){
  };

  virtual ~FORTE_QX(){};

};

#endif //close the ifdef sequence from the beginning of the file
