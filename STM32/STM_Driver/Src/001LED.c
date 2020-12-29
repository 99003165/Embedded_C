#include "STM32F4XX.h"

void delay(void)
{
	for(uint32_t i=0; i<500000; i++)
	{

	}
}

int main()
{
GPIO_Handle_t GPIOLED;
GPIOLED.pGPIOx = GPIOD;
GPIOLED.PIN_CONFIG.GPIO_PinNumber = GPIO_PinNumber_12;
GPIOLED.PIN_CONFIG.GPIO_PinMode = GPIO_PinMode_OUT;
GPIOLED.PIN_CONFIG.GPIO_PinSpeed = GPIO_PinSpeed_FAST;
GPIOLED.PIN_CONFIG.GPIO_PinOPType = GPIO_OUT_PP	;
GPIOLED.PIN_CONFIG.GPIO_PinPuPdControl = GPIO_PIN_PU;
GPIO_PericlockControl(GPIOD, ENABLE);
GPIO_Init(&GPIOLED);

while(1)
{
	GPIO_ToggleOutputPin(GPIOD, 12);
	delay();
}

}
