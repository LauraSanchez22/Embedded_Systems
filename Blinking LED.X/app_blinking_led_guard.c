/* 
 * Title:Finite State Machines
 * File: app_blinking_led_guard.c
 * Author: Laura Lizbeth Sanchez Ramirez 
 * Comments: Use of Guard Conditions
 */

#define _XTAL_FREQ 8000000UL //Oscillator working frequency
#define FCY (_XTAL_FREQ / 2) //Machine Cycle Frequency


#include "system.h"
#include <libpic30.h>

/*Definition of machine states*/
typedef enum {
    //On
    LED_OFF_STATE,
    //Off
    LED_ON_STATE,
    //Standby
    IDLE_STATE
} LED_STATE;

//Initial state
LED_STATE led_state = LED_OFF_STATE;
//transition counter
uint8_t blink_ctr = 3;

void app_blinking_led_guard() {
    switch (led_state) {

            //Configuration for machine off state
        case LED_OFF_STATE:
            //1s delay
            __delay_ms(1000);
            led.on(APP_LED);
            +
            //Change of status
            led_state = LED_ON_STATE;
            break;

            //Configuration for the machine's on state
        case LED_ON_STATE:
            //1s delay
            __delay_ms(1000);
            led.off(APP_LED);
            //Change of status
            led_state = LED_OFF_STATE;
            
            /*Guard condition*/
            led_state = ((blink_ctr > 0) ? LED_OFF_STATE : IDLE_STATE);
            
            break;

        default:
            break;
    }
}
