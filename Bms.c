#include <stdio.h>
#include "Bms.h"


/****************soc*****************************************/
int intBattSocLowLimit(float soc)
{	
	if ((soc >= MIN_LOWSOCBREACH) || (soc <= MIN_SOCNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		/*SOC of Battery is in charging state*/
		return E_OK; 
	}
}

int intBattSocHighLimit(float soc)
{
	if ((soc >= MIN_HIGHSOCWARNING) || (soc <= MIN_HIGHSOCBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int inttBatterySocIsOk(float soc )
{
	int socStatus = E_OK;
	if((soc >= MIN_LOWSOCBREACH) && (soc <= MIN_HIGHSOCWARNING))
	{
		socStatus = intBattSocLowLimit(soc);
	}
	else
	{
		socStatus = intBattSocHighLimit(soc);
	}
	return socStatus;
}

/****************TEMP*****************************************/
int intBattTempLowLimit(float temp)
{	
	if ((temp >= MIN_LOWTEMPBREACH) || (temp <= MIN_TEMPNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int intBattTempHighLimit(float temp, char tempUnit)
{
	if ((temp >= MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		inttBattConvertTemp(temp, tempUnit);
		return E_NOT_OK; 
	}
	
}

int inttBatteryTempIsOk(float temp, char tempUnit )
{
	int tempStatus = E_OK;
	if((temp >= MIN_LOWTEMPBREACH) && (temp < MIN_HIGHTEMPWARNING))
	{
		tempStatus = intBattTempLowLimit(temp);
	}
	else
	{
		tempStatus = intBattTempHighLimit(temp, tempUnit);
	}
	return tempStatus;
}

 bool inttBattTempUnit(char cel)
 {
 	if(cel == TEMP_UNIT_CELCIUS)
		return true;
	 else
		return false;
 }

float inttBattConvertTemp(float temp, char tempUnit)
{
	float celcius;
	if((temp > MAX_HIGHTEMPBREACH) && (tempUnit == TEMP_UNIT_FARENHEIT))
	{
		celcius = (temp - 32) * 5 / 9;
	}
	else
	{
		return temp;
	}
}
/****************ChargeRate*****************************************/
int intBattChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int intBattChargeRateHighLimit(float chargeRate)
{
	if ((chargeRate >= MIN_HIGHCHARGERATEWARNING) || (chargeRate <= MIN_HIGHCHARGERATEBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int inttBatteryChargeRateIsOk(float chargeRate )
{
	int chargeRateStatus = E_OK;
	if((chargeRate >= MIN_LOWCHARGERATEBREACH) && (chargeRate < MIN_HIGHCHARGERATEWARNING))
	{
		chargeRateStatus = intBattChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = intBattChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}

int batteryIsOk( float soc, float temp , float chargeRate, char tempUnit )
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = inttBatteryTempIsOk(temp, tempUnit);
	float chargerate = inttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc, float temp , float chargeRate, char tempUnit)
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = inttBatteryTempIsOk(temp, tempUnit);
	float chargerate = inttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

