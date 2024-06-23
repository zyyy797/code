
#include "hw_g4_lcd1602_6800.h"

//-----------------------------------------------------------
void  lcd1602_delay_us(u32 CountLing)
 {	u8 i;
  while(CountLing--)
				{ 	 i = 30;
					while(i--);
				}
 }
//-----------------------------------------------------------
void  lcd1602_gpio_init()
{
//		GPIO_InitTypeDef GPIO_InitStructure
	 GPIO_InitTypeDef GPIO_InitStruct = {0};

	 __HAL_RCC_GPIOC_CLK_ENABLE();
   __HAL_RCC_GPIOA_CLK_ENABLE();

	
	 
	//  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = RS_PIN|RW_PIN|E_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CMD_PORT, &GPIO_InitStruct);
	 
	
	//  /*Configure GPIO pins : PA0 PA1 PA2 PA3 PA4 PA5 PA6 PA7 */	 
  GPIO_InitStruct.Pin = D0_PIN|D1_PIN|D2_PIN|D3_PIN|D4_PIN|D5_PIN|D6_PIN|D7_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
	
}
//-----------------------------------------------------------
void  lcd1602_write_data_to_port(u8 i)
{
	if((i&0x01)==0x01)	{GPIO_SetBits(DATA_PORT,D0_PIN);} else{GPIO_ResetBits(DATA_PORT,D0_PIN);}
	if((i&0x02)==0x02)	{GPIO_SetBits(DATA_PORT,D1_PIN);} else{GPIO_ResetBits(DATA_PORT,D1_PIN);}
	if((i&0x04)==0x04)	{GPIO_SetBits(DATA_PORT,D2_PIN);} else{GPIO_ResetBits(DATA_PORT,D2_PIN);}
	if((i&0x08)==0x08)	{GPIO_SetBits(DATA_PORT,D3_PIN);} else{GPIO_ResetBits(DATA_PORT,D3_PIN);}
	if((i&0x10)==0x10)	{GPIO_SetBits(DATA_PORT,D4_PIN);} else{GPIO_ResetBits(DATA_PORT,D4_PIN);}
	if((i&0x20)==0x20)	{GPIO_SetBits(DATA_PORT,D5_PIN);} else{GPIO_ResetBits(DATA_PORT,D5_PIN);}
	if((i&0x40)==0x40)	{GPIO_SetBits(DATA_PORT,D6_PIN);} else{GPIO_ResetBits(DATA_PORT,D6_PIN);}
	if((i&0x80)==0x80)	{GPIO_SetBits(DATA_PORT,D7_PIN);} else{GPIO_ResetBits(DATA_PORT,D7_PIN);}
}
//-----------------------------------------------------------
void  lcd1602_check_busy()
{
		lcd1602_write_data_to_port(0XFF);
		SET_E_PIN	;		//1
		CLR_RS_PIN  ; //0
		SET_RW_PIN	;	//1	
	
//输出改输入
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	 GPIO_InitStruct.Pin = D7_PIN;
	 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull = GPIO_PULLUP;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
	 
  	while(GPIO_ReadInputDataBit(DATA_PORT,D7_PIN)==1); //PB7为高则忙，无法进行下一步操作。
	 

	 GPIO_InitStruct.Pin =D7_PIN;
	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct); 
	 
		CLR_E_PIN;	//001 表示读完后
}
//-----------------------------------------------------------
void  lcd1602_write_cmd(u8 cmd)
{
	lcd1602_check_busy();
	SET_E_PIN;
	CLR_RS_PIN; 
	CLR_RW_PIN;
	lcd1602_delay_us(100);
	lcd1602_write_data_to_port(cmd);
	lcd1602_delay_us(100);	
	CLR_E_PIN;
}
//-----------------------------------------------------------
void  lcd1602_write_data(u8 data)
{
	lcd1602_check_busy();
	SET_E_PIN;
	SET_RS_PIN; 
	CLR_RW_PIN;
	lcd1602_delay_us(100);
	lcd1602_write_data_to_port(data);
	lcd1602_delay_us(100);	
	CLR_E_PIN;
}
//-----------------------------------------------------------
void  lcd1602_init(void)
{
	lcd1602_gpio_init();
	lcd1602_delay_us(100);
  lcd1602_write_cmd(0x38);//8位数据宽度、2行显示、5*8格式点阵显示
	lcd1602_delay_us(100);
  lcd1602_write_cmd(0x0c);//打开显示、无游标无闪烁。
	lcd1602_delay_us(100);	
  lcd1602_write_cmd(0x06);//输过字符传送后、游标右移、显示的字符不移动
	lcd1602_delay_us(100);		
	lcd1602_write_cmd(0x01);//显示清屏
	lcd1602_delay_us(100);
}
//-----------------------------------------------------------
void lcd1602_cgram_disp_char(u8 x,u8 y,u8 data)
{  u8 address;
		if(x==0) { if(y>15) y%=16;  //y的坐标大于15，坐标循环
							address=0x80+y;
							} 
					else{if(y>15) y%=16;  //y的坐标大于15，坐标循环
							address=0xc0+y;   
							};
		lcd1602_write_cmd(address);				
		lcd1602_write_data(data);  //数字0
}
//-----------------------------------------------------------
void lcd1602_cgram_disp_string(u8 x,u8 y,u8 *p)
{ 
	while(*p!='\0')
	{
		lcd1602_cgram_disp_char(x,y,*p);		
		y++;
		p++;
	}	
}
//-----------------------------------------------------------
void  lcd1602_cgram_disp_num(u8 x,u8 y,u32 num)
{  
 u8 address;
		if(x==0) { if(y>15) y%=16;  //y的坐标大于15，坐标循环
							address=0x80+y;
							} 
					else{if(y>15) y%=16;  //y的坐标大于15，坐标循环
							address=0xc0+y;   
							};
		lcd1602_write_cmd(address);				
		lcd1602_write_data(num+0x30);  //数字0

}

