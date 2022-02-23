#pragma once
#include "alerttarget.h"
#include "batterycharacter.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit);

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
