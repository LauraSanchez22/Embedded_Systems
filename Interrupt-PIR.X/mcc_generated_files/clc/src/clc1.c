/**
 * CLC1 Generated Driver File.
 * 
 * @file clc1.c
 * 
 * @ingroup  clc1
 * 
 * @brief This file contains the API implementations for the CLC1 driver.
 *
 * @version CLC1 Driver Version 1.0.1
*/
/*
� [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include <xc.h>
#include "../clc1.h"

static void (*CLC1_CLCI_InterruptHandler)(void);
static void CLC1_DefaultCLCI_ISR(void);

void CLC1_Initialize(void)
{
    
    // LCG1POL not_inverted; LCG2POL not_inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLC1POL = 0x0;
    // LCD1S CLCIN0 (CLCIN0PPS); 
    CLC1SEL0 = 0x0;
    // LCD2S CLCIN0 (CLCIN0PPS); 
    CLC1SEL1 = 0x0;
    // LCD3S CLCIN0 (CLCIN0PPS); 
    CLC1SEL2 = 0x0;
    // LCD4S CLCIN0 (CLCIN0PPS); 
    CLC1SEL3 = 0x0;
    // LCG1D1N enabled; LCG1D1T disabled; LCG1D2N disabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLC1GLS0 = 0x1;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T disabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLC1GLS1 = 0x0;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T disabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLC1GLS2 = 0x0;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLC1GLS3 = 0x0;
    // LCMODE OR-XOR; LCINTN enabled; LCINTP enabled; LCEN enabled; 
    CLC1CON = 0x99;

    // Clear the CLC interrupt flag
    PIR5bits.CLC1IF = 0;
    //Configure interrupt handlers
    CLC1_CLCI_SetInterruptHandler(CLC1_DefaultCLCI_ISR);
    // Enabling CLC1 interrupt.
    PIE5bits.CLC1IE = 1;
}

void CLC1_ISR(void)
{   
    // Clear the CLC interrupt flag
    //PIR5bits.CLC1IF = 0;
    LATAbits.LATA0 = !LATAbits.LATA0;

    if (CLC1_CLCI_InterruptHandler != NULL)
    {
        CLC1_CLCI_InterruptHandler();
    }
}

void CLC1_CLCI_SetInterruptHandler(void (* InterruptHandler)(void))
{
    CLC1_CLCI_InterruptHandler = InterruptHandler;
}

static void CLC1_DefaultCLCI_ISR(void)
{
    //Add your interrupt code here or
    //Use CLC1_CLCI_SetInterruptHandler() function to use custom ISR
}

bool CLC1_OutputStatusGet(void)
{
    return(CLC1CONbits.LC1OUT);
}
/**
 End of File
*/
