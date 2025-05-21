/* 
 * Title: Adapter Pattern
 * File: app_led_switch.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

#include "bsp_interface.h"

/*Application layer implementation*/

void app_led_switch() {
    //If the button is pressed
    if (button.IsPressed(WIFI_CONNECTION_BUTTON) == true) {
        //LED turns on
        led.on(WIFI_CONNECTION_BUTTON);
        //LED turns off
    } else {
        led.off(WIFI_CONNECTION_LED);
    }
}
