#include "stm32f10x.h"
#include "Delay.h"
#include "Led.h"
#include "Key.h"
uint8_t KeyNum;
int main(void)
{	
	LED_Init();		
	Key_Init();		
	while(1)
	{
		KeyNum = Key_GetNum();		//获取按键键码		
		if (KeyNum == 1)			//按键1按下
			LED1_Turn();			//LED1翻转
		
		if (KeyNum == 2)			//按键2按下
			LED2_Turn();			//LED2翻转
	}
}
