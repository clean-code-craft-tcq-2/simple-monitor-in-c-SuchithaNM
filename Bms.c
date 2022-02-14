#include <stdio.h>
#include "Bms.h"

int IntBatteryCharging_u8 ;
float inttBatterySocIsOk(float totalChargeInput )
{
	float soc = (totalChargeInput / MAX_CAPACITY_BATTERY) * 100;
	if ((soc >= MIN_LOWSOCBREACH) || (soc < MIN_LOWSOCWARNING))
	{
		return LOW_SOC_BREACH; 
	}
	else if ((soc >= MIN_LOWSOCWARNING) || (soc <= MIN_SOCNORMAL))
	{
		return LOW_SOC_WARNING; 
	}
	else if ((soc > MIN_SOCNORMAL) || (soc <= MIN_HIGHSOCWARNING))
	{
		return NORMAL_SOC; 
	}
	else if ((soc > MIN_HIGHSOCWARNING) || (soc <= MIN_HIGHSOCBREACH))
	{
		return HIGH_SOC_WARNING; 
	}
	else
	{
		return HIGH_SOC_BREACH; 
	}
}

float inttBatteryTempIsOk(float temp)
{
	if ((temp >= MIN_LOWTEMPBREACH) || (temp < MIN_LOWTEMPWARNING))
	{
		return LOW_TEMP_BREACH; 
	}
	else if ((temp >= MIN_LOWTEMPWARNING) || (temp <= MIN_TEMPNORMAL))
	{
		return LOW_TEMP_WARNING; 
	}
	else if ((temp > MIN_TEMPNORMAL) || (temp <= MIN_HIGHTEMPWARNING))
	{
		return NORMAL_TEMP; 
	}
	else if ((temp > MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		return HIGH_TEMP_WARNING; 
	}
	else
	{
		return HIGH_TEMP_BREACH; 
	}		
}
float inttBatteryChargeRateIsOk(float chargeRate)
{
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate < MIN_LOWCHARGERATEWARNING))
	{
		return LOW_CHARGERATE_BREACH; 
	}
	else if ((chargeRate >= MIN_LOWCHARGERATEWARNING) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		return LOW_CHARGERATE_WARNING; 
	}
	else if ((chargeRate > MIN_CHARGERATENORMAL) || (chargeRate <= MIN_HIGHCHARGERATEWARNING))
	{
		return NORMAL_CHARGERATE; 
	}
	else if ((chargeRate > MIN_HIGHCHARGERATEWARNING) || (chargeRate <= MIN_HIGHCHARGERATEBREACH))
	{
		return HIGH_CHARGERATE_WARNING; 
	}
	else
	{
		return HIGH_CHARGERATE_BREACH; 
	}		
}
int batteryIsOk( float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float))
{	
	float stateOfCharge = fpInttBatterySocIsOk(totalChargeInput);
	float temperature = fpInttBatteryTempIsOk(temp);
	float chargerate = fpInttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float))
{	
	float stateOfCharge = fpInttBatterySocIsOk(totalChargeInput);
	float temperature = fpInttBatteryTempIsOk(temp);
	float chargerate = fpInttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

void IntBattChargControl(IntBattChargControl_type ChargeCntrl)
{
   IntBatteryCharging_u8 = (int)ChargeCntrl;
}



