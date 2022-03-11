#include <stdio.h>
#include "alerttarget.h"

char emailMessages[][50] = {"", "Hi, the temperature is too low\n", "Hi, the temperature is too high\n"};

void sendToController(BreachType breachType)
{
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

char *getBreachTypeEmailMessage(BreachType breachType)
{
    return emailMessages[breachType];
}

void sendToEmail(BreachType breachType)
{
    char *message = getBreachTypeEmailMessage(breachType);
    if (strcmp(message, "") == 0)
    {
        return;
    }

    const char *recepient = "a.b@c.com";
    printf("To: %s\n", recepient);
    printf(message);
}

AlertTarget createControllerAlertTarget()
{
    struct AlertTarget controllerAlertTarget;
    controllerAlertTarget.send = sendToController;
    return controllerAlertTarget;
}

AlertTarget createEmailAlertTarget()
{
    struct AlertTarget emailAlertTarget;
    emailAlertTarget.send = sendToEmail;
    return emailAlertTarget;
}