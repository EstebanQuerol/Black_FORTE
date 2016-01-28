/*******************************************************************************
 * Copyright (c) 2007 - 2015 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef CKBUSFB_H_
#define CKBUSFB_H_

#include <esfb.h>
#include <ldkc_kbus_information.h>

class CKBusHandler;

/*! \brief Base class for all KBus I/O Function Blocks
 *
 * This class provides nearly all logic required for the I/O FBs, which should reduce
 * the effort to add a new one for an I/O module. In order to achieve this some assumptions
 * are made:
 *  - Each FB has at least an INIT and REQ event input and an INITO CNF event output
 *  - Each FB has an QI, Slot<USINT> data input, and an QO data output
 *  - Output FBs will transfer their input data on REQ (handled by this class)
 *  - Input FBs have in addition an IND at the third place. The behavior is as follows
 *     - If the input data changes an IND output event is sent
 *     - On request the latest data values received in the last KBus cycle are sampled to
 *       the output connections
 *
 * If a different behavior is required the FBs need to overwrite the execute event and change
 * the behavior as appropriate
 *
 */
class CKBusFB : public CEventSourceFB{
  public:
    CKBusFB(CResource *pa_poSrcRes,
        const SFBInterfaceSpec *pa_pstInterfaceSpec,
        const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData,
        TForteByte *pa_acFBVarsData);
    virtual ~CKBusFB();

    /*! \brief call back from KBus handler informing that a kbus cycle has happend.
     *
     * Check if input data needs to be updated and IND output event needs to be send.
     *
     * @return true if an IND output event needs to be send
     */
    bool onKBusCylce(CKBusHandler &pa_roKBusHandler);

  protected:
    virtual void executeEvent(int pa_nEIID);

    //! Notification function for the specific FB to take the data from the indata array and apply it to its output points
    virtual void applyKBusInputData() = 0;
    //! Function for the specific FB to update the kbus output data array from the FB's data input points
    virtual void udpateKBusOutputData() = 0;
    virtual bool checkTerminalId(u16 pa_unTerminalId) = 0;

    tldkc_KbusInfo_TerminalInfo *m_pstTerminalInfo;
    TForteByte *m_acIndata;
    TForteByte *m_acOutdata;

  private:
    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventREQID = 1;

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventCNFID = 1;
    static const TEventID scm_nEventINDID = 2;

    CIEC_BOOL& QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }

    CIEC_USINT& SLOT(){
      return *static_cast<CIEC_USINT*>(getDI(1));
    }

    CIEC_BOOL& QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }

    void handleINIT();
    void handleREQ();
    void handleExternalEvent();

    void initialize();
    void deInitialize();
    void allocateIOData();

    unsigned int getInputDataSize(){
      return (m_pstTerminalInfo->SizeInput_bits / 8) + ((0 != (m_pstTerminalInfo->SizeInput_bits % 8)) ? 1 : 0);
    }

    unsigned int getOutputDataSize(){
      return (m_pstTerminalInfo->SizeOutput_bits / 8) + ((0 != (m_pstTerminalInfo->SizeOutput_bits % 8)) ? 1 : 0);
    }

    bool m_bInitialized;

};

#endif /* CKBUSFB_H_ */
