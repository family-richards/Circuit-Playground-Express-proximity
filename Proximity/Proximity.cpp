#include "Arduino.h"
#include "Proximity.h"
Proximity::Proximity() {
	pinMode(25, OUTPUT);
	digitalWrite(25, LOW);
	pinMode(A8, INPUT);
}

bool Proximity::close() {
	delay(200);
	digitalWrite(25, HIGH);
	delay(50);
	int IR = analogRead(A8);
	digitalWrite(25, LOW);
	IR = map(IR, 930, 970, 0, 100);
	return IR > 70;
}