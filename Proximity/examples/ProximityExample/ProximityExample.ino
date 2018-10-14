#include <Adafruit_CircuitPlayground.h>
#include <Proximity.h>

Proximity prox;

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif

void setup() {
  //Setup everything
  CircuitPlayground.begin();
  while (!Serial);
  Serial.begin(19200);
  //Change this number for your sensitivity, make higher if always says "Close to object", make lower if you can't get it to say "Close to object".
  prox.begin(71);
}
int IR;
void loop() {
  if (prox.close()) {
    Serial.print("Close to object, threshold is ");
    Serial.println(String(prox.getThreshold()));
  } else {
    Serial.print("Not close to object, threshold is ");
    Serial.println(String(prox.getThreshold()));
  }
  delay(250);
}