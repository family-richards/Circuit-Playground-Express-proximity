#include <Adafruit_CircuitPlayground.h>
#include <Proximity.h>

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif
Proximity prox;
void setup() {
  //Setup everything
  CircuitPlayground.begin();
  //Change this number for your sensitivity, make higher if you can't get NeoPixels to turn off, make lower if you can't get it to turn NeoPixels on.
  prox.begin(80);
  Serial.begin(19200);
}
void on() {
  //Turn all NeoPixels on
  CircuitPlayground.setPixelColor(0, 255, 255, 255);
  CircuitPlayground.setPixelColor(1, 255, 255, 255);
  CircuitPlayground.setPixelColor(2, 255, 255, 255);
  CircuitPlayground.setPixelColor(3, 255, 255, 255);
  CircuitPlayground.setPixelColor(4, 255, 255, 255);
  CircuitPlayground.setPixelColor(5, 255, 255, 255);
  CircuitPlayground.setPixelColor(6, 255, 255, 255);
  CircuitPlayground.setPixelColor(7, 255, 255, 255);
  CircuitPlayground.setPixelColor(8, 255, 255, 255);
  CircuitPlayground.setPixelColor(9, 255, 255, 255);
}
void off() {
  //Turn all NeoPixels off
  CircuitPlayground.setPixelColor(0, 0, 0, 0);
  CircuitPlayground.setPixelColor(1, 0, 0, 0);
  CircuitPlayground.setPixelColor(2, 0, 0, 0);
  CircuitPlayground.setPixelColor(3, 0, 0, 0);
  CircuitPlayground.setPixelColor(4, 0, 0, 0);
  CircuitPlayground.setPixelColor(5, 0, 0, 0);
  CircuitPlayground.setPixelColor(6, 0, 0, 0);
  CircuitPlayground.setPixelColor(7, 0, 0, 0);
  CircuitPlayground.setPixelColor(8, 0, 0, 0);
  CircuitPlayground.setPixelColor(9, 0, 0, 0);
}
void gray(int val) {
  //Turn all NeoPixels to a percent of white
  CircuitPlayground.setPixelColor(0, val, val, val);
  CircuitPlayground.setPixelColor(1, val, val, val);
  CircuitPlayground.setPixelColor(2, val, val, val);
  CircuitPlayground.setPixelColor(3, val, val, val);
  CircuitPlayground.setPixelColor(4, val, val, val);
  CircuitPlayground.setPixelColor(5, val, val, val);
  CircuitPlayground.setPixelColor(6, val, val, val);
  CircuitPlayground.setPixelColor(7, val, val, val);
  CircuitPlayground.setPixelColor(8, val, val, val);
  CircuitPlayground.setPixelColor(9, val, val, val);
}
void mid() {
  //Turn all NeoPixels to gray
  gray(64);
}
bool prev;
bool isOn;
long lastActivation;
void loop() {
  if (CircuitPlayground.slideSwitch()) {
    //Run if mode is proximity
    //Turn off LED to show proximity mode
    digitalWrite(13, LOW);
    //Check proximity
    if (prox.close()) {
      //Close to object
      if (!prev) {
        //Close to object but not when ran last loop
        mid();
        prev = true;
        lastActivation = millis();
      } else {
        //Close to object in last loop and this loop
        on();
        prev = true;
        lastActivation = millis();
      }
    } else {
      //Not close to object
      if (millis() - lastActivation < 30000 && millis() - lastActivation > 29700) {
        //Been close to object in 29700-30000 milliseconds
        mid();
        prev = false;
      } else if (millis() - lastActivation > 30000) {
        //Haven't been close to object within 30 seconds
        off();
        prev = false;
      } else {
        //Fix bug for when you only activate the IR sense in 1 loop so the NeoPixels are at mid bright for the time
        on();
      }
    }
  } else {
    //Manual mode, so show LED
    digitalWrite(13, HIGH);
    if (CircuitPlayground.rightButton()) {
      //On button is pressed
      isOn = true;
    } else if (CircuitPlayground.leftButton()) {
      //Off button is pressed and on button isn't pressed
      isOn = false;
    }
    //Manage NeoPixels
    if (isOn) {
      on();
    } else {
      off();
    }
  }
}
