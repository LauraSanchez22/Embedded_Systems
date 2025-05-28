/* 
 * File: app_blinking_led.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */

#ifndef APP_BLINKING_LED_H
#define	APP_BLINKING_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef enum {
        LED_OFF_STATE,
        LED_ON_STATE
    } LED_STATE;

    void app_blinking_led();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* APP_BLINKING_LED_H */

