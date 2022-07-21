#include "typewise-alert.h"
#include <stdio.h>
#include"Checklimit.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
 
 BreachType breach = NORMAL;
 set_up_limit(value, &upperLimit, &breach);
 set_low_limit(value, &lowerlimit, &breach);
 
 return breach;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
 
  Check_Passive_Cooling(coolingType, &lowerlimit, &upperlimit);
  Check_Hi_Active_Cooling(coolingType, &lowerlimit, &upperlimit);
  Check_Med_Active_Cooling(coolingType, &lowerlimit, &upperlimit);

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

bool checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
	
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  
  	if(breachType != NORMAL)
	{
		sendAlert(alertTarget, breachType);
		return true;
	}
	return false;
}

void sendAlert(alertTarget, breachType)
{
	if(alertTarget == TO_CONTROLLER)
	{
		sendToController(breachType);
	}
	else if(alertTarget == TO_EMAIL)
	{
		sendToEmail(breachType);
	}
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
  }
}
