/*
 * On-demand-Traffic-Light-Control.c
 *
 * Created: 10/9/2022 11:17:16 PM
 * Author : 20109
 */ 

#include <avr/io.h>
#include "ECUAL/LED/led.h"
#include "MCAL/TIMER/timer0.h"
#include "MCAL/EXT_INT/ext_int.h"
#include "APP/app.h"

led_t led0 = {
	.pin = GPIO_PIN0,
	.port = GPIO_PORTA,
	.led_status = LED_OFF
};
extern uint8 val1;
extern uint8 val2;
extern pin_config_t buttonPin;
Std_ReturnType ret;
int main(void)
{
			//ret = led_init(&led0);
			//EXT_INT_enable(INT_0);
			//All_Lights_init();
			appInit();
    /* Replace with your application code */
    while (1) 
    {
		//EXT_INT_init(INT_0, FALLING_EDGE);
		//ret = led_turn_on(&led0);
		//ret = led_turn_on(&led0);
		//TIMER0_DelayInMilliSec(1000);
		//ret = led_turn_off(&led0);
		//TIMER0_DelayInMilliSec(1000);
		//LIGHTS_NormalMode();
		
		ret = GPIO_PIN_READ_LOGIC(&buttonPin, &val1);	
		appStart();

    }
}
/*
ISR(INT0_vect){
	ret = led_tog(&led0);
	TIMER0_DelayInMilliSec(500);

}*/

