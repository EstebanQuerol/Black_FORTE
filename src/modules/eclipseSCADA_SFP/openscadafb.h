/*******************************************************************************
 * Copyright (c) 2007-2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef OPENSCADAFB_H_
#define OPENSCADAFB_H_

#include "funcbloc.h"
#include "openscadaserverhandler.h"

class COpenSCADAFB : public CFunctionBlock{
  public:
    virtual ~COpenSCADAFB();

    virtual bool writeDataPointDataRecieved(struct sfp_item * pa_pstItem, struct sfp_variant *pa_pstValue) = 0;

  protected:
    COpenSCADAFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
        const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);

    void allocateOpenScadaData(TForteUInt8 pa_unNumDIs, TForteUInt8 pa_unNumDOs);

    bool registerDataPoints(CIEC_STRING &pa_roBaseAddress, TForteUInt8 pa_unNumDIs, const CStringDictionary::TStringId* pa_cacDataInputNames, TIEC_ANYPtr pa_poDataInputs,
        TForteUInt8 pa_unNumDOs, const CStringDictionary::TStringId* pa_cacDataOutputNames, TIEC_ANYPtr pa_poDataOutputs);
    void unregisterDataPoints(TForteUInt8 pa_unNumDIs, TForteUInt8 pa_unNumDOs);



    bool m_bInitialized;
    TOpenSCADAItem *m_ppstInputItemList;
    TOpenSCADAItem *m_ppstOutputItemList;

  private:

};

#endif /* OPENSCADAFB_H_ */
