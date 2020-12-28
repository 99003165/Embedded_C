/*
 * STM32FXX_GPIO_DRIVER.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003165
 */

#include "STM32F4XX.h"

#ifndef INC_STM32FXX_GPIO_DRIVER_H_
#define INC_STM32FXX_GPIO_DRIVER_H_

/*GPIO Pin configuration*/

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

} GPIO_PIN_CONFIG_t;


/* GPIO Handle structure  */

typedef struct
{
	GPIO_REG_DEF_t *pGPIOx;
	GPIO_PIN_CONFIG_t PIN_CONFIG;

} GPIO_Handle_t;


#define GPIO_PinNumber_0		0
#define GPIO_PinNumber_1		1
#define GPIO_PinNumber_2		2
#define GPIO_PinNumber_3		3
#define GPIO_PinNumber_4		4
#define GPIO_PinNumber_5		5
#define GPIO_PinNumber_6		6
#define GPIO_PinNumber_7		7
#define GPIO_PinNumber_8		8
#define GPIO_PinNumber_9		9
#define GPIO_PinNumber_10		10
#define GPIO_PinNumber_11		11
#define GPIO_PinNumber_12		12
#define GPIO_PinNumber_13		13
#define GPIO_PinNumber_14		14
#define GPIO_PinNumber_15		15


#define GPIO_PinMode_IN			0
#define GPIO_PinMode_OUT		1
#define GPIO_PinMode_ALTFN 		2
#define GPIO_PinMode_ANALOG 	3
#define GPIO_PinMode_IT_FT		4
#define GPIO_PinMode_IT_RT 		5
#define GPIO_PinMode_IT_RFT		6

/**/


/*GPIO output modes*/

#define GPIO_OUT_PP				0
#define GPIO_OUT_OD				1

/* GPIO possible output speeds */

#define GPIO_PinSpeed_LOW		0
#define GPIO_PinSpeed_MEDIUM	1
#define GPIO_PinSpeed_FAST		2
#define GPIO_Pinspeed_HIGH		3

/*GPIO pin pull-up | pull-down configuration macros*/

#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2

/*Peripheral clock setup*/

void GPIO_PericlockControl(GPIO_REG_DEF_t *pGPIOx, uint8_t Enordi);

/* Init and De-init*/

void GPIO_Init(GPIO_Handle_t);
void GPIO_deInit(GPIO_REG_DEF_t *pGPIOx);


/*Data read and write*/

uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_REG_DEF_t *pGPIOx, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber);

#endif /* INC_STM32FXX_GPIO_DRIVER_H_ */
