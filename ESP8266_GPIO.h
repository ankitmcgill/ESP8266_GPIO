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

#ifndef _ESP8266_GPIO_H_
#define _ESP8266_GPIO_H_

#include <osapi.h>
#include <ets_sys.h>
#include <gpio.h>

void ESP8266_GPIO_Sys_Delay_Us(uint32_t micro_sec);
void ESP8266_GPIO_Set_Direction(uint8_t gpio_num, uint8_t direction);
void ESP8266_GPIO_Set_Value(uint8_t gpio_num, uint8_t val);
uint8_t ESP8266_GPIO_Get_Value(uint8_t gpio_num);

#endif
