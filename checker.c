#include <stdio.h>
#include <assert.h>
#include "Bmc.h"
#include "test_BmsStatus.h"



int batteryIsOk(float (*fptemperature)(float), float (*fpsoc)(float), float (*fpchargeRate)(float)
{	
	fpsoc = fpInttBatterygetSoc;
	fptemperature = IntBatterygetTemp();
	fpchargeRate = IntBatterygetChargeRate();
	
  if(fptemperature == 0 || fpsoc == 0 || fpchargeRate == 0 ) 
  {
	return 0;
  }
  else
  {
	 return 1;
  }
}


int main()
{
	testBatteryStatus_env();
}
