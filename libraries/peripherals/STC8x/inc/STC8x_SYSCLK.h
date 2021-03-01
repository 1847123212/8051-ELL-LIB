/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_SYSCLK.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote SYSCLK chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_SYSCLK_H_
#define __STC8x_SYSCLK_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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
| @Description: System clock ferquency division define   |
--------------------------------------------------------*/
#if     (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx )

    #define     SYSCLK_DIV1     0x10
    #define     SYSCLK_DIV2     0x20
    #define     SYSCLK_DIV4     0x40
    #define     SYSCLK_DIV8     0x70
    #define    SYSCLK_DIV16     0x90
    #define    SYSCLK_DIV32     0xB0
    #define    SYSCLK_DIV64     0xD0
    #define   SYSCLK_DIV128     0xF0

#endif

/*--------------------------------------------------------
| @Description: IRC frequency little trimmer enum type   |
--------------------------------------------------------*/

typedef enum
{
	TRIM0 = 0x00,
	TRIM1 = 0x01,
	TRIM2 = 0x02,
    TRIM3 = 0x03  
}   LIRCTRIM_Type;

/*--------------------------------------------------------
| @Description: System clock out pin enum type           |
--------------------------------------------------------*/

typedef enum
{
	SCLK_OUT_P54 = 0x00, /* GPIO Port 5 pin 4 */
	SCLK_OUT_P16 = 0x01  /* GPIO Port 1 pin 6 */
}   SCLKOut_Type;



/*--------------------------------------------------------
| @Description: Master clock source enum type            |
--------------------------------------------------------*/

typedef enum
{
	AUTO = 0x00,   /* stc -isp toll control */
	HIRC = 0x01,   /* High internal 4MHz~24MHz oscillator */
	LIRC = 0x02,   /* Internal 32KHz oscillator */
    XOSC = 0x03,   /* External oscillator control */
#if (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
    X32KSC = 0x04  /* External  32KHzoscillator control */
#endif
}   MCLKSrc_Type;

#if (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

/*--------------------------------------------------------
| @Description: External crystal filter enum type        |
--------------------------------------------------------*/
    typedef enum
    {
        XOSC_Filter_150MHz = 0x00,
        XOSC_Filter_125MHz = 0x01,
        XOSC_Filter_66MHz  = 0x02,
        XOSC_Filter_Null   = 0x03
    }   XOSCFilter_Type;

/*--------------------------------------------------------
| @Description: IRC band selector enum type              |
--------------------------------------------------------*/
    typedef enum
    {
        IRC_Band_20MHz = 0x00,
        IRC_Band_35MHz = 0x01
    }   IRCBand_Type;

#endif


/**
  * @name    SYSCLK_InitType
  * @brief   System clock init struct type   
  * @param   MCLKSrc  Master clock source
  * @param   IRCTRIM  IRC frequency trimmer
  * @param   LIRCTRIM  IRC little trimmer
  * @param   MCLKDiv  Master clock frequency division Parameter range: 0 <= MDiv <= 255
  * @param   SCLKDiv  System clock ferquency division
  * @param   SCLKOutPin  Select system clock output pin
  * @param   XOSCFilter  External crystal filter (STC8Hx)
***/
typedef struct
{
    MCLKSrc_Type MCLKSrc;  /* Master clock source */
	
    uint8_t IRCTRIM;    /* IRC frequency trimmer */
	
    LIRCTRIM_Type LIRCTRIM;  /* IRC little trimmer */
	
    uint8_t MCLKDiv;  /* Master clock frequency division Parameter range: 0 <= MDiv <= 255 */

    uint8_t SCLKDiv;  /* System clock ferquency division */

    SCLKOut_Type SCLKOutPin; /* Select system clock output pin */
    
#if (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    XOSCFilter_Type XOSCFilter; 

    IRCBand_Type  IRCBand;
    
#endif

}   SYSCLK_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

uint32_t Get_SysClk_FRE(void);
FSCSTATE SYSCLK_Init(const SYSCLK_InitType *sysClkn);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
