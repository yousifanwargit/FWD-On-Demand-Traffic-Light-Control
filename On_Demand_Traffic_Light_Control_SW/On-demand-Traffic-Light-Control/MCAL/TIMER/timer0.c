/*
 * timer0.c
 *
 * Created: 10/18/2022 4:09:56 PM
 *  Author: 20109
 */

#include "timer0.h" 

uint8 exit_flag = 0; // to skip current delay

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_init(uint8 prescaler, uint8 preload){
	TCNT0 = preload;
	TCCR0 = prescaler;
}
 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_start(int N, uint8 preload){
		// start timer with calculated number of overflows and preload value
		// initialize counter with zero
		int N_counter = 0;
		// loop until counter exceeds number of overflows
		while (N_counter < N)
		{
			// check for exit flag
			if (exit_flag == 1)
			{
				exit_flag = 0;
				return;
			}
			// busy wait until timer overflows
			while (READ_BIT(TIFR, 0) == 0)
			;
			// increment counter
			N_counter++;
			// set timer preload
			TIMER0_setPreload(preload);
			// clear overflow flag by setting to the flag
			SET_BIT(TIFR, 0);
		}
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_setPreload(uint8 preload){
	TCNT0 = preload;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_stop(void){
	TCCR0 = 0;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_reset(void){
	exit_flag = 1;
}

 /**
  * @description 
  * @param  
  * @return
  * @complexity : O(1)
  */
void TIMER0_DelayInMilliSec(int TimeMs){
	// generate timer delay
	// first calculate number of overflows and preload from given time in ms
	int N = (((float)TimeMs / 1000.0) / (256 * (64.0 / 1000000.0)));
	uint8 preload = 256 - (uint8)((float)(((float)TimeMs / 1000.0) / (256 * (1024.0 / 1000000.0))) / (float)N);
	// initialize timer with  prescaler
	TIMER0_init(TIMER_0_PRESCALER_64, preload);
	// start timer with given number of overflows and preload value
	TIMER0_start(N, preload);
}