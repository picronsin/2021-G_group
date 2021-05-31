#include "motor.h"
#include <STC15F2K60S2.H>
#include "check.h"

void delay_ms(unsigned int ms)
{
     unsigned int i;
	 do{
	      i = 22118400L / 13000;
		  while(--i)	;   //14T per loop
     }while(--ms);
}

void Motor_Turn_Left90(void)
{
	MOTOR_LEFT;
	delay_ms(370);
	MOTOR_STOP;
}

//void Motor_Turn_Right90(void)
//{
//	MOTOR_RIGHT;
//	delay_ms(370);
//	MOTOR_STOP;
//}

void Motor_Turn_Left_Lock(void)
{
	MOTOR_LEFT;
	while(!Check_Crossing());
	while(!Check_Center());
	MOTOR_STOP;
}

void Motor_Turn_Right_Lock(void)
{
	MOTOR_RIGHT;
	while(!Check_Crossing());
	while(!Check_Center());
	MOTOR_STOP;
}
