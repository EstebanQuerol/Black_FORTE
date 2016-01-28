/*******************************************************************************
 * Copyright (c) 2007-2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _PROCESSINTERFACE_H_
#define _PROCESSINTERFACE_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_string.h>

class CRaspiProcessInterface: public CFunctionBlock{

public:
   CRaspiProcessInterface(CResource *pa_poSrcRes,
           const SFBInterfaceSpec *paInterfaceSpec,
           const CStringDictionary::TStringId pa_nInstanceNameId,
           TForteByte *pa_anFBConnData,
           TForteByte *pa_anFBVarsData) :
    CFunctionBlock(pa_poSrcRes,
                   paInterfaceSpec,
                   pa_nInstanceNameId,
                   pa_anFBConnData,
                   pa_anFBVarsData), mPinNumber(-1){}

protected:
  bool initialise(bool m_bInputOrOutput);
  bool deinitialise();
  bool writePin();
  bool readPin();

private:
  bool checkPin();

   CIEC_BOOL &QO(){
     return *static_cast<CIEC_BOOL*>(getDO(0));
   };

   CIEC_STRING &STATUS(){
     return *static_cast<CIEC_STRING*>(getDO(1));
   };

   CIEC_BOOL &IN(){
     return *static_cast<CIEC_BOOL*>(getDO(2));
   };

   CIEC_BOOL &QI(){
     return *static_cast<CIEC_BOOL*>(getDI(0));
   };

   CIEC_STRING &PARAMS(){
     return *static_cast<CIEC_STRING*>(getDI(1));
   };

   CIEC_BOOL &OUT(){
     return *static_cast<CIEC_BOOL*>(getDI(2));
   };

  int mPinNumber; 

  static const char * const scmPinInUse;
  static const char * const scmInitDeinitOK;
  static const char * const scmNotInitialised;

  enum EPinState{
    enUnused,
    enInput,
    enOutput
  };
  
  static EPinState smPinUsage[16];
};

//tell the IX and QX FB that this is the process interface to be used
typedef CRaspiProcessInterface CProcessInterface;

#endif /*PROCESSINTERFACE_H_*/

