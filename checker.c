#include <stdio.h>
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatteryGetSoc)(float,float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float stateOfCharge = fpInttBatteryGetSoc(soc,totalChargeInput);
	float temperature = fpInttBatteryGetTemp(temp);
	float chargeRate = fpInttBatteryGetChargeRate(chargeRate);
	return (soc && temperature && chargeRate);
}


int main()
{
	//testBatteryStatus_env();
	assert(batteryIsOk(32,8,40,0.7,&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate));
        assert(!batteryIsOk(&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate)); 
}
