typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingTypeName;

typedef struct CoolingType
{
  CoolingTypeName name;
  int lowerLimit;
  int upperLimit;
} CoolingType;

CoolingType createPassiveCoolingType();

CoolingType createHiActiveCoolingType();

CoolingType createMedActiveCoolingType();