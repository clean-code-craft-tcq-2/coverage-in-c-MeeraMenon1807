#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("test create controller alert target does not throw error")
{
  REQUIRE_NOTHROW(createControllerAlertTarget()); 
}

TEST_CASE("test alert send to controller does not throw error")
{
  AlertTarget alertTarget = createControllerAlertTarget();
  REQUIRE_NOTHROW(alertTarget.send(TOO_LOW));
  REQUIRE_NOTHROW(alertTarget.send(TOO_HIGH));
  REQUIRE_NOTHROW(alertTarget.send(NORMAL));
}

TEST_CASE("test create email alert target does not throw error")
{
  REQUIRE_NOTHROW(createEmailAlertTarget());
}

SCENARIO("get email alert message")
{
  WHEN("breach type is NORMAL")
  {
    BreachType breachType = NORMAL;

    THEN("message is \"\"")
    {
      REQUIRE(strcmp(getBreachTypeEmailMessage(breachType), "") == 0);
    }
  }

  WHEN("breach type is not normal")
  {
    BreachType breachType = TOO_HIGH;

    THEN("message is not \"\"")
    {
      REQUIRE(strcmp(getBreachTypeEmailMessage(breachType), "") != 0);
    }
  }
}

TEST_CASE("test alert send to email does not throw error")
{
  AlertTarget alertTarget = createEmailAlertTarget();
  REQUIRE_NOTHROW(alertTarget.send(TOO_LOW));
  REQUIRE_NOTHROW(alertTarget.send(TOO_HIGH));
  REQUIRE_NOTHROW(alertTarget.send(NORMAL));
}

SCENARIO("create passive cooling type")
{
  WHEN("passive cooling type is created")
  {
    CoolingType coolingType = createPassiveCoolingType();
    THEN("lower limit should be 0")
    {
      REQUIRE(coolingType.lowerLimit == 0);
    }
    THEN("upper limit should be 35")
    {
      REQUIRE(coolingType.upperLimit == 35);
    }
  }
}

SCENARIO("create hi active cooling type")
{
  WHEN("hi active cooling type is created")
  {
    CoolingType coolingType = createHiActiveCoolingType();
    THEN("lower limit should be 0")
    {
      REQUIRE(coolingType.lowerLimit == 0);
    }
    THEN("upper limit should be 45")
    {
      REQUIRE(coolingType.upperLimit == 45);
    }
  }
}

SCENARIO("create med active cooling type")
{
  WHEN("med active cooling type is created")
  {
    CoolingType coolingType = createMedActiveCoolingType();
    THEN("lower limit should be 0")
    {
      REQUIRE(coolingType.lowerLimit == 0);
    }
    THEN("upper limit should be 40")
    {
      REQUIRE(coolingType.upperLimit == 40);
    }
  }
}

SCENARIO("create battery character")
{
  GIVEN("cooling type and brand")
  {
    CoolingType coolingType = createMedActiveCoolingType();
    char brand[48] = "Exide";

    WHEN("battery character is created")
    {
      BatteryCharacter batteryCharacter = createBatteryCharacter(coolingType, brand);

      THEN("battery charcter should have given cooling type")
      {
        REQUIRE(batteryCharacter.coolingType.name == MED_ACTIVE_COOLING);
        REQUIRE(batteryCharacter.coolingType.lowerLimit == coolingType.lowerLimit);
        REQUIRE(batteryCharacter.coolingType.upperLimit == coolingType.upperLimit);
      }

      THEN("battery charter should have given brand")
      {
        REQUIRE(strcmp(batteryCharacter.brand, brand) == 0);
      }
    }
  }
}

SCENARIO("infer the breach according to limits")
{
  GIVEN("an upper limit and lower limit")
  {
    double upperLimit = 30;
    double lowerLimit = 20;

    WHEN("value less than lower limit is provided")
    {
      double value = 12;
      THEN("breach should be TOO_LOW")
      {
        REQUIRE(inferBreach(value, lowerLimit, upperLimit) == TOO_LOW);
      }
    }

    WHEN("value greater than upper limit is provided")
    {
      double value = 35;
      THEN("breach should be TOO_HIGH")
      {
        REQUIRE(inferBreach(value, lowerLimit, upperLimit) == TOO_HIGH);
      }
    }

    WHEN("value between upper and lower limit is provided")
    {
      double value = 25;
      THEN("breach should be NORMAL")
      {
        REQUIRE(inferBreach(value, lowerLimit, upperLimit) == NORMAL);
      }
    }

    WHEN("value equal to upper limit is provided")
    {
      double value = upperLimit;
      THEN("breach should be NORMAL")
      {
        REQUIRE(inferBreach(value, lowerLimit, upperLimit) == NORMAL);
      }
    }

    WHEN("value equal to lower limit is provided")
    {
      double value = upperLimit;
      THEN("breach should be NORMAL")
      {
        REQUIRE(inferBreach(value, lowerLimit, upperLimit) == NORMAL);
      }
    }
  }
}

TEST_CASE("test check and alert does not throw error")
{
  AlertTarget alertTarget = createControllerAlertTarget();
  CoolingType coolingType = createPassiveCoolingType();
  char brand[48] = "Exide";
  BatteryCharacter batteryCharacter = createBatteryCharacter(coolingType, brand);
  REQUIRE_NOTHROW(checkAndAlert(alertTarget, batteryCharacter, 20));
}
