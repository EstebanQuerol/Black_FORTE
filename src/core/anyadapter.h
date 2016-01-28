/*******************************************************************************
 * Copyright (c) 2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef ANYADAPTER_H_
#define ANYADAPTER_H_

#include "adapter.h"

/*! \brief A generic adapter that behaves similar to the ANY data type and allows all other adapters to be connected.
 *
 *  The main use of such an adapter is in service interfaces that provide generic services based on the adapter connected.
 */

class CAnyAdapter : public CAdapter{
  DECLARE_ADAPTER_TYPE(CAnyAdapter)

  public:
    CAnyAdapter(CStringDictionary::TStringId pa_anAdapterInstanceName, CResource *pa_poSrcRes, bool pa_bIsPlug);
    virtual ~CAnyAdapter();

    virtual bool connect(CAdapter *pa_poPeer, CAdapterConnection *pa_poAdConn);
    virtual bool disconnect(CAdapterConnection *pa_poAdConn);

    //! Helper functions allowing to retrieve interface information from any_adpaters TODO look for Doxygen grouping syntax
    TForteUInt8 getNumEIs(){
      return m_pstInterfaceSpec->m_nNumEIs;
    }

    const TForteInt16* getEIWithIndexes(){
      return m_pstInterfaceSpec->m_anEIWithIndexes;
    }

    const TDataIOID* getEIWiths(){
      return m_pstInterfaceSpec->m_anEIWith;
    }

    TForteUInt8 getNumDIs(){
      return m_pstInterfaceSpec->m_nNumDIs;
    }

    const CStringDictionary::TStringId* getDataInputNames(){
      return m_pstInterfaceSpec->m_aunDINames;
    }

    TIEC_ANYPtr getDataInputs(){
      return getDI(0);
    }

    TForteUInt8 getNumDOs(){
      return m_pstInterfaceSpec->m_nNumDOs;
    }

    const CStringDictionary::TStringId* getDataOutputNames(){
      return m_pstInterfaceSpec->m_aunDONames;
    }

    TIEC_ANYPtr getDataOutputs(){
      return getDO(0);
    }

  protected:

  private:
    static const SFBInterfaceSpec scm_stFBInterfaceSpec;  //! interface spec for the empty interface of an any adapter will be used for plug and socket

    //!Interface specification to be used when configured
    SFBInterfaceSpec m_stCurrentFBInterfaceSpec;
};

#endif /* ANYADAPTER_H_ */
