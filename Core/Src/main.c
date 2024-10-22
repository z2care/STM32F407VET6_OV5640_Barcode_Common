/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ov5640.h"

void DCMI_DMA_MemInc_En(void);
void DCMI_DMA_MemInc_Den(void);

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t aRxBuffer=0;

uint8_t TxBuff[99] = {0};
uint8_t StatusFlag = 0;

uint8_t ov5640_reg1 = 0xff;
uint8_t ov5640_reg2 = 0xff;

HAL_StatusTypeDef dcmi_dma_status = HAL_OK;

uint32_t dcmi_data_buff[16000];

uint32_t DCMI_RN = 0;  //row number
uint32_t DCMI_CN = 0;  //column number
uint32_t DCMI_RS = 0;  //row start
uint32_t DCMI_CS = 0;  //column start

uint8_t scmd = 0;
uint8_t tx_busy = 0;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
DCMI_HandleTypeDef hdcmi;
DMA_HandleTypeDef hdma_dcmi;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_DCMI_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_DCMI_Init();
  MX_USB_DEVICE_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  if (HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1)!=HAL_OK)
   {
 	  MX_USART1_UART_Init();
 	  HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
   }

     HAL_Delay(500); //Await OV5640 running stable
     SCCB_Rst();
     HAL_Delay(100);

 	 ov5640_reg1 = SCCB_RD_Reg(OV5640_CHIPIDH);
 	 ov5640_reg2 = SCCB_RD_Reg(OV5640_CHIPIDL);
     if((ov5640_reg1==0xff)||(ov5640_reg2==0xff)) while(1);;

 	   OV5640_Init(); HAL_Delay(1);
 	   OV5640_RGB565_Mode(); HAL_Delay(1);
 	   OV5640_Focus_Init(); HAL_Delay(1);
 	   ov5640_speed_ctrl(); HAL_Delay(1);
 	   OV5640_OutSize_Set(16,4,640,482); HAL_Delay(1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	 	HAL_Delay(1);

	    if (scmd==1)
	    {
	    	scmd = 0;

	    	  OV5640_Focus_Single();

	      	  DCMI_DMA_MemInc_En();
	      	  HAL_DCMI_DisableCrop (&hdcmi);
	       	  TxBuff[0]=0x55;
	          TxBuff[1]=0xaa;
	          TxBuff[2]=0x03; //OV5640 Label
	          CDC_Transmit_FS(TxBuff, 3);
	          HAL_Delay(100);

       	      dcmi_dma_status = HAL_DCMI_Init(&hdcmi);
	    	  for (uint8_t i=0; i<10;i++)
	    	  {
	 		     HAL_DCMI_DisableCrop (&hdcmi);

	 	    	 DCMI_RN = 48;
	 	    	 DCMI_CN = 1280;

	 	    	 DCMI_RS = 48*i;
	 	    	 DCMI_CS = 0;

	 	    	 HAL_DCMI_ConfigCrop (&hdcmi, DCMI_CS, DCMI_RS, DCMI_CN, DCMI_RN);
	 	    	 HAL_Delay(1);
	 	    	 HAL_DCMI_EnableCrop (&hdcmi);
	 	    	 HAL_Delay(1);

	 	    	 dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, dcmi_data_buff, DCMI_CN*DCMI_RN/4);
	 	    	 while(HAL_DMA_GetState(&hdcmi)==HAL_DMA_STATE_BUSY) ;
	 	    	 HAL_DCMI_Stop(&hdcmi);

	 	    	 tx_busy = 1;
 		    	 CDC_Transmit_FS((uint8_t *)dcmi_data_buff, 61440);
 		    	 while(tx_busy!=0) ;
	    	  }
	    }

	    if (scmd==2)
	    {
	    	scmd = 0;

	    	 OV5640_Focus_Single();

	      	  DCMI_DMA_MemInc_En();
	      	  HAL_DCMI_DisableCrop (&hdcmi);
	       	  TxBuff[0]=0x55;
	          TxBuff[1]=0xaa;
	          TxBuff[2]=0x03; //OV5640 Label
	      	  HAL_UART_Transmit(&huart1, TxBuff, 3, 0xFFFFFF);
	          HAL_Delay(100);

       	      dcmi_dma_status = HAL_DCMI_Init(&hdcmi);
	    	  for (uint8_t i=0; i<10;i++)
	    	  {
	 		     HAL_DCMI_DisableCrop (&hdcmi);

	 	    	 DCMI_RN = 48;
	 	    	 DCMI_CN = 1280;

	 	    	 DCMI_RS = 48*i;
	 	    	 DCMI_CS = 0;

	 	    	 HAL_DCMI_ConfigCrop (&hdcmi, DCMI_CS, DCMI_RS, DCMI_CN, DCMI_RN);
	 	    	 HAL_Delay(1);
	 	    	 HAL_DCMI_EnableCrop (&hdcmi);
	 	    	 HAL_Delay(1);

	 	    	 dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, dcmi_data_buff, DCMI_CN*DCMI_RN/4);
	 	    	 while(HAL_DMA_GetState(&hdcmi)==HAL_DMA_STATE_BUSY) ;
	 	    	 HAL_DCMI_Stop(&hdcmi);

	 	    	  tx_busy = 1;
	 	    	  HAL_UART_Transmit_DMA(&huart1, (uint8_t *)dcmi_data_buff, 61440);
   		          while(tx_busy!=0) ;
	    	  }
	    }

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_4);
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USART1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
}

/**
  * @brief DCMI Initialization Function
  * @param None
  * @retval None
  */
static void MX_DCMI_Init(void)
{

  /* USER CODE BEGIN DCMI_Init 0 */

  /* USER CODE END DCMI_Init 0 */

  /* USER CODE BEGIN DCMI_Init 1 */

  /* USER CODE END DCMI_Init 1 */
  hdcmi.Instance = DCMI;
  hdcmi.Init.SynchroMode = DCMI_SYNCHRO_HARDWARE;
  hdcmi.Init.PCKPolarity = DCMI_PCKPOLARITY_RISING;
  hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_HIGH;
  hdcmi.Init.HSPolarity = DCMI_HSPOLARITY_LOW;
  hdcmi.Init.CaptureRate = DCMI_CR_ALL_FRAME;
  hdcmi.Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;
  hdcmi.Init.JPEGMode = DCMI_JPEG_DISABLE;
  if (HAL_DCMI_Init(&hdcmi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DCMI_Init 2 */

  /* USER CODE END DCMI_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 230400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);
  /* DMA2_Stream7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart ==  &huart1)
	{

		if (aRxBuffer==0x01)
		{
			scmd = 0x02;
			aRxBuffer=0x00;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else
		{

		HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);

		}


	}
      return;

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

	if (huart ==  &huart1)
	{
		tx_busy = 0;
	}

}

void DCMI_DMA_MemInc_En(void)
{
    HAL_DMA_DeInit(&hdma_dcmi);

    hdma_dcmi.Init.MemInc = DMA_MINC_ENABLE;
    if (HAL_DMA_Init(&hdma_dcmi) != HAL_OK)
    {
      Error_Handler();
    }
}

void DCMI_DMA_MemInc_Den(void)
{
    HAL_DMA_DeInit(&hdma_dcmi);
    hdma_dcmi.Init.MemInc = DMA_MINC_DISABLE;
    if (HAL_DMA_Init(&hdma_dcmi) != HAL_OK)
    {
      Error_Handler();
    }
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
