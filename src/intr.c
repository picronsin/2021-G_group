#include <STC15F2K60S2.H>
#include "app.h"
#include "motor.h"

unsigned char  lock = 0;
unsigned char throw_flag = 0;
static T1_num = 0;
static T0_num = 0;
static pwm_value = 0;

void Timer1_Init(void)
{
	EA = 1;
	ET1 = 1;
	TMOD = 0x10;
	T1_num = 0;
	TH1 = (65536 - 10000)/256; 
	TL1 = (65536 - 10000)%256;
	TR1 = 1;
}

void Servor_Control(unsigned char helf_ms)
{
	lock = 1;
	pwm_value = helf_ms;
	EA = 1;
	ET0 = 1;
	TMOD = 0x01;
	T0_num = 0;
	TH0 = (65536 - 300)/256;
	TL0 = (65536 - 300)%256;
	TR0 = 1;
	servor = 0;
	while(lock);
	delay_ms(1000);
}


void Throw_Wait(void) interrupt 3
{
	if(T1_num > 20)
	{
		T1_num = 0;
		TR1 = 0;
		ET1 = 0;
		throw_flag = 1;
	}
	TH1 = (65536 - 10000)/256; 
	TL1 = (65536 - 10000)%256;
	T1_num++;
}

void Servor(void) interrupt 1
{
	if(T0_num < pwm_value)
		servor = 1;
	else if(T0_num > 40)
	{
		T0_num = 0;
		TR0 = 0;
		ET0 = 0;
		lock = 0;
	}
	else
	{
		servor = 0;
	}
	T0_num++;
	TH0 = (65536 - 300)/256;
	TL0 = (65536 - 300)%256;
}