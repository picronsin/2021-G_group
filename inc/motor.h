#ifndef __MOTOR_H
#define __MOTOR_H

#include <STC15F2K60S2.H>

#define MOTOR_PORT 						P2
#define MOTOR_FORWARD    MOTOR_PORT=0x66
#define MOTOR_BACKWARD   MOTOR_PORT=0x99
#define MOTOR_STOP       MOTOR_PORT=0x00
#define MOTOR_LEFT       MOTOR_PORT=0x69
#define MOTOR_RIGHT      MOTOR_PORT=0x96
sbit servor = P3^7;

void delay_ms(unsigned int);
/* 小车前进；后退；停车；左转；右转*/
void Motor_Turn_Left90(void);
//void Motor_Turn_Right90(void);
void Motor_Turn_Left_Lock(void);
void Motor_Turn_Right_Lock(void);

#endif