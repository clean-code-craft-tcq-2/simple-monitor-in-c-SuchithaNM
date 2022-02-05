#include <stdio.h>
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float (*fpInttBatteryGetSoc)(float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float soc = fpInttBatteryGetSoc();
	float temperature = fpInttBatteryGetTemp();
	float chargeRate = fpInttBatteryGetChargeRate();
	return (soc && temperature && chargeRate);
}


int main()
{
	//testBatteryStatus_env();
	assert(batteryIsOk(25, 70, 0.7));
        assert(!batteryIsOk(50, 85, 0)); 
}
