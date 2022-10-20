/*
 * ext_int.h
 *
 * Created: 10/18/2022 11:31:05 PM
 *  Author: 20109
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

/*=============================INCLUDES========================*/
#include <avr/io.h>
#include "../GPIO/hal_gpio.h"
#include "../../includes.h"
#include "../../bit_mainpulation.h"
#include "../../std_types.h"

/*=============================MACRO DECLARATIONS========================*/

#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3

#define INT_0    0
#define INT_1    1
#define INT_2    2

#define LOW_LEVEL       0
#define ANY_CHANGE      1
#define FALLING_EDGE    2
#define RISING_EDGE     3

/*=============================MACRO FUNCTIONS DECLARATIONS========================*/
#define ISR(INT_VECT)\
void INT_VECT(void) __attribute__((signal, used)); \
void INT_VECT(void)

/*=============================DATA TYPES DECLARATION========================*/


/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/	

void EXT_INT_init(uint8 interupt, uint8 signal_type);
void EXT_INT_enable(uint8 interupt);
void EXT_INT_disble(uint8 interupt);

#endif /* EXT_INT_H_ */