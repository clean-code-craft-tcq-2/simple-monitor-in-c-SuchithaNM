#include "test_BmsStaus.h"
#include "Bms.h"

void testBatteryStatusOk(float soc ,float temp , float chargeRate)
{
  assert(batteryIsOk(soc, temp, chargeRate));
}

void testBatteryStatusNotOk(float soc ,float temp , float chargeRate)
{
  assert(!batteryIsOk(soc, temp, chargeRate));
}

void testBatteryStatus_env()
{
	testBatteryStatusNotOk(50,80,-1);
	testBatteryStatusOk(30,40,0.7);
}