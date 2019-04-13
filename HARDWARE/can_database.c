
#include "all.h"

uint8_t Can_Data_Num=0;
union fi64_to_u8 CtrlCurrent;
union fi64_to_u8 Motor2Stm[M3508_num];

//SLAVER--GPS
//新加ID时，在ID_NUMDEF中定义相应ID的意义
/**/

//uint8_t MISO_GRAB_MOTOR;
//uint8_t MISO_COVER_MOTOR;
//union u16_to_u8 MISO_CURRENT;
//union fi64_to_u8 MISO_GRAB_LOC;
//union fi32_to_u8 MISO_COVER_SP;

//uint8_t MOSI_GAME_PROCESS;
//uint8_t MISO_CONTINUE_FLAG;
//uint8_t CAN_GAME_PROCESS;
//uint8_t MOSI_GRAB_FLAG; 
//uint8_t MOSI_SET_IO_FLAG;
//union u16_to_u8 MOSI_ESCON_DUTY;
//union fi64_to_u8 MOSI_GRAB_LOC;
//union fi64_to_u8 MOSI_TABLE_LOC;
//uint8_t MOSI_MOTOR_TEST_FLAG;
//uint8_t MOSI_RESTART_FLAG;
//uint8_t MISO_PASS_FLAG; 

uint8_t Now_Process;
uint8_t MISO_CONTINUE_FLAG;
uint8_t MISO_PASS_FLAG;
uint8_t MOSI_TEST_IO_FLAG;
uint8_t MOSI_MOTOR_TEST_FLAG;
uint8_t MOSI_HANDLE_FLAG;
uint8_t MOSI_BRAKE_FLAG;

union u16_to_u8 MOSI_ESCON_DUTY;
union fi64_to_u8 MOSI_GRAB_LOC;
union fi64_to_u8 MISO_GRAB_LOC;
union fi32_to_u8 MOSI_COVER_SP;
union fi32_to_u8 MISO_COVER_SP;

uint8_t MOSI_LENGTH_X;
uint8_t MOSI_LENGTH_Y;
union fi64_to_u8 MISO_LENGTH_X;
union fi64_to_u8 MISO_LENGTH_Y;

uint8_t MISO_GRAB_MOTOR;
uint8_t MISO_COVER_MOTOR;
union u16_to_u8 MISO_CURRENT;

void Null(void){}
Can_Data Can_Database[]=
{
	{Message,     ControlMotorID,    (uint8_t*)(&CtrlCurrent.u8_data),  	   8,        NULL,          		   	  2,        CAN_FILTER_FIFO0},
	{Control,     MOTOR1,            (uint8_t*)(&Motor2Stm[0].u8_data), 	   8,        PID_01,       				  2,        CAN_FILTER_FIFO0},
	{Control,     MOTOR2,            (uint8_t*)(&Motor2Stm[1].u8_data),        8,        PID_02,          			  2,        CAN_FILTER_FIFO0},
//	{Control,     MOTOR3,            (uint8_t*)(&Motor2Stm[2].u8_data),        8,        PID_03,       		   	      2,        CAN_FILTER_FIFO0},
	                                                                                                            	
	{READ_ONLY,  S_GRAB_MOTOR_ID,    (uint8_t*)(&MISO_GRAB_MOTOR),            1,        GRAB_Handler,                    1,     CAN_FILTER_FIFO0},
	{READ_ONLY,  S_SET_GRAB_ID,      (uint8_t*)(&MISO_GRAB_LOC.u8_data),      8,        Null,              				 1,     CAN_FILTER_FIFO0},
	{READ_ONLY,  S_COVER_MOTOR_ID,   (uint8_t*)(&MISO_COVER_MOTOR),           1,        COVER_Handler,   			     1,     CAN_FILTER_FIFO0},
	{READ_ONLY,  S_SET_COVER_ID,     (uint8_t*)(&MISO_COVER_SP.u8_data),      4,        Null,             				 1,     CAN_FILTER_FIFO0},
	{READ_ONLY,  S_SET_CURRENT_ID,   (uint8_t*)(&MISO_CURRENT.u8_data),       2,        Null,            				 1,     CAN_FILTER_FIFO0},
	

	{READ_ONLY,  W_GAME_PROCESS_ID,  (uint8_t*)(&Now_Process),                1,        W_GAME_PROCESS_ID_record,        1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  S_CONTINUE_FLAG_ID, (uint8_t*)(&MISO_CONTINUE_FLAG),         1,        S_CONTINUE_FLAG_ID_record,       1,     CAN_FILTER_FIFO1},

	{READ_ONLY,  W_SET_GRAB_ID,      (uint8_t*)(&MOSI_GRAB_LOC.u8_data),      8,        W_SET_GRAB_ID_record,      		1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_SET_COVER_ID,     (uint8_t*)(&MOSI_COVER_SP.u8_data),      4,        W_SET_COVER_ID_record,   		1,	  CAN_FILTER_FIFO1},
	{READ_ONLY,  W_SET_ESCON_ID,     (uint8_t*)(&MOSI_ESCON_DUTY.u8_data),    2,        W_SET_ESCON_ID_record,   	    1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_IO_TEST_ID,       (uint8_t*)(&MOSI_TEST_IO_FLAG),          1,        W_IO_TEST_ID_record,            1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_MOTOR_TEST_ID,    (uint8_t*)(&MOSI_MOTOR_TEST_FLAG),       1,        W_MOTOR_TEST_ID_record,         1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_HANDLE_ID,        (uint8_t*)(&MOSI_HANDLE_FLAG),           1,        W_HANDLE_record,  			    1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_BRAKE_ID,         (uint8_t*)(&MOSI_BRAKE_FLAG),            1,        W_BRAKE_ID_record,              1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  S_PASS_FLAG_ID,         (uint8_t*)(&MISO_PASS_FLAG),            1,        S_PASS_FLAG_ID_record,              1,     CAN_FILTER_FIFO1},
	
	{READ_ONLY,  W_LENGTH_X_ID,      (uint8_t*)(&MOSI_LENGTH_X),              1,        W_LENGTH_X_ID_record,       1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  W_LENGTH_Y_ID,      (uint8_t*)(&MOSI_LENGTH_Y),              1,        W_LENGTH_Y_ID_record,       1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  S_LENGTH_X_ID,      (uint8_t*)(&MISO_LENGTH_X.u8_data),      8,        S_LENGTH_X_ID_record,       1,     CAN_FILTER_FIFO1},
	{READ_ONLY,  S_LENGTH_Y_ID,      (uint8_t*)(&MISO_LENGTH_Y.u8_data),      8,        S_LENGTH_Y_ID_record,       1,     CAN_FILTER_FIFO1},
};


//HASH_TABLE初始值为999，认为Can_Data_Num值小于1000，即设备数少于1000个
uint16_t HASH_TABLE[1000]={999};

void Hash_Table_Init(void)
{
	int i;
	
	Can_Data_Num = sizeof(Can_Database) / sizeof(Can_Database[0]);
	for(i=0;i<256;i++)
	{
		HASH_TABLE[i] = 999;
	}
	for(i=0;i<Can_Data_Num;i++)
	{
		HASH_TABLE[Can_Database[i].Data_ID] = i;
	}
}

void Write_Database(ID_NUMDEF ID_NUM)
{
	uint8_t j;

	/* Check the parameters */
#if CAN_MASTER == 1
	if((HASH_TABLE[ID_NUM] >= Can_Data_Num)&&(Can_Database[HASH_TABLE[ID_NUM]].Data_type!=WRITE_ONLY))
#else
	if((HASH_TABLE[ID_NUM] >= Can_Data_Num)&&(Can_Database[HASH_TABLE[ID_NUM]].Data_type!=READ_ONLY))
#endif
	{
// 		LED4 = ON;
		return;
	}
	
	if (Can_Database[HASH_TABLE[ID_NUM]].Channel == 1)
	{
		CAN1_TxMessage.StdId=Can_Database[HASH_TABLE[ID_NUM]].Data_ID;
		CAN1_TxMessage.ExtId=0;
		CAN1_TxMessage.IDE=CAN_ID_STD;
		CAN1_TxMessage.RTR=CAN_RTR_DATA;
		CAN1_TxMessage.DLC=Can_Database[HASH_TABLE[ID_NUM]].Data_length;
		
		for(j = 0; j < Can_Database[HASH_TABLE[ID_NUM]].Data_length; ++j)
		{
			CAN1_TxMessage.Data[j]=(*(Can_Database[HASH_TABLE[ID_NUM]].Data_ptr+j));
		}
		
		Can_SendData(&CAN1_Handler);
	}
	else if (Can_Database[HASH_TABLE[ID_NUM]].Channel == 2)
	{
		CAN2_TxMessage.StdId=Can_Database[HASH_TABLE[ID_NUM]].Data_ID;
		CAN2_TxMessage.ExtId=0;
		CAN2_TxMessage.IDE=CAN_ID_STD;
		CAN2_TxMessage.RTR=CAN_RTR_DATA;
		CAN2_TxMessage.DLC=Can_Database[HASH_TABLE[ID_NUM]].Data_length;
		
		for(j = 0;j < Can_Database[HASH_TABLE[ID_NUM]].Data_length; ++j)
		{
			CAN2_TxMessage.Data[j]=(*(Can_Database[HASH_TABLE[ID_NUM]].Data_ptr+j));
		}
		
		Can_SendData(&CAN2_Handler);
	}
}
