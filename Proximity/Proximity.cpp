#include "Arduino.h"
#include "Proximity.h"
Proximity::Proximity() {
}

bool Proximity::close() {
	//Avoid overheating when called in repeating loop w/ no delay
	delay(200);
	//Turn on IR LED
	digitalWrite(25, HIGH);
	delay(50);
	//Get reading
	IR = analogRead(A8);
	//Turn off IR LED
	digitalWrite(25, LOW);
	//Make reading a more reasonable number
	IR = map(IR, 930, 970, 0, 100);
	return IR > _threshold;
}

void Proximity::begin(int threshold) {
	//Setup IR LED pin
	pinMode(25, OUTPUT);
	digitalWrite(25, LOW);
	//Set threshold
	_threshold = threshold;
}

void Proximity::setThreshold(int threshold) {
	//Set the threshold
	_threshold = threshold;
}

int Proximity::getThreshold() {
	//Get the threshold
	return _threshold;
}

int Proximity::lastDist() {
	return IR;
}

//Declare Proximity object
Proximity prox;
