#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM_LED.h"
uint8_t cnt;
int main(void)
{		
	OLED_Init();		
	PWM_LED_Init();
	int i;
	while(1)
	{	
		for (i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(i);			//���ν���ʱ����CCR�Ĵ�������Ϊ0~100��PWMռ�ձ�������LED�𽥱���
			Delay_ms(10);				//��ʱ10ms
		}
		for (i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(100 - i);	//���ν���ʱ����CCR�Ĵ�������Ϊ100~0��PWMռ�ձ��𽥼�С��LED�𽥱䰵
			Delay_ms(10);				//��ʱ10ms
		}
	}
}
