/*
 * hal_gpio.c
 *
 * Created: 10/9/2022 11:33:51 PM
 *  Author: 20109
 */ 


#include "hal_gpio.h"

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PIN_SET_DIRECTION(const pin_config_t *_pin, uint8 direction_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin) || (GPIO_PIN_MAX_NUMBER-1 < _pin->PIN) || (GPIO_PORT_MAX_NUMBER-1 < _pin->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_pin->PORT){
			case GPIO_PORTA :	if(GPIO_DIRECTION_OUTPUT == direction_config){SET_BIT(DDRA, _pin->PIN);} else{CLEAR_BIT(DDRA, _pin->PIN);} break;
			case GPIO_PORTB :	if(GPIO_DIRECTION_OUTPUT == direction_config){SET_BIT(DDRB, _pin->PIN);} else{CLEAR_BIT(DDRB, _pin->PIN);} break;
			case GPIO_PORTC :	if(GPIO_DIRECTION_OUTPUT == direction_config){SET_BIT(DDRC, _pin->PIN);} else{CLEAR_BIT(DDRC, _pin->PIN);} break;
			case GPIO_PORTD :	if(GPIO_DIRECTION_OUTPUT == direction_config){SET_BIT(DDRD, _pin->PIN);} else{CLEAR_BIT(DDRD, _pin->PIN);} break;
			default:	      	ret = E_NOT_OK;
		}
		
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PIN_WRITE_LOGIC(const pin_config_t *_pin, uint8 logic_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin) || (GPIO_PIN_MAX_NUMBER-1 < _pin->PIN) || (GPIO_PORT_MAX_NUMBER-1 < _pin->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_pin->PORT){
			case GPIO_PORTA :	if(GPIO_LOGIC_HIGH == logic_config){SET_BIT(PORTA, _pin->PIN);} else{CLEAR_BIT(PORTA, _pin->PIN);} break;
			case GPIO_PORTB :	if(GPIO_LOGIC_HIGH == logic_config){SET_BIT(PORTB, _pin->PIN);} else{CLEAR_BIT(PORTB, _pin->PIN);} break;
			case GPIO_PORTC :	if(GPIO_LOGIC_HIGH == logic_config){SET_BIT(PORTC, _pin->PIN);} else{CLEAR_BIT(PORTC, _pin->PIN);} break;
			case GPIO_PORTD :	if(GPIO_LOGIC_HIGH == logic_config){SET_BIT(PORTD, _pin->PIN);} else{CLEAR_BIT(PORTD, _pin->PIN);} break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PIN_READ_LOGIC(const pin_config_t *_pin, uint8 *pin_status){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin) || (NULL == pin_status) || (GPIO_PIN_MAX_NUMBER-1 < _pin->PIN) || (GPIO_PORT_MAX_NUMBER-1 < _pin->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_pin->PORT){
			case GPIO_PORTA : *pin_status = READ_BIT(PINA, _pin->PIN);	 break;
			case GPIO_PORTB : *pin_status = READ_BIT(PINB, _pin->PIN);	 break;
			case GPIO_PORTC : *pin_status = READ_BIT(PINC, _pin->PIN);	 break;
			case GPIO_PORTD : *pin_status = READ_BIT(PIND, _pin->PIN);	 break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PIN_TOGGLE(const pin_config_t *_pin){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin) || (GPIO_PIN_MAX_NUMBER-1 < _pin->PIN) || (GPIO_PORT_MAX_NUMBER-1 < _pin->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_pin->PORT){
			case GPIO_PORTA : TOG_BIT(PORTA, _pin->PIN); break;
			case GPIO_PORTB : TOG_BIT(PORTB, _pin->PIN); break;
			case GPIO_PORTC : TOG_BIT(PORTC, _pin->PIN); break;
			case GPIO_PORTD : TOG_BIT(PORTD, _pin->PIN); break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PIN_INIT(const pin_config_t *_pin){
	Std_ReturnType ret = E_OK;
	if((NULL == _pin) || (GPIO_PIN_MAX_NUMBER-1 < _pin->PIN) || (GPIO_PORT_MAX_NUMBER-1 < _pin->PORT)){
		ret = E_NOT_OK;
	}
	else{
		ret = GPIO_PIN_SET_DIRECTION(_pin, GPIO_DIRECTION_OUTPUT);
		ret = GPIO_PIN_WRITE_LOGIC(_pin, _pin->LOGIC);
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PORT_SET_DIRECTION(const port_config_t *_port, uint8 direction_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _port) || (GPIO_PORT_MAX_NUMBER-1 < _port->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_port->PORT){
			case GPIO_PORTA : DDRA = direction_config; break;
			case GPIO_PORTB : DDRB = direction_config; break;
			case GPIO_PORTC : DDRC = direction_config; break;
			case GPIO_PORTD : DDRD = direction_config; break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PORT_WRITE_LOGIC(const port_config_t *_port, uint8 logic_config){
	Std_ReturnType ret = E_OK;
	if((NULL == _port) || (GPIO_PORT_MAX_NUMBER-1 < _port->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_port->PORT){
			case GPIO_PORTA : PORTA = logic_config; break;
			case GPIO_PORTB : PORTB = logic_config; break;
			case GPIO_PORTC : PORTC = logic_config; break;
			case GPIO_PORTD : PORTD = logic_config; break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PORT_READ_LOGIC(const port_config_t *_port, uint8 *port_status){
	Std_ReturnType ret = E_OK;
	if((NULL == _port) || (NULL == port_status) || (GPIO_PORT_MAX_NUMBER-1 < _port->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_port->PORT){
			case GPIO_PORTA : *port_status = PORTA; break;
			case GPIO_PORTB : *port_status = PORTB; break;
			case GPIO_PORTC : *port_status = PORTC; break;
			case GPIO_PORTD : *port_status = PORTD; break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType GPIO_PORT_TOGGLE(const port_config_t *_port){
	Std_ReturnType ret = E_OK;
	if((NULL == _port) || (GPIO_PORT_MAX_NUMBER-1 < _port->PORT)){
		ret = E_NOT_OK;
	}
	else{
		switch(_port->PORT){
			case GPIO_PORTA : PORTA ^= PORT_MASK; break;
			case GPIO_PORTB : PORTB ^= PORT_MASK; break;
			case GPIO_PORTC : PORTC ^= PORT_MASK; break;
			case GPIO_PORTD : PORTD ^= PORT_MASK; break;
			default:	      	ret = E_NOT_OK;
		}
	}
	return ret;
}
