/*******************************************************************************
 * Copyright (c) 2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef CRITICALREGION_H_
#define CRITICALREGION_H_

#include <sync.h>

class CCriticalRegion{
  public:
    CCriticalRegion(CSyncObject &paSyncObject) : mSyncObject(paSyncObject){
      mSyncObject.lock();
    }

    ~CCriticalRegion(){
      mSyncObject.unlock();
    }

  private:
    CSyncObject &mSyncObject;

};



#endif /* CRITICALREGION_H_ */
