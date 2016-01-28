/*******************************************************************************
 * Copyright (c) 2007-2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "processinterface.h"
#include "wiringPi.h"

//This array is needed for observing the current state of the GPIOs on Raspi
CRaspiProcessInterface::EPinState CRaspiProcessInterface::smPinUsage[16] = {
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused,
	CRaspiProcessInterface::enUnused
};

const char * const CRaspiProcessInterface::scmPinInUse = "Pin already in use by other FB";
const char * const CRaspiProcessInterface::scmInitDeinitOK = "OK";
const char * const CRaspiProcessInterface::scmNotInitialised = "Not initialised";

bool CRaspiProcessInterface::initialise(bool m_bInputOrOutput){
  wiringPiSetup();
  CIEC_INT param;
  param.fromString(PARAMS().getValue());
  mPinNumber = param;

  if(true == checkPin()){
    if(m_bInputOrOutput){ 						//if pin used as input
      pullUpDnControl(mPinNumber, PUD_DOWN); 	//pull-down the input-pin. use PUD_UP for pull-up. 
      CRaspiProcessInterface::smPinUsage[mPinNumber] = CRaspiProcessInterface::enInput;
      pinMode(mPinNumber, INPUT);
    }else{
      CRaspiProcessInterface::smPinUsage[mPinNumber] = CRaspiProcessInterface::enOutput;
      pinMode(mPinNumber, OUTPUT);
    }
    STATUS() = scmInitDeinitOK;
    return true;
  }else{
    STATUS() = scmPinInUse;
    return false;
  }
}

bool CRaspiProcessInterface::deinitialise(){
  CRaspiProcessInterface::smPinUsage[mPinNumber] = CRaspiProcessInterface::enUnused;
  mPinNumber = -1;
  STATUS() = scmInitDeinitOK;
  return true;
}

bool CRaspiProcessInterface::readPin(){
  if(-1 != mPinNumber){
    IN() = digitalRead(mPinNumber);
    return true;
  }else{
    STATUS() = scmNotInitialised;
  }
  return false;
}

bool CRaspiProcessInterface::writePin(){
  if(-1 != mPinNumber){
    digitalWrite(mPinNumber, OUT());
    return true;
  }else{
    STATUS() = scmNotInitialised;
  }
  return false;
}

bool CRaspiProcessInterface::checkPin(){
  if(mPinNumber > -1 && mPinNumber < 17){
    if(CRaspiProcessInterface::smPinUsage[mPinNumber] == CRaspiProcessInterface::enUnused){
      return true;
    }
  }
  return false;
}
