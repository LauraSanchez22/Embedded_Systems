/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef BUTTONS_H
#define	 BUTTONS_H_H

#include <xc.h> // include processor files - each processor file is guarded.  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>

    typedef enum {
        BUTTON_NONE,
        BUTTON_SW0,
        BUTTON_SW1
    } BUTTON;
    
    void BUTTON_Enable(BUTTON button);
    bool BUTTON_IsPressed(BUTTON button);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/*  BUTTONS_H_H */

