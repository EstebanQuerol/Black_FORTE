/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef SOCKHAND_H_
#define SOCKHAND_H_


#include <sockLib.h>
#include <selectLib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//these include needs to be last
#include "../fdselecthand.h"
#include "../bsdsocketinterf.h"
#include "../gensockhand.h"

typedef CGenericIPComSocketHandler<CFDSelectHandler, CBSDSocketInterface> CIPComSocketHandler;

#endif /* SOCKHAND_H_ */
