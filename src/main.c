#include <STC15F2K60S2.H>
#include "app.h"
#include "intr.h"
#include "motor.h"
#include "color.h"

sbit key1 = P3^2;
sbit key2 = P3^3;
sbit LED1 = P0^5;
sbit LED2 = P0^6;
sbit LED3 = P0^7;

void main()
{
	unsigned char throw_direction = 1;
	servor = 0;
	delay_ms(1000);
	Servor_Control(5);
	
//	Line_inspection();
	while(1)
	{
		switch(throw_direction)
				{
					case 1:
						LED1 = 1;
						LED2 = 1;
						LED3 = 0;
						break;
					case 2:
						LED1 = 1;
						LED2 = 0;
						LED3 = 1;
						break;
					case 3:
						LED1 = 1;
						LED2 = 0;
						LED3 = 0;
						break;
					case 4:
						LED1 = 0;
						LED2 = 1;
						LED3 = 1;
						break;
					case 5:
						LED1 = 0;
						LED2 = 1;
						LED3 = 0;
				}
		if(key1 == 0)
		{
			delay_ms(20);
			if(key1 == 0)
			{
				while(key1 == 0);
				throw_direction++;
				if(throw_direction > 5)
					throw_direction = 1;
			}
		}
		if(key2 == 0)
		{
			delay_ms(20);
			if(key2 == 0)
			{	
				while(key2 == 0);
				delay_ms(500);
				switch(throw_direction)
				{
					case 1:
					case 2:
					case 3:
						Object_Throw(throw_direction);
						break;
					case 4:
						{
							unsigned char color = 0;
							while(!(color = Get_Color()));
							Object_Throw(color);
						}
						break;
					case 5:
						Line_inspection();
						break;
				}
			}
		}
	}
}