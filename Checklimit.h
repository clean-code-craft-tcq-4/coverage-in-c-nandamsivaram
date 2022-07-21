#include<stdio.h>
#include "typewise-alert.h"

void Check_Passive_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit);
void Check_Hi_Active_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit);
void Check_Med_Active_Cooling(CoolingType coolingType, int* lowerlimit, int* upperlimit);
void set_up_limit(double value, double upperlimit, BreachType* breach);
void set_low_limit(double value, double lowerlimit, BreachType* breach);
