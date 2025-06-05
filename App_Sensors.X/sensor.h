/* 
 * Title: Application with sensors 
 * File: sensor.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */


#ifndef SENSOR_H
#define	SENSOR_H
#include <stdint.h>


#define EMC1001_SENSOR_ID 5
#define DS1624_SENSOR_ID  6
#define MCP9808_SENSOR_ID 7

typedef struct sensor sensor_t;

typedef union{
    uint8_t analog_iface;
    uint8_t i2c_iface;
    uint8_t spi_iface;
    uint8_t swi_iface;
}interface_t;

/*ABSTRACT CLASS SENSOR (parent class)*/
struct sensor{
    
    /**Properties that child classes can implement
     * CHARACTERISTICS THAT SENSORS CAN HAVE
     */
    
    uint8_t *value; /*measurement value*/
    uint8_t *name; /*text string, pointer to char*/
    uint8_t id;
    interface_t interface;
    
    /**Universal methods for all sensors
     * A handler is used (a handler to point to the memory block where the sensor is located).
     * Generic pointers do not yet have a defined type.
     */
    void (*init)(void* pvS, uint8_t *name, uint8_t id);
    void (*configure)(void *pvS, uint8_t id);
    void (*calibrate)(void *pvS, uint8_t id);
    uint8_t* (*read)(void *pvS, uint8_t id);
    void (*write)(void *pvS, uint8_t id, uint8_t *data);
    void (*setName)(void *pvS, uint8_t* name);
    uint8_t* (*getName)(void *pvS);
    void (*setId)(void *pvS, uint8_t id);
    uint8_t (*getId)(void *pvS);
};

#endif	/* SENSOR_H */

