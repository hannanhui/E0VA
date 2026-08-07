/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      AdcIf.c                                                                  */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/



#include "model_Cfg_feature.h"

#include "Ecal_Adc.h"

uint16_t ADValBuff[ADC_GROUP_CH_NUM] = 
{
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000
};
static AdcWorkSt_t AdcWorkSt[ADC_CFG_GROUP_NUM] = {AdcWorkSt_Init, AdcWorkSt_Init, AdcWorkSt_Init};
static uint8_t AdcInitSts[ADC_CFG_GROUP_NUM] = {FALSE, FALSE, FALSE};


//瀵瑰簲鍘熺悊鍥?1璺疉D鍊?
AdcResult_t AdcResult[ADC_GROUP_CH_NUM] = 
{
    [ADC_INSIDE_CHANNEL_4] = 
    {
        //.Ch = ADC_P_CH2,
        .DataValidSt = 0u,
        .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_2] = 
    {
        //.Ch = ADC_P_CH6,
        .DataValidSt = 0u,
        .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_3] = 
    {
      //.Ch = ADC_P_CH7,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_5] = 
    {
      //.Ch = ADC_P_CH10,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_6] = 
    {
      //.Ch = ADC_P_CH11,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_9] = 
    {
      //.Ch = ADC_P_CH12,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_8] = 
    {
      //.Ch = ADC_P_CH15,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_10] = 
    {
      //.Ch = ADC_P_CH14,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_7] = 
    {
      //.Ch = ADC_P_CH2,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_15] = 
    {
      //.Ch = ADC_P_CH2,
      .DataValidSt = 0u,
      .Val = 0u,
    },
    [ADC_INSIDE_CHANNEL_12] = 
    {
      //.Ch = ADC_P_CH2,
      .DataValidSt = 0u,
      .Val = 0u,
    }
};
void Cbk_Adc0Group0_Notification(void)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc0Group0] = AdcWorkSt_SamplFinsh;
//    Adc_ReadGroup(AdcConf_AdcGroup_Adc0Group0, &ADValBuff[0u]);
//    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc0Group0);
}

void Cbk_Adc1Group0_Notification(void)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc1Group0] = AdcWorkSt_SamplFinsh;
//    Adc_ReadGroup(AdcConf_AdcGroup_Adc1Group0, &ADValBuff[6u]);
//    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc1Group0);
}

void Cbk_Adc1Group1_Notification(void)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc1Group1] = AdcWorkSt_SamplFinsh;
//    Adc_ReadGroup(AdcConf_AdcGroup_Adc1Group1, &ADValBuff[6u]);
//    Adc_StartGroupConversion(AdcConf_AdcGroup_Adc1Group1);
}


void Cbk_Adc0TriggerErrorNotification(void)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc0Group0] = AdcWorkSt_Err;
    Adc_StopGroupConversion(AdcConf_AdcGroup_Adc0Group0);
}

void Cbk_Adc1TriggerErrorNotification(void)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc1Group0] = AdcWorkSt_Err;
    Adc_StopGroupConversion(AdcConf_AdcGroup_Adc1Group0);
}

void Cbk_DmaChannel0ErrorInterrupt(uint32 LogicChIndex)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc0Group0] = AdcWorkSt_Err;
    Adc_StopGroupConversion(AdcConf_AdcGroup_Adc0Group0);
}

void Cbk_DmaChannel1ErrorInterrupt(uint32 LogicChIndex)
{
    AdcWorkSt[AdcConf_AdcGroup_Adc1Group0] = AdcWorkSt_Err;
    Adc_StopGroupConversion(AdcConf_AdcGroup_Adc1Group0);
}

void ADC_Drv_Init(uint8_t idx)
{
	uint8_t tmepIdx = 0u;

	if(idx==AdcConf_AdcGroup_Adc0Group0)
		tmepIdx = 0u;
	else if(idx==AdcConf_AdcGroup_Adc1Group0)
		tmepIdx = ADC_CFG_GROUP_0_CHANNEL_NUM;
	else if(idx==AdcConf_AdcGroup_Adc1Group1)
		tmepIdx = ADC_CFG_GROUP_0_CHANNEL_NUM \
				  +ADC_CFG_GROUP_1_CHANNEL_NUM;
	
	//Adc_CalibrationStatusType CalibStatus;
	
	//ADC_CurrSampGroup[0u] = AdcConf_AdcGroup_Adc0Group0;
	//ADC_CurrSampGroup[1u] = AdcConf_AdcGroup_Adc1Group0;

	//自检，第一次的数据不准需要丢
//	if(idx == AdcConf_AdcGroup_Adc0Group0)
//	{
//		Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_0);
//	}
//	else
//	{
//		Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_1);
//	}
	//Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_1);
	
	//Adc_Calibrate(AdcHwUnit_0, &CalibStatus);
	//Adc_Calibrate(AdcHwUnit_1, &CalibStatus);
	
	Adc_SetupResultBuffer(idx, &ADValBuff[tmepIdx]);
	Adc_EnableGroupNotification(idx);
	Adc_StartGroupConversion(idx);
}






void  ADC_Drv_DeInit(void)
{
		

}
void ADCIf_DeInit(void)
{
	  ADC_Drv_DeInit();
}



void ADCIf_Init(void)
{

	Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_0);
	Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_1);

	Adc_Init(NULL_PTR);
    Dma_Init(NULL_PTR);
}


/* Adc sampl data filtering calculation */
static void AdcIf_DataFilteCalc(uint8_t idx)
{
    uint8_t i = 0u, i0 = 0u, iMax = 0u, j = 0u;
    uint32_t temp = 0u;
    static uint8_t cnt[ADC_CFG_GROUP_NUM] = {0u, 0u, 0u};
    static uint16_t ADValCacheBuff[ADC_GROUP_CH_NUM][ADC_SAMP_NUM];
    //static int32_t sum = 0u;
    
    if(idx==AdcConf_AdcGroup_Adc0Group0)
    {
        i0 = 0u;
        iMax = ADC_CFG_GROUP_0_CHANNEL_NUM;
    }
    else if(idx==AdcConf_AdcGroup_Adc1Group0)
    {
        i0 = ADC_CFG_GROUP_0_CHANNEL_NUM;
        iMax = ADC_CFG_GROUP_0_CHANNEL_NUM \
               +ADC_CFG_GROUP_1_CHANNEL_NUM;
    }
    else if(idx==AdcConf_AdcGroup_Adc1Group1)
    {
        i0 = ADC_CFG_GROUP_0_CHANNEL_NUM \
             +ADC_CFG_GROUP_1_CHANNEL_NUM;
        iMax = ADC_CFG_GROUP_0_CHANNEL_NUM \
               +ADC_CFG_GROUP_1_CHANNEL_NUM \
               +ADC_CFG_GROUP_2_CHANNEL_NUM;
    }
    
    if(cnt[idx]<ADC_SAMP_NUM)
    {
        for(i=i0; i<iMax; i++)
        {
            ADValCacheBuff[i][cnt[idx]] = ADValBuff[i]&0xFFF;
        }
        
        cnt[idx]++;
    }
    else
    {
        for(i=i0; i<iMax; i++)
        {
            AdcResult[i].DataValidSt = 1u;
            temp = 0u;
          #if 1u
            for(j=2u;j<ADC_SAMP_NUM;j++)
            {
                temp += ADValCacheBuff[i][j];
            }
            AdcResult[i].Val = temp/(ADC_SAMP_NUM-2u);
          #else
            //Take the average after dropping the maximum and minimum
            SortU16FromMinToMax(&ADValCacheBuff,ADC_SAMP_NUM);
            //SortU16FromMinToMax(&tempVolt,10u);
            for(j=1u;j<(ADC_SAMP_NUM-1u);j++)
            {
                sum += ADValCacheBuff[j];
            }
            AdcResult[ADC_CurrSampGroup].Val = sum/(ADC_SAMP_NUM-2u);
            sum = 0u;
          #endif
            
            for(j=0u;j<ADC_SAMP_NUM;j++) //reset value
            {
                ADValCacheBuff[i][j] = 0u;
            }
        }
        
        cnt[idx] = 0u;
    }
}


/* Adc sampl error deal,  */
static uint8_t AdcIf_SampErrDeal(uint8_t idx)
{
    uint8_t ret = TRUE;
    static uint16_t cnt[ADC_CFG_GROUP_NUM] = {0u, 0u, 0u};
    
    if(idx == AdcConf_AdcGroup_Adc0Group0)
    {
        ADValBuff[0u] = ADC_VAL_INVALID;
        ADValBuff[1u] = ADC_VAL_INVALID;
        ADValBuff[2u] = ADC_VAL_INVALID;
    }
    else if(idx == AdcConf_AdcGroup_Adc1Group0)
    {
        ADValBuff[3u] = ADC_VAL_INVALID;
        ADValBuff[4u] = ADC_VAL_INVALID;
        ADValBuff[5u] = ADC_VAL_INVALID;
        ADValBuff[6u] = ADC_VAL_INVALID;
        ADValBuff[7u] = ADC_VAL_INVALID;
        ADValBuff[8u] = ADC_VAL_INVALID;
    }
    else if(idx == AdcConf_AdcGroup_Adc1Group1)
    {
        ADValBuff[9u] = ADC_VAL_INVALID;
        ADValBuff[10u] = ADC_VAL_INVALID;
    } 
    
    if(cnt[idx] == 0u)
    {
        Adc_DeInit();
        cnt[idx]++;
    }
    else if(cnt[idx]<T1_1000MS)
        cnt[idx]++;
    else
    {
        Adc_Init(NULL_PTR);
        ret = FALSE;
        cnt[idx] = 0u;
    }
    
    return ret;
}

BOOL ADCIf_Periodic_10mS_Call_Func(void)
{
	
}

BOOL ADCIf_Periodic_1mS_Call_Func(void)
{
	static uint8_t i = 0u;
	uint8_t tmepIdx = 0u;

	switch(AdcWorkSt[i])
	{
		case AdcWorkSt_Init:
			ADC_Drv_Init(i);
			AdcInitSts[i] = TRUE;
			AdcWorkSt[i] = AdcWorkSt_Sampling;
			break;
		
		case AdcWorkSt_Idle: //do nothing
			break;
		
		case AdcWorkSt_Sampling: //do nothing
			//while (ADC_STREAM_COMPLETED != Adc_GetGroupStatus(AdcConf_AdcGroup_Adc0Group0)); //test code
			break;
		
		case AdcWorkSt_SamplFinsh:
			//if(i==AdcConf_AdcGroup_Adc0Group0)
			//	  tmepIdx = 0u;
			//else if(i==AdcConf_AdcGroup_Adc1Group0)
			//	  tmepIdx = ADC_CFG_GROUP_0_CHANNEL_NUM;
			//else if(i==AdcConf_AdcGroup_Adc1Group1)
			//	  tmepIdx = ADC_CFG_GROUP_0_CHANNEL_NUM \
			//				+ADC_CFG_GROUP_1_CHANNEL_NUM;
			//Adc_ReadGroup(i, &ADValBuff[tmepIdx]);
			AdcIf_DataFilteCalc(i);
			//Adc_SetupResultBuffer(i, &ADValBuff[tmepIdx]);
			//Adc_EnableGroupNotification(i);
			if(i < (ADC_CFG_GROUP_NUM - 1))
			{
				//进入下一组ADC转换
				i++;
			}
			else
			{
				//从第一组开始
				i = AdcConf_AdcGroup_Adc0Group0;
			}
			if(AdcInitSts[i] == TRUE)
			{
				AdcWorkSt[i] = AdcWorkSt_Sampling;
				Adc_StartGroupConversion(i);
			}
			break;
		
		case AdcWorkSt_Err:
			if( AdcIf_SampErrDeal(i) == FALSE ) //error deal finish
			{
				AdcInitSts[i] = FALSE;
				AdcWorkSt[i] = AdcWorkSt_Init; //retry init
			}
			break;
		
		default:
			break;
	}
}




uint16_t ADCIf_Get_Normal_CalculateVoltage(uint8_t Ch)
{
	if( AdcResult[Ch].DataValidSt )
    {
        //AdcResult[ch].DataValidSt = 0u;
        return AdcResult[Ch].Val;
    }
    
    return ADC_VAL_INVALID;
}





