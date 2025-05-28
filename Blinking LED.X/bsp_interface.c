/* 
 * Title:Finite State Machines
 * File: bsp_interface.c
 * Author: Laura Lizbeth Sanchez Ramirez 
 */

#include "bsp_interface.h"

const leds_t led = {
  .enable = LED_Enable,
  .on = LED_On,
  .off =  LED_Off
};

const buttons_t button = {
    .enable = BUTTON_Enable,
    .IsPressed = BUTTON_IsPressed
};