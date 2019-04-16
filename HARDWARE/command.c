 #include "all.h"

FIL f_can;
FIL f_mycan;
FRESULT f_can_res;
bool isSDcardExistence = false;
//bool isCovermove = false;
void GRAB_Handler(void) 
{
	set_loc[0] = MISO_GRAB_LOC.i32_data[0];
	set_spd[0] = MISO_GRAB_LOC.i32_data[1];
	f_record("f_mytest.txt",&f_mycan,"GRAB_Handler		loc:%d  	spd:%d 		time:%d \r\n",set_loc[0],set_spd[0],time*1000+TIM2->CNT);
}

void COVER_Handler(void)
{
	//isCovermove = true;
	set_spd[1] = MISO_COVER_SP.i32_data;
	f_record("f_mytest.txt",&f_mycan,"COVER_Handler		spd:%d 		time:%d \r\n",MISO_COVER_SP.i32_data,time*1000+TIM2->CNT);
	
}

void W_GAME_PROCESS_ID_record(void)
{
	if(Now_Process == 0)	//ÓÎÏ·¿ªÊ¼
	{	
		TIM2->CNT = 0;
		time = 0;
		__HAL_TIM_ENABLE(&TIM2_Handler);
	}
	f_record("f_test.txt",&f_can,"W_GAME_PROCESS_ID		%d  	time:%d \r\n",Now_Process,time*1000+TIM2->CNT);
}

void S_CONTINUE_FLAG_ID_record(void)
{
	f_record("f_test.txt",&f_can,"S_CONTINUE_FLAG_ID		%d 		time:%d \r\n",MISO_CONTINUE_FLAG,time*1000+TIM2->CNT);
}

void W_SET_GRAB_ID_record(void)
{
	f_record("f_test.txt",&f_can,"W_SET_GRAB_ID		data0:%d  	data1:%d\r\n",MOSI_GRAB_LOC.i32_data[0],MOSI_GRAB_LOC.i32_data[1]);
}

void W_SET_COVER_ID_record(void)
{
		f_record("f_test.txt",&f_can,"W_SET_COVER_ID		%d\r\n",MOSI_COVER_SP.i32_data);
}

void W_SET_ESCON_ID_record(void)
{
		f_record("f_test.txt",&f_can,"W_SET_ESCON_ID		%d\r\n",MOSI_ESCON_DUTY.u16_data);
}
void W_IO_TEST_ID_record(void)
{
		f_record("f_test.txt",&f_can,"W_IO_TEST_ID		%d	\r\n",MOSI_TEST_IO_FLAG);
}
void W_MOTOR_TEST_ID_record(void)
{
		f_record("f_test.txt",&f_can,"W_MOTOR_TEST_ID		%d	\r\n",MOSI_MOTOR_TEST_FLAG);
}
void W_HANDLE_record(void)
{
		f_record("f_test.txt",&f_can,"W_HANDLE		%d\r\n",MOSI_HANDLE_FLAG);
}
void W_BRAKE_ID_record(void)
{
		f_record("f_test.txt",&f_can,"W_BRAKE_ID		%d\r\n",W_BRAKE_ID);
}
void W_LENGTH_X_ID_record(void)
{
	f_record("f_test.txt",&f_can,"W_LENGTH_X_ID		%d  	time:%d \r\n",MOSI_LENGTH_X,time*1000+TIM2->CNT);
}
void W_LENGTH_Y_ID_record(void)
{
	f_record("f_test.txt",&f_can,"W_LENGTH_Y_ID		%d  	time:%d \r\n",MOSI_LENGTH_Y,time*1000+TIM2->CNT);
}
void S_LENGTH_X_ID_record(void)
{
	f_record("f_test.txt",&f_can,"S_LENGTH_X_ID		%f  	%f  	time:%d \r\n",MISO_LENGTH_X.f32_data[0],MISO_LENGTH_X.f32_data[1],time*1000+TIM2->CNT);
}
void S_LENGTH_Y_ID_record(void)
{
	f_record("f_test.txt",&f_can,"S_LENGTH_Y_ID		%f  	time:%d\r\n",MISO_LENGTH_Y.f64_data,time*1000+TIM2->CNT);
}
void S_PASS_FLAG_ID_record(void)
{
	f_record("f_test.txt",&f_can,"S_PASS_FLAG_ID		%d  	time:%d \r\n",MISO_PASS_FLAG,time*1000+TIM2->CNT);
}
