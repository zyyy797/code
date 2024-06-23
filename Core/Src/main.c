/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "hw_g4_lcd1602_6800.h"

#include "DHT11.h"
uint8_t  temperature=1;
uint8_t   humidity=1;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t CF_CNT;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  lcd1602_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//实现了基本功能 
	   	u32 i,TEMP;


if(GPIO_PIN_12 ==0)
{
   if(GPIO_PIN_12 ==0)
	 {
	       DHT11_Read_Data(&temperature,&humidity);
	    	lcd1602_cgram_disp_num(0,0,temperature); //湿度
						lcd1602_cgram_disp_string(0,3,"%"); //湿度
		
	    	lcd1602_cgram_disp_num(1,0,humidity); //温度
						lcd1602_cgram_disp_string(1,3,"%"); //温度
	 }
}	
if(GPIO_PIN_13 ==0)
{
   if(GPIO_PIN_13 ==0)
	 {
	       DHT11_Read_Data(&temperature,&humidity);
	    	lcd1602_cgram_disp_num(0,0,temperature); //湿度
						lcd1602_cgram_disp_string(0,3,"%"); //湿度
		
	    	lcd1602_cgram_disp_num(1,0,humidity); //温度
						lcd1602_cgram_disp_string(1,3,"%"); //温度
	 }
}	
if(GPIO_PIN_14 ==0)
{
   if(GPIO_PIN_14 ==0)
	 {
	       DHT11_Read_Data(&temperature,&humidity);
	    	lcd1602_cgram_disp_num(0,0,temperature); //湿度
						lcd1602_cgram_disp_string(0,3,"%"); //湿度
		
	    	lcd1602_cgram_disp_num(1,0,humidity); //温度
						lcd1602_cgram_disp_string(1,3,"%"); //温度
	 }
}	

    lcd1602_cgram_disp_string(0,7,"kwh");
    TEMP = CF_CNT;
    TEMP = TEMP / 1638.4; // 1,638,400=800imp*2048个即1638400个CF脉冲为1度电、

    i = TEMP % 1000000;
    i = i / 100000;
    lcd1602_cgram_disp_num(0, 0, i);
    i = TEMP % 100000;
    i = i / 10000;
    lcd1602_cgram_disp_num(0, 1, i);
    i = TEMP % 100000;
    i = i / 1000;
    lcd1602_cgram_disp_num(0, 2, i);

    lcd1602_cgram_disp_char(0, 3, '.');
    i = TEMP % 1000;
    i = i / 100;
    lcd1602_cgram_disp_num(0, 4, i);
    i = TEMP % (100);
    i = i / (10);
    lcd1602_cgram_disp_num(0, 5, i);
    i = TEMP % 10;
    i = i / 1;
    lcd1602_cgram_disp_num(0, 6, i);

    i = CF_CNT % 1000000;
    i = i / 100000;
    lcd1602_cgram_disp_num(0, 10, i);
    i = CF_CNT % 100000;
    i = i / 10000;
    lcd1602_cgram_disp_num(0, 11, i);
    i = CF_CNT % 10000;
    i = i / 1000;
    lcd1602_cgram_disp_num(0, 12, i);
    i = CF_CNT % 1000;
    i = i / 100;
    lcd1602_cgram_disp_num(0, 13, i);
    i = CF_CNT % 100;
    i = i / 10;
    lcd1602_cgram_disp_num(0, 14, i);
    i = CF_CNT % 10;
    i = i / 1;
    lcd1602_cgram_disp_num(0, 15, i);


		
		
		

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 18;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
