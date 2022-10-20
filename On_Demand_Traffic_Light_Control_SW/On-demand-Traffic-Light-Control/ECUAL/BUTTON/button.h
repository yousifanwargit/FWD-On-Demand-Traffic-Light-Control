/*
 * button.h
 *
 * Created: 10/9/2022 11:34:27 PM
 *  Author: 20109
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


/*=============================INCLUDES========================*/
#include "../../MCAL/GPIO/hal_gpio.h"
/*=============================MACRO FUNCTIONS DECLARATIONS========================*/
/*=============================MACRO DECLARATIONS========================*/
#define BUTTON_PRESSED   (uint8)0x01
#define BUTTON_RELEASED  (uint8)0x00

#define BUTTON_ACTIVE_HIGH    (uint8)0x01
#define BUTTON_ACTIVE_LOW     (uint8)0x00

/*=============================DATA TYPES DECLARATION========================*/

typedef struct {
	pin_config_t pin;
	uint8 button_state;
	uint8 button_type;
}button_t;

/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/

Std_ReturnType button_init(const button_t *_button);
Std_ReturnType button_read_state(const button_t *_button, uint8 *btn_logic);




#endif /* BUTTON_H_ */