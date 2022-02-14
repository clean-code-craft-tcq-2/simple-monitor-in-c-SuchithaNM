#include "test_BmsStaus.h"
#include <stdio.h>

int test_batteryIsOk(float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsOk(expectedTotalChargeInput,expectedTemp,expectedChargeRate,&inttBatterySocIsOk, &inttBatteryTempIsOk, &inttBatteryChargeRateIsOk);
}
int test_batteryIsNotOk(float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsNotOk(expectedTotalChargeInput,expectedTemp,expectedChargeRate,&inttBatterySocIsOk, &inttBatteryTempIsOk, &inttBatteryChargeRateIsOk);
}

void testBatteryStatus_env(void)
{
	assert(test_batteryIsOk(32,40,0.7));
  	assert(test_batteryIsNotOk(88,50,0.9)); 
}
