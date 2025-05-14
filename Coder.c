#include "Coder.h"

void Coder_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStruct; 
	EXTI_InitTypeDef EXTI_InitStruct; 

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE); 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource2);

	EXTI_InitStruct.EXTI_Line = EXTI_Line2; 
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; 
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising; 
	EXTI_InitStruct.EXTI_LineCmd = ENABLE; 
	EXTI_Init(&EXTI_InitStruct); 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 

	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn; 
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =0; 
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =0; 
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStruct); 
}