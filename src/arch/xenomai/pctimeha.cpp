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

void CPCTimerHandler::run(){
  //Calculate time handler thread period based on TICKS_PER_SECOND parameter configured in CMake
  struct timespec stPeriod;
  stPeriod.tv_sec = 0;
  stPeriod.tv_nsec = (1000000000 / getTicksPerSecond());
  if(stPeriod.tv_nsec < 1){
	  //Time base under 1 ns is not supported
	  DEVLOG_ERROR("TICKS_PER_SECOND greater than 1000000000 are not supported");
	  stPeriod.tv_nsec = 1;
  }
  //Make this thread periodic
  unsigned long nOverRuns;
  struct timespec stAuxTime;
  clock_gettime(CLOCK_REALTIME, &stAuxTime);
  stAuxTime.tv_nsec += 100000;
  pthread_t oThreadId = pthread_self();
  if(oThreadId != 0){
	  if(pthread_make_periodic_np(oThreadId,&stAuxTime,&stPeriod)!= 0){
		  DEVLOG_ERROR("Error could not set time handler thread period! %s\n", strerror(errno));
		  return;
	  }
  }

  while(isAlive()){
	//TODO: Handle overruns
    nextTick();
    pthread_wait_np(&nOverRuns);
  }
}

void CPCTimerHandler::enableHandler(void){
	start(SCHED_FIFO,sched_get_priority_max(SCHED_FIFO));
}

void CPCTimerHandler::disableHandler(void){
	end();
}

void CPCTimerHandler::setPriority(int ){
  //TODO think on how to handle this.
}

int CPCTimerHandler::getPriority(void) const {
  //TODO think on how to handle this.
  return 1;
}
