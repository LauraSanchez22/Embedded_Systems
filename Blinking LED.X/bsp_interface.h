/* 
 * File: bsp_interface.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */
 
#ifndef BSP_INTERFACE_H
#define	BSP_INTERFACE_H

#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#include "io_mapping.h"
    
    /*LED activation status configuration*/
    typedef struct{
        void (*enable) (LED led);
        void (*on) (LED led);
        void (*off) (LED led);
    }leds_t;
    
    /*Configuration for the button*/
    typedef struct{
        void (*enable) (BUTTON button);
        bool (*IsPressed) (BUTTON button);
    }buttons_t;
    
    extern const buttons_t button;
    extern const leds_t led;

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* BSP_INTERFACE_H */

