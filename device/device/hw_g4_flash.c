#include "hw_g4_flash.h"



u64  save_flash_data[save_flash_cnt];
/////////////////////////////////////////////////////////////////////////////////////
void g4_write_flash()                //调试本程序时必须使用单步f进入执行完解锁，然后全速、否则会进入硬件错误处理
{

//本段赋值代码放到主程序中写	
//save_flash_data[0]=0x01234567; 
//save_flash_data[1]=0x11234567; 
//save_flash_data[2]=0x21234567; 
//save_flash_data[3]=0x31234567; 
//save_flash_data[4]=0x41234567; 
//save_flash_data[5]=0x51234567; 	
//save_flash_data[6]=0x61234567; 
//save_flash_data[7]=0x71234567; 
//save_flash_data[8]=0x81234567; 	
//save_flash_data[9]=0x12345678;

	

	
	//解锁	/* Clear OPTVERR bit set on virgin samples */
	HAL_FLASH_Unlock();//FLASH解锁
 __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);  //清除flash的各种类型的错误标志	

	//擦除：算第几页、算长度、固定是块擦除还是页擦除
	//	FirstPage = GetPage(FLASH_USER_START_ADDR);  
	//擦除要用到的变量	
	u32 FirstPage = 0, NbOfPages = 0,PageError = 0;	
	static FLASH_EraseInitTypeDef EraseInitStruct; 
	FirstPage=(FLASH_USER_START_ADDR - FLASH_BASE) / FLASH_PAGE_SIZE;//算出第几页、算法是当前地址减基址/页内地址、启始地址是第62页：ADDR_FLASH_PAGE_62）
	NbOfPages =  1;                //擦除几页（长度）
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;    //擦除类型、整页擦还是块擦除
  EraseInitStruct.Page        = FirstPage;               //启始页
  EraseInitStruct.NbPages     = NbOfPages;              //长度页
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)//FLASH擦除
  {  
		
  }	
	
//写入数据
	uint32_t Address = 0; //写入时用到的变量
	u32 tmp_cnt=0;
	
	Address = FLASH_USER_START_ADDR;          //页写入的启始地址	
  while (Address <= FLASH_USER_END_ADDR)    //如果小于结束地址就一直写
  {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, save_flash_data[tmp_cnt]) == HAL_OK)//FLASH写入  //写64位长数据，所以地址加8
    {
      Address = Address + 8;  /* increment to next double word*/
			tmp_cnt++;
    }
   else
    {
      /* Error occurred while writing data in Flash memory.
         User can add here some code to deal with this error */
    }
  }

 HAL_FLASH_Lock();          //写完后，锁数据
 
}
	
/////////////////////////////////////////////////////////////////////////////////////
void g4_read_flash( )
{	u32 tmp_cnt=0,Address;

	Address = FLASH_USER_START_ADDR;          //页写入的启始地址	
  while (Address <= FLASH_USER_END_ADDR)    //如果小于结束地址就一直写
  {
    save_flash_data[tmp_cnt]=(*(volatile u32 *)Address);
    Address = Address + 8;  /* increment to next double word*/
		
		 save_flash_data[tmp_cnt]++;
		
  	tmp_cnt++;
   }
tmp_cnt=tmp_cnt;
}	

//**********************************备用代码查询***********************************//

//u32 g4_read_flash(u32 Address);
//void test_read_write()
//{
//uint32_t FirstPage = 0, NbOfPages = 0;
//uint32_t Address = 0, PageError = 0;	
//static FLASH_EraseInitTypeDef EraseInitStruct; 

////解锁	/* Clear OPTVERR bit set on virgin samples */
//	HAL_FLASH_Unlock();//FLASH解锁
// __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);  //清除flash的各种类型的错误标志

// 
////擦除：算第几页、算长度、固定是块擦除还是页擦除
//	FirstPage = GetPage(FLASH_USER_START_ADDR);  //算出第几页、算法是当前地址减基址/页内地址、启始地址是第62页：ADDR_FLASH_PAGE_62）
//  NbOfPages =  1;                //擦除几页（长度）

//  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;    //擦除类型、整页擦还是块擦除
//  EraseInitStruct.Page        = FirstPage;               //启始页
//  EraseInitStruct.NbPages     = NbOfPages;              //长度页

//  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
//     you have to make sure that these data are rewritten before they are accessed during code
//     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
//     DCRST and ICRST bits in the FLASH_CR register. */
//  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)//FLASH擦除
//  {
//    /*
//      Error occurred while page erase.
//      User can add here some code to deal with this error.
//      PageError will contain the faulty page and then to know the code error on this page,
//      user can call function 'HAL_FLASH_GetError()'
//    */
//    /* Infinite loop */

//  }


////准备写入
//  Address = FLASH_USER_START_ADDR;          //页写入的启始地址
//	
//	

//  while (Address < FLASH_USER_END_ADDR)    //如果小于结束地址就一直写
//  {
//    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, DATA_64) == HAL_OK)//FLASH写入  //写64位长数据，所以地址加8
//    {
//      Address = Address + 8;  /* increment to next double word*/
//    }
//   else
//    {
//      /* Error occurred while writing data in Flash memory.
//         User can add here some code to deal with this error */

//    }
//  }

//  HAL_FLASH_Lock();          //写完后，锁数据
// 
////	g4_read_flash(u64 g4_read_flash_buf[],u32 i)

//}
//////////////////////////////////////////////////////////////////////////////////////////////////
//volatile u32 MemoryProgramStatus = 0;
//volatile u32 read_l_result_data32, read_h_result_data32 ;
//u32 Address = 0;
//	
//	
//u64 temp_result,j=0;	
////读取和比较程序
  /* Check if the programmed data is OK
      MemoryProgramStatus = 0: data programmed correctly
      MemoryProgramStatus != 0: number of words not programmed correctly ******/
//  Address = FLASH_USER_START_ADDR;    //0x0801F000 
//  MemoryProgramStatus = 0x0;        //编程成功与否的状态位，是0为成功，非0为失败

//  do
//	{
//	read_l_result_data32 = *(volatile u32 *)Address;
//	Address = Address + 4;
//	read_h_result_data32 = *(volatile u32 *)Address;
//	Address = Address + 4;	
//	temp_result=(read_h_result_data32<<8)&&(read_l_result_data32);

//	g4_read_flash_buf[j]=temp_result;
//	}
//	while(j<=i);

//  while (Address < FLASH_USER_END_ADDR)
//  {
//    read_result_data32 = *(volatile u32 *)Address;// 读取很简单，按地址取内容即可、读取FLASH内容

//    if (read_result_data32 != DATA_32)//与写入的内容比较
//    {
//      MemoryProgramStatus++;
//    }
//    Address = Address + 4;
//  }

//  /*Check if there is an issue to program data*/
//  if (MemoryProgramStatus == 0)
//  {
//    /* No error detected. Switch on LED2*/
//		while(1)
//		{
//			HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//			HAL_Delay(500);
//		}
//  
//  }
//  else
//  {
//    /* Error detected. LED2 will blink with 1s period */

//  }

//  /* USER CODE END 2 */

//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
//  while (1)
//  {
//    /* USER CODE END WHILE */

//    /* USER CODE BEGIN 3 */
//  }
//  /* USER CODE END 3 */		
	




/* USER CODE BEGIN PFP */
//static uint32_t GetPage(uint32_t Addr)
//{
//  return (Addr - FLASH_BASE) / FLASH_PAGE_SIZE;
//}
//void g4_write_flash(void);   //调试本程序时必须使用单步、否则会进入硬件错误处理
//	





