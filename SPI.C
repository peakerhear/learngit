#include <HTC.H>
#include <stdio.h>
#include "DEFINE.H"

/***************************************************************************
**函数名  : SPIMasterInit
**功能    : SPI初始化函数
**输入参数：无
**返回值  ：无
***************************************************************************/ 

void SPIMasterInit()
{
	//TRISC = TRISC|0xD7; //SDO、SCK为输出，其它为输入

	SSPSTAT=0x80;        //清除SMP、CKE位

 	SSPCON1=0X30;         //设置SSP控制方式：SPI主控,CKP=1;  FOSC/64---0x32, FOSC/16---0x31,FOSC/4---0x30
}


/***************************************************************************
**函数名  : SPIMasterTransmit
**功能    : SPI主机传输函数
**输入参数：sData
**返回值  ：SSPBUF
***************************************************************************/ 

UCHAR SPIMasterTransmit(UCHAR sData)
{
	SSPBUF = sData;			             //启动数据传输
							
	while (!SSPIF)	;                    //等待数据传输完毕

       SSPIF = 0;

	return SSPBUF;
}

/***************************************************************************
**函数名  : SPI_MasterReceive
**功能    : SPI主机接收函数
**输入参数：null
**返回值  ：SSPBUF
***************************************************************************/ 

UCHAR SPI_MasterReceive()
{
    UCHAR sdata = 0;

	SSPBUF = 0;		
			
    	while (!SSPIF)	;    	//等待数据接收完毕		
	
	SSPIF = 0;

       sdata  = SSPBUF;

	return (sdata);
}
/***************************Nothing code below this line*******************************/