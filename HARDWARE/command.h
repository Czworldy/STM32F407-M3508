#ifndef _COMMAND_H
#define _COMMAND_H

#include "sys.h"
#include "stdbool.h"
void GRAB_Handler(void);
void COVER_Handler(void);

void W_GAME_PROCESS_ID_record(void);
void S_CONTINUE_FLAG_ID_record(void);
void W_SET_GRAB_ID_record(void);
void W_SET_COVER_ID_record(void);
void W_SET_ESCON_ID_record(void);
void W_IO_TEST_ID_record(void);
void W_MOTOR_TEST_ID_record(void);
void W_HANDLE_record(void);
void W_BRAKE_ID_record(void);
void W_LENGTH_X_ID_record(void);
void W_LENGTH_Y_ID_record(void);
void S_LENGTH_X_ID_record(void);
void S_LENGTH_Y_ID_record(void);
void S_PASS_FLAG_ID_record(void);

extern bool isSDcardExistence;
extern bool isCovermove;
#endif
