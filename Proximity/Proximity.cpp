#include "Arduino.h"
#include "Proximity.h"
Proximity::Proximity() {
}

bool Proximity::close() {
	delay(200);
	digitalWrite(25, HIGH);
	delay(50);
	int IR = analogRead(A8);
	digitalWrite(25, LOW);
	IR = map(IR, 930, 970, 0, 100);
	return IR > _threshold;
}

void Proximity::begin(int threshold) {
	pinMode(25, OUTPUT);
	digitalWrite(25, LOW);
	_threshold = threshold;
}

void Proximity::setThreshold(int threshold) {
	_threshold = threshold;
}
int Proximity::getThreshold() {
	return _threshold;
}