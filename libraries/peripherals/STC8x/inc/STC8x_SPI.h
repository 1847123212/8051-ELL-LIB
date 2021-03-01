/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_SPI.h
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote SPI chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_SPI_H_
#define __STC8x_SPI_H_
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
| @Description: SPI type control enum                    |
--------------------------------------------------------*/

typedef enum
{
  SPI_Type_Master_Slave = 0x00,
  SPI_Type_Master       = 0x90,
  SPI_Type_Slave        = 0x80,
} SPIType_Type;

/*--------------------------------------------------------
| @Description: SPI clock source select enum             |
--------------------------------------------------------*/

typedef enum
{
  SPI_SCLK_DIV_4  = 0x00,
  SPI_SCLK_DIV_8  = 0x01,
  SPI_SCLK_DIV_16 = 0x02,
  SPI_SCLK_DIV_32 = 0x03
} SPIClkSrc_Type;

/*--------------------------------------------------------
| @Description: SPI Transmission sequence enum           |
--------------------------------------------------------*/

typedef enum
{
  SPI_Tran_MSB = 0x00,
  SPI_Tran_LSB = 0x01
} SPITran_Type;

/*--------------------------------------------------------
| @Description: SPI mode control enum                    |
--------------------------------------------------------*/

typedef enum
{
  SPI_Mode_0  = 0x00,
  SPI_Mode_1  = 0x01,
  SPI_Mode_2  = 0x02,
  SPI_Mode_3  = 0x03
} SPIMode_Type;

/**
  * @name    SPIInit_Type
  * @brief   SPI init structure 
  * @param   Type     SPI_Type_Master | SPI_Type_Slave | SPI_Type_Master_Slave
  * @param   ClkSrc   SPI_SCLK_DIV_4 | SPI_SCLK_DIV_8 | SPI_SCLK_DIV_16 | SPI_SCLK_DIV_32
  * @param   Mode     SPI_Mode_0 | SPI_Mode_1 | SPI_Mode_2 | SPI_Mode_3
  * @param   Tran     SPI_Tran_MSB | SPI_Tran_LSB
  * @param   Run      ENABLE | DISABLE 
***/
typedef struct 
{
  SPIType_Type Type;
  SPIClkSrc_Type ClkSrc;
  SPIMode_Type Mode;
  SPITran_Type Tran;
  FUNSTATE Run;
} SPIInit_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

FSCSTATE SPI_Init(SPIInit_Type *spix);
FSCSTATE SPI_Send_Data(uint8 dat);
uint8 SPI_Rev_Data(void);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
