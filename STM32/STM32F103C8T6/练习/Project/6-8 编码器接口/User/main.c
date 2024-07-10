#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
int Speed=0;
int main(void)
{	
	//LED_Init();		
	OLED_Init();		//OLED初始化
	TimerInit();		//定时器初始化
	Encoder_Init();		//编码器初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "Speed:");		//1行1列显示字符串Speed:
	
	while (1)
	{
		OLED_ShowSignedNum(1, 7, Speed, 5);	//不断刷新显示编码器测得的最新速度
	}
}


void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Speed = Encoder_Get();						
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);	
													
													
	}
}