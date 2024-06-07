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
#include "adc.h"
#include "fdcan.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LEFT_Forward  	1				//����ǰ��ʱPHֵΪ1 �� ����ʱPHֵΪ0
#define LEFT_Back  			0
#define RIGHT_Forward  	0				//����ǰ��ʱPHֵΪ0 �� ����ʱPHֵΪ1
#define RIGHT_Back  		1
#define CAR_Forward			1				//����С����ǰ����1��ʾ �� ������0��ʾ
#define CAR_Back				0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */
void car_LF(unsigned int pwm , uint8_t Dir);
void car_RF(unsigned int pwm , uint8_t Dir);
void car_LB(unsigned int pwm , uint8_t Dir);
void car_RB(unsigned int pwm , uint8_t Dir);
void car_down(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*�ɵ���printf*/
int fputc(int ch,FILE *f)
{
    /*&huart1ָ���Ǵ���1������ñ�Ĵ��ھ��޸�����*/
    HAL_UART_Transmit(&huart7 , (uint8_t *)&ch , 1 , 0xffff);
    return ch;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_FDCAN1_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  MX_UART7_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
	FDCAN1_Config();
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,1000);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,1000);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1000);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {	
//		HAL_UART_Transmit(&huart7,&Right_Back_Wheel.Speed,sizeof(Right_Back_Wheel.Speed),10);
		printf("a\n");
		HAL_Delay(100);
//		switch(1){
//			case 1:
//				car_LF(2000);
//				car_RF(2000);
//				car_LB(2000);
//				car_RB(2000);
//			  break;
//			case 2:
//				car_LF(2000);
//				car_RF(2000);
//				car_LB(2000);
//				car_RB(2000);
//				break;
//			case 3:
//				car_LF(500);
//				car_RF(500);
//				car_LB(2000);
//				car_RB(2000);
//				break;
//			case 4:
//				car_LF(2000);
//				car_RF(2000);
//				car_LB(500);
//				car_RB(500);
//				break;
//			default:break;
//		}
//		HAL_Delay(5000);
//		car_down();
//		HAL_Delay(5000);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 9;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOMEDIUM;
  RCC_OscInitStruct.PLL.PLLFRACN = 3072;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInitStruct.PLL2.PLL2M = 4;
  PeriphClkInitStruct.PLL2.PLL2N = 9;
  PeriphClkInitStruct.PLL2.PLL2P = 2;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 3072;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void car_LF(unsigned int pwm , uint8_t Dir)
{
	HAL_GPIO_WritePin(GPIOD,PHLF_Pin,Dir);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,pwm);
	HAL_GPIO_WritePin(GPIOD, nSLEEPLF_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,LFLED_Pin,GPIO_PIN_RESET);
	
}
void car_RF(unsigned int pwm , uint8_t Dir)
{
	HAL_GPIO_WritePin(GPIOD,PHRF_Pin,Dir);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,pwm);
	HAL_GPIO_WritePin(GPIOD, nSLEEPRF_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,RFLED_Pin,GPIO_PIN_RESET);
	
}
void car_LB(unsigned int pwm , uint8_t Dir)
{
	HAL_GPIO_WritePin(GPIOD,PHLB_Pin,Dir);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,pwm);
	HAL_GPIO_WritePin(GPIOD, nSLEEPLB_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,LBLED_Pin,GPIO_PIN_RESET);
	
}
void car_RB(unsigned int pwm , uint8_t Dir)
{
	HAL_GPIO_WritePin(GPIOD,PHRB_Pin,Dir);
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,pwm);
	HAL_GPIO_WritePin(GPIOD, nSLEEPRB_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,RBLED_Pin,GPIO_PIN_RESET);
	
}
void car_down(void)
{
	HAL_GPIO_WritePin(GPIOD, nSLEEPLF_Pin|nSLEEPLB_Pin|nSLEEPRF_Pin|nSLEEPRB_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, PHLF_Pin|PHLB_Pin|PHRF_Pin|PHRB_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,LBLED_Pin|RBLED_Pin|LFLED_Pin|RFLED_Pin,GPIO_PIN_SET);
}

void car_move(unsigned int pwm , uint8_t Dir)
{
	car_RF(pwm,!Dir);				//С���������ǰ�����ֵ���ǰ�պ��෴��Ҫ�Ӹ�ȡ��
	car_RB(pwm,!Dir);
	car_LF(pwm,Dir);
	car_LB(pwm,Dir);
	
}
/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

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
