#include "Bms.h"


float (*fpInttBatteryGetSoc)(float totalChargeInput)
{
	float soc = totalChargeInput / MAX_CAPACITY_BATTERY;
	if (soc >= MIN_STATEOFCHARGE || soc <= MAX_STATEOFCHARGE)
	{
		printf("SOC of Battery is in charging state\n");
		return 1; 
	}
	else
	{
		printf("SOC of Battery is in discharging state\n");
		return 0; 
	}
}

float (*fpInttBatteryGetTemp)(float temp)
{
	if(temp >= MIN_TEMPERATURE || temp <=  MAX_TEMPERATURE)
	{
		printf("Charge the Battery and Temperature is in range\n");
		return 1;
	}
	else
	{
		printf("DisCharge the Battery and Temperature is out of range\n");
		return 0;
	}		
}
float (*fpInttBatteryGetChargeRate)(float chargeRate)
{
	if(chargeRate >= MIN_CHARGERATE || chargeRate <=  MAX_CHARGERATE)
	{
		printf("Charge  rate of battery is in range\n");
		return 1;
	}
	else
	{
		printf("Charge  rate of battery is out of range\n");
		return 0;
	}		
}
