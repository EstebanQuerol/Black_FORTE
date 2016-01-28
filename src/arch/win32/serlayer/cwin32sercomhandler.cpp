/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include "cwin32sercomhandler.h"
#include "cwin32sercomlayer.h"
#include <devlog.h>
#include <devexec.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

DEFINE_SINGLETON(CWin32SerComHandler);

CWin32SerComHandler::CWin32SerComHandler(){
}

CWin32SerComHandler::~CWin32SerComHandler(){
  this->end();
}

void CWin32SerComHandler::registerSerComLayer(CWin32SerComLayer *pa_poComLayer){
  m_oSync.lock();
  m_lstComLayerList.push_back(pa_poComLayer);
  m_oSync.unlock();
  if(!isAlive()){
    this->start();
  }
  resumeSelfSuspend();
}

void CWin32SerComHandler::unregisterSerComLayer(CWin32SerComLayer *pa_poComLayer){
  m_oSync.lock();

  TCWin32SerComLayerContainer::Iterator itRunner(m_lstComLayerList.begin());
  TCWin32SerComLayerContainer::Iterator itRefNode(m_lstComLayerList.end());
  TCWin32SerComLayerContainer::Iterator itEnd(m_lstComLayerList.end());

  while(itRunner != itEnd){
    if(*itRunner == pa_poComLayer){
      if(itRefNode == itEnd){
        m_lstComLayerList.pop_front();
      }
      else{
        m_lstComLayerList.eraseAfter(itRefNode);
      }
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }
  m_oSync.unlock();
}

void CWin32SerComHandler::run(){
  while(isAlive()){

    if(true == m_lstComLayerList.isEmpty()){
      selfSuspend();
    }

    m_oSync.lock();
    TCWin32SerComLayerContainer::Iterator itEnd(m_lstComLayerList.end());
    for(TCWin32SerComLayerContainer::Iterator itRunner = m_lstComLayerList.begin(), itCurrent = m_lstComLayerList.begin(); itRunner != itEnd;){
      itCurrent = itRunner;
      ++itRunner;

      m_oSync.unlock();
      if(forte::com_infra::e_Nothing != (*itCurrent)->recvData(0,0)){
        startNewEventChain((*itCurrent)->getCommFB());
      }
      m_oSync.lock();
    }
    m_oSync.unlock();
    Sleep(1);
  }

}
