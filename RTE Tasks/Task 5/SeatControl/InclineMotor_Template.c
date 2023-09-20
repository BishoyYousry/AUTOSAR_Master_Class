/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/12/2023 06:30 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepType Step)
{
	/* Server Call Points */
	if(Step == MOTOR_STEP_PLUS)
	{
		Rte_Call_rpIOSetIncline_IOSetForward();
	}
	else if(Step == MOTOR_STEP_MINUS)
	{
		Rte_Call_rpIOSetIncline_IOSetReverse();	
	}
}

