/*******************************************************************************
 * Copyright (c) 2007-2014 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef PROCESSINTERFACE_H_
#define PROCESSINTERFACE_H_

#include <../../stdfblib/io/processinterfacebase.h>
#include <GPIO/GPIOManager.h>


class CBBBProcessInterface : public CProcessInterfaceBase{
  public:
    CBBBProcessInterface(CResource *paSrcRes, const SFBInterfaceSpec *paInterfaceSpec,
        const CStringDictionary::TStringId paInstanceNameId, TForteByte *paFBConnData, TForteByte *paFBVarsData);
    virtual ~CBBBProcessInterface();

  protected:
    bool initialise(bool paInput);
    bool deinitialise();
    bool readPin();
    bool writePin();

  private:
    static bool checkPin(int paPinNum, bool paDirection);

    GPIO::GPIOManager* mGPManager;
    int mPin;
};

//tell the IX and QX FB that this is the process interface to be used
typedef CBBBProcessInterface CProcessInterface;

#endif /* PROCESSINTERFACE_H_ */
