/* 
 * Title:Finite State Machines
 * File: newmain.c
 * Author: Laura Lizbeth Sanchez Ramirez 
 */

#include "system.h"

int main() {
    
    SYSTEM_Initialize(SYSTEM_STATE_POLLING);
    
    while(1){
        //State machine execution
        app_blinking_led_guard();
    }
    return 1;
}
