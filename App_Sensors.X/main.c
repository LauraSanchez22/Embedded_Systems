#include <stdio.h>
#include "temp_sensor.h"
#include "Barometric_sensor.h"
#include "sensor.h"

/* 
 * Title: Application with sensors 
 * File: main.c
 * Author: Laura Lizbeth Sanchez Ramirez
 */


int main() {


    /*<<<<<Objects used for temperature sensors>>>>>*/
    temperatura_sensor_t tempSensor_emc1001, *pTempSensor_emc1001 = newTempSensor(&tempSensor_emc1001);
    temperatura_sensor_t tempSensor_ds1624, * pTempSensor_ds1624 = newTempSensor(&tempSensor_ds1624);
    temperatura_sensor_t tempSensor_mcp9808, *pTempSensor_mcp9808 = newTempSensor(&tempSensor_mcp9808);

    /*<<<<<Objects used for barometric pressure sensors>>>>>*/
    barometricPressure_sensor baroSensor_bmp085, *pBaroSensor_bmp085 = newBaroPressure_Sensor(&baroSensor_bmp085);
    barometricPressure_sensor baroSensor_dps368, *pBaroSensor_dps368 = newBaroPressure_Sensor(&baroSensor_dps368);
    
    /*Data for temperature sensors*/
    pTempSensor_emc1001->sensor.init(pTempSensor_emc1001, "EMC1001", EMC1001_SENSOR_ID);
    pTempSensor_ds1624->sensor.init(pTempSensor_ds1624, "DS1624", DS1624_SENSOR_ID);
    pTempSensor_mcp9808->sensor.init(pTempSensor_mcp9808, "MCP9808", MCP9808_SENSOR_ID);

    /*Data for barometric pressure sensors*/
    pBaroSensor_bmp085->sensor.init(pBaroSensor_bmp085, "BMP085", BMP085_SENSOR_ID);
    pBaroSensor_dps368->sensor.init(pBaroSensor_dps368, "DPS368", DPS368_SENSOR_ID);
    

    printf("Sensor %s | Temperature: %u\n", pTempSensor_emc1001->sensor.getName(pTempSensor_emc1001),
            pTempSensor_emc1001->sensor.read(pTempSensor_emc1001, EMC1001_SENSOR_ID));
    printf("Sensor %s | Temperature: %u\n", pTempSensor_ds1624->sensor.getName(pTempSensor_ds1624),
            pTempSensor_ds1624->sensor.read(pTempSensor_ds1624, DS1624_SENSOR_ID));
    printf("Sensor %s | Temperature: %u\n", pTempSensor_mcp9808->sensor.getName(pTempSensor_mcp9808),
            pTempSensor_mcp9808->sensor.read(pTempSensor_mcp9808, MCP9808_SENSOR_ID));
    
    printf("Sensor %s | Pressure: %d hPa\n", pBaroSensor_bmp085->sensor.getName(pBaroSensor_bmp085),
            pBaroSensor_bmp085->ReadPressure(pBaroSensor_bmp085));
    printf("Sensor %s | Pressure: %d hPa\n", pBaroSensor_dps368->sensor.getName(pBaroSensor_dps368),
            pBaroSensor_dps368->ReadPressure(pBaroSensor_dps368));
    
    return 1;
}
