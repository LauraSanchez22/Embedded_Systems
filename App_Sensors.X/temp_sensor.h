/* 
 * Title: Application with sensors 
 * File: temp_sensor.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */

 
#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#define EMC1001_SENSOR_ID   5
#define DS1624_SENSOR_ID    6
#define MCP9808_SENSOR_ID   7 

#include "sensor.h"

typedef struct temperatura_sensor temp_sensor_t;
/**DATA HIDDING*/
typedef const struct temperatura_sensor temperatura_sensor_t;

//Child class for temperature sensors
struct temperatura_sensor
{
    sensor_t sensor;
    uint8_t range;
    void (*displayTemp)(temp_sensor_t *pSensor);
};

temp_sensor_t* newTempSensor(temp_sensor_t *pSensor);

#endif	/* TEMP_SENSOR_H */

