#ifndef _USART_H
#define _USART_H

#include "stm32f4xx_hal.h"
#include "stdio.h"	 	  	


int fputc(int ch, FILE *f) ;

#endif













#ifdef MAINBAKCUP

#define RAW //RAW format

#include "main.h"
//OV2640 SXGA初�?�化寄存器序列表
//SXGA(1600*1200)

const uint8_t ov2640_sxga_init_reg_tbl[][2]=
{
	0xff, 0x00,
	0x2c, 0xff,  //RSV
	0x2e, 0xdf,  //RSV

	0xff, 0x01,
	0x3c, 0x32,  //RSV
	0x11, 0x01,  //CLOCK DIVIDER
	0x09, 0x02,  //STANDBY MODE AND OUT DRIVER
	0x04, 0x20,  //MIRROR AND FLIP
	0x13, 0xe5,  //AGC AND EXPLOSURE CONTROL
	0x14, 0x48,  //AGC GAIN
	0x2c, 0x0c,  //RSV
	0x33, 0x78,  //RSV
	0x3a, 0x33,  //RSV
	0x3b, 0xfB,  //RSV
	0x3e, 0x00,  //RSV
	0x43, 0x11,  //RSV
	0x16, 0x10,  //RSV
	0x39, 0x92,  //RSV
	0x35, 0xda,  //RSV
	0x22, 0x1a,  //RSV
	0x37, 0xc3,  //RSV
	0x23, 0x00,  //RSV
	0x34, 0xc0,  //RSV, ZOOM WINDOW HORIZENTAL START POINT
	0x36, 0x1a,  //RSV
	0x06, 0x88,  //RSV
	0x07, 0xc0,  //RSV
	0x0d, 0x87,  //CLOCK OUTPUT PIN STATUS IN POWER-DOWN
	0x0e, 0x41,  //RSV
	0x4c, 0x00,  //RSV
	0x48, 0x00,  //ZOOM WINDOW VERTICAL START POINT
	0x5B, 0x00,  //RSV
	0x42, 0x03,  //RSV
	0x4a, 0x81,  //RSV
	0x21, 0x99,  //RSV
	0x24, 0x40,  //LUMINANCE SIGNAL HIGH THRESHOLD FOR AGC/AEC
	0x25, 0x38,  //LUMINANCE SIGNAL LOW THRESHOLD FOR AGC/AEC
	0x26, 0x82,  //FAST MODE LARGE STEP RANGE THRESHOLD
	0x5c, 0x00,  //RSV
	0x63, 0x00,  //RSV
	0x46, 0x00,  //FRAME LENGTH ADJUSTMENT LSBS
	0x0c, 0x3c,  //BANDING AND SNAPSHOT OPTION
	0x61, 0x70,  //HISTOGRAM ALGORITHM LOW LEVEL
	0x62, 0x80,  //HISTOGRAM ALGORITHM HIGH LEVEL
	0x7c, 0x05,  //RSV
	0x20, 0x80,  //RSV
	0x28, 0x30,  //RSV
	0x6c, 0x00,  //RSV
	0x6d, 0x80,  //RSV
	0x6e, 0x00,  //RSV
	0x70, 0x02,  //RSV
	0x71, 0x94,  //RSV
	0x73, 0xc1,  //RSV
	0x3d, 0x34,  //RSV
	0x5a, 0x57,  //RSV
	0x12, 0x00, //UXGA 1600*1200, NO ZOOM, NO COLOR BAR
	0x17, 0x11,  //HORIZONTAL WINDOW START MSB 8 BITS
	0x18, 0x75,  //HORIZONTAL WINDOW END MSB 8BITS
	0x19, 0x01,  //VERTICAL WINDOW LINE START MSB 8 BITS
	0x1a, 0x97,  //VERTICAL WINDOW LINE END MSB 8 BITS
	0x32, 0x36,  //PCLK DIVIDER, HORIZONTAL WINDOW END LSB 3BITS,HORIZONTAL WINDOW START LSB 3BITS
	0x03, 0x0f,  //Dummy frame control, VERTICAL WINDOW LINE END LSB 2 BITS, VERTICAL WINDOW LINE START LSB 2 BITS
	0x37, 0x40,  //RSV
	0x4f, 0xca,  //50HZ BANDING AEC 8 LSBS
	0x50, 0xa8,  //60HZ BANDING AEC 8 LSBS
	0x5a, 0x23,  //RSV
	0x6d, 0x00,  //RSV
	0x6d, 0x38,  //RSV
	0xff, 0x00,
	0xe5, 0x7f,  //RSV
	0xf9, 0xc0,  //MCU RESET, BOOT ROM SELECT
	0x41, 0x24,  //RSV
    0xe0, 0x14,  //RESET CONTROL FOR MCU, SCCB, JPEG, DVP, IPU & CIF
	0x76, 0xff,  //RSV
	0x33, 0xa0,  //RSV
	0x42, 0x20,  //RSV
	0x43, 0x18,  //RSV
	0x4c, 0x00,  //RSV
	0x87, 0xd5,  //MODULE ENABLE FOR BPC, WPC
	0x88, 0x3f,  //RSV
	0xd7, 0x03,  //RSV
	0xd9, 0x10,  //RSV
	0xd3, 0x82,  //AUTO MODE, DVP OUTPUT SPEED
	0xc8, 0x08,  //RSV
	0xc9, 0x80,  //RSV
	0x7c, 0x00,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x00,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7c, 0x03,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x48,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x48,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7c, 0x08,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x20,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x10,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x0e,  //SED INDIRECT REGISTER ACCESS: DATA
	0x90, 0x00,  //RSV
	0x91, 0x0e,  //RSV
	0x91, 0x1a,  //RSV
	0x91, 0x31,  //RSV
	0x91, 0x5a,  //RSV
	0x91, 0x69,  //RSV
	0x91, 0x75,  //RSV
	0x91, 0x7e,  //RSV
	0x91, 0x88,  //RSV
	0x91, 0x8f,  //RSV
	0x91, 0x96,  //RSV
	0x91, 0xa3,  //RSV
	0x91, 0xaf,  //RSV
	0x91, 0xc4,  //RSV
	0x91, 0xd7,  //RSV
	0x91, 0xe8,  //RSV
	0x91, 0x20,  //RSV
	0x92, 0x00,  //RSV
	0x93, 0x06,  //RSV
	0x93, 0xe3,  //RSV
	0x93, 0x05,  //RSV
	0x93, 0x05,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x04,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x93, 0x00,  //RSV
	0x96, 0x00,  //RSV
	0x97, 0x08,  //RSV
	0x97, 0x19,  //RSV
	0x97, 0x02,  //RSV
	0x97, 0x0c,  //RSV
	0x97, 0x24,  //RSV
	0x97, 0x30,  //RSV
	0x97, 0x28,  //RSV
	0x97, 0x26,  //RSV
	0x97, 0x02,  //RSV
	0x97, 0x98,  //RSV
	0x97, 0x80,  //RSV
	0x97, 0x00,  //RSV
	0x97, 0x00,  //RSV
	0xc3, 0xef,  //MODULE ENABLE FOR CIP, CMY, RAW_GMA, DG, AWB, AWB_GAIN, LENC, PRE
	0xa4, 0x00,  //RSV
	0xa8, 0x00,  //RSV
	0xc5, 0x11,  //RSV
	0xc6, 0x51,  //RSV
	0xbf, 0x80,  //RSV
	0xc7, 0x10,  //RSV
	0xb6, 0x66,  //RSV
	0xb8, 0xA5,  //RSV
	0xb7, 0x64,  //RSV
	0xb9, 0x7C,  //RSV
	0xb3, 0xaf,  //RSV
	0xb4, 0x97,  //RSV
	0xb5, 0xFF,  //RSV
	0xb0, 0xC5,  //RSV
	0xb1, 0x94,  //RSV
	0xb2, 0x0f,  //RSV
	0xc4, 0x5c,  //RSV
	0xc0, 0xc8,  //IMAGE HORIZENTAL SIZE HSIZE[10:3]
	0xc1, 0x96,  //IMAGE VERTICAL VSIZE[10:3]
	0x8c, 0x00,  //{HSIZE[11], HSIZE[2:0], VSIZE[2:0]}
	0x86, 0x3d,  //MODULE ENABLE FOR DCW, SDE, UV_ADJ, UV_AVG, CMX
	0x50, 0x00,  //LP_DP, V_DIVIDER, H_DIVIDER
	0x51, 0x90,  //H_SIZE[7:0](REAL/4)
	0x52, 0x2c,  //V_SIZE[7:0](REAL/4)
	0x53, 0x00,  //OFFSET_X[7:0]
	0x54, 0x00,  //OFFSET_Y[7:0]
	0x55, 0x88,  //V_SIZE[8], OFFSET_Y[10:8], H_SIZE[8], OFFSET_X[10:8]
	0x5a, 0x90,  //OUTW[7:0](REAL/4)
	0x5b, 0x2C,  //OUTH[7:0](REAL/4)
	0x5c, 0x05,  //ZOOM SPEED, OUTH[8], OUTW[9:8]
	0xd3, 0x82,  //AUTO MODE, DVP OUTPUT SPEED
    0xc3, 0xed,  //MODULE ENABLE FOR CIP, CMY, RAW_GMA, DG, AWB, AWB_GAIN, LENC, PRE
	0x7f, 0x00,  //RSV
	0xda, 0x08,  //IMAGE OUTPUT FORMAT SELECT
	0xe5, 0x1f,  //RSV
	0xe1, 0x67,  //RSV
	0xe0, 0x00,  //RESET FOR MCU, SCCB, JPEG, DVP, IPU, CIF
	0xdd, 0x7f,  //RSV
    0x05, 0x00,  //use DSP
	0xff, 0x01,
	0x15, 0x00   //PCLK, HREF, VSYNC POLARITY

};

//sxga raw
const uint8_t ov2640_sxga_init_reg_tbl_raw[][2]=
{
		0xff, 0x00,
		0x2c, 0x0c,  //adjust the value to see kinds of effects
		0x2e, 0xdf,
		0x33, 0x78,
		0x3a, 0x33,
		0x3b, 0xfb,
		0x3e, 0x00,
		0x43, 0x11,
		0x16, 0x10,
		0x39, 0x92,
        0x35, 0xda,
		0x22, 0x1a,
		0x37, 0xc3,
		0x23, 0x00,
		0x34, 0xc0,
		0x36, 0x1a,
		0x06, 0x88,
		0x07, 0xc0,
		0x0d, 0x87,
		0x0e, 0x41,
		0x4c, 0x00,
		0x48, 0x00,
		0x5b, 0x00,
		0x42, 0x03,
		0x4a, 0x81,
		0x21, 0x99,
		0x24, 0x40,
		0x25, 0x38,
		0x26, 0x82,
		0x5c, 0x00,
		0x63, 0x00,
		0x46, 0x22,
		0x0c, 0x3c,
		0x61, 0x70,
		0x62, 0x80,
		0x7c, 0x05,
		0x20, 0x80,
		0x6c, 0x00,
		0x6d, 0x80,
		0x6e, 0x00,
		0x70, 0x02,
		0x71, 0x94,
		0x73, 0xc1,
	    0X44, 0x06, //Quantization scale factor
    0XFF,0x01,
	0x3c, 0x32,
	0X03, 0x0f,   //common control 1
	0X04, 0x0c,   //register 04
	//0X09,0x00,
	0x11, 0x01,  //CLOCK DIVIDER
	0x09, 0x02,  //STANDBY MODE AND OUT DRIVER
	//0x04, 0x20,  //MIRROR AND FLIP
	0x04, 0x28,  //MIRROR AND FLIP
	0x13, 0xe5,  //AGC AND EXPLOSURE CONTROL
	0x14, 0x48,  //AGC GAIN
	0x34, 0xc0,  //RSV, ZOOM WINDOW HORIZENTAL START POINT
	0x0d, 0x87,  //CLOCK OUTPUT PIN STATUS IN POWER-DOWN
	0x48, 0x00,  //ZOOM WINDOW VERTICAL START POINT
	0x24, 0x40,  //LUMINANCE SIGNAL HIGH THRESHOLD FOR AGC/AEC
	0x25, 0x38,  //LUMINANCE SIGNAL LOW THRESHOLD FOR AGC/AEC
	0x26, 0x82,  //FAST MODE LARGE STEP RANGE THRESHOLD
	0x46, 0x00,  //FRAME LENGTH ADJUSTMENT LSBS
	0x0c, 0x3c,  //BANDING AND SNAPSHOT OPTION
	0x61, 0x70,  //HISTOGRAM ALGORITHM LOW LEVEL
	0x62, 0x80,  //HISTOGRAM ALGORITHM HIGH LEVEL
	0x12, 0x00, //UXGA 1600*1200, NO ZOOM, NO COLOR BAR
	0x17, 0x11,  //HORIZONTAL WINDOW START MSB 8 BITS
	0x18, 0x75,  //HORIZONTAL WINDOW END MSB 8BITS
	0x19, 0x01,  //VERTICAL WINDOW LINE START MSB 8 BITS
	0x1a, 0x97,  //VERTICAL WINDOW LINE END MSB 8 BITS
	0x32, 0x36,  //PCLK DIVIDER, HORIZONTAL WINDOW END LSB 3BITS,HORIZONTAL WINDOW START LSB 3BITS
	0x03, 0x0f,  //Dummy frame control, VERTICAL WINDOW LINE END LSB 2 BITS, VERTICAL WINDOW LINE START LSB 2 BITS
	0x4f, 0xca,  //50HZ BANDING AEC 8 LSBS

	0xff, 0x00,
	0xe5, 0x7f,
	0xf9, 0xc0,  //MCU RESET, BOOT ROM SELECT
	0x41, 0x24,
//	0xe0, 0x14,  //RESET CONTROL FOR MCU, SCCB, JPEG, DVP, IPU & CIF
	0xe0, 0x04,  //RESET CONTROL FOR MCU, SCCB, JPEG, DVP, IPU & CIF
	0x76, 0xff,
	0x33, 0xa0,
	0x42, 0x20,
	0x43, 0x18,
	0x4c, 0x00,
	0x87, 0xd5,  //MODULE ENABLE FOR BPC, WPC
	0x88, 0x3f,
	0xd7, 0x03,
	0xd9, 0x10,
	0xd3, 0x82,  //AUTO MODE, DVP OUTPUT SPEED
	0x7c, 0x00,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x00,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7c, 0x03,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x48,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x48,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7c, 0x08,  //SDE INDIRECT REGISTER ACCSS: ADDRESS
	0x7d, 0x20,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x10,  //SED INDIRECT REGISTER ACCESS: DATA
	0x7d, 0x0e,  //SED INDIRECT REGISTER ACCESS: DATA
	0x90, 0x00,
	0x91, 0x0e,
	0x91, 0x1a,
	0x91, 0x31,
	0x91, 0x5a,
	0x91, 0x69,
	0x91, 0x75,
	0x91, 0x7e,
	0x91, 0x88,
	0x91, 0x8f,
	0x91, 0x96,
	0x91, 0xa3,
	0x91, 0xaf,
	0x91, 0xc4,
	0x91, 0xd7,
	0x91, 0xe8,
	0x91, 0x20,
	0x92, 0x00,
	0x93, 0x06,
	0x93, 0xe3,
	0x93, 0x05,
	0x93, 0x05,
	0x93, 0x00,
	0x93, 0x04,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x96, 0x00,
	0x97, 0x08,
	0x97, 0x19,
	0x97, 0x02,
	0x97, 0x0c,
	0x97, 0x24,
	0x97, 0x30,
	0x97, 0x28,
	0x97, 0x26,
	0x97, 0x02,
	0x97, 0x98,
	0x97, 0x80,
	0x97, 0x00,
	0x97, 0x00,
	0xa4, 0x00,
	0xa8, 0x00,
	0xc5, 0x11,
	0xc6, 0x51,
	0xbf, 0x80,
	0xc7, 0x10,
	0xb6, 0x66,
	0xb8, 0xA5,
	0xb7, 0x64,
	0xb9, 0x7C,
	0xb3, 0xaf,
	0xb4, 0x97,
	0xb5, 0xFF,
	0xb0, 0xC5,
	0xb1, 0x94,
	0xb2, 0x0f,
	0xc4, 0x5c,
	//0xc3, 0xef,  //MODULE ENABLE FOR CIP, CMY, RAW_GMA, DG, AWB, AWB_GAIN, LENC, PRE
	0xc3, 0xed,
	0xc0, 0xc8,  //IMAGE HORIZENTAL SIZE HSIZE[10:3]
	0xc1, 0x96,  //IMAGE VERTICAL VSIZE[10:3]
	0x8c, 0x00,  //{HSIZE[11], HSIZE[2:0], VSIZE[2:0]}
	0x86, 0x3d,  //MODULE ENABLE FOR DCW, SDE, UV_ADJ, UV_AVG, CMX
	0x50, 0x00,  //LP_DP, V_DIVIDER, H_DIVIDER
	0x51, 0x90,  //H_SIZE[7:0](REAL/4)
	0x52, 0x2c,  //V_SIZE[7:0](REAL/4)
	0x53, 0x00,  //OFFSET_X[7:0]
	0x54, 0x00,  //OFFSET_Y[7:0]
	0x55, 0x88,  //V_SIZE[8], OFFSET_Y[10:8], H_SIZE[8], OFFSET_X[10:8]
	0x5a, 0x90,  //OUTW[7:0](REAL/4)
	0x5b, 0x2C,  //OUTH[7:0](REAL/4)
	0x5c, 0x05,  //ZOOM SPEED, OUTH[8], OUTW[9:8]
	0xd3, 0x82,  //AUTO MODE, DVP OUTPUT SPEED
	//0xc3, 0xed,  //MODULE ENABLE FOR CIP, CMY, RAW_GMA, DG, AWB, AWB_GAIN, LENC, PRE
	0xc3, 0xed,
	0xda, 0x08,  //IMAGE OUTPUT FORMAT SELECT

	0xc3, 0xff,
	0xc2, 0x01,
	0xda, 0x44,  //IMAGE OUTPUT FORMAT SELECT

	0xe5, 0x1f,
	0xe1, 0x67,
	0xe0, 0x00,  //RESET FOR MCU, SCCB, JPEG, DVP, IPU, CIF
    0x05, 0x01,  //bypass DSP
	0xff, 0x01,
	0x15, 0x00   //PCLK, HREF, VSYNC POLARITY

};

//OV2640 SVGA初�?�化寄存器序列表
//SVGA 800*600 up to 30 fps
const uint8_t ov2640_svga_init_reg_tbl[][2]=
{
	0xff, 0x00,
	0x2c, 0xff,
	0x2e, 0xdf,
	0xff, 0x01,
	0x3c, 0x32,
	//
	0x11, 0x00,
	0x09, 0x02,
	0x04, 0x20,
	0x13, 0xe5,
	0x14, 0x48,
	0x2c, 0x0c,
	0x33, 0x78,
	0x3a, 0x33,
	0x3b, 0xfB,
	//
	0x3e, 0x00,
	0x43, 0x11,
	0x16, 0x10,
	//
	0x39, 0x92,
	//
	0x35, 0xda,
	0x22, 0x1a,
	0x37, 0xc3,
	0x23, 0x00,
	0x34, 0xc0,
	0x36, 0x1a,
	0x06, 0x88,
	0x07, 0xc0,
	0x0d, 0x87,
	0x0e, 0x41,
	0x4c, 0x00,
	0x48, 0x00,
	0x5B, 0x00,
	0x42, 0x03,
	//
	0x4a, 0x81,
	0x21, 0x99,
	//
	0x24, 0x40,
	0x25, 0x38,
	0x26, 0x82,
	0x5c, 0x00,
	0x63, 0x00,
	0x46, 0x22,
	0x0c, 0x3c,
	//
	0x61, 0x70,
	0x62, 0x80,
	0x7c, 0x05,
	//
	0x20, 0x80,
	0x28, 0x30,
	0x6c, 0x00,
	0x6d, 0x80,
	0x6e, 0x00,
	0x70, 0x02,
	0x71, 0x94,
	0x73, 0xc1,
	//
	0x3d, 0x34,
	0x5a, 0x57,
	//
	0x12, 0x40,//SVGA 800*600
	0x17, 0x11,
	0x18, 0x43,
	0x19, 0x00,
	0x1a, 0x4b,
	0x32, 0x09,
	0x37, 0xc0,
	//
	0x4f, 0xca,
	0x50, 0xa8,
	0x5a, 0x23,
	0x6d, 0x00,
	0x3d, 0x38,
	//
	0xff, 0x00,
	0xe5, 0x7f,
	0xf9, 0xc0,
	0x41, 0x24,
	0xe0, 0x14,
	0x76, 0xff,
	0x33, 0xa0,
	0x42, 0x20,
	0x43, 0x18,
	0x4c, 0x00,
	0x87, 0xd5,
	0x88, 0x3f,
	0xd7, 0x03,
	0xd9, 0x10,
	0xd3, 0x82,
	//
	0xc8, 0x08,
	0xc9, 0x80,
	//
	0x7c, 0x00,
	0x7d, 0x00,
	0x7c, 0x03,
	0x7d, 0x48,
	0x7d, 0x48,
	0x7c, 0x08,
	0x7d, 0x20,
	0x7d, 0x10,
	0x7d, 0x0e,
	//
	0x90, 0x00,
	0x91, 0x0e,
	0x91, 0x1a,
	0x91, 0x31,
	0x91, 0x5a,
	0x91, 0x69,
	0x91, 0x75,
	0x91, 0x7e,
	0x91, 0x88,
	0x91, 0x8f,
	0x91, 0x96,
	0x91, 0xa3,
	0x91, 0xaf,
	0x91, 0xc4,
	0x91, 0xd7,
	0x91, 0xe8,
	0x91, 0x20,
	//
	0x92, 0x00,
	0x93, 0x06,
	0x93, 0xe3,
	0x93, 0x05,
	0x93, 0x05,
	0x93, 0x00,
	0x93, 0x04,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	0x93, 0x00,
	//
	0x96, 0x00,
	0x97, 0x08,
	0x97, 0x19,
	0x97, 0x02,
	0x97, 0x0c,
	0x97, 0x24,
	0x97, 0x30,
	0x97, 0x28,
	0x97, 0x26,
	0x97, 0x02,
	0x97, 0x98,
	0x97, 0x80,
	0x97, 0x00,
	0x97, 0x00,
	//
	0xc3, 0xed,
	0xa4, 0x00,
	0xa8, 0x00,
	0xc5, 0x11,
	0xc6, 0x51,
	0xbf, 0x80,
	0xc7, 0x10,
	0xb6, 0x66,
	0xb8, 0xA5,
	0xb7, 0x64,
	0xb9, 0x7C,
	0xb3, 0xaf,
	0xb4, 0x97,
	0xb5, 0xFF,
	0xb0, 0xC5,
	0xb1, 0x94,
	0xb2, 0x0f,
	0xc4, 0x5c,
	//
	0xc0, 0x64,
	0xc1, 0x4B,
	0x8c, 0x00,
	0x86, 0x3D,
	0x50, 0x00,
	0x51, 0xC8,
	0x52, 0x96,
	0x53, 0x00,
	0x54, 0x00,
	0x55, 0x00,
	0x5a, 0xC8,
	0x5b, 0x96,
	0x5c, 0x00,
	//
	0xd3, 0x82,
	//
	0xc3, 0xed,
	0x7f, 0x00,
	//
	0xda, 0x08,
	//
	0xe5, 0x1f,
	0xe1, 0x67,
	0xe0, 0x00,
	0xdd, 0x7f,
	0x05, 0x00,  //use DSP
	0xff, 0x01,
	0x15, 0x00   //PCLK, HREF, VSYNC POLARITY

};
const uint8_t ov2640_jpeg_reg_tbl[][2]=
{
	0xff, 0x01,
	0xe0, 0x14,
	0xe1, 0x77,
	0xe5, 0x1f,
	0xd7, 0x03,
	0xda, 0x10,  //for jpeg
	0xe0, 0x00
};
const uint8_t ov2640_rgb565_reg_tbl[][2]=
{
	0xFF, 0x00,
	0xDA, 0x08,  //for rgb565
	0xD7, 0x03,  //RSV
	0xDF, 0x02,  //RSV
	0x33, 0xa0,  //RSV
	0x3C, 0x00,  //RSV
	0xe1, 0x67,  //RSV
	0xc2, 0xc2,

	0xff, 0x01,
	0xe0, 0x00,  //RESET FOR MCU, SCCB, JPEG, DVP, IPU, CIF
	0xe1, 0x00,  //RSV
	0xe5, 0x00,  //RSV
	0xd7, 0x00,   //RSV

};
const uint8_t ov2640_yuv422_reg_tbl[][2]=
{
	{0xFF, 0x00},
	{0xDA, 0x00},   //for YUV422
	{0xD7, 0x03},
	{0xDF, 0x00},
	{0x33, 0x80},
	{0x3C, 0x40},
	{0xe1, 0x77},
	{0x00, 0x00},
	{0xc2, 0xcc}
};

//�?动曝光�?�置参数,�?�?5�?等级
const static uint8_t OV2640_AUTOEXPOSURE_LEVEL[5][8]=
{
    {
        0xFF,0x01,
        0x24,0x20,
        0x25,0x18,
        0x26,0x60,
    },
    {
        0xFF,0x01,
        0x24,0x34,
        0x25,0x1c,
        0x26,0x00,
    },
    {
        0xFF,0x01,
        0x24,0x3e,
        0x25,0x38,
        0x26,0x81,
    },
    {
        0xFF,0x01,
        0x24,0x48,
        0x25,0x40,
        0x26,0x81,
    },
    {
        0xFF,0x01,
        0x24,0x58,
        0x25,0x50,
        0x26,0x92,
    },
};
//OV2640�?动曝光等级�?�置
//level:0~4
void OV2640_Auto_Exposure(uint8_t level)
{
    uint8_t i;
    uint8_t *p=(uint8_t*)OV2640_AUTOEXPOSURE_LEVEL[level];
    for(i=0;i<4;i++)
    {
        SCCB_WR_Reg(p[i*2],p[i*2+1]);
    }
}
//白平衡�?�置
//0:�?�?
//1:�?阳sunny
//2,阴天cloudy
//3,办公�?office
//4,家里home
void OV2640_Light_Mode(uint8_t mode)
{
    uint8_t regccval=0X5E;//Sunny
    uint8_t regcdval=0X41;
    uint8_t regceval=0X54;
    switch(mode)
    {
        case 0://auto
            SCCB_WR_Reg(0XFF,0X00);
            SCCB_WR_Reg(0XC7,0X10);//AWB ON
            return;
        case 2://cloudy
            regccval=0X65;
            regcdval=0X41;
            regceval=0X4F;
            break;
        case 3://office
            regccval=0X52;
            regcdval=0X41;
            regceval=0X66;
            break;
        case 4://home
            regccval=0X42;
            regcdval=0X3F;
            regceval=0X71;
            break;
    }
    SCCB_WR_Reg(0XFF,0X00);
    SCCB_WR_Reg(0XC7,0X40);    //AWB OFF
    SCCB_WR_Reg(0XCC,regccval);
    SCCB_WR_Reg(0XCD,regcdval);
    SCCB_WR_Reg(0XCE,regceval);
}
//色度设置
//0:-2
//1:-1
//2,0
//3,+1
//4,+2
void OV2640_Color_Saturation(uint8_t sat)
{
    uint8_t reg7dval=((sat+2)<<4)|0X08;
    SCCB_WR_Reg(0XFF,0X00);
    SCCB_WR_Reg(0X7C,0X00);
    SCCB_WR_Reg(0X7D,0X02);
    SCCB_WR_Reg(0X7C,0X03);
    SCCB_WR_Reg(0X7D,reg7dval);
    SCCB_WR_Reg(0X7D,reg7dval);
}
//�?度�?�置
//0:(0X00)-2
//1:(0X10)-1
//2,(0X20) 0
//3,(0X30)+1
//4,(0X40)+2
void OV2640_Brightness(uint8_t bright)
{
  SCCB_WR_Reg(0xff, 0x00);
  SCCB_WR_Reg(0x7c, 0x00);
  SCCB_WR_Reg(0x7d, 0x04);
  SCCB_WR_Reg(0x7c, 0x09);
  SCCB_WR_Reg(0x7d, bright<<4);
  SCCB_WR_Reg(0x7d, 0x00);
}
//对比度�?�置
//0:-2
//1:-1
//2,0
//3,+1
//4,+2
void OV2640_Contrast(uint8_t contrast)
{
    uint8_t reg7d0val=0X20;//默�?�为�?通模�?
    uint8_t reg7d1val=0X20;
      switch(contrast)
    {
        case 0://-2
            reg7d0val=0X18;
            reg7d1val=0X34;
            break;
        case 1://-1
            reg7d0val=0X1C;
            reg7d1val=0X2A;
            break;
        case 3://1
            reg7d0val=0X24;
            reg7d1val=0X16;
            break;
        case 4://2
            reg7d0val=0X28;
            reg7d1val=0X0C;
            break;
    }
    SCCB_WR_Reg(0xff,0x00);
    SCCB_WR_Reg(0x7c,0x00);
    SCCB_WR_Reg(0x7d,0x04);
    SCCB_WR_Reg(0x7c,0x07);
    SCCB_WR_Reg(0x7d,0x20);
    SCCB_WR_Reg(0x7d,reg7d0val);
    SCCB_WR_Reg(0x7d,reg7d1val);
    SCCB_WR_Reg(0x7d,0x06);
}
//特效设置
//0:�?通模�?
//1,负片
//2,黑白
//3,偏红
//4,偏绿
//5,偏蓝
//6,复古
void OV2640_Special_Effects(uint8_t eft)
{
    uint8_t reg7d0val=0X00;//默�?�为�?通模�?
    uint8_t reg7d1val=0X80;
    uint8_t reg7d2val=0X80;
    switch(eft)
    {
        case 1://负片
            reg7d0val=0X40;
            break;
        case 2://黑白
            reg7d0val=0X18;
            break;
        case 3://偏红
            reg7d0val=0X18;
            reg7d1val=0X40;
            reg7d2val=0XC0;
            break;
        case 4://偏绿
            reg7d0val=0X18;
            reg7d1val=0X40;
            reg7d2val=0X40;
            break;
        case 5://偏蓝
            reg7d0val=0X18;
            reg7d1val=0XA0;
            reg7d2val=0X40;
            break;
        case 6://复古
            reg7d0val=0X18;
            reg7d1val=0X40;
            reg7d2val=0XA6;
            break;
    }
    SCCB_WR_Reg(0xff,0x00);
    SCCB_WR_Reg(0x7c,0x00);
    SCCB_WR_Reg(0x7d,reg7d0val);
    SCCB_WR_Reg(0x7c,0x05);
    SCCB_WR_Reg(0x7d,reg7d1val);
    SCCB_WR_Reg(0x7d,reg7d2val);
}
//彩条测试
//sw:0,关闭彩条
//   1,开�?彩条(注意OV2640的彩条是叠加在图像上面的)
void OV2640_Color_Bar(uint8_t sw)
{
    uint8_t reg;
    SCCB_WR_Reg(0XFF,0X01);
    reg=SCCB_RD_Reg(0X12);
    reg&=~(1<<1);
    if(sw)reg|=1<<1;
    SCCB_WR_Reg(0X12,reg);
}
//设置图像输出窗口
//sx,sy,起�?�地址
//width,height:宽度(对应:horizontal)和高�?(对应:vertical)
void OV2640_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height)
{
    uint16_t endx;
    uint16_t endy;
    uint8_t temp;
    endx=sx+width/2;    //V*2
     endy=sy+height/2;

    SCCB_WR_Reg(0XFF,0X01);
    temp=SCCB_RD_Reg(0X03);                //读取Vref之前的�?
    temp&=0XF0;
    temp|=((endy&0X03)<<2)|(sy&0X03);
    SCCB_WR_Reg(0X03,temp);                //设置Vref的start和end的最�?2�?
    SCCB_WR_Reg(0X19,sy>>2);               //设置Vref的start的高8�?
    SCCB_WR_Reg(0X1A,endy>>2);             //设置Vref的end的高8�?

    temp=SCCB_RD_Reg(0X32);                //读取Href之前的�?
    temp&=0XC0;
    temp|=((endx&0X07)<<3)|(sx&0X07);
    SCCB_WR_Reg(0X32,temp);                //设置Href的start和end的最�?3�?
    SCCB_WR_Reg(0X17,sx>>3);               //设置Href的start�?8�?
    SCCB_WR_Reg(0X18,endx>>3);             //设置Href的end的高8�?
}
//设置图像输出大小
//OV2640输出图像的大�?(分辨�?),完全由改函数�?�?
//width,height:宽度(对应:horizontal)和高�?(对应:vertical),width和height必须�?4的倍数
//for RGB565/YUV OV2640_OutSize_Set(w,h) outputs 2*w bytes for per line, and total h lines.
//返回:0,设置成功
//     其他,设置失败
uint8_t OV2640_OutSize_Set(uint16_t width,uint16_t height)
{
    uint16_t outh;
    uint16_t outw;
    uint8_t temp;
    if(width%4)return 1;
    if(height%4)return 2;
    outw=width/4;
    outh=height/4;
    SCCB_WR_Reg(0XFF,0X00);
    SCCB_WR_Reg(0XE0,0X04);
    SCCB_WR_Reg(0X5A,outw&0XFF);        //设置OUTW的低�?�?
    SCCB_WR_Reg(0X5B,outh&0XFF);        //设置OUTH的低�?�?
    temp=(outw>>8)&0X03;
    temp|=(outh>>6)&0X04;
    SCCB_WR_Reg(0X5C,temp);                //设置OUTH/OUTW的高�??????????
    SCCB_WR_Reg(0XE0,0X00);
    return 0;
}
//设置图像开窗大�?
//由OV2640_ImageSize_Set�?定传感器输出分辨率大小�?
//该函数则在这�?范围上面进�?�开窗，用于OV2640_OutSize_Set的输�?
//注意:�?函数的�?�度和高�?,必须大于等于OV2640_OutSize_Set函数的�?�度和高�?
//     OV2640_OutSize_Set设置的�?�度和高�?,根据�?函数设置的�?�度和高,由DSP
//     �?动�?�算缩放比例,输出给�?�部设�??
//width,height:宽度(对应:horizontal)和高�?(对应:vertical),width和height必须�?4的倍数
//返回�?:0,设置成功
//    其他,设置失败
uint8_t OV2640_ImageWin_Set(uint16_t offx,uint16_t offy,uint16_t width,uint16_t height)
{
    uint16_t hsize;
    uint16_t vsize;
    uint8_t temp;
    if(width%4)return 1;
    if(height%4)return 2;
    hsize=width/4;
    vsize=height/4;
    SCCB_WR_Reg(0XFF,0X00);
    SCCB_WR_Reg(0XE0,0X04);
    SCCB_WR_Reg(0X51,hsize&0XFF);        //设置H_SIZE的低�?�?
    SCCB_WR_Reg(0X52,vsize&0XFF);        //设置V_SIZE的低�?�?
    SCCB_WR_Reg(0X53,offx&0XFF);        //设置offx的低�?�?
    SCCB_WR_Reg(0X54,offy&0XFF);        //设置offy的低�?�?
    temp=(vsize>>1)&0X80;
    temp|=(offy>>4)&0X70;
    temp|=(hsize>>5)&0X08;
    temp|=(offx>>8)&0X07;
    SCCB_WR_Reg(0X55,temp);                //设置H_SIZE/V_SIZE/OFFX,OFFY的高�?
    SCCB_WR_Reg(0X57,(hsize>>2)&0X80);    //设置H_SIZE/V_SIZE/OFFX,OFFY的高�?
    SCCB_WR_Reg(0XE0,0X00);
    return 0;
}
//该函数�?�置图像尺�?�大�?,也就�?所选格式的输出分辨�?
//UXGA:1600*1200,SVGA:800*600,CIF:352*288
//width,height:图像宽度和图像高�?
//返回�?:0,设置成功
//    其他,设置失败
uint8_t OV2640_ImageSize_Set(uint16_t width,uint16_t height)
{
    uint8_t temp;
    SCCB_WR_Reg(0XFF,0X00);
    SCCB_WR_Reg(0XE0,0X04);
    SCCB_WR_Reg(0XC0,(width)>>3&0XFF);        //设置HSIZE�??????????10:3�??????????
    SCCB_WR_Reg(0XC1,(height)>>3&0XFF);        //设置VSIZE�??????????10:3�??????????
    temp=(width&0X07)<<3;
    temp|=height&0X07;
    temp|=(width>>4)&0X80;
    SCCB_WR_Reg(0X8C,temp);
    SCCB_WR_Reg(0XE0,0X00);
    return 0;
}

//OV2640 mode: RGB565
void OV2640_RGB565_Mode(void)
{
	uint16_t i=0;

	for(i=0;i<(sizeof(ov2640_rgb565_reg_tbl)/2);i++)
	{
		SCCB_WR_Reg(ov2640_rgb565_reg_tbl[i][0],ov2640_rgb565_reg_tbl[i][1]);
	}
}

//OV2640 mode: yuv422
void OV2640_YUV422_Mode(void)
{
	uint16_t i=0;

	for(i=0;i<(sizeof(ov2640_yuv422_reg_tbl)/2);i++)
	{
		SCCB_WR_Reg(ov2640_yuv422_reg_tbl[i][0],ov2640_yuv422_reg_tbl[i][1]);
	}
}


#ifdef RAW  //RAW format

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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define RowNum 480
#define ColumnNum 1280

void DCMI_DMA_MemInc_En(void);
void DCMI_DMA_MemInc_Den(void);
void SPI2_ENDIAN_L(void) ;
void SPI2_ENDIAN_H(void) ;



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t aRxBuffer;			//接收�?�?缓冲
uint8_t Uart1_RxBuff[99] = {0};		//Rx buffer，should be adjusted according to Rx max byte length per communication.
uint8_t Uart2_RxBuff[99] = {0};		//Rx buffer，should be adjusted according to Rx max byte length per communication.
HAL_StatusTypeDef uart1_status_rx;
uint8_t Uart1_TxBuff[99] = {0};		//Tx buffer
uint8_t Uart4_TxBuff[2] = {0};			//Tx buffer
uint8_t StatusFlag = 0;

uint8_t ov2640_rd = 0xff;

uint8_t sram_wd;
uint8_t sram_rd;

uint8_t sram_TxCmd[4]={0x02,0x00,0x00,0x00};
uint8_t sram_TxData= 0x5a;
uint8_t sram_RxCmd[4]={0x03,0x00,0x00,0x00};
uint8_t sram_RxDummy= 0x00;
uint8_t sram_RxData= 0x00;

uint8_t sram_RxCmd_inv[4]={0xc0,0x00,0x00,0x00}; //for LSB of SPI2

HAL_StatusTypeDef spi_dma_status = HAL_OK;
HAL_StatusTypeDef dcmi_dma_status = HAL_OK;

uint32_t dcmi_data;

uint32_t dcmi_data_buff[19200]={0};

uint32_t vsync_counter = 0;
uint32_t line_counter = 0;
uint32_t point_counter =0;
uint32_t frame_counter =0;
uint32_t timing_ctr = 1;

uint8_t DCMI_CROP_EN = 0;
uint32_t DCMI_RN = 0;  //row number
uint32_t DCMI_CN = 0;  //column number
uint32_t DCMI_RS = 0;  //row start
uint32_t DCMI_CS = 0;  //column start


uint8_t scmd = 0;


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

SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_SPI2_Init(void);
static void MX_DCMI_Init(void);
static void MX_UART4_Init(void);
static void MX_USART2_UART_Init(void);
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
  MX_TIM2_Init();
  MX_SPI2_Init();
  MX_DCMI_Init();
  MX_UART4_Init();
  MX_USART2_UART_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_Delay(100);

  if (HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1)!=HAL_OK) printf("UART1 IT FAILED! \r\n");
  printf("Serial port connected!");
  printf("\r\n");
  HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);

    HAL_Delay(500); //must to await camera running stable
    SCCB_Rst();
    HAL_Delay(500);

	SCCB_WR_Reg(0xff, 0x01);
 	SCCB_WR_Reg(0x12, 0x80);

    HAL_Delay(100);

	ov2640_rd = SCCB_RD_Reg(0x1c);
	printf("PID = %d",ov2640_rd);
	printf("\r\n");
	ov2640_rd = SCCB_RD_Reg(0x1d);
	printf("VER = %d",ov2640_rd);
	printf("\r\n");

		/*UXGA Capture, 7.5fps, 24MHz input clock*/
	 	SCCB_WR_Reg(0xff, 0x01);
		SCCB_WR_Reg(0x11, 0x01);
		SCCB_WR_Reg(0x12, 0x00);
		SCCB_WR_Reg(0x2a, 0x00);
		SCCB_WR_Reg(0x2b, 0x00);
		SCCB_WR_Reg(0x46, 0x00);
		SCCB_WR_Reg(0x47, 0x00);
		SCCB_WR_Reg(0x3d, 0x34);

		for(uint32_t i=0; i<sizeof(ov2640_sxga_init_reg_tbl_raw)/2 ; i++)
	     {
	       SCCB_WR_Reg(ov2640_sxga_init_reg_tbl_raw[i][0],ov2640_sxga_init_reg_tbl_raw[i][1]);
		   if(i<10) HAL_Delay(5);
 	     }

		 OV2640_Window_Set(140,0,1624,732);


     OV2640_Color_Bar(0);
     OV2640_Auto_Exposure(2);
     OV2640_Special_Effects(0);
     OV2640_Light_Mode(0);    //�?动模�?
     OV2640_Color_Saturation(2);//色彩饱和�??
     OV2640_Brightness(2);    //�?�?0
     OV2640_Contrast(2);        //对比�??

	 HAL_Delay(500); //pay attention

	   DCMI_CROP_EN = 1;
	   DCMI_RN = 159;  //row number
	   DCMI_CN = 320;  //column number
	   DCMI_RS = 0;  //row start
	   DCMI_CS = 0;  //column start
	   OV2640_PD ;
	   HAL_DCMI_DisableCrop (&hdcmi);
	   HAL_DCMI_ConfigCrop (&hdcmi, DCMI_CS, DCMI_RS, DCMI_CN, DCMI_RN);
	   HAL_DCMI_EnableCrop (&hdcmi);
	   dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, &dcmi_data, (DCMI_RN+1)*DCMI_CN/4); //65535 38400 (DCMI_RN+1)*DCMI_CN/4
	   OV2640_PU ;
	   printf("dcmi_dma_status = %d",dcmi_dma_status);
	   printf("\r\n");

	   HAL_Delay(250);  //pay attention

	   HAL_DCMI_Stop(&hdcmi);
		printf("\r\n");
		printf("vn = %d",vsync_counter);
		printf("\r\n");
		printf("ln = %d",line_counter);
		printf("\r\n");
		printf("pn = %d",point_counter);
		printf("\r\n");
		printf("fn = %d",frame_counter);
		printf("\r\n");


		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
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

    }


    if (scmd==2)
    {
     	scmd = 0;

     	 vsync_counter = 0;
     	 line_counter = 0;
     	 frame_counter =0;
     	 point_counter = 0;


     	  DCMI_DMA_MemInc_En();

      	  HAL_DCMI_DisableCrop (&hdcmi);
      	  HAL_Delay(100);
       	  Uart4_TxBuff[0]=0x55;
          Uart4_TxBuff[1]=0xaa;
      	  HAL_UART_Transmit(&huart4, Uart4_TxBuff, 2, 0xFFFFFF);

    	  for (uint8_t i=0; i<13;i++)
    	  {
                OV2640_Window_Set(144,0+i*48,1600,48);
                HAL_Delay(100);

    		     dcmi_dma_status = HAL_DCMI_Init(&hdcmi);

    	    	 HAL_Delay(100);

    	    	 dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, dcmi_data_buff, 76800/4);

    	    	 HAL_Delay(200);

    	    	 HAL_DCMI_Stop(&hdcmi);

    	    	  HAL_UART_Transmit(&huart4, (uint8_t *)dcmi_data_buff, 38400, 0xFFFFFF);
    	    	  HAL_UART_Transmit(&huart4, (uint8_t *)(&dcmi_data_buff[38400/4]), 38400, 0xFFFFFF);
    	    	  //HAL_Delay(200);

    	        	memset(dcmi_data_buff, 0, 76800);
    	        	HAL_Delay(10);


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
  /* TIM2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
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
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 230400;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

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
  huart1.Init.BaudRate = 9600;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 230400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3|GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin : PE3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PE13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
/*
 * Due to the hardware fault of STM32F407VET6 development board, the RX receiving bytes will be return to TX. It can be obvious at 9600 baud-rate.
 */
	extern uint8_t scmd;

	if (huart ==  &huart1)
	{


		if (aRxBuffer==0x00)
		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			printf("OV2640 Camera Menu!");
			printf("\r\n");
			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x01)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 1;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x02)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 2;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x03)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 3;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x04)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 4;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x05)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 5;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else
		{

		HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);

		}

	}

	if (huart ==  &huart2)
	{


		if (aRxBuffer==0x00)
		{
			printf("OV2640 Camera Menu!");
			printf("\r\n");
			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x01)		{
			scmd = 1;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x02)		{
			scmd = 2;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x03)		{
			scmd = 3;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x04)		{
			scmd = 4;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x05)		{
			scmd = 5;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else
		{

		HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);

		}

	}

      return;
}

/*
 * In hardware synchronization mode, only four interrupts can be used (IT_LINE, IT_FRAME, IT_OVR and IT_DCMI_VSYNC) but in embedded synchronization mode all the five interrupts can be used.
 */
void HAL_DCMI_VsyncEventCallback(DCMI_HandleTypeDef *hdcmi)  //w/ response
{
	extern uint32_t vsync_counter;
	extern uint32_t timing_ctr;
	static uint32_t cc=0;



	vsync_counter++;

	if (DCMI_CROP_EN==1)
	{
		   timing_ctr = 0;
	}
	else
	{
		if (vsync_counter%2==0)
		{
			timing_ctr = 1;
			while(HAL_DCMI_GetState(&hdcmi)== HAL_DCMI_STATE_BUSY) cc++;
		}
		else
		{
			timing_ctr = 0;
		}

	}

}

void HAL_DCMI_LineEventCallback(DCMI_HandleTypeDef *hdcmi)  //w/ response
{
	extern uint32_t line_counter;
	extern uint32_t point_counter;
	extern uint32_t timing_ctr;



	if (timing_ctr==0)
		{
		  if (line_counter==DCMI_RS)
		   {
			point_counter = __HAL_DMA_GET_COUNTER(&hdma_dcmi); //__HAL_DMA_GET_COUNTER(&hdma_dcmi):The left transmission times

		   }
		  if (line_counter==(DCMI_RS+1))
		   {
			point_counter = point_counter - __HAL_DMA_GET_COUNTER(&hdma_dcmi);

		   }
		  line_counter++;
		}


}

void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi) //w/ response
{
	extern uint32_t frame_counter;
	extern uint32_t timing_ctr;
	//static uint32_t dd=0;

	frame_counter++;

	if (DCMI_CROP_EN==1)
	{
		timing_ctr = 1;
	}
}

void HAL_DCMI_VsyncCallback(DCMI_HandleTypeDef *hdcmi) //w/o response
{
	//extern uint32_t vsync_counter;
	//vsync_counter++;

}

void HAL_DCMI_HsyncCallback(DCMI_HandleTypeDef *hdcmi)  //w/o response
{
	//extern uint32_t vsync_counter;
	//vsync_counter++;
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

void SPI2_ENDIAN_L(void)
{
	HAL_SPI_DeInit(&hspi2) ;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_LSB;
	  if (HAL_SPI_Init(&hspi2) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void SPI2_ENDIAN_H(void)
{
	HAL_SPI_DeInit(&hspi2) ;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	  if (HAL_SPI_Init(&hspi2) != HAL_OK)
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

















#else //RAW format

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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define RowNum 480
#define ColumnNum 1280

void DCMI_DMA_MemInc_En(void);
void DCMI_DMA_MemInc_Den(void);
void SPI2_ENDIAN_L(void) ;
void SPI2_ENDIAN_H(void) ;



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t aRxBuffer;			//接收�?�?缓冲
uint8_t Uart1_RxBuff[99] = {0};		//Rx buffer，should be adjusted according to Rx max byte length per communication.
uint8_t Uart2_RxBuff[99] = {0};		//Rx buffer，should be adjusted according to Rx max byte length per communication.
HAL_StatusTypeDef uart1_status_rx;
uint8_t Uart1_TxBuff[99] = {0};		//Tx buffer
uint8_t Uart4_TxBuff[2] = {0};			//Tx buffer
uint8_t StatusFlag = 0;

uint8_t ov2640_rd = 0xff;

uint8_t sram_wd;
uint8_t sram_rd;

uint8_t sram_TxCmd[4]={0x02,0x00,0x00,0x00};
uint8_t sram_TxData= 0x5a;
uint8_t sram_RxCmd[4]={0x03,0x00,0x00,0x00};
uint8_t sram_RxDummy= 0x00;
uint8_t sram_RxData= 0x00;

uint8_t sram_RxCmd_inv[4]={0xc0,0x00,0x00,0x00}; //for LSB of SPI2

HAL_StatusTypeDef spi_dma_status = HAL_OK;
HAL_StatusTypeDef dcmi_dma_status = HAL_OK;

uint32_t dcmi_data;

uint32_t dcmi_data_buff[19200]={0};

uint32_t vsync_counter = 0;
uint32_t line_counter = 0;
uint32_t point_counter =0;
uint32_t frame_counter =0;
uint32_t timing_ctr = 1;

uint8_t DCMI_CROP_EN = 0;
uint32_t DCMI_RN = 0;  //row number
uint32_t DCMI_CN = 0;  //column number
uint32_t DCMI_RS = 0;  //row start
uint32_t DCMI_CS = 0;  //column start


uint8_t scmd = 0;


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

SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_tx;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_SPI2_Init(void);
static void MX_DCMI_Init(void);
static void MX_UART4_Init(void);
static void MX_USART2_UART_Init(void);
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
  MX_TIM2_Init();
  MX_SPI2_Init();
  MX_DCMI_Init();
  MX_UART4_Init();
  MX_USART2_UART_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_Delay(100);

  if (HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1)!=HAL_OK) printf("UART1 IT FAILED! \r\n");
  printf("Serial port connected!");
  printf("\r\n");
  HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);

    HAL_Delay(500); //must to await camera running stable
    SCCB_Rst();
    HAL_Delay(500);

	SCCB_WR_Reg(0xff, 0x01);
 	SCCB_WR_Reg(0x12, 0x80);

    HAL_Delay(100);

	ov2640_rd = SCCB_RD_Reg(0x1c);
	printf("PID = %d",ov2640_rd);
	printf("\r\n");
	ov2640_rd = SCCB_RD_Reg(0x1d);
	printf("VER = %d",ov2640_rd);
	printf("\r\n");




		//SVGA Preview, 25fps, 24 Mhz input clock
		SCCB_WR_Reg(0xff, 0x01);
		SCCB_WR_Reg(0x11, 0x00);
		SCCB_WR_Reg(0x12, 0x40);
		SCCB_WR_Reg(0x2a, 0x00);
		SCCB_WR_Reg(0x2b, 0x00);
		SCCB_WR_Reg(0x46, 0x87);
		SCCB_WR_Reg(0x47, 0x00);
		SCCB_WR_Reg(0x3d, 0x38);


  		for(uint32_t i=0; i<sizeof(ov2640_svga_init_reg_tbl)/2 ; i++)
  	     {
  	       SCCB_WR_Reg(ov2640_svga_init_reg_tbl[i][0],ov2640_svga_init_reg_tbl[i][1]);
  		   if(i<10) HAL_Delay(5);
   	     }

		OV2640_YUV422_Mode();

		SCCB_WR_Reg(0xff, 0x01);
  		SCCB_WR_Reg(0x11, 0x04);  //revised by Pegasus Yu. PCLK can't be too fast to be captured by STM32 input pin.
  		SCCB_WR_Reg(0x32, 0x09);  //Warn: PCLK can't be adjusted here. Or it will affect vsync normal output.


		OV2640_Window_Set(140,4,800,600);
        OV2640_ImageSize_Set(800,600);
    	OV2640_ImageWin_Set(0,0,800,600);
    	OV2640_OutSize_Set(160,240);


     OV2640_Color_Bar(0);
     OV2640_Auto_Exposure(2);
     OV2640_Special_Effects(0);
     OV2640_Light_Mode(0);    //�?动模�?
     OV2640_Color_Saturation(2);//色彩饱和�?
     OV2640_Brightness(2);    //�?�?0
     OV2640_Contrast(2);        //对比�?

	 HAL_Delay(500); //pay attention

	   DCMI_CROP_EN = 1;
	   DCMI_RN = 159;  //row number
	   DCMI_CN = 320;  //column number
	   DCMI_RS = 0;  //row start
	   DCMI_CS = 0;  //column start
	   OV2640_PD ;
	   HAL_DCMI_DisableCrop (&hdcmi);
	   HAL_DCMI_ConfigCrop (&hdcmi, DCMI_CS, DCMI_RS, DCMI_CN, DCMI_RN);
	   HAL_DCMI_EnableCrop (&hdcmi);
	   dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, &dcmi_data, (DCMI_RN+1)*DCMI_CN/4); //65535 38400 (DCMI_RN+1)*DCMI_CN/4
	   OV2640_PU ;
	   printf("dcmi_dma_status = %d",dcmi_dma_status);
	   printf("\r\n");

	   HAL_Delay(250);  //pay attention

	   HAL_DCMI_Stop(&hdcmi);
		printf("\r\n");
		printf("vn = %d",vsync_counter);
		printf("\r\n");
		printf("ln = %d",line_counter);
		printf("\r\n");
		printf("pn = %d",point_counter);
		printf("\r\n");
		printf("fn = %d",frame_counter);
		printf("\r\n");


		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
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

    	 vsync_counter = 0;
    	 line_counter = 0;
    	 frame_counter =0;
    	 point_counter = 0;

      	  DCMI_DMA_MemInc_En();

      	  HAL_DCMI_DisableCrop (&hdcmi);
      	  HAL_Delay(100);
       	  Uart4_TxBuff[0]=0x55;
          Uart4_TxBuff[1]=0xaa;
      	  HAL_UART_Transmit(&huart4, Uart4_TxBuff, 2, 0xFFFFFF);

    	  for (uint8_t i=0; i<13;i++)
    	  {

    				//OV2640_Window_Set(140,0,800,640);
    		        //OV2640_ImageSize_Set(800,640);

    		    	OV2640_ImageWin_Set(0,i*48,800,48);
    		    	OV2640_OutSize_Set(800,48);
    		    	HAL_Delay(100);


    		     dcmi_dma_status = HAL_DCMI_Init(&hdcmi);

    	    	 HAL_Delay(100);

    	    	 dcmi_dma_status = HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, dcmi_data_buff, 76800/4);

    	    	 HAL_Delay(250);

    	    	 HAL_DCMI_Stop(&hdcmi);

    	    	  HAL_UART_Transmit(&huart4, (uint8_t *)dcmi_data_buff, 38400, 0xFFFFFF);
    	    	  HAL_UART_Transmit(&huart4, (uint8_t *)(&dcmi_data_buff[38400/4]), 38400, 0xFFFFFF);
    	    	  //HAL_Delay(200);

    	        	memset(dcmi_data_buff, 0, 76800);
    	        	HAL_Delay(10);


    	  }

    }


    if (scmd==2)
    {
     	scmd = 0;


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
  /* TIM2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
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
  hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_LOW;
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
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 230400;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

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
  huart1.Init.BaudRate = 9600;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 230400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3|GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin : PE3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PE13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
/*
 * Due to the hardware fault of STM32F407VET6 development board, the RX receiving bytes will be return to TX. It can be obvious at 9600 baud-rate.
 */
	extern uint8_t scmd;

	if (huart ==  &huart1)
	{


		if (aRxBuffer==0x00)
		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			printf("OV2640 Camera Menu!");
			printf("\r\n");
			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x01)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 1;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x02)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 2;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x03)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 3;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x04)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 4;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x05)		{
			HAL_Delay(500); //dummy time for hardware fault of serial port circuit in STM32F407VET6 development board
			scmd = 5;

			HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
		}
		else
		{

		HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);

		}

	}

	if (huart ==  &huart2)
	{


		if (aRxBuffer==0x00)
		{
			printf("OV2640 Camera Menu!");
			printf("\r\n");
			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x01)		{
			scmd = 1;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x02)		{
			scmd = 2;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x03)		{
			scmd = 3;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x04)		{
			scmd = 4;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else if(aRxBuffer==0x05)		{
			scmd = 5;

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);
		}
		else
		{

		HAL_UART_Receive_IT(&huart2, (uint8_t *)&aRxBuffer, 1);

		}

	}

      return;
}

/*
 * In hardware synchronization mode, only four interrupts can be used (IT_LINE, IT_FRAME, IT_OVR and IT_DCMI_VSYNC) but in embedded synchronization mode all the five interrupts can be used.
 */
void HAL_DCMI_VsyncEventCallback(DCMI_HandleTypeDef *hdcmi)  //w/ response
{
	extern uint32_t vsync_counter;
	extern uint32_t timing_ctr;
	static uint32_t cc=0;



	vsync_counter++;

	if (DCMI_CROP_EN==1)
	{
		   timing_ctr = 0;
	}
	else
	{
		if (vsync_counter%2==0)
		{
			timing_ctr = 1;
			while(HAL_DCMI_GetState(&hdcmi)== HAL_DCMI_STATE_BUSY) cc++;
		}
		else
		{
			timing_ctr = 0;
		}

	}

}

void HAL_DCMI_LineEventCallback(DCMI_HandleTypeDef *hdcmi)  //w/ response
{
	extern uint32_t line_counter;
	extern uint32_t point_counter;
	extern uint32_t timing_ctr;



	if (timing_ctr==0)
		{
		  if (line_counter==DCMI_RS)
		   {
			point_counter = __HAL_DMA_GET_COUNTER(&hdma_dcmi); //__HAL_DMA_GET_COUNTER(&hdma_dcmi):The left transmission times

		   }
		  if (line_counter==(DCMI_RS+1))
		   {
			point_counter = point_counter - __HAL_DMA_GET_COUNTER(&hdma_dcmi);

		   }
		  line_counter++;
		}


}

void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi) //w/ response
{
	extern uint32_t frame_counter;
	extern uint32_t timing_ctr;
	//static uint32_t dd=0;

	frame_counter++;

	if (DCMI_CROP_EN==1)
	{
		timing_ctr = 1;
	}
}

void HAL_DCMI_VsyncCallback(DCMI_HandleTypeDef *hdcmi) //w/o response
{
	//extern uint32_t vsync_counter;
	//vsync_counter++;

}

void HAL_DCMI_HsyncCallback(DCMI_HandleTypeDef *hdcmi)  //w/o response
{
	//extern uint32_t vsync_counter;
	//vsync_counter++;
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

void SPI2_ENDIAN_L(void)
{
	HAL_SPI_DeInit(&hspi2) ;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_LSB;
	  if (HAL_SPI_Init(&hspi2) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void SPI2_ENDIAN_H(void)
{
	HAL_SPI_DeInit(&hspi2) ;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	  if (HAL_SPI_Init(&hspi2) != HAL_OK)
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





















#endif//#ifdef RAW


#endif//#ifdef MAINBAKCUP
