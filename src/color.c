#include <STC15F2K60S2.H>
#include "color.h"
#include "motor.h"
#define HIGH 1
#define LOW 0

sbit S2 = P1^6;
sbit S3 = P1^7;



static unsigned int Get_Pul()
{
	unsigned int count = 0;
	TH1 = 0x00;
	TL1 = 0x00;
	TR1 = 1;
	delay_ms(300);
	TR1 = 0;
	count |= TH1;
	count <<= 8;
	count |= TL1;
	return count;
}

unsigned char Get_Color()
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	TMOD =0x50; //定时器初始化
	TH1 = 0x00;
	TL1 = 0x00;
//	S0 = LOW;
//	S1 = HIGH;
	//测量红色
	S2 = LOW;
	S3 = LOW;
	red = Get_Pul()/50;
	//测量绿色
	S2 = HIGH;
	S3 = HIGH;
	green = Get_Pul()/50;
	//测量蓝色
	S2 = LOW;
	S3 = HIGH;
	blue = Get_Pul()/50;
	if(blue * 8 > red * 10)
		return 3;
	if(green * 8 > blue * 10)
		return 2;
	if(red * 7 > blue * 10)
		return 1;
	return 0;
}