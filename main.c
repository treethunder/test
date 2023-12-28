#include "stm32f10x.h" // Device header
#include "OLED.h"
#include "delay.h"



int main(void)
{
	OLED_Init();

	OLED_ShowString(1,2,"STM32F103C8T6");

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef s;
	s.GPIO_Mode=GPIO_Mode_Out_OD;
	s.GPIO_Pin=GPIO_Pin_1;
	s.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&s);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	Delay_ms(1000);
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
	OLED_ShowString(2,1,"data:0x");
	//BKP_WriteBackupRegister(BKP_DR1,0x3361);	 
	uint16_t data=BKP_ReadBackupRegister(BKP_DR1);	
		OLED_ShowHexNum(2,8,data,4);
	while(1)
	{
	

	}

}


	
