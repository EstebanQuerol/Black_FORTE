/*
 * MQTTHandler.h
 *
 *  Created on: Feb 7, 2014
 *      Author: mmm
 */

#ifndef MQTTHANDLER_H_
#define MQTTHANDLER_H_

#include <singlet.h>
#include <extevhan.h>
#include <fortelist.h>
#include <MQTTComLayer.h>
#include "sync.h"

extern "C" {
#include <MQTTClient.h>
}

class MQTTHandler : public CExternalEventHandler {
	DECLARE_SINGLETON(MQTTHandler)
public:
	enum RegisterLayerReturnCodes {
		eRegisterLayerSucceeded,
		eWrongClientID,
		eConnectionFailed
	};
	int registerLayer(char* paAddress, char* paClientId, MQTTComLayer* paLayer);

	void unregisterLayer(MQTTComLayer* paLayer);

	MQTTClient& getClient(void) {
		return client;
	}

	void mqttMessageProcessed(void);

    virtual void enableHandler(void);
    /*!\brief Disable this event source
     */
    virtual void disableHandler(void);
    /*!\brief Sets the priority of the event source
     *
     * \param pa_nPriority new priority of the event source
     */
    virtual void setPriority(int pa_nPriority);
    /*!\brief Get the current priority of the event source
     *
     * \return current priority
     */
    virtual int getPriority(void) const;

    static int mqttMessageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message);

private:
    static char* mClientId;
    static char* mAddress;

    static CSyncObject mLockMessageDelivery;

    static MQTTClient client;
    static MQTTClient_connectOptions clientConnectionOptions;

    CSinglyLinkedList<MQTTComLayer*> layers;


};

#endif /* MQTTHANDLER_H_ */
