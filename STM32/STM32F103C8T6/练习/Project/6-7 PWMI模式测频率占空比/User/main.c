#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
uint8_t cnt;
int main(void)
{		
	OLED_Init();		//OLED��ʼ��
	PWM_Init();			//PWM��ʼ��
	IC_Init();			//���벶���ʼ��
	
	/*��ʾ��̬�ַ���*/
	OLED_ShowString(1, 1, "Freq:00000Hz");		//1��1����ʾ�ַ���Freq:00000Hz
	OLED_ShowString(2, 1, "Duty:000%");			//2��1����ʾ�ַ���Duty:00%
	
	/*ʹ��PWMģ���ṩ���벶��Ĳ����ź�*/
	PWM_SetPrescaler(720 - 1);					//PWMƵ��Freq = 72M / (PSC + 1) / 100
	PWM_SetCompare1(50);						//PWMռ�ձ�Duty = CCR / 100
	
	while (1)
	{
		OLED_ShowNum(1, 6, IC_GetFreq(), 5);	//����ˢ����ʾ���벶���õ�Ƶ��
		OLED_ShowNum(2, 6, IC_GetDuty(), 3);	//����ˢ����ʾ���벶���õ�ռ�ձ�
	}
}
