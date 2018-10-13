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
	return IR > 80;
}

void Proximity::setup() {
	pinMode(25, OUTPUT);
	digitalWrite(25, LOW);
}