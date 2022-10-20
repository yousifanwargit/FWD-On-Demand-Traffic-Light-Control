/*
 * traffic.h
 *
 * Created: 10/20/2022 1:28:08 AM
 *  Author: 20109
 */ 


#ifndef TRAFFIC_H_
#define TRAFFIC_H_

/*=============================INCLUDES========================*/
#include "../../includes.h"
#include "../../bit_mainpulation.h"
#include "../../std_types.h"
#include "../LED/led.h"
#include "../../MCAL/EXT_INT/ext_int.h"
#include "../../MCAL/GPIO/hal_gpio.h"
#include "../../MCAL/TIMER/timer0.h"
/*=============================MACRO FUNCTIONS DECLARATIONS========================*/

/*=============================MACRO DECLARATIONS========================*/

#define CARS_MODE_RED      0
#define CARS_MODE_YELLOW   1
#define CARS_MODE_GREEN    2


/*=============================DATA TYPES DECLARATION========================*/


/*=============================SOFTWARE INTERFACES DECLARATIONS========================*/

void All_Lights_init(void);
void LIGHTS_NormalMode(void);
void CarsGreenEnable(void);
void CarsGreenDisable(void);
void PedsGreenEnable(void);
void PedsGreenDisable(void);
void Cars_Peds_Yellow_Blinking(void);
void CarsYellowBlinking(void);
void CarsRedEnable(void);
void CarsRedDisable(void);
void PedsRedEnable(void);
void PedsRedDisable(void);
uint8 TrafficLights_CurrentMode(void);
void TurnCarsOff(void);
void TurnAllOff(void);
void ResetNormalMode(void);

#endif /* TRAFFIC_H_ */