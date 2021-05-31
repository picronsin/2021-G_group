#include <STC15F2K60S2.H>
#include <check.h>

#define CHECK_MASK 0x1F //����
#define Check_Pin P0 //ѭ����IO��
#define CROSSING_LEFT_PIN   P0^0 //ת�Ǽ��IO��
#define CROSSING_RIGHT_PIN	P0^4

unsigned char Check_Center(void)
{
	if((~Check_Pin) & 0x04)
		return 1;
	return 0;
}

unsigned char Check_Path(void)	//ѭ���Ƽ��
{
	if((~Check_Pin) & 0x02)
		return 1;
	if((~Check_Pin) & 0x08)
		return 2;
	return 0;
}

unsigned char Check_Crossing(void) //��·�ڼ��
{
		if(~Check_Pin & 0x01)
			return 1;
		if(~Check_Pin & 0x10)
			return 2;
		return 0;
}

