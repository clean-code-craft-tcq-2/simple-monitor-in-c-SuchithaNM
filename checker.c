#include <stdio.h>
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatteryGetSoc)(float,float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float stateOfCharge = fpInttBatteryGetSoc(soc,totalChargeInput);
	float temperature = fpInttBatteryGetTemp(temp);
	float chargerate = fpInttBatteryGetChargeRate(chargeRate);
	if(stateOfCharge == 1 && temperature == 1 && chargerate == 1)
	{
		return 1;
	}
}
int batteryIsNotOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatteryGetSoc)(float,float), float (*fpInttBatteryGetTemp)(float), float (*fpInttBatteryGetChargeRate)(float))
{	
	float stateOfCharge = fpInttBatteryGetSoc(soc,totalChargeInput);
	float temperature = fpInttBatteryGetTemp(temp);
	float chargerate = fpInttBatteryGetChargeRate(chargeRate);
	if(stateOfCharge == 0 || temperature == 0 || chargerate == 0)
	{
		return 0;
	}
}
void testBatteryStatus_env()
{
	assert(batteryIsOk(32,8,40,0.7,&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate));
        assert(batteryIsNotOk(88,22,50,0.9,&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate)); 
}

int main()
{
	testBatteryStatus_env();
}
