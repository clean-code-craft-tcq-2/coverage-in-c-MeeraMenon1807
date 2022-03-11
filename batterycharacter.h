#include "coolingtype.h"

typedef struct BatteryCharacter
{
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

BatteryCharacter createBatteryCharacter(CoolingType coolingType, char brand[48]);