#include <stdio.h>
#include "Bms.h"

int IntBatteryCharging_u8 ;



/****************soc*****************************************/
int intBattSocLowLimit(float soc)
{	
	if ((soc >= MIN_LOWSOCBREACH) || (soc <= MIN_SOCNORMAL))
	{
		IntBattChargControl(BattChargENABLE_en);
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
		IntBattChargControl(BattChargDISABLE_en);
		return E_NOT_OK; 
	}
	else 
	{
		IntBattChargControl(BattChargDISABLE_en);
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
	if ((temp >= MIN_LOWTEMPBREACH) || (temp < =MIN_TEMPNORMAL))
	{
		IntBattChargControl(BattChargENABLE_en);
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int intBattTempHighLimit(float temp)
{
	if ((temp >= MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		IntBattChargControl(BattChargDISABLE_en);
		return E_NOT_OK; 
	}
	else 
	{
		IntBattChargControl(BattChargDISABLE_en);
		return E_NOT_OK; 
	}
	
}

int inttBatteryTempIsOk(float temp )
{
	int tempStatus = E_OK;
	if(temp >= MIN_LOWTEMPBREACH && temp < MIN_HIGHTEMPWARNING)
	{
		tempStatus = intBattTempLowLimit(temp);
	}
	else
	{
		tempStatus = intBattTempHighLimit(temp);
	}
	return tempStatus;
}

/****************ChargeRate*****************************************/
int intBattChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		IntBattChargControl(BattChargENABLE_en);
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
		IntBattChargControl(BattChargDISABLE_en);
		return E_NOT_OK; 
	}
	else 
	{
		IntBattChargControl(BattChargDISABLE_en);
		return E_NOT_OK; 
	}
	
}

int inttBatteryChargeRateIsOk(float chargeRate )
{
	int chargeRateStatus = E_OK;
	if(chargeRate >= MIN_LOWCHARGERATEBREACH && chargeRate < MIN_HIGHCHARGERATEWARNING)
	{
		chargeRateStatus = intBattChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = intBattChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}

int batteryIsOk( float soc, float temp , float chargeRate)
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = inttBatteryTempIsOk(temp);
	float chargerate = inttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc, float temp , float chargeRate)
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = inttBatteryTempIsOk(temp);
	float chargerate = inttBatteryChargeRateIsOk(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}


void IntBattChargControl(IntBattChargControl_type ChargeCntrl)
{
   IntBatteryCharging_u8 = (int)ChargeCntrl;
}

