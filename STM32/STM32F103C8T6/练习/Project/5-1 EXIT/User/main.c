#include "stm32f10x.h"
#include "Delay.h"
#include "Led.h"
#include "EXIT.h"
#include "OLED.h"
uint8_t flag;
int main(void)
{	
	LED_Init();		
	Key_Init();	
	OLED_Init();		//OLED初始化
	
	/*OLED显示*/
		
	while(1)
	{
					
		OLED_ShowString(1, 1, "Flag=");	//1行3列显示字符串HelloWorld!
		OLED_ShowNum(1, 6, flag, 1);
		if(flag)
			LED1_Turn();
	}
}
