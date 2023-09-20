#ifndef RTE_SLIDESENSOR_H
#define RTE_SLIDESENSOR_H

/* Type Definitions */
typedef enum
{
	SENSOR_POSITION_STEP_0,
	SENSOR_POSITION_STEP_1,
	SENSOR_POSITION_STEP_2,
	SENSOR_POSITION_STEP_3
}IoPositionSensorReadingType;

void SlideSensor_GetPosition (SensorPositionType* position);

#endif