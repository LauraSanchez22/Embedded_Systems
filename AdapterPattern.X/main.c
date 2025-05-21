/* 
 * Title: Adapter Pattern
 * File: main.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */
     
#include "system.h"

int main(){
    
    SYSTEM_Initialize(SYSTEM_STATE_POLLING);
    
    while(1){
        app_led_switch();
    }
    return 1;
}
