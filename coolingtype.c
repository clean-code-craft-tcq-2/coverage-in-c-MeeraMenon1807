#include "coolingtype.h"

CoolingType createPassiveCoolingType()
{
  struct CoolingType passiveCoolingType;
  passiveCoolingType.name = PASSIVE_COOLING;
  passiveCoolingType.lowerLimit = 0;
  passiveCoolingType.upperLimit = 35;
  return passiveCoolingType;
}

CoolingType createHiActiveCoolingType()
{
  struct CoolingType hiActiveCoolingType;
  hiActiveCoolingType.name = HI_ACTIVE_COOLING;
  hiActiveCoolingType.lowerLimit = 0;
  hiActiveCoolingType.upperLimit = 45;
  return hiActiveCoolingType;
}

CoolingType createMedActiveCoolingType()
{
  struct CoolingType medActiveCoolingType;
  medActiveCoolingType.name = MED_ACTIVE_COOLING;
  medActiveCoolingType.lowerLimit = 0;
  medActiveCoolingType.upperLimit = 40;
  return medActiveCoolingType;
}