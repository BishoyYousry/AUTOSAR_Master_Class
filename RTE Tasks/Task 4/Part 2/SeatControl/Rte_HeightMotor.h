#ifndef RTE_HEIGHTMOTOR_H
#define RTE_HEIGHTMOTOR_H

/* Type definitions */
typedef enum
{
    MOTOR_STEP_MINUS,
    MOTOR_STEP_PLUS
}StepMotorStepType;

/* Runnables Prototypes */
void HeightMotor_Move (StepMotorStepType step);

#endif