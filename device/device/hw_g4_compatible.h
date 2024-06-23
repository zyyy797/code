#ifndef __HW_G4_COMPATIBLE_H
#define __HW_G4_COMPATIBLE_H

#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_gpio.h"


#define    u8   uint8_t
#define    u32  uint32_t
#define    u64  uint64_t

#define GPIO_SetBits(a,b) HAL_GPIO_WritePin(a, b,GPIO_PIN_SET)
#define GPIO_ResetBits(a,b) HAL_GPIO_WritePin(a, b,GPIO_PIN_RESET)

#define GPIO_ReadInputDataBit(a,b) HAL_GPIO_ReadPin(a, b)

//Òý½ÅÈ¡·´
//HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);//PB4¡¤-¡Áa¨º?3?

#endif
//void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)

//	while(1)
//	{ 		u32  i;
//		GPIO_SetBits(GPIOB,GPIO_PIN_0);

//	for(i=0;i<0x3fffff;i++);
//		GPIO_ResetBits(GPIOB,GPIO_PIN_0);	
//	for(i=0;i<0x3fffff;i++);
//	}
