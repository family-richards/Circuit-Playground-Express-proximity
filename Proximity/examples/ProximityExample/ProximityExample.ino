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
  //Check if amount of IR light is greater than threshold
  if (prox.close()) {
    //Say the threshold and that it recieved more IR light than the threshold
    Serial.print("Close to object, threshold is ");
    Serial.println(String(prox.getThreshold()));
  } else {
    //Say the threshold and that it recieved less IR light than the threshold
    Serial.print("Not close to object, threshold is ");
    Serial.println(String(prox.getThreshold()));
  }
  //If user sent data
  if (Serial.available()) {
    //Get number that user sent
    int num = Serial.parseInt();
    //Set new threshold
    prox.setThreshold(num);
    //Say the new threshold
    Serial.print("Changed threshold to ");
    Serial.println(num);
  }
  //Delay
  delay(250);
}
