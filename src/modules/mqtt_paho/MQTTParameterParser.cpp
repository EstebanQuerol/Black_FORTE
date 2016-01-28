/*
 * MQTTParameterParser.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: mmm
 */

#include <MQTTParameterParser.h>
#include <string.h>
#include <cctype>

MQTTParameterParser::MQTTParameterParser(char* paParameters) : mParameters(paParameters) {
	mCurrentParameter = 0;
}

MQTTParameterParser::~MQTTParameterParser() {
	// TODO Auto-generated destructor stub
}

void MQTTParameterParser::setSeparator(char paSeparator) {
	mSeparator = paSeparator;
}

void MQTTParameterParser::parseParameters() {
	parsePosition = mParameters;
	for(int i = 0; i < mAmountOfParameters; ++i) {
		moveToPositionOfFirstNonWhiteSpaceCharacter();
		saveStartPositionForParameterSubstring(i);
		moveToPositionOfNextParameterSeparatorOrEndOfString();
		trimTrailingWhiteSpacesOfParameterSubstring();
		moveToNextParameterStart();
	}
}

void MQTTParameterParser::moveToPositionOfFirstNonWhiteSpaceCharacter() {
	while (0 != isspace(*parsePosition)) {
		++parsePosition;
	}
}

void MQTTParameterParser::saveStartPositionForParameterSubstring(int paParameterNumber) {
	mParameterSeparators[paParameterNumber] = parsePosition;
}

void MQTTParameterParser::moveToPositionOfNextParameterSeparatorOrEndOfString() {
	while (mSeparator != *parsePosition && '\0' != *parsePosition) {
		++parsePosition;
	}
}

void MQTTParameterParser::trimTrailingWhiteSpacesOfParameterSubstring() {
	char* backTraceCharacter = parsePosition;
	*backTraceCharacter = ' ';
	while( 0 != isspace(*backTraceCharacter) ) {
		--backTraceCharacter;
	}
	backTraceCharacter++;
	*backTraceCharacter = '\0';
}

void MQTTParameterParser::moveToNextParameterStart() {
	++parsePosition;
}

void MQTTParameterParser::moveToNextParameter() {
	mCurrentParameter < mAmountOfParameters ? ++mCurrentParameter: mCurrentParameter;
}

char* MQTTParameterParser::getCurrentParameter() {
	return mParameterSeparators[mCurrentParameter];
}

char* MQTTParameterParser::MQTTParameterParser::operator [](const int& index) {
	return mParameterSeparators[index];
}
