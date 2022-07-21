#include "typewise-alert.h"
#include <stdio.h>
#include"Checklimit.h"

BreachType inferBreach(double value, double lowerlimit, double upperlimit) {
 
 BreachType breach = NORMAL;
 set_up_limit(value, lowerlimit, &breach);
 set_low_limit(value, upperlimit, &breach);
 
 return breach;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerlimit = 0;
  int upperlimit = 0;
 
  Check_Passive_Cooling(coolingType, &lowerlimit, &upperlimit);
  Check_Hi_Active_Cooling(coolingType, &lowerlimit, &upperlimit);
  Check_Med_Active_Cooling(coolingType, &lowerlimit, &upperlimit);

  return inferBreach(temperatureInC, lowerlimit, upperlimit);
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

void sendAlert(AlertTarget alertTarget, BreachType breachType)
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
	 if(breachType == TOO_LOW)
	 {
	      printf("To: %s\n", recepient);
	      printf("Hi, the temperature is too low\n");
	 }
	 else if(breachType == TOO_HIGH)
	 {
	      printf("To: %s\n", recepient);
	      printf("Hi, the temperature is too high\n");
	 }
}
