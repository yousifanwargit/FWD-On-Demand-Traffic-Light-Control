/*
 * button.c
 *
 * Created: 10/9/2022 11:34:13 PM
 *  Author: 20109
 */ 


#include "button.h"

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType button_init(const button_t *_button){
	Std_ReturnType ret = E_OK;
	if (NULL == _button){
		ret = E_NOT_OK;
	}
	else{
		ret = GPIO_PIN_SET_DIRECTION(&(_button->pin), GPIO_DIRECTION_INPUT);
	}
	return ret;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
Std_ReturnType button_read_state(const button_t *_button, uint8 *btn_logic){
	Std_ReturnType ret = E_OK;
	uint8 pin_logic_status = GPIO_LOGIC_LOW;
	if (NULL == _button){
		ret = E_NOT_OK;
	}
	else{
		ret = GPIO_PIN_READ_LOGIC(&(_button->pin), &pin_logic_status);
		if (BUTTON_ACTIVE_HIGH == _button->button_type){
			if (GPIO_LOGIC_HIGH == pin_logic_status){
				*btn_logic = BUTTON_PRESSED;
			}
			else{
				*btn_logic = BUTTON_RELEASED;
			}
		}
		else if (BUTTON_ACTIVE_HIGH == _button->button_type){
			if (GPIO_LOGIC_HIGH == pin_logic_status){
				*btn_logic = BUTTON_RELEASED;
			}
			else{
				*btn_logic = BUTTON_PRESSED;
			}
		}
		else{/* NO THING */}
	}
	return ret;
}
