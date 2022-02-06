#include <stdio.h>
#include "Bms.h"


float InttBatteryGetSoc(float totalChargeInput , float soc )
{
	soc = (totalChargeInput / MAX_CAPACITY_BATTERY) * 100;
	if ((soc >= MIN_STATEOFCHARGE) || (soc <= MAX_STATEOFCHARGE))
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

float InttBatteryGetTemp(float temp)
{
	if((temp >= MIN_TEMPERATURE) || (temp <=  MAX_TEMPERATURE))
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
float InttBatteryGetChargeRate(float chargeRate)
{
	if((chargeRate >= MIN_CHARGERATE) || (chargeRate <=  MAX_CHARGERATE))
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
int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatteryGetSoc)(float,float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float stateOfCharge = fpInttBatteryGetSoc(soc,totalChargeInput);
	float temperature = fpInttBatteryGetTemp(temp);
	float chargerate = fpInttBatteryGetChargeRate(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatteryGetSoc)(float,float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float stateOfCharge = fpInttBatteryGetSoc(soc,totalChargeInput);
	float temperature = fpInttBatteryGetTemp(temp);
	float chargerate = fpInttBatteryGetChargeRate(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

