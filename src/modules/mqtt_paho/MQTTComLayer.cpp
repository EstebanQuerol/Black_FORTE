/*
 * CPahoMqttComLayer.cpp
 *
 *  Created on: Jul 30, 2013
 *      Author: mmm
 */

#include "MQTTComLayer.h"
#include "MQTTParameterParser.h"
#include "MQTTHandler.h"
#include "commfb.h"
#include <unistd.h>

#define QOS 1

using namespace forte::com_infra;

MQTTComLayer::MQTTComLayer(CComLayer* pa_poUpperLayer, CCommFB * pa_poFB) : CComLayer(pa_poUpperLayer, pa_poFB) {
	// TODO Auto-generated constructor stub

}

MQTTComLayer::~MQTTComLayer() {
	// TODO Auto-generated destructor stub
}

EComResponse MQTTComLayer::sendData(void* pa_pvData,
		unsigned int pa_unSize) {

	MQTTClient_deliveryToken token;
	MQTTClient_message message = MQTTClient_message_initializer;
	message.payload = pa_pvData;
	message.payloadlen = pa_unSize;
	message.qos = QOS;
	message.retained = 0;
	int errorCode = MQTTClient_publishMessage(MQTTHandler::getInstance().getClient(), mTopicName, &message, NULL);
	if (0 != errorCode) {
		return e_ProcessDataSendFailed;
	}
	//while(deliveredtoken != token);
	return e_ProcessDataOk;
}

EComResponse MQTTComLayer::recvData(const void* pa_pvData,
		unsigned int pa_unSize) {
	memcpy(dataBuffer, pa_pvData, pa_unSize);
	bufferSize = pa_unSize;
	m_eInterruptResp = e_ProcessDataOk;
	m_poFb->interruptCommFB(this);
	return m_eInterruptResp;

}

EComResponse MQTTComLayer::processInterrupt() {
	if(e_ProcessDataOk == m_eInterruptResp) {
		if((0 < bufferSize) && (0 != m_poTopLayer)) {
			m_eInterruptResp = m_poTopLayer->recvData(dataBuffer, bufferSize);
			bufferSize = 0;
			//MQTTHandler::getInstance().mqttMessageProcessed();
		}
	}
	return m_eInterruptResp;
}

void MQTTComLayer::closeConnection() {
	MQTTHandler::getInstance().unregisterLayer(this);
}

EComResponse MQTTComLayer::openConnection(char* pa_acLayerParameter) {
	EComResponse eRetVal = e_InitTerminated;
	MQTTParameterParser parser(pa_acLayerParameter);
	parser.setSeparator(',');
	parser.parseParameters();
	mTopicName = (char*)malloc(strlen(parser[Topic]) + 1);
	mTopicName = strcpy(mTopicName, parser[Topic]);
	if( MQTTHandler::eRegisterLayerSucceeded ==
			(MQTTHandler::getInstance()).registerLayer(parser[Address], parser[ClientID], this)) {
		eRetVal = e_InitOk;
	}
	else eRetVal = e_InitInvalidId;

	switch (m_poFb->getComServiceType()){
	case e_Server:
		// TODO: Not implemented yet
		eRetVal = e_InitTerminated;
		break;
	case e_Client:
		// TODO: Not implemented yet
		eRetVal = e_InitTerminated;
		break;
	case e_Publisher:
		//is handled via sendData
		break;
	case e_Subscriber:
		MQTTClient_subscribe(MQTTHandler::getInstance().getClient(), mTopicName, QOS);
		break;
	}

	return eRetVal;
}

