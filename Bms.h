#ifndef BMS_H
#define BMS_H

#define MAX_CAPACITY_BATTERY 25
#define MIN_STATEOFCHARGE 20
#define MAX_STATEOFCHARGE 80
#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGERATE 0.2
#define MAX_CHARGERATE 0.8

extern float (*fpInttBatteryGetSoc)(float totalChargeInput);
extern float (*fpInttBatteryGetTemp)(float temp);
extern float (*fpInttBatteryGetChargeRate)(float chargeRate);
extern int batteryIsOk(float (*fptemperature)(float), float (*fpsoc)(float), float (*fpchargeRate)(float);

#endif
