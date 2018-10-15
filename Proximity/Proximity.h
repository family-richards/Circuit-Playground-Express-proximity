#ifndef Proximity_h
#define Proximity_h

#include "Arduino.h"

class Proximity
{
public:
Proximity();
bool close();
int lastDist();
void begin(int threshold = 80);
void setThreshold(int threshold);
int getThreshold();
private:
int _threshold;
int IR;
};
#endif