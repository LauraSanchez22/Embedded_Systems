/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/winc/driver/../include/../m2m/m2m_wifi.h"
#include "mcc_generated_files/config/conf_winc.h"
#include "mcc_generated_files/drivers/../winc/common/winc_defines.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/* 
 * Title: Wifi network.- ATWINC1510 
 * File: Main application
 * Author: Laura Lizbeth Sanchez Ramirez
 */
 


bool wifi_connect();

static void wifi_cb(uint8_t u8MsgType, void *pvMsg) {
    switch (u8MsgType) {
            /*It handles what happens when the state changes*/
        case M2M_WIFI_RESP_CON_STATE_CHANGED:
        {
            tstrM2mWifiStateChanged *pstrWifiState = (tstrM2mWifiStateChanged*) pvMsg;

            /*Check if you are connected to a Wi-Fi network*/
            if (pstrWifiState->u8CurrState == M2M_WIFI_CONNECTED) {
                printf("WIFI STATE: CONNECTED\n");
                BLUE_LED_SetLow();
                RED_LED_SetHigh();
                /*Check if you are disconnected from a Wi-Fi network*/
            } else if (pstrWifiState->u8CurrState == M2M_WIFI_DISCONNECTED) {
                printf("WIFI STATE: DISCONNECTED\n");
            }
            break;
        }
        /*Gets a response from the DHCP server*/
        case M2M_WIFI_REQ_DHCP_CONF:
        {
            printf("IP Address obtained\n");
            break;
        }
    }
}

//Callback.- EvenHandler

int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    
    //LEDs start off
    BLUE_LED_SetHigh();
    RED_LED_SetHigh()
    YELLOW_LED_SetHigh()
    GREEN_LED_SetHigh()

    //Initialize the wifi controller event notifier
    tstrWifiInitParam param;
    int8_t ret;

    nm_bsp_init();

    m2m_memset((uint8_t*) &param, 0, sizeof (param));

    param.pfAppWifiCb = wifi_cb;

    ret = m2m_wifi_init(&param);

    //If it is different than 0, there are problems
    if (ret != M2M_SUCCESS) {
        printf("Failed to Init Wifi driver\n");
    }


    if(wifi_connect() == true){
        printf("\nCONNECTING...\n");
    }
    while (1) {
        while(m2m_wifi_handle_events(NULL) != M2M_SUCCESS);
    }

    return 1;
}

/*Function used to connect to a Wi-Fi network*/
bool wifi_connect() {
    static uint8_t ssid[30];
    static uint8_t pass[30];

    int8_t ret = 0;

    //Wifi SSID
    strcpy(ssid, CFG_MAIN_WLAN_SSID);

    //Password
    strcpy(pass, CFG_MAIN_WLAN_PSK);

    //Find Wi-Fi network
    ret = m2m_wifi_connect((char*) ssid, strlen(ssid),
            CFG_MAIN_WLAN_AUTH, (char*) pass, M2M_WIFI_CH_ALL);

    //In case of issues with the Wi-Fi network connection
    if (ret != M2M_SUCCESS) {
        printf("Failed to request a wifi connection\n");
        return false;
    }
    return true;
}
/**
 End of File
 */

