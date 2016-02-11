/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "pctimeha.h"
#include "../../core/devexec.h"
#include <time.h>
#include <sys/time.h>
#include "devlog.h"
void CTimerHandler::createTimerHandler(void){
  if(0 == sm_poFORTETimer) 
    sm_poFORTETimer = new CPCTimerHandler();
}

CPCTimerHandler::CPCTimerHandler(){
}

CPCTimerHandler::~CPCTimerHandler(){
  disableHandler();
}
//TODO: Change all the timeval structs for timespec
void CPCTimerHandler::run(){
  //Calculate time thread periodic cycle based on TICKS_PER_SECOND parameter configured in CMake
  struct timespec stReq;
  stReq.tv_sec = 0;
  stReq.tv_nsec = (1000000000 / getTicksPerSecond());
  if(stReq.tv_nsec < 1000){
	  //Time base under 1 us is not supported
	  DEVLOG_ERROR("TICKS_PER_SECOND greater than 1000000 are not supported");
	  stReq.tv_nsec = 1000;
  }
  struct timeval stReqTime;
  stReqTime.tv_sec = 0;
  stReqTime.tv_usec = stReq.tv_nsec / 1000;
  struct timeval stOldTime;
  struct timeval stNewTime;
  struct timeval stDiffTime;
  struct timeval stRemainingTime;
  timerclear(&stRemainingTime);

  struct timespec stAuxTime;
  clock_gettime(CLOCK_HOST_REALTIME, &stAuxTime);
  stOldTime.tv_sec = stAuxTime.tv_sec;
  stOldTime.tv_usec = stAuxTime.tv_nsec / 1000;

  while(isAlive()){

    nanosleep(&stReq, NULL);

    clock_gettime(CLOCK_HOST_REALTIME, &stAuxTime);
    stNewTime.tv_sec = stAuxTime.tv_sec;
    stNewTime.tv_usec = stAuxTime.tv_nsec / 1000;

    timersub(&stNewTime, &stOldTime, &stDiffTime);
    timeradd(&stRemainingTime, &stDiffTime, &stRemainingTime);
    while(!timercmp(&stRemainingTime, &stReqTime, <)){
      nextTick();
      timersub(&stRemainingTime, &stReqTime, &stRemainingTime);
    }
    stOldTime = stNewTime;  // in c++ this should work fine
  } 
}

void CPCTimerHandler::enableHandler(void){
  start();
}

void CPCTimerHandler::disableHandler(void){
  end(); 
}

void CPCTimerHandler::setPriority(int ){
  //TODO think on hwo to handle this.
}

int CPCTimerHandler::getPriority(void) const {
  //TODO think on hwo to handle this.
  return 1;
}
