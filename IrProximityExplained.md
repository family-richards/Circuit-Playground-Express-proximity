# How IR Proximity with the Circuit Playground Express works

In this file, you'll learn about using IR proximity with the Circuit Playground Express.

## Concept

The concept of IR proximity sensing is pretty simple.

You turn on a IR LED, wait, check how much IR light you recieved, then turn the LED off.

If there's an object, it'll reflect the light causing a higher amount of IR light to be recieved.

Otherwise, there'll be a lower amount.

You can threshold that to determine whether the IR LED and the IR light sensor is close to an object.

We can do that with the Circuit Playground's IR sender and reciever.

The sender is at pin 25 and the reciever is at pin A8, so we can do the following bit of code to determine whether
the Express is close or not:

```c++
#include <Adafruit_CircuitPlayground.h>

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif

void setup() {
  //Setup everything
  CircuitPlayground.begin();
  pinMode(CPLAY_IR_EMITTER, OUTPUT);
  digitalWrite(CPLAY_IR_EMITTER, LOW);
  pinMode(A8, INPUT);
  while (!Serial);
  Serial.begin(19200);
}
int IR;
void loop() {
  delay(200);
  digitalWrite(CPLAY_IR_EMITTER, HIGH);
  delay(50);
  IR = analogRead(A8);
  digitalWrite(CPLAY_IR_EMITTER, LOW);
  IR = map(IR, 930, 970, 0, 100);
  if (IR > 70) {
    Serial.println("Close to object");
  } else {
    Serial.println("Not close to object");
  }
  delay(250);
}
```

By the way, IR proximity sensing has trouble with black objects.

## Summary
Things that I explained:
+ The concept of IR proximity sensing
+ How to use it in your own sketch, and also I included an example sketch.

If you want to add something, don't be afraid to make a poll request.
I hope I helped you in your projects today.
