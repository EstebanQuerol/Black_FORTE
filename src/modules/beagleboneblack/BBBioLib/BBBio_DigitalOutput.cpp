/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: BBBio_DigitalOutput
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2017-02-25/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "BBBio_DigitalOutput.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "BBBio_DigitalOutput_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_BBBio_DigitalOutput, g_nStringIdBBBio_DigitalOutput)

const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPORT, g_nStringIdPIN, g_nStringIdOUTPUT};

const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBYTE, g_nStringIdBYTE, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};

const TForteInt16 FORTE_BBBio_DigitalOutput::scm_anEIWithIndexes[] = {0, 5};
const TDataIOID FORTE_BBBio_DigitalOutput::scm_anEIWith[] = {0, 1, 3, 2, 255, 0, 3, 1, 2, 255};
const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_BBBio_DigitalOutput::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_BBBio_DigitalOutput::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_BBBio_DigitalOutput::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_BBBio_DigitalOutput::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};



void FORTE_BBBio_DigitalOutput::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		if(QI() == true){
    		if(this->joinBBBioLib() == 0){
    			STATUS() = "OK";
				QO() = true;
				iolib_init();
				iolib_setdir(PORT(),PIN(),1);
				sendOutputEvent(scm_nEventINITOID);
			}
		}
      break;
    case scm_nEventREQID:

		if(OUTPUT()){
			pin_high(PORT(),PIN());
		}else{
			pin_low(PORT(),PIN());
		}

		sendOutputEvent(scm_nEventCNFID);

      break;
  }
}



