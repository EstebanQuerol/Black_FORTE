/*
 * CPahoMqttComLayer.h
 *
 *  Created on: Jul 30, 2013
 *      Author: mmm
 */

#ifndef MQTTCOMLAYER_H_
#define MQTTCOMLAYER_H_

#include "comlayer.h"
extern "C" {
	#include <MQTTClient.h>
}

//fbdk[].mqtt[tcp://localhost:1883, ClientID, Topic]

using namespace forte::com_infra;

class MQTTComLayer: public forte::com_infra::CComLayer{
public:
	MQTTComLayer(CComLayer* pa_poUpperLayer, CCommFB * pa_poFB);
	virtual ~MQTTComLayer();

	EComResponse sendData(void* pa_pvData, unsigned int pa_unSize);

	EComResponse recvData(const void *pa_pvData, unsigned int pa_unSize);

	EComResponse processInterrupt();

	char const* getTopicName() {
		return mTopicName;
	}


protected:
	void closeConnection();

private:
	char* mTopicName;

    char dataBuffer[255];
    unsigned int bufferSize;
    EComResponse m_eInterruptResp;

	EComResponse openConnection(char* pa_acLayerParameter);

	enum Parameters {
		Address,
		ClientID,
		Topic
	};
};

#endif /* MQTTCOMLAYER_H_ */
