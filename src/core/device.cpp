/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "device.h"
#include "resource.h"
#include "if2indco.h"

EMGMResponse CDevice::executeMGMCommand(forte::core::SManagementCMD &pa_oCommand){
  EMGMResponse retval = e_INVALID_DST;

  if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.mDestination){
    retval = CResource::executeMGMCommand(pa_oCommand);
  }
  else{
    CResource *res = (CResource *)CFBContainer::getFB(pa_oCommand.mDestination);
    if(0 != res){
      pa_oCommand.mDestination = CStringDictionary::scm_nInvalidStringId;
      retval = res->executeMGMCommand(pa_oCommand);
    }
  }
  return retval;
}


