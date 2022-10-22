/*
 * app.c
 *
 * Created: 10/18/2022 5:23:06 PM
 *  Author: 20109
 */ 

#include "app.h"

pin_config_t buttonPin = {
	.DIRECTION = GPIO_DIRECTION_INPUT,
	.PORT = GPIO_PORTD,
	.PIN = GPIO_PIN2
};

uint8 val = 0;


ISR(INT0_vect){

	TIMER0_DelayInMilliSec(500);
	GPIO_PIN_READ_LOGIC(&buttonPin, &val);
	
	if (val == 0)
	{
		// long press detected
		// nothing here
		// return immediately to continue normal mode
		//return;
	}
	else if (val != 0)
	{
		// there is on long press
		// check for current state (cars)
		uint8 currentMode = TrafficLights_CurrentMode();
		if (currentMode == CARS_MODE_GREEN || currentMode == CARS_MODE_YELLOW)
		{
			
			// if cars state is green or yellow
			/********************************************/
			// turn peds red on
			PedsRedEnable();
			//turn car green off
			CarsGreenDisable();
			// blink yellow for 5 secs
			Cars_Peds_Yellow_Blinking();
			// turn  peds red off and turn peds green on
			PedsRedDisable();
			PedsGreenEnable();
			// turn cars red on and turn cars green off
			CarsRedEnable();
			CarsGreenDisable();
			// wait for 5 secs
			TIMER0_DelayInMilliSec(5000);
			//turn car red off
			CarsRedDisable();
			// blink both yellow leds for 5 secs
			Cars_Peds_Yellow_Blinking();
			/********************************************/
			// turn all leds of
			TurnAllOff();
			// reset timer to escape after return
			TIMER0_reset();
			// reset normal mode to beginning
			ResetNormalMode();
			/********************************************/
		}
		else if (TrafficLights_CurrentMode() == CARS_MODE_RED)
		{
			// if cars state is  red
			/********************************************/
			//turn peds green on
			PedsGreenEnable();
			// turn cars red on and turn cars green off
			CarsRedEnable();
			CarsGreenDisable();
			// wait for 5 secs
			TIMER0_DelayInMilliSec(5000);
			//turn cars red off
			CarsRedDisable();
			// blink both yellow while peds green on
			Cars_Peds_Yellow_Blinking();
			/********************************************/
			// turn off all leds
			TurnAllOff();
			// reset timer to escape after return
			TIMER0_reset();
			// reset normal mode to beginning
			ResetNormalMode();
		}
	}
}

void appInit(void){
	// initialize external interrupt 0
	EXT_INT_init(INT0, FALLING_EDGE);

	// initialize traffic lights module
	All_Lights_init();
}
void appStart(void){
	while(1){
		// enable external interrupt 0
		EXT_INT_enable(INT0);
		// call normal mode function
		LIGHTS_NormalMode();
		
	}
	
}