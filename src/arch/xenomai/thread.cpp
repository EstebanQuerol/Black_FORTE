/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "thread.h"
#include "../devlog.h"
#include <errno.h>
#include <cstring>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <criticalregion.h>

void CXenomaiThread::start(void){
	 // Get new Thread
	  if(0 == m_stThreadID){

	    //If the stackSize is not 0 we have to set it
	    if(m_nStackSize){
	      pthread_attr_t stAttr;

	      if(pthread_attr_init(&stAttr)){
	        DEVLOG_ERROR("Error could not get the default thread attributes! %s\n", strerror(errno));
	        return;
	      }
	      if(pthread_attr_setstack(&stAttr, m_pacStack, m_nStackSize)){
	        DEVLOG_ERROR("Error could not set the stacksize for the thread! %s\n", strerror(errno));
	        return;
	      }
	      if(__real_pthread_create(&m_stThreadID, &stAttr, threadFunction, this)){
	        DEVLOG_ERROR("Error could not create the thread! %s\n", strerror(errno));
	        return;
	      }
	      if(pthread_attr_destroy(&stAttr)){
	        DEVLOG_ERROR("Error could not free the thread attributes! %s\n", strerror(errno));
	        return;
	      }
	    }
	    else{
	      if(__real_pthread_create(&m_stThreadID, NULL, threadFunction, this)){
	        DEVLOG_ERROR("Error could not create the thread! %s\n", strerror(errno));
	        return;
	      }
	    }
	  }
	  //wait till the thread is up and running
	  do{
	    //pthread_yield();
	    sleep(1);
	  }while(!isAlive());
}

void CXenomaiThread::start(int pa_nPolicy, int pa_nPriority){
	// Get new Thread
	if(0 == m_stThreadID){
		int l_nPolicy = pa_nPolicy;
		int l_nPriority = pa_nPriority;
		//Check input parameters
		if(l_nPriority < 0 || l_nPriority > 99){
			DEVLOG_ERROR("Error RT thread priority is not within [0-99]. Default is 99 %s\n");
			l_nPriority = 99;
		}
		if(l_nPolicy != SCHED_FIFO && l_nPolicy != SCHED_RR){
			DEVLOG_ERROR("Error RT thread policy is unknown. Default is FIFO %s\n");
			l_nPolicy = SCHED_FIFO;
		}
		struct sched_param sParam;
		sParam.__sched_priority = l_nPriority;
		pthread_attr_t stAttr;
		if(pthread_attr_init(&stAttr)){
			DEVLOG_ERROR("Error could not get the default thread attributes! %s\n", strerror(errno));
			return;
		}
		//Change inheritance policy
		if(pthread_attr_setinheritsched(&stAttr, PTHREAD_EXPLICIT_SCHED)){
			DEVLOG_ERROR("Error could not disable thread attribute inheritance! %s\n", strerror(errno));
			return;
		}
		//Change scheduler policy
		if(pthread_attr_setschedpolicy(&stAttr, l_nPolicy)){
			DEVLOG_ERROR("Error could not set the scheduler policy for the thread! %s\n", strerror(errno));
			return;
		}
		//Change thread priority
		if(pthread_attr_setschedparam(&stAttr, &sParam)){
			DEVLOG_ERROR("Error could not set the priority for the thread! %s\n", strerror(errno));
		return;
		}
		//If the stackSize is not 0 we have to set it
		if(m_nStackSize){
		  if(pthread_attr_setstack(&stAttr, m_pacStack, m_nStackSize)){
			DEVLOG_ERROR("Error could not set the stacksize for the thread! %s\n", strerror(errno));
			return;
		  }
		}
		if(pthread_create(&m_stThreadID, &stAttr, threadFunction, this)){
			DEVLOG_ERROR("Error could not create the thread! %s\n", strerror(errno));
			return;
		}
		if(pthread_attr_destroy(&stAttr)){
			DEVLOG_ERROR("Error could not free the thread attributes! %s\n", strerror(errno));
			return;
		}
	}
	//wait till the thread is up and running
	do{
		//pthread_yield();
		sleep(1);
	}while(!isAlive());
}

void * CXenomaiThread::threadFunction(void *arguments){
  // Get pointer to CThread object out of void pointer
	CXenomaiThread *pThread = (CXenomaiThread *) arguments;

  // if pointer is ok
  if(0 != pThread){
    CCriticalRegion criticalRegion(pThread->mJoinMutex);
    pThread->m_bAlive = true;
    pThread->run();
    pThread->m_bAlive = false;
    pThread->m_stThreadID = 0;
  }
  else{
    DEVLOG_ERROR("pThread pointer is 0!");
  }
  return 0;
}

CXenomaiThread::CXenomaiThread(long pa_nStackSize) :
  m_bAlive(false), m_stThreadID(0), m_nStackSize(pa_nStackSize), m_pacStack(0){

  if(0 != m_nStackSize){
    m_pacStack = new char[m_nStackSize];
  }

  if(-1 == sem_init(&m_stSuspendSemaphore, 0, 0)){
    DEVLOG_ERROR("Could not initialize suspend sempaphore: %s\n", strerror(errno));
  }
}

CXenomaiThread::~CXenomaiThread(){
  if(0 != m_stThreadID){
    end();
  }
  if(0 != m_nStackSize){
    delete[] m_pacStack;
  }
  sem_destroy(&m_stSuspendSemaphore);
}

void CXenomaiThread::setDeadline(const CIEC_TIME &pa_roVal){
  m_oDeadline = pa_roVal;
  //under the posix pthread implemention currently it makes no sense to set any priority.
  //It will not be considered.
}

void CXenomaiThread::resumeSelfSuspend(void){
  sem_post(&m_stSuspendSemaphore);
}

void CXenomaiThread::join(void){
  if(0 != m_stThreadID){
    CCriticalRegion criticalRegion(mJoinMutex);
  }
}

void CXenomaiThread::selfSuspend(void) {
  int n;
  do{
    n = sem_wait(&m_stSuspendSemaphore);
  }while( (-1 == n) && (errno == EINTR) );  //handle interrupts from signals
}
