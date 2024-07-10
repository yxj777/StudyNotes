#include "stm32f10x.h"                  // Device header
#include "Encoder.h"

void Encoder_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	TIM_TimeBaseInitTypeDef TIM_InitBaseIStruct;
	TIM_InitBaseIStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitBaseIStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitBaseIStruct.TIM_Period=65536-1;
	TIM_InitBaseIStruct.TIM_Prescaler=1-1;
	TIM_InitBaseIStruct.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_InitBaseIStruct);
	
	TIM_ICInitTypeDef TIM_ICInitStruct;
	TIM_ICStructInit(&TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICFilter=0xF;
	TIM_ICInit(TIM3, &TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel=TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICFilter=0xF;
	TIM_ICInit(TIM3, &TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	
	TIM_Cmd(TIM3, ENABLE);
}
int16_t Encoder_Get(void)
{
	int16_t temp=TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3, 0);
	return temp;
}