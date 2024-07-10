#include "stm32f10x.h"                  
#include "Delay.h"
extern uint8_t flag;
void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
	EXTI_InitTypeDef EXIT_InitStructure;
	EXIT_InitStructure.EXTI_Line=EXTI_Line1;
	EXIT_InitStructure.EXTI_LineCmd=ENABLE;
	EXIT_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXIT_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXIT_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI1_IRQHandler(void)
{
	flag=!flag;
	EXTI_ClearITPendingBit(EXTI_Line1);
}

