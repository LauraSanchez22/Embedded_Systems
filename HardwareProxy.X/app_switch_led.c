/* 
 * File: app_switch_led.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

#include "system.h"
//Proxy Client
void app_led_switch(){
  
    //When you press the button the LED lights up.
    if(BUTTON_IsPressed(WIFI_CONNECTION_BUTTON)){
        LED_On(WIFI_CONNECTION_LED);
    }else{
            LED_On(CLOUD_CONNECTION_LED);

    }
    
}
