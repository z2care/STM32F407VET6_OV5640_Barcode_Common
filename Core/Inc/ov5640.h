#ifndef _OV5640_H
#define _OV5640_H

/*
 * SIOC: PB0
 * SIOD: PB1
 * VSYNC: PB7
 * HREF: PA4
 * PCLK: PA6
 * XCLK: PA8 //24MHz, optional to use
 * D7: PC6
 * D6: PC7
 * D5: PE0
 * D4: PE1
 * D3: PE4
 * D2: PB6
 * D1: PE5
 * D0: PE6
 * RESET: PD10
 * PWDN: PD11
 *
 *
 */
#include "stm32f4xx_hal.h"

#define SCCB_SCL_L    		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET)
#define SCCB_SCL_H    		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET)
#define SCCB_SDA_L    		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET)
#define SCCB_SDA_H    		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET)

#define SCCB_READ_SDA    	HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)
#define SCCB_ID_W   	    0X78  			//OV5640 ID for Write
#define SCCB_ID_R   	    0X79  			//OV5640 ID for Read

#define OV5640_PD           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_SET)
#define OV5640_PU           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_RESET)

#define OV5640_PWDN           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_SET)
#define OV5640_PWUP           HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_RESET)
#define OV5640_RST  	      HAL_GPIO_WritePin(GPIOD,GPIO_PIN_10,GPIO_PIN_RESET)
#define OV5640_RUN  	      HAL_GPIO_WritePin(GPIOD,GPIO_PIN_10,GPIO_PIN_SET)
#define OV5640_VSYNC 	      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7)
#define OV5640_HREF  	      HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define OV5640_PCLK  	      HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)

void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
uint8_t SCCB_WR_Byte(uint8_t data);
uint8_t SCCB_RD_Byte(void);
uint8_t SCCB_WR_Reg(uint16_t reg,uint8_t data);
uint8_t SCCB_RD_Reg(uint16_t reg);
uint32_t tickdelay;

void SCCB_SDA_IN(void);
void SCCB_SDA_OUT(void);

#define ticknumber 12*5

void SCCB_Rst(void);

//OV5640相关寄存器定义
#define OV5640_CHIPIDH          0X300A  	//OV5640芯片ID高字节
#define OV5640_CHIPIDL          0X300B  	//OV5640芯片ID低字节

//OV5640相关寄存器定义
#define OV5640_CHIPIDH          0X300A  	//OV5640 CHIP ID high byte
#define OV5640_CHIPIDL          0X300B  	//OV5640 CHIP ID low byte

/***********************************/

void OV5640_Init(void);
void OV5640_RGB565_Mode(void);
void OV5640_Exposure(uint8_t exposure);
void OV5640_Light_Mode(uint8_t mode);
void OV5640_Color_Saturation(uint8_t sat);
void OV5640_Brightness(uint8_t bright);
void OV5640_Contrast(uint8_t contrast);
void OV5640_Sharpness(uint8_t sharp);
void OV5640_Special_Effects(uint8_t eft);
uint8_t OV5640_OutSize_Set(uint16_t offx,uint16_t offy,uint16_t width,uint16_t height);
uint8_t OV5640_ImageWin_Set(uint16_t offx,uint16_t offy,uint16_t width,uint16_t height);
uint8_t OV5640_Focus_Init(void);
uint8_t OV5640_Focus_Single(void);
uint8_t OV5640_Focus_Constant(void);
void ov5640_speed_ctrl(void);

#endif
