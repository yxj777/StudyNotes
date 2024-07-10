#include "stm32f10x.h"
#include "Delay.h"
#include "Led.h"
#include "OLED.h"
#include "Timer.h"
uint8_t cnt;
int main(void)
{	
	//LED_Init();		
	OLED_Init();		
	TimerInit();
	OLED_ShowString(1, 1, "cnt=");
	
	while(1)
	{	
		OLED_ShowNum(1, 5, cnt, 5);
	}
}
