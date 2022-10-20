/*
 * led.c
 *
 * Created: 10/9/2022 11:34:53 PM
 *  Author: 20109
 */ 


#include "led.h"

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType led_init(const led_t *_led){
	Std_ReturnType ret = E_OK;
	if (NULL == _led){
		ret = E_NOT_OK;
	}
	else{
		pin_config_t pin = {
			.DIRECTION = GPIO_DIRECTION_OUTPUT,
			.LOGIC = GPIO_LOGIC_LOW,
			.PIN = _led->pin,
			.PORT = _led->port
		};
		ret = GPIO_PIN_INIT(&pin);
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType led_turn_on(const led_t *_led){
	Std_ReturnType ret = E_OK;
	if (NULL == _led){
		ret = E_NOT_OK;
	}
	else{
		pin_config_t pin = {
			.DIRECTION = GPIO_DIRECTION_OUTPUT,
			.LOGIC = GPIO_LOGIC_LOW,
			.PIN = _led->pin,
			.PORT = _led->port
		};
		ret = GPIO_PIN_WRITE_LOGIC(&pin, GPIO_LOGIC_HIGH);
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType led_turn_off(const led_t *_led){
	Std_ReturnType ret = E_OK;
	if (NULL == _led){
		ret = E_NOT_OK;
	}
	else{
		pin_config_t pin = {
			.DIRECTION = GPIO_DIRECTION_OUTPUT,
			.LOGIC = GPIO_LOGIC_LOW,
			.PIN = _led->pin,
			.PORT = _led->port
		};
		ret = GPIO_PIN_WRITE_LOGIC(&pin, GPIO_LOGIC_LOW);
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType led_tog(const led_t *_led){
	Std_ReturnType ret = E_OK;
	if (NULL == _led){
		ret = E_NOT_OK;
	}
	else{
		pin_config_t pin = {
			.DIRECTION = GPIO_DIRECTION_OUTPUT,
			.LOGIC = GPIO_LOGIC_LOW,
			.PIN = _led->pin,
			.PORT = _led->port
		};
		ret = GPIO_PIN_TOGGLE(&pin);
	}
	return ret;
}
