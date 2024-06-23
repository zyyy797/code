#ifndef __HW_LCD1602_6800_H
#define __HW_LCD1602_6800_H


#include "hw_g4_compatible.h"






//端口需要按实际接线进行更改***********************////
		//   LCD1602_PIN     CPU_PIN
		//     VSS							GND     			// 1.GND
		//     VDD							5V     				// 2.VDD
		//     VL								电位器   			// 3.VL   液晶屏灰度调节
#define    RS_PIN						GPIO_PIN_13   // 4.数据、命令选择  0写命令、1写数据
#define    RW_PIN						GPIO_PIN_14   // 5.读/写选择  
#define    E_PIN						GPIO_PIN_15  	// 6.使能信号
#define    CMD_PORT					GPIOC							//上面3个命令引脚所用的端口
#define		 CMD_PORT_RCC			RCC_APB2Periph_GPIOC

#define    D0_PIN						GPIO_PIN_0  	// 7.数据D0引脚
#define    D1_PIN						GPIO_PIN_1  	// 8.数据D1引脚
#define    D2_PIN						GPIO_PIN_2  	// 9.数据D2引脚
#define    D3_PIN						GPIO_PIN_3  	// 10.数据D3引脚
#define    D4_PIN						GPIO_PIN_4  	// 11.数据D4引脚
#define    D5_PIN						GPIO_PIN_5  	// 12.数据D5引脚
#define    D6_PIN						GPIO_PIN_6  	// 13.数据D6引脚
#define    D7_PIN						GPIO_PIN_7  	// 14.数据D7引脚
																					// 15.背光A引脚,接正3V3或正5V
																					// 16.背光K引脚,接GND
#define    DATA_PORT					GPIOA				//上面数据引脚所用的端口
#define		 DATA_PORT_RCC			RCC_APB2Periph_GPIOA
//端口需要按实际接线进行更改***********************////

#define			SET_RS_PIN		GPIO_SetBits(CMD_PORT,RS_PIN)
#define			CLR_RS_PIN		GPIO_ResetBits(CMD_PORT,RS_PIN)
#define			SET_RW_PIN		GPIO_SetBits(CMD_PORT,RW_PIN)
#define			CLR_RW_PIN		GPIO_ResetBits(CMD_PORT,RW_PIN)
#define			SET_E_PIN		GPIO_SetBits(CMD_PORT,E_PIN)
#define			CLR_E_PIN		GPIO_ResetBits(CMD_PORT,E_PIN)

//不会被主函数调用到函数
void 	lcd1602_delay_us(u32 CountLing);  //uint8_t
void  lcd1602_gpio_init(void);
void  lcd1602_check_busy(void);
void  lcd1602_write_data_to_port(u8 i);
void  lcd1602_write_cmd(u8 cmd);
void  lcd1602_write_data(u8 data);


//真正会调用的显示
void  lcd1602_init(void);
void  lcd1602_cgram_disp_char(u8 x,u8 y,u8 data);     //lcd1602_cgram_disp_char(1,15,'i');
void  lcd1602_cgram_disp_string(u8 x,u8 y,u8 *p);  //x是行 从0开始，最大值为1. y是列，从0开始，最大值为15
																										//  lcd1602_cgram_disp_string(0,0,"wellcome to ningbo");
void  lcd1602_cgram_disp_num(u8 x,u8 y,u32 num);  //num的值最大显示1位数，足够了，3位数怎么办																												
#endif	


