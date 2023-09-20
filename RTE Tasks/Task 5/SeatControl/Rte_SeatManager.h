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
}StepMotorStepType;

typedef enum
{
	SENSOR_POSITION_STEP_0,
	SENSOR_POSITION_STEP_1,
	SENSOR_POSITION_STEP_2,
	SENSOR_POSITION_STEP_3
}SensorPositionType;

typedef uint8 SensorWeightType;


/* Runnables Prototypes */
void SeatManager_SetHeight(void);
void SeatManager_SetSlide (void);
void SeatManager_Setincline (void);
void SeatManager_AutoHeight (void);
void SeatManager_AutoIncline (void);
void SeatManager_AutoSlide (void);
static bool IsMotorAdjustNeeded(SensorWeightType, SensorPositionType, StepMotorStepType);

#endif