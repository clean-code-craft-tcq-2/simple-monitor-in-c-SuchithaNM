#include "test_BmsStatus.h"
#include "Bms.h"

float testBatteryStatusOk(float soc ,float temp , float chargeRate)
{
  assert(batteryIsOk(soc, temp, chargeRate));
}

float testBatteryStatusNotOk(float soc ,float temp , float chargeRate)
{
  assert(!batteryIsOk(soc, temp, chargeRate));
}

float testBatteryStatus_env()
{
	testBatteryStatusNotOk(50,80,-1);
	testBatteryStatusOk(30,40,0.7);
}
