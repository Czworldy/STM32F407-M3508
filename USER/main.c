#include "all.h"
#include "ff.h"

int main(void)
{
	char f_name[30] = "0:/STM32F407 LogicRecorder";
	
	HAL_Init();                     //��ʼ��HAL��    
	Stm32_Clock_Init(336,8,2,7);   //����ʱ��,168Mhz
	SystemCoreClockUpdate();
	
	delay_init(168);
	IO_Init();
	TIM2_Init(1000-1,84-1); //ms TIM2 ��APB1�����ϵĶ�ʱ�� ʱ����Դ84MHz
//	EXTI_Config();
	LED1 = LED2 = LED3 = LED4 = OFF;
	
	my_mem_init(SRAMIN);		    //��ʼ���ڲ��ڴ��
	my_mem_init(SRAMCCM);		    //��ʼ��CCM�ڴ�� 
	
	if(!SD_Init())//��⵽SD��
	{
		isSDcardExistence = true;      //SDcard���ڱ�־λ
		LED1 = LED2 = LED3 = ON;
		exfuns_init();							//Ϊfatfs��ر��������ڴ�
		f_mount(fs[0],"0:",1); 					//����SD��
		f_record_init(f_name); 
	}
	else
	{
		LED4 = ON;
	}
	PID_Init();
	CAN_Mode_Init();
	while(1)
	{
//		if(isCovermove == true)
//		{	
//			set_spd[1] = MISO_COVER_SP.i32_data;
//			delay_ms(5000);//5s��ʱ ���᲻��Ӱ���жϣ�
//			set_spd[1] = 0;
//			isCovermove = false;
//		}
	}
}
