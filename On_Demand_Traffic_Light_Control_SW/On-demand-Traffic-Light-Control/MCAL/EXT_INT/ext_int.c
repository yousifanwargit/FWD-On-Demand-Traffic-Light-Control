/*
 * ext_int.c
 *
 * Created: 10/18/2022 11:30:07 PM
 *  Author: 20109
 */ 


#include "ext_int.h"

void EXT_INT_init(uint8 interupt, uint8 signal_type){
	
	SET_BIT(SREG, 7);
	//select and enable chosen interrupt with chosen sense control
	//and initialize its corresponding pin
	switch (interupt)
	{
		case INT0: ;
			pin_config_t pin_int_0 = {
			.DIRECTION = GPIO_DIRECTION_INPUT,
			.PIN = GPIO_PIN2,
			.PORT = GPIO_PORTD,
			.LOGIC = GPIO_LOGIC_HIGH
			};
		if (signal_type == FALLING_EDGE)
		{
			pin_int_0.LOGIC = GPIO_LOGIC_HIGH;
		}
		GPIO_PIN_INIT(&pin_int_0);
		MCUCR = signal_type;
		SET_BIT(GICR, 6);
		break;
		case INT1: ;
			pin_config_t pin_int_1 = {
			.DIRECTION = GPIO_DIRECTION_INPUT,
			.PIN = GPIO_PIN3,
			.PORT = GPIO_PORTD,
			.LOGIC = GPIO_LOGIC_HIGH
			};
		if (signal_type == FALLING_EDGE)
		{
			pin_int_1.LOGIC = GPIO_LOGIC_HIGH;
		}
		GPIO_PIN_INIT(&pin_int_1);
		MCUCR = (signal_type << 2);
		SET_BIT(GICR, 7);
		break;
		case INT2: ;
			pin_config_t pin_int_2 = {
			.DIRECTION = GPIO_DIRECTION_INPUT,
			.PIN = GPIO_PIN2,
			.PORT = GPIO_PORTB,
			.LOGIC = GPIO_LOGIC_HIGH
			};
		GPIO_PIN_INIT(&pin_int_2);
		MCUCSR |= ((signal_type & 0x01) << 6);
		SET_BIT(GICR, 8);
		break;
	}
}
void EXT_INT_enable(uint8 interupt){
	if (INT_0 == interupt){
		SET_BIT(SREG, 7);
		SET_BIT(GICR, 6);
	} 
	else if (INT_1 == interupt){
		SET_BIT(SREG, 7);
		SET_BIT(GICR, 8);
	}
	else if(INT_2 == interupt){
		SET_BIT(SREG, 7);
		SET_BIT(GICR, 9);
	}
	else{
		/*NOTHING*/
	}
	
}
void EXT_INT_disble(uint8 interupt){
	if (INT_0 == interupt){
		CLEAR_BIT(GICR, 6);
	}
	else if (INT_1 == interupt){
		CLEAR_BIT(GICR, 7);
	}
	else if(INT_2 == interupt){
		CLEAR_BIT(GICR, 8);
	}
	else{
		/*NOTHING*/
	}
}