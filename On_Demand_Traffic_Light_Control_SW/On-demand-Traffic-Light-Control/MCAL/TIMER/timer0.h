/*
 * timer0.h
 *
 * Created: 10/18/2022 4:10:08 PM
 *  Author: 20109
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


/*=============================INCLUDES========================*/
#include <avr/io.h>
#include "../../includes.h"
#include "../../bit_mainpulation.h"
#include "../../std_types.h"
/*=============================MACRO DECLARATIONS========================*/
#define TIMER_0_NO_CLK_SOURCE    0
#define TIMER_0_PRESCALER_1      1
#define TIMER_0_PRESCALER_8      2
#define TIMER_0_PRESCALER_64     3
#define TIMER_0_PRESCALER_256    4
#define TIMER_0_PRESCALER_1024   5
/*=============================MACRO FUNCTIONS DECLARATIONS========================*/


/*=============================DATA TYPES DECLARATION========================*/


/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/

void TIMER0_init(uint8 prescaler, uint8 preload);
void TIMER0_start(int N, uint8 preload);
void TIMER0_setPreload(uint8 preload);
void TIMER0_stop(void);
void TIMER0_reset(void);
void TIMER0_DelayInMilliSec(int TimeMs);


#endif /* TIMER0_H_ */