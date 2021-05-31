#include <STC15F2K60S2.H>
#include "check.h"
#include "motor.h"
#include "intr.h"

extern unsigned char throw_flag;
unsigned char Position_Status = 0;
/* 入线并巡线模式 Line_inspection() */

void Throw(void)
{
	MOTOR_STOP;
	delay_ms(300);
	Motor_Turn_Left90();
	delay_ms(140);
	MOTOR_FORWARD;
	delay_ms(400);
	MOTOR_STOP;
	delay_ms(300);
	servor = 0;
	delay_ms(200);
	Servor_Control(2);
	Servor_Control(5);
	MOTOR_BACKWARD;
	delay_ms(400);
	MOTOR_STOP;
	delay_ms(140);
	Motor_Turn_Right_Lock();
	delay_ms(300);
	throw_flag = 0;
}

static void Throw_1()
{
	while(1)
	{
		if(throw_flag == 1)
			Throw();
		if(Position_Status > 3)
		{
			Position_Status = 0;
			break;
		}
	  if(Check_Crossing())
		{
			MOTOR_FORWARD;
			delay_ms(140);
			MOTOR_STOP;
			delay_ms(300);
			Motor_Turn_Left_Lock();
			delay_ms(140);
			Position_Status++;
			if(Position_Status == 1)
				Timer1_Init();
			continue;
		}
		if(Check_Path() == 1)
		{
			MOTOR_LEFT;
		}
		else if(Check_Path() == 2)
		{
			MOTOR_RIGHT;
		}
		else
		{
			MOTOR_FORWARD;
		}
	}
}

static void Throw_2()
{
	while(1)
	{
		if(throw_flag == 1)
			Throw();
		if(Position_Status > 5)
		{
			Position_Status = 0;
			break;
		}
	  if(Check_Crossing())
		{
			if(Position_Status == 1 || Position_Status == 4)
			{
				MOTOR_FORWARD;
				delay_ms(150);
				Position_Status++;
				if(Position_Status == 2)
					Timer1_Init();
				continue;
			}
			MOTOR_FORWARD;
			delay_ms(140);
			MOTOR_STOP;
			delay_ms(300);
			Motor_Turn_Left_Lock();
			delay_ms(140);
			Position_Status++;
			continue;
		}
		if(Check_Path() == 1)
		{
			MOTOR_LEFT;
		}
		else if(Check_Path() == 2)
		{
			MOTOR_RIGHT;
		}
		else
		{
			MOTOR_FORWARD;
		}
	}
}

static void Throw_3()
{
	while(1)
	{
		if(throw_flag == 1)
			Throw();
		if(Position_Status > 7)
		{
			Position_Status = 0;
			break;
		}
	  if(Check_Crossing())
		{
			if(Position_Status == 1 || Position_Status == 2 || Position_Status == 5 || Position_Status == 6)
			{
				MOTOR_FORWARD;
				delay_ms(150);
				Position_Status++;
				if(Position_Status == 3)
					Timer1_Init();
				continue;
			}
			MOTOR_FORWARD;
			delay_ms(140);
			MOTOR_STOP;
			delay_ms(300);
			Motor_Turn_Left_Lock();
			delay_ms(140);
			Position_Status++;
			continue;
		}
		if(Check_Path() == 1)
		{
			MOTOR_LEFT;
		}
		else if(Check_Path() == 2)
		{
			MOTOR_RIGHT;
		}
		else
		{
			MOTOR_FORWARD;
		}
	}
}

void Line_inspection(void)
{
	Position_Status = 0;
	while(1)
	{
		if(Position_Status > 7)
		{
			Position_Status = 0;
			MOTOR_STOP;
			break;
		}
	  if(Check_Crossing())
		{
			if(Position_Status == 1 || Position_Status == 2 || Position_Status == 5 || Position_Status == 6)
			{
				MOTOR_FORWARD;
				delay_ms(150);
				Position_Status++;
				continue;
			}
			MOTOR_FORWARD;
			delay_ms(140);
			MOTOR_STOP;
			delay_ms(300);
			Motor_Turn_Left_Lock();
			delay_ms(140);
			Position_Status++;
			continue;
		}
		if(Check_Path() == 1)
		{
			MOTOR_LEFT;
		}
		else if(Check_Path() == 2)
		{
			MOTOR_RIGHT;
		}
		else
		{
			MOTOR_FORWARD;
		}
	}
}

void Object_Throw(unsigned char area_num)
{
	Position_Status = 0;
	switch(area_num)
	{
		case 1:
			Throw_1();
			break;
		case 2:
			Throw_2();
			break;
		case 3:
			Throw_3();
			break;
	}
}
