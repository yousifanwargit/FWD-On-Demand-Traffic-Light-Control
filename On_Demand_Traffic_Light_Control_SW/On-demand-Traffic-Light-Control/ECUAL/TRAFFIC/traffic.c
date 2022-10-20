/*
 * traffic.c
 *
 * Created: 10/20/2022 1:27:56 AM
 *  Author: 20109
 */ 

#include "traffic.h"
led_t cars_red = {
	.pin = GPIO_PIN2,
	.port = GPIO_PORTA,
	.led_status = LED_OFF
};

led_t cars_yellow = {
	.pin = GPIO_PIN1,
	.port = GPIO_PORTA,
	.led_status = LED_OFF
};

led_t cars_green = {
	.pin = GPIO_PIN0,
	.port = GPIO_PORTA,
	.led_status = LED_OFF
};

led_t peds_red = {
	.pin = GPIO_PIN2,
	.port = GPIO_PORTB,
	.led_status = LED_OFF
};

led_t peds_yellow = {
	.pin = GPIO_PIN1,
	.port = GPIO_PORTB,
	.led_status = LED_OFF
};

led_t peds_green = {
	.pin = GPIO_PIN0,
	.port = GPIO_PORTB,
	.led_status = LED_OFF
};

uint8 cars_mode;
uint8 reset_flag;

Std_ReturnType ret;
void All_Lights_init(void){
	ret = led_init(&cars_red);
	ret = led_init(&cars_yellow);
	ret = led_init(&cars_green);
	ret = led_init(&peds_red);
	ret = led_init(&peds_yellow);
	ret = led_init(&peds_green);
}
void LIGHTS_NormalMode(void){
	
	while (reset_flag == 0)
		{
		// turn cars green on
		CarsGreenEnable();
		// wait for 5 secs then check for reset
		TIMER0_DelayInMilliSec(5000);
		if (reset_flag == 1)
		{
			TurnCarsOff();
			reset_flag = 0;
			break;
		}
		// turn cars green off
		CarsGreenDisable();
		// blink cars yellow for 5 secs
		CarsYellowBlinking();
		// check for reset
		if (reset_flag == 1)
		{
			TurnCarsOff();
			reset_flag = 0;
			break;
		}
		// turn cars red on
		CarsRedEnable();
		// wait for 5 secs then check for reset
		TIMER0_DelayInMilliSec(5000);
		if (reset_flag == 1)
		{
			TurnCarsOff();
			reset_flag = 0;
			break;
		}
		// turn cars red off
		CarsRedDisable();
		// blink cars yellow for  secs
		CarsYellowBlinking();
		// check for reset
		if (reset_flag == 1)
		{
			TurnCarsOff();
			reset_flag = 0;
			break;
		}
	}
	}
void CarsGreenEnable(void){
	cars_mode = CARS_MODE_GREEN;
	ret = led_turn_on(&cars_green);
}
void CarsGreenDisable(void){
	ret = led_turn_off(&cars_green);
}
void PedsGreenEnable(void){
	ret = led_turn_on(&peds_green);
}
void PedsGreenDisable(void){
	ret = led_turn_off(&peds_green);
}
void Cars_Peds_Yellow_Blinking(void){
	// define variable to be iterator
	uint8 i;
	// set cars state to yellow state
	cars_mode = CARS_MODE_YELLOW;
	for (i = 1; i <= 10; i++)
	{
		// check for reset
		if (reset_flag == 1)
		{
			TurnCarsOff();
			return;
		}
		// toggle cars yellow
		led_tog(&cars_yellow);
		led_tog(&peds_yellow);
		// delay for half secs
		TIMER0_DelayInMilliSec(500);
	}
	// turn of cars yellow
	led_turn_off(&cars_yellow);
	led_turn_off(&peds_yellow);
}
void CarsYellowBlinking(void){
	// define variable to be iterator
	 uint8 i;
	// set cars state to yellow state
	cars_mode = CARS_MODE_YELLOW;
	for (i = 1; i <= 10; i++)
	{
		// check for reset
		if (reset_flag == 1)
		{
			TurnCarsOff();
			return;
		}
		// toggle cars yellow
		led_tog(&cars_yellow);
		// delay for half secs
		TIMER0_DelayInMilliSec(500);
	}
	// turn of cars yellow
	led_turn_off(&cars_yellow);
}
void CarsRedEnable(void){
	cars_mode = CARS_MODE_RED;
	ret = led_turn_on(&cars_red);
}
void CarsRedDisable(void){
	ret = led_turn_off(&cars_red);
}
void PedsRedEnable(void){
	ret = led_turn_on(&peds_red);
}
void PedsRedDisable(void){
	ret = led_turn_off(&peds_red);
}
uint8 TrafficLights_CurrentMode(void){
	return cars_mode;
}
void TurnCarsOff(void){
	ret = led_turn_off(&cars_red);
	ret = led_turn_off(&cars_yellow);
	ret = led_turn_off(&cars_green);
}
void TurnAllOff(void){
	ret = led_turn_off(&cars_red);
	ret = led_turn_off(&cars_yellow);
	ret = led_turn_off(&cars_green);
	ret = led_turn_off(&peds_red);
	ret = led_turn_off(&peds_yellow);
	ret = led_turn_off(&peds_green);
}
void ResetNormalMode(void){
	reset_flag = 1;
}