/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef SOCKHAND_H_
#define SOCKHAND_H_

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#include <winsock2.h>
#include <windows.h>
#include <Ws2tcpip.h>
//these include needs to be last
#include "../fdselecthand.h"
#include "../bsdsocketinterf.h"
#include "../gensockhand.h"

typedef CGenericIPComSocketHandler<CFDSelectHandler, CBSDSocketInterface> CIPComSocketHandler;

#endif /* SOCKHAND_H_ */
