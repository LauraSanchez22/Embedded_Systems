#include "Barometric_sensor.h"
#include <stdio.h>

/* 
 * Title: Application with sensors 
 * File: Barometric_sensor.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

/*Function Prototypes*/
baroPressure_sensor_t* newBaroPressure_Sensor(baroPressure_sensor_t *pSensor);
static void initBaroPressureSensor(void* pSensor, uint8_t *name, uint8_t id);
static void setNameBaroPressureSensor(void* pSensor, uint8_t *name);
static uint8_t* getNameBaroPressureSensor(void* pSensor);
static void setIdBaroPressureSensor(void* pSensor, uint8_t id);
static uint8_t getIdBaroPressureSensor(void* pSensor);
static uint16_t* readPressureBaroSensor(void *pvSensor);

baroPressure_sensor_t* newBaroPressure_Sensor(baroPressure_sensor_t *pSensor) {

    /*Method mapping*/
    pSensor->sensor.init = initBaroPressureSensor;
    pSensor->sensor.setName = setNameBaroPressureSensor;
    pSensor->sensor.getName = getNameBaroPressureSensor;
    pSensor->sensor.setId = setIdBaroPressureSensor;
    pSensor->sensor.getId = getIdBaroPressureSensor;
    pSensor->ReadPressure = readPressureBaroSensor;

    return pSensor;
}

/*Initializing pressure sensor data*/
static void initBaroPressureSensor(void* pSensor, uint8_t *name, uint8_t id) {
    /*Start logical control of sensor pSensor with name and id*/
    setNameBaroPressureSensor(pSensor, name);
    setIdBaroPressureSensor(pSensor, id);
    printf("Pressure sensor: %s ID %u\n", getNameBaroPressureSensor(pSensor), getIdBaroPressureSensor(pSensor));
}

/*Set name to pressure sensor*/
static void setNameBaroPressureSensor(void* pSensor, uint8_t *name) {
    //A generic pointer is shaped with casting
    baroPressure_sensor_t *pBaroPressureSensor = (baroPressure_sensor_t*) pSensor;
    pBaroPressureSensor->sensor.name = name;
}

/*Get the name of the pressure sensor*/
static uint8_t* getNameBaroPressureSensor(void* pSensor) {
    baroPressure_sensor_t *pBaroPressureSensor = (baroPressure_sensor_t*) pSensor;
    return pBaroPressureSensor->sensor.name;
}

/*Set the ID to the pressure sensor*/
static void setIdBaroPressureSensor(void* pSensor, uint8_t id) {
    baroPressure_sensor_t *pBaroPressureSensor = (baroPressure_sensor_t*) pSensor;
    pBaroPressureSensor->sensor.id = id;
}

/*Get the ID to the pressure sensor*/
static uint8_t getIdBaroPressureSensor(void* pSensor) {
    baroPressure_sensor_t *pBaroPressureSensor = (baroPressure_sensor_t*)pSensor;
    return pBaroPressureSensor->sensor.id;
}

/*Read the pressure level from the sensor*/
static uint16_t* readPressureBaroSensor(void *pvSensor) {

    baroPressure_sensor_t *pBaroPressureSensor = (baroPressure_sensor_t*)pvSensor;

    switch (pBaroPressureSensor->sensor.id) {

        case BMP085_SENSOR_ID:
            printf("Accessing the BMP085 sensor drivers....\n");
            pBaroPressureSensor->pressure = 400;
            break;

        case DPS368_SENSOR_ID:
            printf("Accessing the DPS368 sensor drivers....\n");
            pBaroPressureSensor->pressure = 500;
            break;
    }
    return pBaroPressureSensor->pressure;
}