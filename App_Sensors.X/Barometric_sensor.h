/* 
 * Title: Application with sensors 
 * File: Barometric_sensor.h
 * Author: Laura Lizbeth Sanchez Ramirez
 */

 
#ifndef BAROMETRIC_SENSOR_H
#define	BAROMETRIC_SENSOR_H

#define BMP085_SENSOR_ID    10
#define DPS368_SENSOR_ID    11

#include "sensor.h"

typedef struct barometricPressure_sensor baroPressure_sensor_t;
typedef const struct barometricPressure_sensor barometricPressure_sensor_t;

/*Pressure sensor properties association*/
struct barometricPressure_sensor{
    sensor_t sensor;
    float temperature;
    uint16_t pressure;
    float altitude;
    uint16_t seaLevelPressure;
    
    uint16_t* (*ReadPressure)(barometricPressure_sensor* pSensor);
    uint16_t* (*ReadTemperature)(barometricPressure_sensor* pSensor, uint8_t id);
    uint16_t* (*ReadSeaLevelPressure)(barometricPressure_sensor* pSensor, uint8_t id);
}


#endif	/* BAROMETRIC_SENSOR_H */

