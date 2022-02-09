#ifndef BMS_H
#define BMS_H

#define MAX_CAPACITY_BATTERY 25
#define MIN_STATEOFCHARGE 20
#define MAX_STATEOFCHARGE 80
#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGERATE 0.2
#define MAX_CHARGERATE 0.8

extern float inttBatterySocIsOk(float totalChargeInput, float soc);
extern float inttBatteryTempIsOk(float temp);
extern float inttBatteryChargeRateIsOk(float chargeRate);
extern int batteryIsOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float,float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float));
extern int batteryIsNotOk(float soc , float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float,float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float));


#endif
