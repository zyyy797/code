#ifndef __HW_LCD1602_6800_H
#define __HW_LCD1602_6800_H


#include "hw_g4_compatible.h"






//�˿���Ҫ��ʵ�ʽ��߽��и���***********************////
		//   LCD1602_PIN     CPU_PIN
		//     VSS							GND     			// 1.GND
		//     VDD							5V     				// 2.VDD
		//     VL								��λ��   			// 3.VL   Һ�����Ҷȵ���
#define    RS_PIN						GPIO_PIN_13   // 4.���ݡ�����ѡ��  0д���1д����
#define    RW_PIN						GPIO_PIN_14   // 5.��/дѡ��  
#define    E_PIN						GPIO_PIN_15  	// 6.ʹ���ź�
#define    CMD_PORT					GPIOC							//����3�������������õĶ˿�
#define		 CMD_PORT_RCC			RCC_APB2Periph_GPIOC

#define    D0_PIN						GPIO_PIN_0  	// 7.����D0����
#define    D1_PIN						GPIO_PIN_1  	// 8.����D1����
#define    D2_PIN						GPIO_PIN_2  	// 9.����D2����
#define    D3_PIN						GPIO_PIN_3  	// 10.����D3����
#define    D4_PIN						GPIO_PIN_4  	// 11.����D4����
#define    D5_PIN						GPIO_PIN_5  	// 12.����D5����
#define    D6_PIN						GPIO_PIN_6  	// 13.����D6����
#define    D7_PIN						GPIO_PIN_7  	// 14.����D7����
																					// 15.����A����,����3V3����5V
																					// 16.����K����,��GND
#define    DATA_PORT					GPIOA				//���������������õĶ˿�
#define		 DATA_PORT_RCC			RCC_APB2Periph_GPIOA
//�˿���Ҫ��ʵ�ʽ��߽��и���***********************////

#define			SET_RS_PIN		GPIO_SetBits(CMD_PORT,RS_PIN)
#define			CLR_RS_PIN		GPIO_ResetBits(CMD_PORT,RS_PIN)
#define			SET_RW_PIN		GPIO_SetBits(CMD_PORT,RW_PIN)
#define			CLR_RW_PIN		GPIO_ResetBits(CMD_PORT,RW_PIN)
#define			SET_E_PIN		GPIO_SetBits(CMD_PORT,E_PIN)
#define			CLR_E_PIN		GPIO_ResetBits(CMD_PORT,E_PIN)

//���ᱻ���������õ�����
void 	lcd1602_delay_us(u32 CountLing);  //uint8_t
void  lcd1602_gpio_init(void);
void  lcd1602_check_busy(void);
void  lcd1602_write_data_to_port(u8 i);
void  lcd1602_write_cmd(u8 cmd);
void  lcd1602_write_data(u8 data);


//��������õ���ʾ
void  lcd1602_init(void);
void  lcd1602_cgram_disp_char(u8 x,u8 y,u8 data);     //lcd1602_cgram_disp_char(1,15,'i');
void  lcd1602_cgram_disp_string(u8 x,u8 y,u8 *p);  //x���� ��0��ʼ�����ֵΪ1. y���У���0��ʼ�����ֵΪ15
																										//  lcd1602_cgram_disp_string(0,0,"wellcome to ningbo");
void  lcd1602_cgram_disp_num(u8 x,u8 y,u32 num);  //num��ֵ�����ʾ1λ�����㹻�ˣ�3λ����ô��																												
#endif	


