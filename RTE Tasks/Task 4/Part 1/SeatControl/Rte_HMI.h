#ifndef RTE_HMI_H
#define RTE_HMI_H

#define HEIGHT_INIT                 0
#define INCLINE_INIT                0
#define SLIDE_INIT                  0
#define RTE_E_MAX_AGE_EXCEEDED      10


typedef enum
{
    MULTI_STATE_BTN_INIT,
    MULTI_STATE_BTN_MINUS,
    MULTI_STATE_BTN_PLUS
}MultiStateBtnType;


typedef uint8    Std_ReturnType;
typedef char                uint8;

/* Runnables Prototypes */
void HMI_MainFunction (void);

#endif