/*
 * app.h
 *
 * Created: 10/18/2022 5:22:55 PM
 *  Author: 20109
 */ 


#ifndef APP_H_
#define APP_H_

/*=============================INCLUDES========================*/
#include <avr/io.h>
#include "../includes.h"
#include "../bit_mainpulation.h"
#include "../std_types.h"
#include "../MCAL/EXT_INT/ext_int.h"
#include "../MCAL/GPIO/hal_gpio.h"
#include "../MCAL/TIMER/timer0.h"
#include "../ECUAL/TRAFFIC/traffic.h"
/*=============================MACRO DECLARATIONS========================*/

/*=============================MACRO FUNCTIONS DECLARATIONS========================*/


/*=============================DATA TYPES DECLARATION========================*/


/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/

void appInit(void);
void appStart(void);


#endif /* APP_H_ */