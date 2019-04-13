
#include "all.h"
#include "math.h"



float one_mm=8192*3591/187/80/3.1415927;//625.9272744521378026886985111002
float one_rpm=80*3.1415927*187/3591/60;//0.21812970756520931959528450756521



/*#define Velocity_Loop 0
#define delta_time 1 //((TIM2->ARR)*(TIM2->PSC))/72000000
int cnt=0;
union fi64_to_u8 Motor2Stm[4];
Set_Target Set_List[4];
Error Error_List[4];
moto_measure_t MotorData[4];
union fi64_to_u8 CtrlCurrent;
u8 UsartData[2];*/

// PID PID_List[4]=
// {
// 	/* Kp  Ki  Kd*/
// 		{1.0 , 10.0 , 0.0 , 0.0 , 0.0 , 0.0},
// 		{1.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0},
// 		{1.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0},
// 		{1.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0},
// };
/*
void PID_Clear()
{
	
}
float PID_calc(float Error, PID *pid)
{
	float A=0;
	float B=0;
	float C=0;
	float delta=0;
	
	A = (pid->p*(1+(delta_time/(pid->i))+((pid->d)/delta_time)));
	B = -pid->p*(1+2*(pid->d)/delta_time);
	C = pid->p*pid->d/delta_time;
	
	delta = A*Error + B*pid->ep1 + C*pid->ep2;
	pid->mend += delta;
	
	pid->ep2 = pid->ep1;
	pid->ep1 = Error;
	
	return pid->mend;
}

void Get_Error(void)
{
	int i;
	for(i=0; i<4; i++)
	{
		Error_List[i].speed_rpm_err = MotorData[i].speed_rpm - Set_List[i].speed_rpm;
		Error_List[i].current_err = MotorData[i].real_current - Set_List[i].current;
		//Error_List[i].locatin_err = MotorData[i].angle - Set_List[i].locatin;
	}
}

void Get_MotorData(void)
{
	int i;
	for(i=0; i<4; i++)
	{
		MotorData[i].angle = (uint16_t)(Motor2Stm[i].u8_data[0] << 8 | Motor2Stm[i].u8_data[1]);
		MotorData[i].speed_rpm = (int16_t)(Motor2Stm[i].u8_data[2] << 8 | Motor2Stm[i].u8_data[3]);
		MotorData[i].real_current = (int16_t)(Motor2Stm[i].u8_data[4] << 8 | Motor2Stm[i].u8_data[5]);
		MotorData[i].temperature = (uint8_t) Motor2Stm[i].u8_data[6];
	}
	UsartData[0] = (Motor2Stm[0].u8_data[2]);
	UsartData[1] = (Motor2Stm[0].u8_data[3]);
	USART_SendData(USART1 , UsartData[0]);
	while (!(USE_USARTx->SR & USART_FLAG_TXE));
	USART_SendData(USART1 , UsartData[1]);
	while (!(USE_USARTx->SR & USART_FLAG_TXE));
}

void PID_Handler(void)
{
	int i;
	Get_MotorData();
	Get_Error();
	for(i=0; i<8 ;i+=2)
	{
		int16_t delta;
		delta = 0.1*(PID_calc(Error_List[0].speed_rpm_err,&PID_List[Velocity_Loop+0]));
		if(delta > 0x4000)
			delta = 0x4000;
		else if(delta < -0x4000)
			delta = -0x4000;
		CtrlCurrent.u8_data[i] = delta >> 8;
		CtrlCurrent.u8_data[i+1] = delta;
	}
	
	Write_Database(ControlMotorID);
	cnt++;
}*/
moto_measure_t moto_chassis[4];
int set_spd[4]={0,0,0,0};
int64_t set_loc[4]={0,0,0,0};
pid_t pid_spd[4];
uint16_t set_angle[4];
pid_t pid_spd[4];
pid_t pid_loc[4];
bool isPIDcomplete = false;	
int Mode[4] = {	Speed_Mode,//GRAB
				Speed_Mode,//上层压板
				Location_Mode,//useless
				Location_Mode};//useless

void abs_limit(float *a, float ABS_MAX){
    if(*a > ABS_MAX)
        *a = ABS_MAX;
    if(*a < -ABS_MAX)
        *a = -ABS_MAX;
}

static void pid_param_init(
    pid_t *pid, 
    uint32_t mode,
    uint32_t maxout,
    uint32_t intergral_limit,
    float 	kp, 
    float 	ki, 
    float 	kd)
{
    
    pid->IntegralLimit = intergral_limit;
    pid->MaxOutput = maxout;
    pid->pid_mode = mode;
    
    pid->p = kp;
    pid->i = ki;
    pid->d = kd;
    
}
float PID_DJI(pid_t *pid, float get, float set)
{
	pid->get[NOW] = get;
	pid->set[NOW] = set;
	pid->err[NOW] = set - get;	//set - measure
	
	
	pid->pout = pid->p * (pid->err[NOW] - pid->err[LAST]);
	pid->iout = pid->i * pid->err[NOW];
	pid->dout = pid->d * (pid->err[NOW] - 2*pid->err[LAST] + pid->err[LLAST]);

	abs_limit(&(pid->iout), pid->IntegralLimit);
	pid->delta_u = pid->pout + pid->iout + pid->dout;
	pid->delta_out = pid->last_delta_out + pid->delta_u;
	abs_limit(&(pid->delta_out), pid->MaxOutput);
	pid->last_delta_out = pid->delta_out;	//update last time
	
	
	pid->err[LLAST] = pid->err[LAST];
	pid->err[LAST] = pid->err[NOW];
	pid->get[LLAST] = pid->get[LAST];
	pid->get[LAST] = pid->get[NOW];
	pid->set[LLAST] = pid->set[LAST];
	pid->set[LAST] = pid->set[NOW];
	
	
	return pid->delta_out;	
}

/**
*@bref GET电机上电的相对角度
	*/
void get_total_angle(moto_measure_t *p){
	
	int res1, res2, delta;
	if(p->angle < p->last_angle){			
		res1 = p->angle + 8192 - p->last_angle;	//正转,delta=+
		res2 = p->angle - p->last_angle;				//反转	delta=-
	}else{	//angle > last
		res1 = p->angle - 8192 - p->last_angle ;//反转	delta -
		res2 = p->angle - p->last_angle;				//正转	delta +
	}
	
	if(ABS(res1)<ABS(res2))
		delta = res1;
	else
		delta = res2;

	p->total_angle += delta;
	p->last_angle = p->angle;
}

void PID_struct_init(
    pid_t* pid,
    uint32_t mode,
    uint32_t maxout,
    uint32_t intergral_limit,
    
    float 	kp, 
    float 	ki, 
    float 	kd)
{
    /*init function pointer*/
    pid->f_param_init = pid_param_init;
//    pid->f_pid_reset = pid_reset;
//	pid->f_cal_pid = pid_calc;	
//	pid->f_cal_sp_pid = pid_sp_calc;	//addition
		
    /*init pid param */
    pid->f_param_init(pid, mode, maxout, intergral_limit, kp, ki, kd);
}	
void set_moto_current( s16 iq1, s16 iq2, s16 iq3, s16 iq4)
{
	CtrlCurrent.u8_data[0] = iq1 >> 8;
	CtrlCurrent.u8_data[1] = iq1;
	CtrlCurrent.u8_data[2] = iq2 >> 8;
	CtrlCurrent.u8_data[3] = iq2;
	CtrlCurrent.u8_data[4] = iq3 >> 8;
	CtrlCurrent.u8_data[5] = iq3;
	CtrlCurrent.u8_data[6] = iq4 >> 8;
	CtrlCurrent.u8_data[7] = iq4;
	Write_Database(ControlMotorID);
}	
int16_t current;
void get_moto_chassis(int i)
{
	moto_chassis[i].angle = (uint16_t)(Motor2Stm[i].u8_data[0] << 8 | Motor2Stm[i].u8_data[1]);
	moto_chassis[i].speed_rpm = (int16_t)(Motor2Stm[i].u8_data[2] << 8 | Motor2Stm[i].u8_data[3]);
	moto_chassis[i].real_current = (int16_t)(Motor2Stm[i].u8_data[4] << 8 | Motor2Stm[i].u8_data[5]);
	moto_chassis[i].temperature = (uint8_t) Motor2Stm[i].u8_data[6];
	if(i == 1)
		current = moto_chassis[i].real_current;
}

int error;

void PID_DJI_Handler(int i)
{
	get_moto_chassis(i);
	get_total_angle(&moto_chassis[i]);
	if(Mode[i] == Speed_Mode)
	{	
			PID_DJI(&pid_spd[i], moto_chassis[i].speed_rpm, set_spd[i]);
			if(i == 0)//抓手电机
			{
				error = moto_chassis[i].total_angle - set_loc[i];
				if( abs(error) <= 1000 )
				{	
					Mode[i] = Location_Mode;
					set_spd[i] = 0;
				}
				else
				{
					Mode[i] = Speed_Mode;
				}
			}
	}
	else if(Mode[i] == Location_Mode)
	{
		if(i == 0)
		{
			error = moto_chassis[i].total_angle - set_loc[i];
			if(abs(error) >= 1000) //抓手电机 
			{	
				Mode[i] = Speed_Mode;
			}
		}
			PID_DJI(&pid_loc[i], moto_chassis[i].total_angle, set_loc[i]);
			PID_DJI(&pid_spd[i], moto_chassis[i].speed_rpm, pid_loc[i].delta_out);
	}
	//isPIDcomplete = true;
	set_moto_current(pid_spd[0].delta_out, 
							pid_spd[1].delta_out,
									pid_spd[2].delta_out,
											pid_spd[3].delta_out);
	
}


void PID_01(void){PID_DJI_Handler(0);}
void PID_02(void){PID_DJI_Handler(1);}
void PID_03(void){PID_DJI_Handler(2);}
void PID_04(void){PID_DJI_Handler(3);}

void PID_Init(void)
{
	/*********** 抓手 ***************/
	PID_struct_init(&pid_spd[0], DELTA_PID, 20000, 20000,
								21.5f,	1.75f,	0.0f);  //4 motos angular rate closeloop.  0.80f,	0.03f,	0.0015f	(超调)
	PID_struct_init(&pid_loc[0], DELTA_PID, 9600, 9600,
								0.08f,	0.0f,	0.00f	);  //4 motos angular location closeloop.}  0.08f 0.0f 0.0f
	/*********** 上层抓板 ***************/
	PID_struct_init(&pid_spd[1], DELTA_PID, 8000, 8000,
								21.5f,	1.75f,	0.0f	);  //4 motos angular rate closeloop.  0.80f,	0.03f,	0.0015f	(超调)
	PID_struct_init(&pid_loc[1], DELTA_PID, 9600, 9600,
								0.08f,	0.000f,	0.00f	);  //4 motos angular location closeloop.}
	for(u8 i=0; i<M3508_num; i++)
	{
		set_spd[i] = set_loc[i] = 0;
	}
//	PID_struct_init(&pid_spd[2], DELTA_PID, 20000, 20000,
//								18.0f,	1.2f,	0.02f	);  //4 motos angular rate closeloop.  0.80f,	0.03f,	0.0015f	(超调)
//	PID_struct_init(&pid_loc[2], DELTA_PID, 9600, 9600,
//								0.10f,	0.00f,	0.000f	);  //4 motos angular location closeloop.}
}
