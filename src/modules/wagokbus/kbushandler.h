/*******************************************************************************
 * Copyright (c) 2007 - 2013 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef KBUSHANDLER_H_
#define KBUSHANDLER_H_

#include <extevhan.h>
#include <thread.h>
#include <sync.h>
#include <singlet.h>
#include <fortelist.h>

#define OS_MUST_BE_ARRAY

extern "C" {
#include <dal/adi_application_interface.h>
#include <ldkc_kbus_information.h>
#include <ldkc_kbus_register_communication.h>
}

//forward declaration in order to avoid cyclic include files
class CKBusFB;

class CKBusHandler : public CExternalEventHandler, public CThread{
  DECLARE_SINGLETON(CKBusHandler)

  public:
    //!KBus interface handling is up and running correctly
    bool isKBusRunning();

    tldkc_KbusInfo_TerminalInfo *getTerminalInfo(TForteUInt8 pa_unSlot);
    u16 getTerminalId(TForteUInt8 pa_unSlot);

    void registerKBusReadFB(CKBusFB *pa_poFB);
    void unregisterKBusReadFB(CKBusFB *pa_poFB);

    void writeOutputDataToKBus(TForteByte *pa_acDta, tldkc_KbusInfo_TerminalInfo *pa_pstTerminal);
    TForteByte *readInputDataFromKBus(tldkc_KbusInfo_TerminalInfo *pa_pstTerminal);

    /* functions needed for the external event handler interface */
    void enableHandler(void);

    void disableHandler(void);

    void setPriority(int pa_nPriority);

    int getPriority(void) const;

  private:
    static const tDeviceId scm_nInvalidDeviceId = -1; //Valid device ids are always greater than 0

    virtual void run();

    /*!Go through the read list notifying the registered FBs on the new cycle allowing
     * them to update their data and if necessary activate an event chain
     */
    void updateReadData();
    void closeKBusInterface();
    bool triggerKBusCycle();
    bool loadTerminalInformation();

    tApplicationDeviceInterface * m_pstAppDevInterface;
    uint32_t m_unTaskId;
    tDeviceId m_nKBusDeviceId;

    /*KBus Terminal information */
    size_t m_unTerminalCount;
    u16 m_aunTerminalIds[LDKC_KBUS_TERMINAL_COUNT_MAX];
    tldkc_KbusInfo_TerminalInfo m_astTerminalDescription[LDKC_KBUS_TERMINAL_COUNT_MAX];

    //List data for registered read FBs
    typedef CSinglyLinkedList<CKBusFB *> TReadFBContainer;

    TReadFBContainer m_lstReadFBList;
    CSyncObject m_oReadFBListSync;


    static const unsigned int scm_unMaxTerminalInputData = 16;   //!< max number of bytes of input data per terminal
    TForteByte m_acInputDataBuffer[scm_unMaxTerminalInputData];
};

#endif /* KBUSHANDLER_H_ */
