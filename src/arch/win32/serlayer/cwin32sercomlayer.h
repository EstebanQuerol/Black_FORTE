/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#include <comlayer.h>
#include <commfb.h>

#include <Windows.h>

#ifndef CWIN32SERCOMLAYER_H_
#define CWIN32SERCOMLAYER_H_

class CEventSourceFB;

class CWin32SerComLayer : public forte::com_infra::CComLayer{
  public:
    CWin32SerComLayer(forte::com_infra::CComLayer* pa_poUpperLayer, forte::com_infra::CCommFB * pa_poFB);
    virtual ~CWin32SerComLayer ();

    virtual forte::com_infra::EComResponse processInterrupt();

    virtual void closeConnection();
    virtual forte::com_infra::EComResponse sendData(void *pa_pvData, unsigned int pa_unSize);
    /*! \brief Perform reading from serial interface
     *
     * @return if not e_Nothing something was read and the FB should get an external event
     */
    virtual forte::com_infra::EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize);

  protected:
  private:
    virtual forte::com_infra::EComResponse openConnection(char *pa_acLayerParameter);
    HANDLE m_hSerial;
	static const unsigned int m_unMaxRecvBuffer = 22;

    forte::com_infra::EComResponse m_eInterruptResp;
    char m_acRecvBuffer[m_unMaxRecvBuffer];
    unsigned int m_unBufFillSize;

};

#endif /* CWIN32SERCOMLAYER_H_ */
