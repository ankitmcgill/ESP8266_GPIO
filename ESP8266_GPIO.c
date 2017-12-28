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

void ESP8266_GPIO_Set_Direction(uint8_t gpio_num, esp8266_gpio_pin_direction_t direction)
{
	//SET THE DIRECTION (INPUT / OUTPUT) OF THE SPECIFIED GPIO PIN

	//SET THE SPECIFIED PIN MODE AS GPIO
	_esp8266_gpio_set_pin_function_gpio(gpio_num);

	if(direction == PIN_DIRECTION_INPUT)
	{
		//INPUT
		GPIO_DIS_OUTPUT(gpio_num);
	}
	else if(direction == PIN_DIRECTION_OUTPUT)
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

void ESP8266_GPIO_Set_Pullup(uint8_t gpio_num)
{
	//ENABLE PULL UP ON THE SPECIFIED PIN

	switch(gpio_num)
	{
		case 0:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_GPIO0_U);
			break;

		case 1:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_U0TXD_U);
			break;

		case 2:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_GPIO2_U);
			break;

		case 3:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_U0RXD_U);
			break;

		case 4:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_GPIO4_U);
			break;

		case 5:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_GPIO5_U);
			break;

		case 12:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_MTDI_U);
			break;

		case 13:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_MTCK_U);
			break;

		case 14:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_MTMS_U);
			break;

		case 15:
			PIN_PULLUP_EN(PERIPHS_IO_MUX_MTDO_U);
			break;
		
		case 16:
			//PIN 16 AS GPIO NOT SUPPORTED
			break;
	}
}

void ESP8266_GPIO_Remove_Pullup(uint8_t gpio_num)
{
	//DISABLE PULL UP ON THE SPECIFIED PIN

	switch(gpio_num)
	{
		case 0:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_GPIO0_U);
			break;

		case 1:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_U0TXD_U);
			break;

		case 2:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_GPIO2_U);
			break;

		case 3:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_U0RXD_U);
			break;

		case 4:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_GPIO4_U);
			break;

		case 5:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_GPIO5_U);
			break;

		case 12:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_MTDI_U);
			break;

		case 13:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_MTCK_U);
			break;

		case 14:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_MTMS_U);
			break;

		case 15:
			PIN_PULLUP_DIS(PERIPHS_IO_MUX_MTDO_U);
			break;
		
		case 16:
			//PIN 16 AS GPIO NOT SUPPORTED
			break;
	}
}

void _esp8266_gpio_set_pin_function_gpio(uint8_t gpio_num)
{
	//SET THE SPECIFIED PIN TO GPIO FUNCTIONS

	switch(gpio_num)
	{
		case 0:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0);
			break;

		case 1:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_U0TXD_U, FUNC_GPIO1);
			break;

		case 2:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
			break;

		case 3:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_U0RXD_U, FUNC_GPIO3);
			break;

		case 4:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO4_U, FUNC_GPIO4);
			break;

		case 5:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5);
			break;

		case 12:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);
			break;

		case 13:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);
			break;

		case 14:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, FUNC_GPIO14);
			break;

		case 15:
			PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);
			break;
		
		case 16:
			//PIN 16 AS GPIO NOT SUPPORTED
			break;
	}
}
