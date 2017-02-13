//////////////////////////////////////////////////////////////////
// GPIO DRIVER - ESP8266
//
// LIBRARY FOR GPIO OPERATIONS ON ESP8266
//
// NOTE : AS THE GPIO ON ESP8266 ARE MODEL SPECIFIC, THIS LIBRARY DOES
//        NOT DEAL WITH SETTING THE PIN AS GPIO. SO PRIOR TO USING THIS
//		  LIBRARY, USER CODE NEEDS TO SET THE PIN FUNCTION TO GENERAL
//		  GPIO
//
// FEBRUARY 13, 2017
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////////////////////////

#include "ESP8266_GPIO.h"

void ESP8266_GPIO_Sys_Delay_Us(uint32_t micro_sec)
{
	//BLOCKING SYSTEM SPECIFIC DELAY OF SPECIFIED
	//MICRO-SECONDS

	os_delay_us(micro_sec);
}

void ESP8266_GPIO_Set_Direction(uint8_t gpio_num, uint8_t direction)
{
	//SET THE DIRECTION (INPUT / OUTPUT) OF THE SPECIFIED GPIO PIN
	//DIRECTION = 0 = INPUT
	//DIRECTION = 1 = OUTPUT
	//NOTE : THE PIN FUNCTIONS NEEDS TO BE SET TO GFENERAL GPIO BY THE USER
	//PROGRAM. THIS LIBRARY WOULD NOT DO THAT !

	if(direction == 0)
	{
		//INPUT
		GPIO_DIS_OUTPUT(gpio_num);
	}
	else
	{
		//OUTPUT + SET VALUE TO 0
		ESP8266_GPIO_Set_Value(gpio_num, 0);
	}
}

void ESP8266_GPIO_Set_Value(uint8_t gpio_num, uint8_t val)
{
	//SET THE VALUE OF THE SPECIFIED GPIO PIN

	GPIO_OUTPUT_SET(gpio_num, val);
}

uint8_t ESP8266_GPIO_Get_Value(uint8_t gpio_num)
{
	//RETURN THE VALUE OF GPIO SET AS INPUT

	return GPIO_INPUT_GET(gpio_num);
}
