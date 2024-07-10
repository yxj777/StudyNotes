#include "stm32f10x.h"
#include "Delay.h"
int main(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	unsigned char led=0x01;
	while(1)
	{
		delay_ms(100);
		GPIO_Write(GPIOA,led);		
		led = led << 1;
		if(!led)
			led=0x01;
	}
}
