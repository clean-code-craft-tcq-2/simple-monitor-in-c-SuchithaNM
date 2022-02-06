#include <stdio.h>
#include <assert.h>
#include "Bms.h"

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

int main()
{
	testBatteryStatus_env();
}
