/*******************************************************************************
 * Copyright (c) 2007-2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "processinterface.h"
#include <GPIO/GPIOConst.h>


CBBBProcessInterface::CBBBProcessInterface(CResource *paSrcRes,
    const SFBInterfaceSpec *paInterfaceSpec,
    const CStringDictionary::TStringId paInstanceNameId, TForteByte *paFBConnData,
    TForteByte *paFBVarsData) :
    CProcessInterfaceBase(paSrcRes, paInterfaceSpec, paInstanceNameId, paFBConnData, paFBVarsData),
    mGPManager(GPIO::GPIOManager::getInstance()),
    mPin(0){

}

CBBBProcessInterface::~CBBBProcessInterface(){
  deinitialise();
}

bool CBBBProcessInterface::initialise(bool paInput){
  bool retVal = false;

  CIEC_INT pinNum;
  if(-1 != pinNum.fromString(PARAMS().getValue())){
    mPin = pinNum;
    //TODO add checks
    mGPManager->exportPin(mPin);
    mGPManager->setDirection(mPin, (paInput) ? GPIO::INPUT : GPIO::OUTPUT);
    retVal = true;
  }
  return retVal;
}

bool CBBBProcessInterface::deinitialise(){
  if(0 != mPin){
    mPin = 0;
    //TODO release pin
  }
  return true;
}

bool CBBBProcessInterface::readPin(){
  bool retVal = false;

  if(0 != mPin){
    IN() = (mGPManager->getValue(mPin) == GPIO::HIGH);
    retVal = true;
  }

  return retVal;
}

bool CBBBProcessInterface::writePin(){
  bool retVal = false;

  if(0 != mPin){
    mGPManager->setValue(mPin, (true == OUT()) ? GPIO::HIGH : GPIO::LOW);
    retVal = true;
  }

  return retVal;
}
