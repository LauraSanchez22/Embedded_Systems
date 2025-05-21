#include "buttons.h"
#include <xc.h>

#define SW0_PORT            PORTAbits.RA7
#define SW1_PORT            PORTAbits.RA10

#define SW0_TRIS            TRISAbits.TRISA7
#define SW1_TRIS            TRISAbits.TRISA10

#define SW0_PULLUP          IOCPUAbits.IOCPUA7
#define SW1_PULLUP          IOCPUAbits.IOCPUA10

#define INPUT                   1
#define OUTPUT                  0

#define PULLUP_ENABLE           1
#define PULLUP_DISABLE          0

#define BUTTON_PRESSED          0
#define BUTTON_NOT_PRESSED      1

void BUTTON_Enable(BUTTON button){
    switch(button){
        
        //Switch Configuration 0
        case BUTTON_SW0:
            SW0_TRIS    = INPUT;
            SW0_PULLUP  = PULLUP_ENABLE;
            break;
        
        case BUTTON_SW1:
            SW1_TRIS    = INPUT;
            SW1_PULLUP  = PULLUP_ENABLE;
            break;
         
        case BUTTON_NONE:
            break;
    }
}

/*Button configuration when pressed*/
bool BUTTON_IsPressed(BUTTON button){
    switch(button){
        case BUTTON_SW0:
            return ((SW0_PORT == BUTTON_PRESSED) ? true : false);
            break;
            
        case BUTTON_SW1:
            return ((SW1_PORT == BUTTON_PRESSED) ? true : false);
            break;
            
        case BUTTON_NONE:
            break;
           
    }
}