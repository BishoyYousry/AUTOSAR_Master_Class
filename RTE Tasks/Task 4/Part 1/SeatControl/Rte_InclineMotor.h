#ifndef RTE_INCLINEMOTOR_H
#define RTE_INCLINEMOTOR_H

/* Type definitions */
typedef enum
{
    MOTOR_STEP_MINUS,
    MOTOR_STEP_PLUS
}StepMotorStepType;

/* Runnables Prototypes */
void InclineMotor_Move (StepMotorStepType step);

#endif