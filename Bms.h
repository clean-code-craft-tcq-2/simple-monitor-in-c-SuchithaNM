#ifndef BMS_H
#define BMS_H

#define MAX_CAPACITY_BATTERY 25

#define MIN_LOWSOCBREACH         0
#define MIN_LOWSOCWARNING        20
#define MIN_SOCNORMAL		 24
#define MIN_HIGHSOCWARNING 	 75
#define MIN_HIGHSOCBREACH        80
#define MAX_HIGHOCBREACH         100

#define MIN_LOWTEMPBREACH        0
#define MIN_LOWTEMPWARNING       5
#define MIN_TEMPNORMAL           10
#define MIN_HIGHTEMPWARNING      40
#define MIN_HIGHTEMPBREACH       45
#define MAX_HIGHTEMPBREACH       80

#define MIN_LOWCHARGERATEBREACH   0
#define MIN_LOWCHARGERATEWARNING  0.2
#define MIN_CHARGERATENORMAL      0.3
#define MIN_HIGHCHARGERATEWARNING 0.7
#define MIN_HIGHCHARGERATEBREACH  0.8
#define MAX_HIGHCHARGERATEBREACH  1.0



typedef enum{
	LOW_SOC_BREACH = 0,
	LOW_SOC_WARNING,
	NORMAL_SOC,
	HIGH_SOC_WARNING,
	HIGH_SOC_BREACH,
	LOW_TEMP_BREACH ,
	LOW_TEMP_WARNING,
	NORMAL_TEMP,
	HIGH_TEMP_WARNING,
	HIGH_TEMP_BREACH,
       LOW_CHARGERATE_BREACH,
	LOW_CHARGERATE_WARNING,
	NORMAL_CHARGERATE,
	HIGH_CHARGERATE_WARNING,
	HIGH_CHARGERATE_BREACH
	
}BMS_INB_State_en;

typedef enum
{
    BattChargDISABLE_en = 0,
    BattChargENABLE_en
}IntBattChargControl_type;





extern float inttBatterySocIsOk(float totalChargeInput);
extern float inttBatteryTempIsOk(float temp);
extern float inttBatteryChargeRateIsOk(float chargeRate);
extern int batteryIsOk( float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float));
extern int batteryIsNotOk( float totalChargeInput, float temp , float chargeRate, float (*fpInttBatterySocIsOk)(float), float (*fpInttBatteryTempIsOk)(float), float (*fpInttBatteryChargeRateIsOk)(float));

extern void IntBattChargControl(IntBattChargControl_type ChargeCntrl);


#endif

