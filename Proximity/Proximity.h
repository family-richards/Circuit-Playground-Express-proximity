#ifndef Proximity_h
#define Proximity_h

#include "Arduino.h"

class Proximity
{
public:
Proximity();
bool close();
void setup(int threshold = 80);
int _threshold;
};
#endif