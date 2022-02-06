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

int test_batteryIsOk(float expectedSoc , float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsOk(expectedSoc,expectedTotalChargeInput,expectedTemp,expectedChargeRate,&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate);
	}
int test_batteryIsNotOk(float expectedSoc , float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsNotOk(expectedSoc,expectedTotalChargeInput,expectedTemp,expectedChargeRate,&InttBatteryGetSoc, &InttBatteryGetTemp, &InttBatteryGetChargeRate);
}

void testBatteryStatus_env()
{
	assert(test_batteryIsOk(32,8,40,0.7));
    	assert(test_batteryIsNotOk(88,22,50,0.9)); 
}

int main()
{
	testBatteryStatus_env();
}
