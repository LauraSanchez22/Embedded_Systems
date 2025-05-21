/* 
 * File: system.h
 * Author: Laura Lizbeth Sanchez Ramirez 
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h> // include processor files - each processor file is guarded.  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    
#include "io_mapping.h"
    
    typedef enum {
        SYSTEM_STATE_POLLING,
        SYSTEM_STATE_INTERRUPT
    }SYSTEM_STATE;
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SYSTEM_H */

