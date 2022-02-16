#include "test_BmsStaus.h"

int test_batteryIsOk(float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}
int test_batteryIsNotOk(float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}

void testBatteryStatus_env(void)
{
	assert(test_batteryIsNotOk(88,-1,1.0,'N')); 
  	assert(test_batteryIsNotOk(88,50,0.9,'C')); 
	assert(test_batteryIsOk(32,39,0.7,'C'));
	assert(test_batteryIsOk(42,30,0.6,'C'));
	assert(test_batteryIsOk(42,283,0.6,'F'));
}
