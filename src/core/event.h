/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _EVENT_H_
#define _EVENT_H_

#include "../arch/datatype.h"


//forward declaration of a few classes to reduce includefile dependencies
class CFunctionBlock;

struct SConnectionPoint;

/*! \ingroup CORE\brief Datatype for holding the IDs of event inputs.
 *
 *  With the current implementation at max 255 event inputs per FB are possible.
 *  That should be enough.
 */
typedef TForteUInt8 TEventID;

//!\ingroup CORE Constant for the invalid event input id
const TEventID cg_nInvalidEventID = cg_unInvalidPortId;
//!\ingroup CORE Constant for the invalid event input id
const TEventID cg_nExternalEventID = 254;

//!\brief With this marker events are anotated that are from the internals of a CFB to the interface of the CFB
const TPortId cgInternal2InterfaceMarker = 0x100;

const TPortId cgInternal2InterfaceRemovalMask = 0xFF;

/*!\ingroup CORE \brief Structure to hold the information needed for delivering input events to FBs.
*/
typedef SConnectionPoint SEventEntry;

typedef SEventEntry *TEventEntryPtr;

#endif /*_EVENT_H_*/
