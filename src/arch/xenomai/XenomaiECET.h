/*
 * XenomaiECET.h
 *
 *  Created on: 18 mar. 2017
 *      Author: Esteban Querol
 * Description: Extended class from XEventChainExecutionThread from 4DIAC which allows
 * 				using xenomai RT capabilities
 */

#ifndef _XENOMAIECET_H_
#define _XENOMAIECET_H_

#include <ecet.h>
#include "../devlog.h"

class CXenomaiECET: public CEventChainExecutionThread {
public:
	CXenomaiECET();
	virtual ~CXenomaiECET();
	void clear(void);
	/**
	 * !\brief allow to start, stop, and kill the execution of the event chain execution thread
     * @param pa_unCommand the management command to be executed
     * @param pa_unPolicy Xenomai thread scheduling policy
     * @param pa_unPriority Xenomai thread priority
     */
    void changeExecutionState(EMGMCommandType pa_unCommand, uint pa_nPolicy, uint pa_nPriority);

	/**
	 * !\brief allow to to modify the scheduling policy and priority of the execution of the event chain execution thread
     * @param pa_unPolicy Xenomai thread scheduling policy
     * @param pa_unPriority Xenomai thread priority
     */
    void changeThreadAttributes(uint pa_nPolicy, uint pa_nPriority);
};

#endif /* _XENOMAIECET_H_ */
