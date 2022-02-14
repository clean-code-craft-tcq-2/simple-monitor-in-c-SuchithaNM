#include "test_BmsStaus.h"

int test_batteryIsOk(float expectedsoc, float expectedTemp , float expectedChargeRate)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate);
}
int test_batteryIsNotOk(float expectedsoc, float expectedTemp , float expectedChargeRate)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate);
}

void testBatteryStatus_env(void)
{
	assert(test_batteryIsNotOk(88,-1,1.0)); 
  	assert(test_batteryIsNotOk(88,50,0.9)); 
	assert(test_batteryIsOk(32,39,0.7));
	assert(test_batteryIsOk(42,30,0.6));
}
