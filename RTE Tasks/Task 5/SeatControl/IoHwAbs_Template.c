/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/12/2023 06:30 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/* For reading from position sensors */
#include "Adc.h"

/* For reading from weight sensor */
#include "Spi.h"

/* For driving motors (Height, Slide, Incline) */
#include "Dio.h"

/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* Position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorsReadings);
	if(status == E_OK)
	{
		Position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorsReadings[0]
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* Position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorsReadings);
	if(status == E_OK)
	{
		Position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorsReadings[1]
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* Position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorsReadings);
	if(status == E_OK)
	{
		Position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorsReadings[2]
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* Weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);
	if(status == E_OK)
	{
		Weight = (IoWeightSensorReadingType)spiData;
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	/* Write STD_HIGH to move forward */
	Dio_WriteChannel(DioConfig_DioChannel_HeightMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	/* Write STD_HIGH to move forward */
	Dio_WriteChannel(DioConfig_DioChannel_InclineMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	/* Write STD_HIGH to move forward */
	Dio_WriteChannel(DioConfig_DioChannel_SlideMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	/* Write STD_LOW to move backward */
	Dio_WriteChannel(DioConfig_DioChannel_HeightMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	/* Write STD_LOW to move backward */
	Dio_WriteChannel(DioConfig_DioChannel_InclineMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	/* Write STD_LOW to move backward */
	Dio_WriteChannel(DioConfig_DioChannel_SlideMotorCh, STD_LOW);
}

