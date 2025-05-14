#include "delay.h" 
#include "usart.h"
#include "Coder.h"

uint32_t count = 0;

int main(void)
{
	
	delay_init(168);
	uart_init(115200);
	Coder_Init();
	while(1)
	{	
		printf("count:%d\n",count);
		delay_ms(1000);
	}
}

void EXTI2_IRQHandler(void)  
{ 
	if (EXTI_GetITStatus(EXTI_Line2) == SET) 
	{ 
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2) == 1)
		{
			count++;
		}
	} 
	EXTI_ClearITPendingBit(EXTI_Line2); 
}