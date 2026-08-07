/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      WatchDogIf.c                                                             */
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

#include "Ecal_WatchDog.h"

#include "Type_Define.h"
#include "Wdg.h"
/* ================================ NEW API ================================ */




void WatchDogIf_Enable(void)
{

}


void WatchDogIf_Init(void)
{
	  Wdg_Init(NULL_PTR);
  	#if (WDGM_FUNCTION_SWITCH == STD_ON)
    WdgM_Init(&WdgMConfigRoot[0u]);
  	#else
   Wdg_SetMode(WDGIF_OFF_MODE);
  	#endif
}



void WatchDogIf_Disable(void)
{	

	
}

void WatchDogIf_Free(void)
{
	#if(WDGM_FUNCTION_SWITCH == STD_ON)
    //WdgM_CheckpointReached(1u,0u);

    WdgM_MainFunction();

  #endif
	
}

