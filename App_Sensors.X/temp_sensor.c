#include <stdio.h>
#include "temp_sensor.h"

/* 
 * Title: Application with sensors 
 * File: temp_sensor.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */

/*Prototype functions*/
static void initTempSensor(void* pSensor, uint8_t *name, uint8_t id);
static void setNameTempSensor(void* pSensor, uint8_t *name);
static uint8_t* getNameTempSensor(void* pSensor);
static void setIdTempSensor(void* pSensor, uint8_t id);
static uint8_t getIdTempSensor(void* pSensor);
static uint8_t* readTempSensor(void* pSensor);

temp_sensor_t* newTempSensor(temp_sensor_t *pSensor) {
    /*methods mapping*/
    //POLYMORPHIC FUNCTIONS
    pSensor->sensor.init = initTempSensor;
    pSensor->sensor.setName = setNameTempSensor;
    pSensor->sensor.getName = getNameTempSensor;
    pSensor->sensor.setId = setIdTempSensor;
    pSensor->sensor.getId = getIdTempSensor;
    return pSensor;
}

/*Temperature sensor data is initialized*/
static void initTempSensor(void* pSensor, uint8_t *name, uint8_t id) {
    /*Start logical control of sensor pSensor with name and id*/
    setNameTempSensor(pSensor, name);
    setIdTempSensor(pSensor, id);
    printf("Temperature sensor: %s ID %u\n", getNameTempSensor(pSensor), getIdTempSensor(pSensor));
}

/*Set temperature sensor name*/
static void setNameTempSensor(void* pSensor, uint8_t *name) {
    //A generic pointer (pSensor) is shaped with casting
    temp_sensor_t *pTempSensor = (temp_sensor_t*) pSensor;
    //Parent class methods (sensor) are accessed
    pTempSensor->sensor.name = name;
}

/*Get temperature sensor name*/
static uint8_t* getNameTempSensor(void* pSensor) {
    temp_sensor_t *pTempSensor = (temp_sensor_t*) pSensor;
    return pTempSensor->sensor.name;
}

/*Set the temperature sensor ID*/
static void setIdTempSensor(void* pSensor, uint8_t id) {
    temp_sensor_t *pTempSensor = (temp_sensor_t*) pSensor;
    pTempSensor->sensor.id = id;
}

/*Get the temperature sensor ID*/
static uint8_t getIdTempSensor(void* pSensor) {
    temp_sensor_t *pTempSensor = (temp_sensor_t*) pSensor;
    return pTempSensor->sensor.id;
}

/*Reads the temperature quantity from the sensor*/
static uint8_t* readTempSensor(void* pSensor) {

    temp_sensor_t *pTempSensor = (temp_sensor_t*) pSensor;

    switch (pTempSensor->sensor.id) {

            /*Temperature measurement with the EMC1001 sensor*/
        case EMC1001_SENSOR_ID:
            printf("\nAccessing the EMC1001 sensor drivers...\n");
            pTempSensor->sensor.value = 30;
            break;

            /*Temperature measurement with the DS1624 sensor*/
        case DS1624_SENSOR_ID:
            printf("\nAccessing the DS1624 sensor drivers...\n");
            pTempSensor->sensor.value = 50;
            break;

            /*Temperature measurement with the MCP9808 sensor*/
        case MCP9808_SENSOR_ID:
            printf("\nAccessing the MCP9808 sensor drivers...\n");
            pTempSensor->sensor.value = 10;
            break;

    }
    return pTempSensor->sensor.value;
}