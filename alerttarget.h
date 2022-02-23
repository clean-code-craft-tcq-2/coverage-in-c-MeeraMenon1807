#include "string.h"
#include "breachtype.h"

typedef struct AlertTarget
{
    void (*send)(BreachType);
} AlertTarget;

void sendToController(BreachType breachType);

char *getBreachTypeEmailMessage(BreachType breachType);

void sendToEmail(BreachType breachType);

AlertTarget createControllerAlertTarget();

AlertTarget createEmailAlertTarget();

extern char emailMessages[][50];