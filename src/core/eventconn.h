/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _EVENCONN_H_
#define _EVENCONN_H_

#include "conn.h"
#include "event.h"
#include "fortelist.h"

class CEventChainExecutionThread;

/*!\ingroup CORE \brief Class for handling an event connection.
 *
 */
class CEventConnection : public CConnection{
  public:
    CEventConnection(CFunctionBlock *paSrcFB, TPortId paSrcPortId);

    virtual ~CEventConnection();

    virtual EMGMResponse connect(CFunctionBlock *paDstFB, CStringDictionary::TStringId paDstPortNameId);

    virtual EMGMResponse connectToCFBInterface(CFunctionBlock *paDstFB, CStringDictionary::TStringId paDstPortNameId);

#ifndef FORTE_CLASS_0
    virtual EMGMResponse disconnect(CFunctionBlock *paDstFB, CStringDictionary::TStringId paDstPortNameId);
#endif

    /*! \brief Triggers the event connection and all destinations are notified.
     *
     *
     *  \param pa_poExecEnv Pointer to the execution environment the event is sent in.
     */
    void triggerEvent(CEventChainExecutionThread &pa_poExecEnv);
  protected:

  private:

};

typedef CEventConnection *TEventConnectionPtr;

#endif /*_EVENCONN_H_*/
