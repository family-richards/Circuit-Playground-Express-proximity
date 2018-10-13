#include <Adafruit_CircuitPlayground.h>
#include <Proximity.h>

Proximity prox();

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif

void setup() {
  //Setup everything
  CircuitPlayground.begin();
  while (!Serial);
  Serial.begin(19200);
}
int IR;
void loop() {
  if (prox.close()) {
    Serial.println("Close to object");
  } else {
    Serial.println("Not close to object");
  }
  delay(250);
}
