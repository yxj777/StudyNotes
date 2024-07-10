#include "stm32f10x.h"

void IC_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_InitBaseIStruct;
	TIM_InitBaseIStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitBaseIStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitBaseIStruct.TIM_Period=100-1;
	TIM_InitBaseIStruct.TIM_Prescaler=720-1;
	TIM_InitBaseIStruct.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_InitBaseIStruct);
	
	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICInitStruct.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICFilter=0xF;
	TIM_ICInitStruct.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3, &TIM_ICInitStruct);
	
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
	
	TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	const double CLOCK=72000000;
	double freq=CLOCK/(TIM_GetPrescaler(TIM2)+1)/100/(TIM_GetCapture1(TIM3)+1);
	return freq;
}

