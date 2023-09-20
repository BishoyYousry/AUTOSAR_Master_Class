/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2023 06:43 PM
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
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */
 
 
 static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType* Step)
{
	boolean adjustMotor = FALSE;
	switch(Position)
	{
		case SENSOR_POSITION_STEP_0:
			if(Weight > 60)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			break;
		case SENSOR_POSITION_STEP_1:
			if(Weight > 80)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 80 && Weight >= 60)
			{
				/* Position is ok */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
				break;
		case SENSOR_POSITION_STEP_2:
			if(Weight > 100)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 100 && Weight >= 80)
			{
				/* Position is ok */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
		case SENSOR_POSITION_STEP_3:
			if(Weight < 100)
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
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
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	/* Server Call Points */
	(void)Rte_Call_rpHeightSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */

void SeatManager_AutoIncline (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;
	
	/* Server Call Points */
	(void)Rte_Call_rpInclineSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpInclineMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */

void SeatManager_AutoSlide (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;
	
	/* Server Call Points */
	(void)Rte_Call_rpSlideSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpSlideMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_SetHeight (void)
{
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	(void)Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Server Call Points */
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_SetSlide (void)
{
	MultiStateBtnType SlideBtnState;

	/* Data Receive Points */
	(void)Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Server Call Points */
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


/**
 *
 * Runnable SeatManager_Setincline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_Setincline (void)
{
	MultiStateBtnType InclineBtnState;

	/* Data Receive Points */
	(void)Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Server Call Points */
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		(void)Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		(void)Rte_Call_rpInclideMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


