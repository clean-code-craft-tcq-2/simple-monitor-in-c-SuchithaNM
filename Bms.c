#include <stdio.h>
#include "Bms.h"


float inttBatterySocCheck(float totalChargeInput , float soc )
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

float inttBatteryTempCheck(float temp)
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
float inttBatteryChargeRateCheck(float chargeRate)
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
int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocCheck)(float,float), float (*fpInttBatteryTempCheck)(float), float (*fpInttBatteryChargeRateCheck)(float))
{	
	float stateOfCharge = fpInttBatterySocCheck(soc,totalChargeInput);
	float temperature = fpInttBatteryTempCheck(temp);
	float chargerate = fpInttBatteryChargeRateCheck(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocCheck)(float,float), float (*fpInttBatteryTempCheck)(float), float (*fpInttBatteryChargeRateCheck)(float))
{	
	float stateOfCharge = fpInttBatterySocCheck(soc,totalChargeInput);
	float temperature = fpInttBatteryTempCheck(temp);
	float chargerate = fpInttBatteryChargeRateCheck(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

