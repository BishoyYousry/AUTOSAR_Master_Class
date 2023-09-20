#ifndef RTE_SEATMANAGER_H
#define RTE_SEATMANAGER_H

/* Type definitions */
typedef enum
{
    MULTI_STATE_BTN_MINUS,
    MULTI_STATE_BTN_PLUS
}MultiStateBtnType;

typedef enum
{
    MOTOR_STEP_MINUS,
    MOTOR_STEP_PLUS
}Step;


/* Runnables Prototypes */
void SeatManager_SetHeight(void);
void SeatManager_SetSlide (void);
void SeatManager_Setincline (void);

#endif