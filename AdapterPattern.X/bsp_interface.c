/* 
 * Title: Adapter Pattern
 * File: bsp_interface.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

#include "bsp_interface.h"

/*Adapter pattern configuration*/

const leds_t led = {

    //Assigning properties to functions for LEDs

    .enable = LED_Enable,
    .on = LED_On,
    .off = LED_Off
};

const buttons_t button = {
    //Assigning properties to functions for buttons
    .enable = BUTTON_Enable,
    . IsPressed = BUTTON_IsPressed
};
