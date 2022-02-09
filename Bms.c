#include <stdio.h>
#include "Bms.h"


float inttBatterySocIsOk(float totalChargeInput , float soc )
{
	soc = (totalChargeInput / MAX_CAPACITY_BATTERY) * 100;
	if ((soc >= MIN_STATEOFCHARGE) || (soc <= MAX_STATEOFCHARGE))
	{
		/*SOC of Battery is in charging state*/
		return 1; 
	}
	else
	{
		/*SOC of Battery is in discharging state*/
		return 0; 
	}
}

float inttBatteryTempIsOk(float temp)
{
	if((temp >= MIN_TEMPERATURE) || (temp <=  MAX_TEMPERATURE))
	{
		/*Charge the Battery and Temperature is in range*/
		return 1;
	}
	else
	{
		/*DisCharge the Battery and Temperature is out of range*/
		return 0;
	}		
}
float inttBatteryChargeRateIsOk(float chargeRate)
{
	if((chargeRate >= MIN_CHARGERATE) || (chargeRate <=  MAX_CHARGERATE))
	{
		/*Charge  rate of battery is in range*/
		return 1;
	}
	else
	{
		/*Charge  rate of battery is out of range*/
		return 0;
	}		
}
int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float,float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float))
{	
	float stateOfCharge = fpInttBatterySocIsOk(soc,totalChargeInput);
	float temperature = fpInttBatteryTempIsOk(temp);
	float chargerate = fpInttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float,float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float))
{	
	float stateOfCharge = fpInttBatterySocIsOk(soc,totalChargeInput);
	float temperature = fpInttBatteryTempIsOk(temp);
	float chargerate = fpInttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

