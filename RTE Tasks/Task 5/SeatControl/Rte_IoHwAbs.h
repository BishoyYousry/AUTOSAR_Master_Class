#ifndef RTE_IOHWABS_H
#define RTE_IOHWABS_H

/* Runnables Prototypes */
void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight);
void IoHwAbs_ECUSetForward_Height (void);
void IoHwAbs_ECUSetForward_Incline (void);
void IoHwAbs_ECUSetForward_Slide (void);
void IoHwAbs_ECUSetReverse_Height (void);
void IoHwAbs_ECUSetReverse_Incline (void);
void IoHwAbs_ECUSetReverse_Slide (void);

#endif