#include "test_BmsStaus.h"


int test_batteryIsOk(float expectedSoc , float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsOk(expectedSoc,expectedTotalChargeInput,expectedTemp,expectedChargeRate,&inttBatterySocCheck, &inttBatteryTempCheck, &inttBatteryChargeRateCheck);
}
int test_batteryIsNotOk(float expectedSoc , float expectedTotalChargeInput, float expectedTemp , float expectedChargeRate)
{	
	batteryIsNotOk(expectedSoc,expectedTotalChargeInput,expectedTemp,expectedChargeRate,&inttBatterySocCheck, &inttBatteryTempCheck, &inttBatteryChargeRateCheck);
}

void testBatteryStatus_env()
{
	assert(test_batteryIsOk(32,8,40,0.7));
  assert(test_batteryIsNotOk(88,22,50,0.9)); 
}
