/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2023 06:43 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	/* Declare three receive state variables */
	Std_ReturnType HeightRcStatus;
	Std_ReturnType InclineRcStatus;
	Std_ReturnType SlideRcStatus;

	/* received data element */
	uint8 Height;
	uint8 Incline;
	uint8 Slide;

	boolean IsUpdated;

	/* Data Send Points */
	Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	
	/* Data Receive Points */
	heightRcStatus = Rte_Read_rpSeatCtrlData_Height(&Height);
	inclineRcStatus = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	slideRcStatus = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	/* SW logic of the height */
	if(Height == 0 || heightRcStatus == RTE_E_MAX_AGE_EXCEEDED || !Rte_IsUpdated(Height))
	{
		HeightBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Height == 1)
	{
		HeightBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Height == 2)
	{
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	}

	/* SW logic of the incline */
	if(Incline == 0 || inclineRcStatus == RTE_E_MAX_AGE_EXCEEDED || !Rte_IsUpdated(Incline))
	{
		InclineBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Incline == 1)
	{
		InclineBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Incline == 2)
	{
		InclineBtnState = MULTI_STATE_BTN_PLUS;
	}

	/* SW logic of the slide */
	if(Slide == 0 || slideRcStatus == RTE_E_MAX_AGE_EXCEEDED || !Rte_IsUpdated(Slide))
	{
		SlideBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Slide == 1)
	{
		SlideBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Slide == 2)
	{
		SlideBtnState = MULTI_STATE_BTN_PLUS;
	}
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	/* Mode Switch Points */
	if(SeatModeBtn == SEAT_MODE_BNT_MANUAL)
	{
		SeatCtrlMode = SEAT_MODE_BNT_MANUAL;
	}
	else if(SeatModeBtn == SEAT_MODE_BNT_AUTO)
	{
		SeatCtrlMode = SEAT_MODE_BNT_AUTO;
	}
	else
	{
		/* Keep init */
	}
	Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
}

