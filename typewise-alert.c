#include "typewise-alert.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  if (value < lowerLimit)
  {
    return TOO_LOW;
  }
  if (value > upperLimit)
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = inferBreach(temperatureInC, batteryChar.coolingType.lowerLimit, batteryChar.coolingType.upperLimit);
  alertTarget.send(breachType);
}
