/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : main.c
  - Author        : zeweni
  - Update date   : 2020.01.11
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
/**
  * @name    main
  * @brief   main program
  * @param   None
  * @return  None
***/
int main(void)
{
    extern float G_VinDat,G_VinDat2;
	STC8x_System_Init();

	for(;;)
	{
        printf("Vin = %0.5f V\r\n", (float)(G_VinDat * 5.0f / 1024));
		printf("Vin2 = %0.5f V\r\n", (float)(G_VinDat2 * 5.0f / 1024));
        delay_ms(500);
	}

}



/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



