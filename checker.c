#include <stdio.h>
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float (*fpInttBatteryGetSoc)(void), float (*fpInttBatteryGetTemp)(void), float (*fpInttBatteryGetChargeRate)(void))
{	
	float soc = fpInttBatteryGetSoc();
	float temperature = fpInttBatteryGetTemp();
	float chargeRate = fpInttBatteryGetChargeRate();
	return (soc && temperature && chargeRate);
}


int main()
{
	//testBatteryStatus_env();
	assert(batteryIsOk(&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate));
        assert(!batteryIsOk(&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate)); 
}
