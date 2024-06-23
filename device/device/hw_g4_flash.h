#ifndef __HW_G4_FLASH_H
#define __HW_G4_FLASH_H

#include "hw_g4_compatible.h"
/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 2 Kbytes */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000800) /* Base @ of Page 1, 2 Kbytes */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08001000) /* Base @ of Page 2, 2 Kbytes */
#define ADDR_FLASH_PAGE_3     ((uint32_t)0x08001800) /* Base @ of Page 3, 2 Kbytes */
#define ADDR_FLASH_PAGE_4     ((uint32_t)0x08002000) /* Base @ of Page 4, 2 Kbytes */
#define ADDR_FLASH_PAGE_5     ((uint32_t)0x08002800) /* Base @ of Page 5, 2 Kbytes */
#define ADDR_FLASH_PAGE_6     ((uint32_t)0x08003000) /* Base @ of Page 6, 2 Kbytes */
#define ADDR_FLASH_PAGE_7     ((uint32_t)0x08003800) /* Base @ of Page 7, 2 Kbytes */
#define ADDR_FLASH_PAGE_8     ((uint32_t)0x08004000) /* Base @ of Page 8, 2 Kbytes */
#define ADDR_FLASH_PAGE_9     ((uint32_t)0x08004800) /* Base @ of Page 9, 2 Kbytes */
#define ADDR_FLASH_PAGE_10    ((uint32_t)0x08005000) /* Base @ of Page 10, 2 Kbytes */
#define ADDR_FLASH_PAGE_11    ((uint32_t)0x08005800) /* Base @ of Page 11, 2 Kbytes */
#define ADDR_FLASH_PAGE_12    ((uint32_t)0x08006000) /* Base @ of Page 12, 2 Kbytes */
#define ADDR_FLASH_PAGE_13    ((uint32_t)0x08006800) /* Base @ of Page 13, 2 Kbytes */
#define ADDR_FLASH_PAGE_14    ((uint32_t)0x08007000) /* Base @ of Page 14, 2 Kbytes */
#define ADDR_FLASH_PAGE_15    ((uint32_t)0x08007800) /* Base @ of Page 15, 2 Kbytes */
#define ADDR_FLASH_PAGE_16    ((uint32_t)0x08008000) /* Base @ of Page 16, 2 Kbytes */
#define ADDR_FLASH_PAGE_17    ((uint32_t)0x08008800) /* Base @ of Page 17, 2 Kbytes */
#define ADDR_FLASH_PAGE_18    ((uint32_t)0x08009000) /* Base @ of Page 18, 2 Kbytes */
#define ADDR_FLASH_PAGE_19    ((uint32_t)0x08009800) /* Base @ of Page 19, 2 Kbytes */
#define ADDR_FLASH_PAGE_20    ((uint32_t)0x0800A000) /* Base @ of Page 20, 2 Kbytes */
#define ADDR_FLASH_PAGE_21    ((uint32_t)0x0800A800) /* Base @ of Page 21, 2 Kbytes */
#define ADDR_FLASH_PAGE_22    ((uint32_t)0x0800B000) /* Base @ of Page 22, 2 Kbytes */
#define ADDR_FLASH_PAGE_23    ((uint32_t)0x0800B800) /* Base @ of Page 23, 2 Kbytes */
#define ADDR_FLASH_PAGE_24    ((uint32_t)0x0800C000) /* Base @ of Page 24, 2 Kbytes */
#define ADDR_FLASH_PAGE_25    ((uint32_t)0x0800C800) /* Base @ of Page 25, 2 Kbytes */
#define ADDR_FLASH_PAGE_26    ((uint32_t)0x0800D000) /* Base @ of Page 26, 2 Kbytes */
#define ADDR_FLASH_PAGE_27    ((uint32_t)0x0800D800) /* Base @ of Page 27, 2 Kbytes */
#define ADDR_FLASH_PAGE_28    ((uint32_t)0x0800E000) /* Base @ of Page 28, 2 Kbytes */
#define ADDR_FLASH_PAGE_29    ((uint32_t)0x0800E800) /* Base @ of Page 29, 2 Kbytes */
#define ADDR_FLASH_PAGE_30    ((uint32_t)0x0800F000) /* Base @ of Page 30, 2 Kbytes */
#define ADDR_FLASH_PAGE_31    ((uint32_t)0x0800F800) /* Base @ of Page 31, 2 Kbytes */
#define ADDR_FLASH_PAGE_32    ((uint32_t)0x08010000) /* Base @ of Page 32, 2 Kbytes */
#define ADDR_FLASH_PAGE_33    ((uint32_t)0x08010800) /* Base @ of Page 33, 2 Kbytes */
#define ADDR_FLASH_PAGE_34    ((uint32_t)0x08011000) /* Base @ of Page 34, 2 Kbytes */
#define ADDR_FLASH_PAGE_35    ((uint32_t)0x08011800) /* Base @ of Page 35, 2 Kbytes */
#define ADDR_FLASH_PAGE_36    ((uint32_t)0x08012000) /* Base @ of Page 36, 2 Kbytes */
#define ADDR_FLASH_PAGE_37    ((uint32_t)0x08012800) /* Base @ of Page 37, 2 Kbytes */
#define ADDR_FLASH_PAGE_38    ((uint32_t)0x08013000) /* Base @ of Page 38, 2 Kbytes */
#define ADDR_FLASH_PAGE_39    ((uint32_t)0x08013800) /* Base @ of Page 39, 2 Kbytes */
#define ADDR_FLASH_PAGE_40    ((uint32_t)0x08014000) /* Base @ of Page 40, 2 Kbytes */
#define ADDR_FLASH_PAGE_41    ((uint32_t)0x08014800) /* Base @ of Page 41, 2 Kbytes */
#define ADDR_FLASH_PAGE_42    ((uint32_t)0x08015000) /* Base @ of Page 42, 2 Kbytes */
#define ADDR_FLASH_PAGE_43    ((uint32_t)0x08015800) /* Base @ of Page 43, 2 Kbytes */
#define ADDR_FLASH_PAGE_44    ((uint32_t)0x08016000) /* Base @ of Page 44, 2 Kbytes */
#define ADDR_FLASH_PAGE_45    ((uint32_t)0x08016800) /* Base @ of Page 45, 2 Kbytes */
#define ADDR_FLASH_PAGE_46    ((uint32_t)0x08017000) /* Base @ of Page 46, 2 Kbytes */
#define ADDR_FLASH_PAGE_47    ((uint32_t)0x08017800) /* Base @ of Page 47, 2 Kbytes */
#define ADDR_FLASH_PAGE_48    ((uint32_t)0x08018000) /* Base @ of Page 48, 2 Kbytes */
#define ADDR_FLASH_PAGE_49    ((uint32_t)0x08018800) /* Base @ of Page 49, 2 Kbytes */
#define ADDR_FLASH_PAGE_50    ((uint32_t)0x08019000) /* Base @ of Page 50, 2 Kbytes */
#define ADDR_FLASH_PAGE_51    ((uint32_t)0x08019800) /* Base @ of Page 51, 2 Kbytes */
#define ADDR_FLASH_PAGE_52    ((uint32_t)0x0801A000) /* Base @ of Page 52, 2 Kbytes */
#define ADDR_FLASH_PAGE_53    ((uint32_t)0x0801A800) /* Base @ of Page 53, 2 Kbytes */
#define ADDR_FLASH_PAGE_54    ((uint32_t)0x0801B000) /* Base @ of Page 54, 2 Kbytes */
#define ADDR_FLASH_PAGE_55    ((uint32_t)0x0801B800) /* Base @ of Page 55, 2 Kbytes */
#define ADDR_FLASH_PAGE_56    ((uint32_t)0x0801C000) /* Base @ of Page 56, 2 Kbytes */
#define ADDR_FLASH_PAGE_57    ((uint32_t)0x0801C800) /* Base @ of Page 57, 2 Kbytes */
#define ADDR_FLASH_PAGE_58    ((uint32_t)0x0801D000) /* Base @ of Page 58, 2 Kbytes */
#define ADDR_FLASH_PAGE_59    ((uint32_t)0x0801D800) /* Base @ of Page 59, 2 Kbytes */
#define ADDR_FLASH_PAGE_60    ((uint32_t)0x0801E000) /* Base @ of Page 60, 2 Kbytes */
#define ADDR_FLASH_PAGE_61    ((uint32_t)0x0801E800) /* Base @ of Page 61, 2 Kbytes */
#define ADDR_FLASH_PAGE_62    ((uint32_t)0x0801F000) /* Base @ of Page 62, 2 Kbytes */
#define ADDR_FLASH_PAGE_63    ((uint32_t)0x0801F800) /* Base @ of Page 63, 2 Kbytes */
/* USER CODE END EC */



//extern const u32  save_flash_cnt;
//extern u64  save_flash_data[save_flash_cnt];

#define FLASH_USER_START_ADDR   ADDR_FLASH_PAGE_62   /* Start @ of user Flash area 0x0801F000 */
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_62+(save_flash_cnt-1)*8   /* End @ of user Flash area  */ //数据总长不能超500个32bit字

#define save_flash_cnt 10         //数组个数定义 数组要小于512个 数组名定义在.c函数中

/* 地址变量存储清单

//   读和写的地址								写时对应的数组名            用户的变量名    
FLASH_USER_START_ADDR  					save_flash_data[0]    			CF_CNT

FLASH_USER_START_ADDR+8	  	    save_flash_data[1]  

FLASH_USER_START_ADDR+16	      save_flash_data[2]

FLASH_USER_START_ADDR+24	      save_flash_data[3]

FLASH_USER_START_ADDR+32				save_flash_data[4]   

FLASH_USER_START_ADDR+40	  	  save_flash_data[5]  

FLASH_USER_START_ADDR+48	      save_flash_data[6]

FLASH_USER_START_ADDR+56	      save_flash_data[7]

FLASH_USER_START_ADDR+64	  	  save_flash_data[8]  

FLASH_USER_START_ADDR+72	      save_flash_data[9]

*/



void	g4_write_flash(void);  //一次性写入整个数组 save_flash_data[save_flash_cnt]到flash
void	g4_read_flash(void);	//一次性读取flash整个数组到 save_flash_data[save_flash_cnt]


/*使用示例：
1.修改 FLASH_USER_START_ADDR 可以改变存储启始块，但必须是上面给出的宏块，不可以是中间地址做为启始块。
	如果不修改存储块，直按从2开始执行：

2.在主程序中先声明:
	extern u64  save_flash_data[save_flash_cnt];

然后在主函数中对要存储数据进行填充、要存几个填几个，但所存数据都必须是u32格式：
	
	save_flash_data[0]=0x01234567; 
	save_flash_data[1]=0x11234567; 
填完后最好在hw_g4_flash.h中的注释行备注要存的变量对应的数组

3.要读取只要调g4_read_flash()即可实现一次性全部读出所有数据，但数据仍存在数组save_flash_data[]中、
再根据注释一条一条取出相应的内容即可。


4.如果现在定义的数组个数10不够用、可直接改大并直接使用即可。。不用修改任何代码。





其余解释：
1.STM32的flash写之前一定要先擦除才可再写，所以就存在要写必须一次性写完，做不到分2次写入。
  
2.为什么正常写入 u32数据、读出也是u32的数据。//虽然可以强行写入u64的数据，但读代码要进行相应的修改才能读出u64
	2.1 写入实际执行的是写u64数据（地址+8）、只是高32位空闲而以、原因是写入u64函数更容易处理、
	2.2 由于写入时地址是+8的、所以读出时也统一按+8处理才能得到数据、但读函数本身一次只能读出32位的，所以写入和读出有矛盾。
	2.3 为了调和上述矛盾、所以就无论读还是写都地址固定+8、内容呢写时64（但高32bit为0）、读时32位，所以最终兼容。
	2.4 块上有点浪费、每8个地址的高4个地址的32位数据是浪费的。
*/

#endif

