/**
 *
 * \file WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/11/2023 10:51 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_WeightSensor.h"


/**
 *
 * Runnable WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_GetWeight
 *
 */

void WeightSensor_GetWeight (SensorWeightType* weight)
{
	Std_ReturnType status;
	Adc_ReadGroup(Group, &DataBufferPtr);
}

