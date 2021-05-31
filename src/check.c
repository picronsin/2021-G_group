#include <STC15F2K60S2.H>
#include <check.h>

#define CHECK_MASK 0x1F //ÑÚÂë
#define Check_Pin P0 //Ñ­¼£µÆIO¿Ú
#define CROSSING_LEFT_PIN   P0^0 //×ª½Ç¼ì²âIO¿Ú
#define CROSSING_RIGHT_PIN	P0^4

unsigned char Check_Center(void)
{
	if((~Check_Pin) & 0x04)
		return 1;
	return 0;
}

unsigned char Check_Path(void)	//Ñ­¼£µÆ¼ì²â
{
	if((~Check_Pin) & 0x02)
		return 1;
	if((~Check_Pin) & 0x08)
		return 2;
	return 0;
}

unsigned char Check_Crossing(void) //²íÂ·¿Ú¼ì²â
{
		if(~Check_Pin & 0x01)
			return 1;
		if(~Check_Pin & 0x10)
			return 2;
		return 0;
}

