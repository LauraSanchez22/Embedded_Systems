/**
 *
 * \file
 *
 * \brief This module contains WINC ADAPTER APIs implementation.
 *
 * Copyright (c) 2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "../../mcc.h"
#include "../../delay.h"
#include "winc_adapter.h"
#include <libpic30.h>

static int_fast8_t serviceRequest;

static void winc_interrupt_handler(void)
{
    serviceRequest++;
}

int_fast8_t winc_adapter_interrupt_request_pending(void)
{
    return serviceRequest ? 1 : 0;
}

int_fast8_t winc_adapter_interrupt_serviced(bool bEdgeInt)
{
    if (bEdgeInt)
    {
        /* disable negative interrupt for INT */ /* no pin selected for INT */
        if(serviceRequest)
        {
            serviceRequest--;
        }
        /* enable negative interrupt for INT */ /* no pin selected for INT */
    }

    return 1;
}

int_fast8_t winc_adapter_init(void)
{
    serviceRequest = 0;
    // Select INT pin.


    return 1;
}

int_fast8_t winc_adapter_deinit(void)
{
    return 1;
}

void winc_adapter_sleep(uint32_t u32TimeMsec)
{
    while (u32TimeMsec--)
    {
        DELAY_milliseconds(1);
    }
}

void winc_adapter_chip_enable_assert(void)
{
    // Select CE pin.
}

void winc_adapter_chip_enable_deassert(void)
{
    // Select CE pin.
}

void winc_adapter_reset_assert(void)
{
    // Select RST pin.
}

void winc_adapter_reset_deassert(void)
{
    // Select RST pin.
}

int_fast8_t winc_adapter_spi_open(void)
{
    return 1;
}

int_fast8_t winc_adapter_spi_write(const uint8_t *puBuf, size_t size)
{
    spiMaster[WINC].spiOpen();
    // Select SPI chip select pin.
    spiMaster[WINC].writeBlock((uint8_t*)puBuf, size);
    // Select SPI chip select pin.
    spiMaster[WINC].spiClose();

    return 1;
}

int_fast8_t winc_adapter_spi_read(uint8_t *puBuf, size_t size)
{
    spiMaster[WINC].spiOpen();
    // Select SPI chip select pin.
    spiMaster[WINC].readBlock(puBuf, size);
    // Select SPI chip select pin.
    spiMaster[WINC].spiClose();

    return 1;
}

int_fast8_t winc_adapter_spi_close(void)
{
    return 1;
}