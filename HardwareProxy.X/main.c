/* 
 * File: main.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

#include "app_led_switch.h"


int main(){
    
    SYSTEM_Initialize(SYSTEM_STATE_POLLING);
    
    while(1){
        
        
        app_led_switch();
        
    }
    return 1;
}
