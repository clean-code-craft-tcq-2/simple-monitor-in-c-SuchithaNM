#include <stdio.h>
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float (*fptemperature)(float), float (*fpsoc)(float), float (*fpchargeRate)(float))
{	
	fpsoc = fpInttBatterygetSoc;
	fptemperature = IntBatterygetTemp();
	fpchargeRate = IntBatterygetChargeRate();
	return (fpsoc && fptemperature && fpchargeRate);
}


int main()
{
	//testBatteryStatus_env();
	assert(batteryIsOk(25, 70, 0.7));
        assert(!batteryIsOk(50, 85, 0)); 
}
