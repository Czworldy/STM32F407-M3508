#ifndef _CAN_DATABASE_H
#define _CAN_DATABASE_H
	#include "all.h"
	
	#ifndef NULL
	#define NULL ((void *)0)
	#endif
	
	#define fp64 double
	#define fp32  float
	
union fi64_to_u8     //fp64�����ݣ���int64_t������ת��u8�����ݽ���can���߷���
	{
		fp64	f64_data;
		float   f32_data[2];
		int64_t i64_data;
		int32_t i32_data[2];
		uint64_t u64_data;
		uint16_t u16_data[4];
		int16_t i16_data[4];
		uint8_t u8_data[8];
	};
	
	union fi32_to_u8     //fp32�����ݣ���int32_t������ת��u8�����ݽ���can���߷���
	{
		fp32	f32_data;
		int32_t i32_data;
		uint32_t u32_data;
		int16_t i16_data[2];
		uint8_t u8_data[4];
	};
	
	union u16_to_u8
	{
		int16_t i16_data;
		uint16_t u16_data;
		uint8_t u8_data[2];
	};

	#define READ_ONLY  0	//���ض�������д
	#define WRITE_ONLY 1	//����д�������
	#define Control    0  //��������
	#define Message    1	//��Ϣ����	
	#define MotorBaseID 0x200

/*���������Ӧ��ID���б�*/
/*
IDλ��	[	(GS:GPS Slave  MS:Motor Slave)							]
NO.7	[			0--GS			|		1--Others				]
NO.6	[	0--MOSI		|	1--MISO	|	0--MS MOSI	|	1--Others	]
NO.5~0	[	ID numbers				|	ID numbers  &  Others		]
	
	Others��
		B11-000-xxx ����&&ISOЭ����ͨ��ID
		B11-001-xxx ����&&cameraͨ��ID--MISO
		B11-011-xxx ����&&cameraͨ��ID--MOSI
		B11-010-xxx ������relayͨ��ID
		B11-100-xxx �����벿��Э����ͨ��ID   ��������������
*/
	typedef enum
	{
//		W_MaxSpeed_ID = 0x1C,
//		W_StartMoving_ID = 0x1D,
//		W_DelayTime_ID = 0x1E,
		
		ControlMotorID = 0x200,
		ControlMotorID2 = 0x1FF,
		MOTOR1 = MotorBaseID + 1,
		MOTOR2 = MotorBaseID + 2,
		MOTOR3 = MotorBaseID + 3,
		MOTOR4 = MotorBaseID + 4,

		S_GRAB_MOTOR_ID=0x80,          //���ض���ץ��
		S_SET_GRAB_ID=0x81,            //���ض���ץ��λ��
		S_COVER_MOTOR_ID=0x82,         //���ض����ϸǵ��
		S_SET_COVER_ID=0x83,           //���ض����ϸ��ٶ�
		S_SET_CURRENT_ID=0x84,         //���ض������Ƶ���

	
		W_GAME_PROCESS_ID=0x01,       //����д,��������ӹ㲥��������
		S_CONTINUE_FLAG_ID=0x02,      //���ض������ϲ���ư�ı�־λ
		W_IO_TEST_ID=0x22,             //����д�����Ե�ŷ�IO��
		W_SET_ESCON_ID=0x23,          //����д������Ħ���ֵ��ת��
		W_SET_GRAB_ID=0x24,           //����д������ץ�ֵ��λ��
		W_SET_COVER_ID=0x25,          //����д�������ϸǵ���ٶ�
		W_MOTOR_TEST_ID=0x26,     	  //����д���������
		W_GAME_RESTART_ID=0x27,	 		  //����д��������־
		S_PASS_FLAG_ID=0x28,          //���ض������ƽ��ӱ�־
		W_HANDLE_ID=0x29,             //����д���ֱ�
		W_BRAKE_ID=0x2A,              //����д��ɲ��

		W_LENGTH_X_ID=0x70,           //����д������X
		W_LENGTH_Y_ID=0x71,           //����д������Y
		S_LENGTH_X_ID=0x72,           //���ض�������X
		S_LENGTH_Y_ID=0x73,           //���ض�������Y
	}ID_NUMDEF;	
	
	/*���غ�GPSЭ����֮��������ʽ*/
//	typedef enum
//	{
//		NO_COMMAND			= 0x00,
//		//M_G_CMD_ID�µ�����
//		GPS_READ			= 0x01,		//��ȡGPS��Ϣ����
//		CHECK_FLOAT			= 0x02,		//֪ͨGPSЭ����У׼��������Ư����
//		GYRO_INIT			= 0x03,		//֪ͨGPSЭ���ر궨����������
//		ENC_L_INIT			= 0x04,		//֪ͨGPSЭ���ر궨��������תϵ������
//		ENC_R_INIT			= 0x05,		//֪ͨGPSЭ���ر궨������ת�뾶����
//		//G_M_CMD_ID�µ�����
//		CF_NORMAL			= 0x06,
//		CF_CHANGED			= 0x07,
//		CF_ERROR			= 0x08
//	}COM_TYPE;
	
//	typedef enum
//	{
//		FIND_ONCE = 0x01,
//		FIND_CONTINIOUS = 0x02,
//		FIND_NO_SEND = 0x03,
//		FIND_STOP = 0x00
//	}CAMERA_CMD;
	
	typedef struct
	{
		uint8_t  Data_type;
		ID_NUMDEF  Data_ID;
		uint8_t* Data_ptr;
		uint8_t  Data_length;
		
		//��can���߽ӵ����ݺ󣬵��õĺ���
		void (*MenuFunc)(void);			//��ں���		
		uint8_t  Channel;
		uint8_t  Fifo_num;			//�ڽ��շ�����ID���õ�fifo��
	}Can_Data;

	
	extern uint8_t Can_Data_Num;
	extern Can_Data Can_Database[];
	extern uint16_t HASH_TABLE[1000];
	extern union fi64_to_u8 CtrlCurrent;
	extern union fi64_to_u8 Motor2Stm[];

	extern uint8_t MISO_GRAB_MOTOR;
	extern uint8_t MISO_UP_MOTOR;
	extern union fi64_to_u8 MISO_GRAB_LOC;
	
	void Hash_Table_Init(void);
	void Write_Database(ID_NUMDEF ID_NUM);
typedef union 
{
    u8 d[2];
    s16 v;
}u8tos16_t;

typedef struct
{
		u8tos16_t	x_or_angle;
		u8tos16_t	y_or_dis;
		u8tos16_t	z;
	  u8tos16_t	turn;  
		int time_flag;
}camera_t;

//	extern union fi64_to_u8 camera_data1;
//	extern uint8_t MISO_FAN_GRAB_STATUS;
//	extern uint8_t M0SI_FAN_GRAB;

//	extern uint8_t MOSI_GAME_PROCESS;
//	extern uint8_t MISO_CONTINUE_FLAG;
//	extern uint8_t CAN_GAME_PROCESS;
//	extern uint8_t MOSI_GRAB_FLAG; 
//	extern uint8_t MOSI_SET_IO_FLAG;
//	extern union u16_to_u8 MOSI_ESCON_DUTY;
//	extern union fi64_to_u8 MOSI_GRAB_LOC;
//	extern union fi64_to_u8 MOSI_TABLE_LOC;

//	extern union fi64_to_u8 MISO_GRAB_LOC;
//	extern union fi32_to_u8 MISO_COVER_SP;
//	extern uint8_t MISO_GRAB_MOTOR;
//	extern uint8_t MISO_COVER_MOTOR;
//	extern union u16_to_u8 MISO_CURRENT;

//	extern uint8_t MOSI_MOTOR_TEST_FLAG;
//	extern uint8_t MOSI_RESTART_FLAG;
//	extern uint8_t MISO_PASS_FLAG;
	
	
	
	
	extern uint8_t Now_Process;
	extern uint8_t MISO_CONTINUE_FLAG;
	extern uint8_t MISO_PASS_FLAG;
	extern uint8_t MOSI_TEST_IO_FLAG;
	extern uint8_t MOSI_MOTOR_TEST_FLAG;
	extern uint8_t MOSI_HANDLE_FLAG;
	extern uint8_t MOSI_BRAKE_FLAG;

	extern union u16_to_u8 MOSI_ESCON_DUTY;
	extern union fi64_to_u8 MOSI_GRAB_LOC;
	extern union fi64_to_u8 MISO_GRAB_LOC;
	extern union fi32_to_u8 MOSI_COVER_SP;
	extern union fi32_to_u8 MISO_COVER_SP;

	extern uint8_t MOSI_LENGTH_X;
	extern uint8_t MOSI_LENGTH_Y;
	extern union fi64_to_u8 MISO_LENGTH_X;
	extern union fi64_to_u8 MISO_LENGTH_Y;
	
	extern uint8_t MISO_GRAB_MOTOR;
	extern uint8_t MISO_COVER_MOTOR;
	extern union u16_to_u8 MISO_CURRENT;


#endif


