#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM_Motor.h"
#include "Key.h"
uint8_t cnt;
int main(void)
{		
	OLED_Init();		
	Motor_Init();
	Key_Init();
	int keyNum=0;
	float Speed=0;
	
	OLED_ShowString(1, 1, "Speed:");	//1行1列显示字符串Angle:
	while(1)
	{	
		keyNum=Key_GetNum();
		if(keyNum==1)
			Speed+=20;
		Mothor_Speed(Speed);
		
		OLED_ShowSignedNum(1, 7, Speed, 3);	//OLED显示速度变量
	}
}
