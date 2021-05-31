#ifndef __APP_H
#define __APP_H

extern unsigned char Model_Flag; //当前模式标志位

void Throw();
void Line_inspection(void); // 巡线模式

void Object_Throw(unsigned char area_num);

#endif