#include "stm32f10x.h"
#include "IC.h"
void IC_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_InitBaseIStruct;
	TIM_InitBaseIStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitBaseIStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitBaseIStruct.TIM_Period=65536-1;
	TIM_InitBaseIStruct.TIM_Prescaler=72-1;
	TIM_InitBaseIStruct.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_InitBaseIStruct);
	
	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICInitStruct.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICFilter=0xF;
	TIM_ICInitStruct.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_PWMIConfig(TIM3, &TIM_ICInitStruct);
	
	
	
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
	
	TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	double freq=CLOCK/(TIM_GetPrescaler(TIM3)+1)/(TIM_GetCapture1(TIM3)+1);
	return freq;
}
uint32_t IC_GetDuty(void)
{
	return (TIM_GetCapture2(TIM3) + 1) * 100 / (TIM_GetCapture1(TIM3) + 1);
}
