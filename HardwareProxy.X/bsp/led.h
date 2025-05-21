
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef LED_H
#define	LED_H

#include <xc.h>  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef enum {
        LED_NONE,
        RED_LED,
        YELLOW_LED,
        GREEN_LED,
        BLUE_LED
    }LED;
    
    /*Prototype functions*/
    void LED_ENABLE(LED led);
    void LED_On(LED led);
    void LED_Off(LED led);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LED_H */

