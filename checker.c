#include <stdio.h>
#include <assert.h>
#include "Bms.h"
#include "test_BmsStaus.h"

BMS_INB_State_en IntBattState ;

int main()
{
	switch(IntBattState) 
	{
		case LOW_SOC_BREACH : 
		IntBattChargControl(BattChargENABLE_en);
		break;
		
		case LOW_SOC_WARNING : 
			IntBattChargControl(BattChargENABLE_en);
	        break;
		
		case NORMAL_SOC :
			IntBattChargControl(BattChargENABLE_en);
		break;
		
		case HIGH_SOC_WARNING :
		IntBattChargControl(BattChargDISABLE_en);
		break;
		
		case HIGH_SOC_BREACH : 
		IntBattChargControl(BattChargDISABLE_en);
		break;
		
		case LOW_TEMP_BREACH : 
		IntBattChargControl(BattChargENABLE_en);
		break;
		
		case LOW_TEMP_WARNING :
			IntBattChargControl(BattChargENABLE_en);
		break;
		
		case NORMAL_TEMP : 
			IntBattChargControl(BattChargENABLE_en);
		break;
		
		case HIGH_TEMP_WARNING : 
			IntBattChargControl(BattChargDISABLE_en);
		break;
		
		case HIGH_TEMP_BREACH : 
		IntBattChargControl(BattChargDISABLE_en);
		break;
		
		case LOW_CHARGERATE_BREACH :
		IntBattChargControl(BattChargENABLE_en);
		break;
		
		case LOW_CHARGERATE_WARNING :
			IntBattChargControl(BattChargENABLE_en);
		break;
		
		case NORMAL_CHARGERATE : 
			IntBattChargControl(BattChargENABLE_en);
		break;
		
		case HIGH_CHARGERATE_WARNING : 
		IntBattChargControl(BattChargDISABLE_en);
		break;
		
		case HIGH_CHARGERATE_BREACH :
			IntBattChargControl(BattChargDISABLE_en);	
		break;
		
		default :
			/*Do nothing*/
		break;
	}

	testBatteryStatus_env();
}

