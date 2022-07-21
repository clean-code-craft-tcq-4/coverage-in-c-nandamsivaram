#include<stdio.h>
#include "typewise-alert.h"
#include "Checklimit.h"

void Check_Passive_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit)
{
	if(coolingType == PASSIVE_COOLING)
	{
	  *lowerlimit = 0;
      *upperlimit = 35;
	}
}

void Check_Hi_Active_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit)
{
	if(coolingType == HI_ACTIVE_COOLING)
	{
	  *lowerlimit = 0;
      *upperlimit = 45;
	}
}

void Check_Med_Active_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit)
{
	if(coolingType == MED_ACTIVE_COOLING)
	{
	  *lowerlimit = 0;
      *upperlimit = 40;
	}
}

void set_up_limit(double value, double upperlimit, BreachType* breach)
{
	if(value > upperlimit)
	{
		*breach = TOO_HIGH;
	}
}

void set_low_limit(double value, double lowerlimit, BreachType* breach)
{
	if(value < lowerlimit)
	{
		*breach = TOO_LOW;
	}
}
