#include "all.h"
#include "ff.h"

int main(void)
{
	char f_name[30] = "0:/STM32F407 LogicRecorder";
	
	HAL_Init();                     //初始化HAL库    
	Stm32_Clock_Init(336,8,2,7);   //设置时钟,168Mhz
	SystemCoreClockUpdate();
	
	delay_init(168);
	IO_Init();
	TIM2_Init(1000-1,84-1); //ms TIM2 是APB1总线上的定时器 时钟来源84MHz
//	EXTI_Config();
	LED1 = LED2 = LED3 = LED4 = OFF;
	
	my_mem_init(SRAMIN);		    //初始化内部内存池
	my_mem_init(SRAMCCM);		    //初始化CCM内存池 
	
	if(!SD_Init())//检测到SD卡
	{
		isSDcardExistence = true;      //SDcard存在标志位
		LED1 = LED2 = LED3 = ON;
		exfuns_init();							//为fatfs相关变量申请内存
		f_mount(fs[0],"0:",1); 					//挂载SD卡
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
//			delay_ms(5000);//5s延时 （会不会影响中断）
//			set_spd[1] = 0;
//			isCovermove = false;
//		}
	}
}
