/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define nFAULTLB_Pin GPIO_PIN_2
#define nFAULTLB_GPIO_Port GPIOE
#define nFAULTRB_Pin GPIO_PIN_3
#define nFAULTRB_GPIO_Port GPIOE
#define nFAULTLF_Pin GPIO_PIN_4
#define nFAULTLF_GPIO_Port GPIOE
#define nFAULTRF_Pin GPIO_PIN_5
#define nFAULTRF_GPIO_Port GPIOE
#define PULSEINRB_B_Pin GPIO_PIN_0
#define PULSEINRB_B_GPIO_Port GPIOA
#define PULSEINRB_F_Pin GPIO_PIN_1
#define PULSEINRB_F_GPIO_Port GPIOA
#define PULSEINLB_B_Pin GPIO_PIN_2
#define PULSEINLB_B_GPIO_Port GPIOA
#define PULSEINLB_F_Pin GPIO_PIN_3
#define PULSEINLB_F_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_4
#define BTN1_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_5
#define BTN2_GPIO_Port GPIOA
#define BTN3_Pin GPIO_PIN_6
#define BTN3_GPIO_Port GPIOA
#define BTN4_Pin GPIO_PIN_7
#define BTN4_GPIO_Port GPIOA
#define CSRF_Pin GPIO_PIN_4
#define CSRF_GPIO_Port GPIOC
#define CSLF_Pin GPIO_PIN_5
#define CSLF_GPIO_Port GPIOC
#define CSRB_Pin GPIO_PIN_0
#define CSRB_GPIO_Port GPIOB
#define CSLB_Pin GPIO_PIN_1
#define CSLB_GPIO_Port GPIOB
#define PULSEINRF_F_Pin GPIO_PIN_9
#define PULSEINRF_F_GPIO_Port GPIOE
#define PULSEINRF_B_Pin GPIO_PIN_11
#define PULSEINRF_B_GPIO_Port GPIOE
#define PULSEINLF_F_Pin GPIO_PIN_13
#define PULSEINLF_F_GPIO_Port GPIOE
#define PULSEINLF_B_Pin GPIO_PIN_14
#define PULSEINLF_B_GPIO_Port GPIOE
#define RFLED_Pin GPIO_PIN_8
#define RFLED_GPIO_Port GPIOD
#define LFLED_Pin GPIO_PIN_9
#define LFLED_GPIO_Port GPIOD
#define RBLED_Pin GPIO_PIN_10
#define RBLED_GPIO_Port GPIOD
#define LBLED_Pin GPIO_PIN_11
#define LBLED_GPIO_Port GPIOD
#define PWMINRF_Pin GPIO_PIN_12
#define PWMINRF_GPIO_Port GPIOD
#define PWMINLF_Pin GPIO_PIN_13
#define PWMINLF_GPIO_Port GPIOD
#define PWMINRB_Pin GPIO_PIN_14
#define PWMINRB_GPIO_Port GPIOD
#define PWMINLB_Pin GPIO_PIN_15
#define PWMINLB_GPIO_Port GPIOD
#define CANLED_Pin GPIO_PIN_6
#define CANLED_GPIO_Port GPIOC
#define FDCAN_SLEEP_Pin GPIO_PIN_10
#define FDCAN_SLEEP_GPIO_Port GPIOA
#define FDCAN_RX_Pin GPIO_PIN_11
#define FDCAN_RX_GPIO_Port GPIOA
#define FDCAN_TX_Pin GPIO_PIN_12
#define FDCAN_TX_GPIO_Port GPIOA
#define nSLEEPLB_Pin GPIO_PIN_0
#define nSLEEPLB_GPIO_Port GPIOD
#define PHLB_Pin GPIO_PIN_1
#define PHLB_GPIO_Port GPIOD
#define PHRB_Pin GPIO_PIN_2
#define PHRB_GPIO_Port GPIOD
#define nSLEEPRB_Pin GPIO_PIN_3
#define nSLEEPRB_GPIO_Port GPIOD
#define nSLEEPLF_Pin GPIO_PIN_4
#define nSLEEPLF_GPIO_Port GPIOD
#define PHLF_Pin GPIO_PIN_5
#define PHLF_GPIO_Port GPIOD
#define nSLEEPRF_Pin GPIO_PIN_6
#define nSLEEPRF_GPIO_Port GPIOD
#define PHRF_Pin GPIO_PIN_7
#define PHRF_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
