#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM_Servo.h"
#include "Key.h"
uint8_t cnt;
int main(void)
{		
	OLED_Init();		
	PWM_Servo_Init();
	Key_Init();
	int keyNum=0;
	float Angle=0;
	
	OLED_ShowString(1, 1, "Angle:");	//1行1列显示字符串Angle:
	while(1)
	{	
//		keyNum=Key_GetNum();
//		if(keyNum == 1)
//			Angle+=30;
//		if(Angle>180)
//			Angle=0;
//		Servo_SetAngle(Angle); 
//		OLED_ShowNum(1, 7, Angle, 3);	//OLED显示角度变量
		Servo_SetAngle(180);
	}
}
