/*
 * hal_gpio.h
 *
 * Created: 10/9/2022 11:33:34 PM
 *  Author: 20109
 */ 


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_


/*=============================INCLUDES========================*/
#include <avr/io.h>
#include "../../includes.h"
#include "../../bit_mainpulation.h"
#include "../../std_types.h"
/*=============================MACRO FUNCTIONS DECLARATIONS========================*/
/*=============================MACRO DECLARATIONS========================*/

/* This macro declarations for port configuration */
#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2
#define GPIO_PORTD     3

/* This macro declarations for pin configuration */
#define GPIO_PIN0     0
#define GPIO_PIN1     1
#define GPIO_PIN2     2
#define GPIO_PIN3     3
#define GPIO_PIN4     4
#define GPIO_PIN5     5
#define GPIO_PIN6     6
#define GPIO_PIN7     7

/* This macro declarations for pin directions INPUT/OUTPUT */
#define GPIO_DIRECTION_INPUT     0
#define GPIO_DIRECTION_OUTPUT    1

/* This macro declarations for pin logic LOW/HIGH */
#define GPIO_LOGIC_LOW     0
#define GPIO_LOGIC_HIGH    1


#define GPIO_PIN_MAX_NUMBER        8
#define GPIO_PORT_MAX_NUMBER       4


/*=============================DATA TYPES DECLARATION========================*/

typedef struct{
	
	uint8 DIRECTION :1;
	uint8 LOGIC :1;
	uint8 PORT :2;
	uint8 PIN :3;
	uint8 reserved :1;
}pin_config_t;

typedef struct{
	
	uint8 DIRECTION ;
	uint8 LOGIC ;
	uint8 PORT :2 ;
	uint8 reserved :6;

}port_config_t;
/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/


Std_ReturnType GPIO_PIN_SET_DIRECTION(const pin_config_t *_pin, uint8 direction_config);
Std_ReturnType GPIO_PIN_WRITE_LOGIC(const pin_config_t *_pin, uint8 logic_config);
Std_ReturnType GPIO_PIN_READ_LOGIC(const pin_config_t *_pin, uint8 *pin_status);
Std_ReturnType GPIO_PIN_TOGGLE(const pin_config_t *_pin);
Std_ReturnType GPIO_PIN_INIT(const pin_config_t *_pin);

Std_ReturnType GPIO_PORT_SET_DIRECTION(const port_config_t *_port, uint8 direction_config);
Std_ReturnType GPIO_PORT_WRITE_LOGIC(const port_config_t *_port, uint8 logic_config);
Std_ReturnType GPIO_PORT_READ_LOGIC(const port_config_t *_port, uint8 *port_status);
Std_ReturnType GPIO_PORT_TOGGLE(const port_config_t *_port);





#endif /* HAL_GPIO_H_ */