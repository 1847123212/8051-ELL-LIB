/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (17870070675@163.com)

 * This file is part of 8051 ELL low-layer libraries.

 * 8051 ELL low-layer libraries is free software: you can redistribute 
 * it and/or modify it under the terms of the Apache-2.0 License.

 * 8051 ELL low-layer libraries is distributed in the hope that it will 
 * be useful,but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_TIMER_H_
#define __STC8x_TIMER_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/

#include "Lib_CFG.h"
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#if    (PER_LIB_MCU_MUODEL == STC8Ax)
    #include "STC8Ax_REG.h"  
#elif  (PER_LIB_MCU_MUODEL == STC8Cx)
    #include "STC8Cx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Fx)
    #include "STC8Fx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Gx)
    #include "STC8Gx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Hx)
    #include "STC8Hx_REG.h"
#endif

/*--------------------------------------------------------
| @Description: STC8x core                               |
--------------------------------------------------------*/

#include "STC8x_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: TIMER number                             |
--------------------------------------------------------*/
/*
TIMER0: 16 Bit timer has four working modes
TIMER1: Same as timer 0, but invalid in 16 bit auto reload 
        mode without maskable interrupt, stop counting
TIMER2: The working mode is fixed in 16 bit auto reload mode
TIMER3: The working mode is fixed in 16 bit auto reload mode
TIMER4: The working mode is fixed in 16 bit auto reload mode
*/

/*--------------------------------------------------------
| @Description: TIMER type                               |
--------------------------------------------------------*/
typedef enum
{
    TIMER_Type_Timer   = 0x00, 
    TIMER_Type_Counter = 0x01
}   TIMERType_Type;

/*--------------------------------------------------------
| @Description: TIMER mode enum                          |
--------------------------------------------------------*/
/*
Mode 0: 16 Bit auto reload timer
Mode 1: 16 Bit non auto reload timer
Mode 2:  8 Bit auto reload timer
Mode 3: 16 Bit auto reload non maskable interrupt
*/
typedef enum
{
	TIMER_16BitAutoReload       = 0x00, 
	TIMER_16Bit                 = 0x01, 
	TIMER_8BitAutoReload        = 0x02,  
	TIMER_16BitAutoReloadNoMask = 0x03 
}	TIMERMode_Type;

/*--------------------------------------------------------
| @Description: TIME Clock mode enum                     |
--------------------------------------------------------*/
/*
Timing 12t mode: The machine executes 12 cycles
Timing  1t mode: The machine executes 1 cycles
*/
typedef enum
{
	TIMER_TCY_1T  = 0x00,	
	TIMER_TCY_12T = 0x01
}	TIMERTCycle_Type;

/**
  * @name    TIMER_InitType
  * @brief   TIME Init structure
  * @param   SysClokDiv  system clock division to timer use
  * @param   Type        timer type
  * @param   Mode        Working mode
  * @param   TCycle      Instruction cycle
  * @param   ClkOut      Programmable clock output
  * @param   Value       Loading initial value
  * @param   Run         Operation control bit
***/
typedef struct 
{
#if  (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
    uint8_t SysClkDiv;   /* just STC8G、STC8H */
#endif
    TIMERType_Type Type;       
    TIMERMode_Type Mode;
    TIMERTCycle_Type TCycle;   
    FUNSTATE ClkOut;           
    uint16_t Value;              
    FUNSTATE Run;              
}   TIMER_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/**
  * @name    TIMER5_Wake_Up_Power
  * @brief   调电唤醒定时器5初始化函数。 
  *          Power up timer 5 initialization function.
  * @param   value  [IN] 定时器5调电唤醒时间值。Timer power up time value.
  * @param   run    [IN] 定时器5调电唤醒运行控制位。Timer 5 power up operation control bit.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER5_Wake_Up_Power(uint16_t value,FUNSTATE run);

/**
  * @name    TIMER0_Init
  * @brief   定时器0初始化函数。 
  *          TIMER0 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER0_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER1_Init
  * @brief   定时器1初始化函数。 
  *          TIMER1 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER1_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER2_Init
  * @brief   定时器2初始化函数。 
  *          TIMER2 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER2_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER3_Init
  * @brief   定时器3初始化函数。 
  *          TIMER3 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER3_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER4_Init
  * @brief   定时器4初始化函数。 
  *          TIMER4 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER4_Init(const TIMER_InitType *timerx);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

