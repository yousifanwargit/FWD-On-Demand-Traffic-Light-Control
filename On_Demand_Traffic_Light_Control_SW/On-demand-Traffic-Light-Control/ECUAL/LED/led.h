/*
 * led.h
 *
 * Created: 10/9/2022 11:34:40 PM
 *  Author: 20109
 */ 


#ifndef LED_H_
#define LED_H_


/*=============================INCLUDES========================*/
#include "../../MCAL/GPIO/hal_gpio.h"
/*=============================MACRO FUNCTIONS DECLARATIONS========================*/
/*=============================MACRO DECLARATIONS========================*/
#define LED_ON   1
#define LED_OFF   0

/*=============================DATA TYPES DECLARATION========================*/

typedef struct{
	uint8 pin:3;
	uint8 port:2;
	uint8 led_status:1;
	uint8 reserved:2;
}led_t;
/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/

Std_ReturnType led_init(const led_t *_led);
Std_ReturnType led_turn_on(const led_t *_led);
Std_ReturnType led_turn_off(const led_t *_led);
Std_ReturnType led_tog(const led_t *_led);





#endif /* LED_H_ */