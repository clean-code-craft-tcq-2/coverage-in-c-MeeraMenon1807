#include <string.h>
#include "batterycharacter.h"

BatteryCharacter createBatteryCharacter(CoolingType coolingType, char brand[48])
{
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = coolingType;
  strcpy(batteryCharacter.brand, brand);
  return batteryCharacter;
}