/*
 * MQTTParameterParser.h
 *
 *  Created on: Feb 17, 2014
 *      Author: mmm
 */

#ifndef MQTTPARAMETERPARSER_H_
#define MQTTPARAMETERPARSER_H_

//mqtt[tcp://localhost:1883, ClientID, Topic]

class MQTTParameterParser {
public:
	MQTTParameterParser(char* paParameters);
	virtual ~MQTTParameterParser();

	void setSeparator(char paSeparator);
	void parseParameters();
	void moveToNextParameter();
	char* getCurrentParameter();

	char* operator[](int const& index);


private:
	static int const mAmountOfParameters = 3;
	int mCurrentParameter;
	char* mParameterSeparators[mAmountOfParameters];
	char mSeparator;
	char* const mParameters;

	char* parsePosition;

	void moveToPositionOfFirstNonWhiteSpaceCharacter();
	void saveStartPositionForParameterSubstring(int paParameterNumber);
	void moveToPositionOfNextParameterSeparatorOrEndOfString();
	void trimTrailingWhiteSpacesOfParameterSubstring();
	void moveToNextParameterStart();
};

#endif /* MQTTPARAMETERPARSER_H_ */
