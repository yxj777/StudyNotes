#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
int Speed=0;
int main(void)
{	
	//LED_Init();		
	OLED_Init();		//OLED��ʼ��
	TimerInit();		//��ʱ����ʼ��
	Encoder_Init();		//��������ʼ��
	
	/*��ʾ��̬�ַ���*/
	OLED_ShowString(1, 1, "Speed:");		//1��1����ʾ�ַ���Speed:
	
	while (1)
	{
		OLED_ShowSignedNum(1, 7, Speed, 5);	//����ˢ����ʾ��������õ������ٶ�
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