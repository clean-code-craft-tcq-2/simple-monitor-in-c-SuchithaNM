#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

extern float testBatteryStatusOk(float soc ,float temp , float chargeRate);
extern float testBatteryStatusNotOk(float soc ,float temp , float chargeRate);
extern float testBatteryStatus_env(void);

#endif
