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


#define E_OK     0
#define E_NOT_OK 1

/*
typedef struct
{
	float lowerLimitBreach;
	float lowerLimitWarning;
	float Normal;
	float higherLimitWarning;
	float higherLimitBreach;
}BatteryStatus_tn;*/



 /*   0 to 20: LOW_SOC_BREACH minSOCbre max
    21 to 24: LOW_SOC_WARNING min soc war max
    24 to 75: NORMAL
    76 to 80: HIGH_SOC_WARNING
    81 to 100: HIGH_SOC_BREACH

typedef struct {
    BMS_INB_State_en         PrevState_en;
    BMS_INB_State_en         CurrentState_en;
}BMS_RamVarType;
*/

typedef enum
{
    BattChargDISABLE_en = 0,
    BattChargENABLE_en
}IntBattChargControl_type;



extern int intBattSocLowLimit(float soc);
extern int intBattSocHighLimit(float soc);
extern int inttBatterySocIsOk(float soc );
extern int intBattTempLowLimit(float temp);
extern int intBattTempHighLimit(float temp);
extern int inttBatteryTempIsOk(float temp );
extern int intBattChargeRateLowLimit(float chargeRate);
extern int intBattChargeRateHighLimit(float chargeRate);
extern int inttBatteryChargeRateIsOk(float chargeRate );


extern int batteryIsOk( float soc, float temp , float chargeRate);
extern int batteryIsNotOk( float soc, float temp , float chargeRate);

extern void IntBattChargControl(IntBattChargControl_type ChargeCntrl);
extern void bmsMainFunction(void);

#endif
