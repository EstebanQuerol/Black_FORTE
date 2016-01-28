/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_RESTART_H_
#define _E_RESTART_H_

#include "../core/esfb.h"
#include "../core/resource.h"

/*! \brief Implementation of the E_RESTART FB.
 */

class E_RESTART : public CEventSourceFB{
  DECLARE_FIRMWARE_FB(E_RESTART)
private:
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(3,0,0, 0);

  static const TEventID csmCOLDID = 0;
  static const TEventID csmWARMID = 1;
  static const TEventID csmSTOPID = 2;

  static const CStringDictionary::TStringId scm_aunEONameIds[];

  bool m_bStartedOnce;

  TEventID mEventToSend;

  virtual void executeEvent(int pa_nEIID);

public:
  EVENT_SOURCE_FUNCTION_BLOCK_CTOR(E_RESTART),
        mEventToSend(cg_nInvalidEventID) {
    setEventChainExecutor(pa_poSrcRes->getResourceEventExecution());
  }
	virtual ~E_RESTART() {};

	virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);
};

#endif /*E_RESTART_H_*/
