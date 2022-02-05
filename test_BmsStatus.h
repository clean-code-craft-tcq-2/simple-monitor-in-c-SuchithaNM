#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

extern void testBatteryStatusOk(float soc ,float temp , float chargeRate);
extern void testBatteryStatusNotOk(float soc ,float temp , float chargeRate);
extern void testBatteryStatus_env(void);

#endif