#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

#include <assert.h>
#include "Bms.h"

extern int test_batteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern int test_batteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern void testBatteryStatus_env(void);


#endif
