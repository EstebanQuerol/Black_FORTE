/*******************************************************************************
 * Copyright (c) 2007-2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <funcbloc.h>
#include <forte_string.h>
#include <forte_bool.h>

#ifndef PROCESSINTERFACEBASE_H_
#define PROCESSINTERFACEBASE_H_


class CProcessInterfaceBase : public CFunctionBlock{
  public:
    CProcessInterfaceBase(CResource *paSrcRes, const SFBInterfaceSpec *paInterfaceSpec,
        const CStringDictionary::TStringId paInstanceNameId, TForteByte *paFBConnData, TForteByte *paFBVarsData) :
          CFunctionBlock(paSrcRes, paInterfaceSpec, paInstanceNameId, paFBConnData, paFBVarsData){

    }

    virtual ~CProcessInterfaceBase(){
    }

  protected:
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }

    CIEC_STRING &PARAMS(){
      return *static_cast<CIEC_STRING*>(getDI(1));
    }

    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }

    CIEC_STRING &STATUS(){
      return *static_cast<CIEC_STRING*>(getDO(1));
    }

    CIEC_BOOL &IN(){
      return *static_cast<CIEC_BOOL*>(getDO(2));
    }

    CIEC_BOOL &OUT() {
      return *static_cast<CIEC_BOOL*>(getDI(2));
    };

    //TODO move pin checking and managing code into this class. Can be solved with recurring template pattern
};

#endif
