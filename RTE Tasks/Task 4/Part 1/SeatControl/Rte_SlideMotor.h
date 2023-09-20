#ifndef RTE_SLIDEMOTOR_H
#define RTE_SLIDEMOTOR_H

/* Type definitions */
typedef enum
{
    MOTOR_STEP_MINUS,
    MOTOR_STEP_PLUS
}StepMotorStepType;

/* Runnables Prototypes */
void SlideMotor_Move (StepMotorStepType step);

#endif