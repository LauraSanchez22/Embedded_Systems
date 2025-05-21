/* 
 * File: io_mapping.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */

 
#ifndef IO_MAPPING_H
#define	IO_MAPPING_H

#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bsp/led.h"
#include "bsp/buttons.h"
    
#define WIFI_CONNECTION_LED         BLUE_LED
#define ERROR_LED                   RED_LED
#define CLOUD_CONNECTION_LED        GREEN_LED
#define WIFI_CONNECTION_BUTTON      BUTTON_SW0   
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* IO_MAPPING_H */

