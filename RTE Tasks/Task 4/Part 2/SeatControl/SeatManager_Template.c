/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/11/2023 10:51 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */


static bool IsMotorAdjustNeeded(SensorWeightType weight, SensorPositionType position, StepMotorStepType step)
{
	bool adjustMotor = false;
	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
			if(weight > 60)
			{
				step = MOTOR_STEP_PLUS;
				adjustMotor = true;
			}
			break;
		case SENSOR_POSITION_STEP_1:
			if(weight > 80)
			{
				step = MOTOR_STEP_PLUS;
				adjustMotor = true;
			}
			else if(weight <= 80 && weight >= 60)
			{
				/* Position is ok */
			}
			else
			{
				step = MOTOR_STEP_MINUS;
				adjustMotor = true;
			}
				break;
		case SENSOR_POSITION_STEP_2:
			if(weight > 100)
			{
				step = MOTOR_STEP_PLUS;
				adjustMotor = true;
			}
			else if(weight <= 100 && weight >= 80)
			{
				/* Position is ok */
			}
			else
			{
				step = MOTOR_STEP_MINUS;
				adjustMotor = true;
			}
			break;
		case SENSOR_POSITION_STEP_3:
			if(weight < 100)
			{
				step = MOTOR_STEP_MINUS;
				adjustMotor = true;
			}
			break;
		default:
			break;
		}
	}
	return adjustMotor;
}


void SeatManager_AutoHeight (void)
{
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	Rte_Call_rpHeightSensor_GetPosition(&position);
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	adjustMotor = IsMotorAdjustNeeded(weight, position, &step);
	if(adjustMotor)
	{
		Rte_Call_rpHeightMotor_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	bool adjustMotor;
	
	/* Server Call Points */
	Rte_Call_rpInclineSensor_GetPosition(&position);
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	adjustMotor = IsMotorAdjustNeeded(weight, position, &step);
	if(adjustMotor)
	{
		Rte_Call_rpInclineMotor_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	bool adjustMotor;
	
	/* Server Call Points */
	Rte_Call_rpSlideSensor_GetPosition(&position);
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	adjustMotor = IsMotorAdjustNeeded(weight, position, &step);
	if(adjustMotor)
	{
		Rte_Call_rpSlideMotor_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Server Call Points */
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Server Call Points */
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


/**
 *
 * Runnable SeatManager_Setincline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_Setincline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Server Call Points */
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpInclideMotor_Move(MOTOR_STEP_PLUS);
	}
	
}

