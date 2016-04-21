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

#include "SI_TXTREADER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SI_TXTREADER_gen.cpp"
#endif
#include <string.h>
#include <errno.h>
#include <string>
#include <iostream>
using namespace std;
DEFINE_FIRMWARE_FB(FORTE_SI_TXTREADER, g_nStringIdSI_TXTREADER)

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFILE_NAME, g_nStringIdSTRING_LENGHT};

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdTXTSTRING, g_nStringIdFILE_END};

const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_SI_TXTREADER::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_SI_TXTREADER::scm_anEIWith[] = {0, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_SI_TXTREADER::scm_anEOWith[] = {0, 1, 255, 2, 3, 255};
const TForteInt16 FORTE_SI_TXTREADER::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_SI_TXTREADER::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SI_TXTREADER::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_SI_TXTREADER::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
    	if(true == QI()){
    		closeTXTFile();
    	        openTXTFile();
    	      }
    	      else{
    	        closeTXTFile();
    	      }
				  sendOutputEvent(scm_nEventINITOID);
			break;
    case scm_nEventREQID:
    	QO() = QI();
    	      if(true == QI()){
    	        readTXTFile();
    	        sendOutputEvent(scm_nEventCNFID);
    	      }

      break;
  }
}

void FORTE_SI_TXTREADER::openTXTFile(){
  QO() = false;

  char* tempfilename = new char[FILE_NAME().length() + 5];
  FILE_NAME().toString(tempfilename, FILE_NAME().length() + 5, 1);
  		string filename(tempfilename);
  delete[]tempfilename;

  char comilla = '\'';
	for(int x = 0; x < filename.length(); x++)
	{
		if (filename[x] == '\'')
		{
			filename.erase(x,1);
		}
	}


  if(0 == m_pstTXTFile){
    m_pstTXTFile = fopen(filename.c_str(), "r");
    if(0 != m_pstTXTFile){
      STATUS() = "OK";
      QO() = true;
    }
    else{
      STATUS() = strerror(errno);
    }
  }
  else{
    STATUS() = "File already open";
  }
}

void FORTE_SI_TXTREADER::closeTXTFile(){
  QO() = false;
  if(0 != m_pstTXTFile){
    if(0 == fclose( m_pstTXTFile)){
      STATUS() = "OK";
    }
    else{
      STATUS() = strerror(errno);
    }
    m_pstTXTFile = 0;
  }
}

void FORTE_SI_TXTREADER::readTXTFile(){
  if(0 != m_pstTXTFile){
    char acBuffer[100]="\x0";
    if (!feof(m_pstTXTFile)){
    	 fread(acBuffer, 1, 99, m_pstTXTFile);

    			TXTSTRING() = acBuffer;
    			FILE_END() = false;
    		}


    if (feof(m_pstTXTFile)){
    			FILE_END() = true;


    		}



    }


  else{
    QO() = false;
    STATUS() = "File not opened";
  }
}


