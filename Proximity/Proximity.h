#ifndef Proximity_h
#define Proximity_h

#include "Arduino.h"

class Proximity
{
public:
Proximity();
bool close();
void begin(int threshold = 80);
void setThreshold(int threshold);
int getThreshold();
private:
int _threshold;
};
#endif