// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 2       // PLL Prescaler Selection bits (Divide by 2 (8 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 2       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes from the 96 MHz PLL divided by 2)

// CONFIG1H
#pragma config FOSC = HSPLL_HS  // Oscillator Selection bits (HS oscillator, PLL enabled (HSPLL))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = OFF     // CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)



#include <xc.h>
#define _XTAL_FREQ 48000000 //Maximum working frequency: 48 MHz

/* 
 * Title: LED lighting sequences
 * File: LedsON.c
 * MCU: PIC18F4550 8 bits
 * Author: Laura Lizbeth Sanchez Ramirez
 */

void main(void) {

    /*ADC0N: Used to set pins to digital. 
     * Register value: 15 bits.*/
    ADCON1bits.PCFG = 0x0F;

    //Configuring pushbuttons as inputs
    TRISDbits.RD0 = 1;
    TRISDbits.RD1 = 1;
    TRISDbits.RD2 = 1;
    TRISDbits.RD3 = 1;

    TRISB = 0x00; //Port B configured as output
    LATB = 0x00; //Clearing port B to prevent overwriting

    while (1) {

        //If the button is pressed
        if (PORTDbits.RD0 == 1) {

            //All LEDs light up one after the other
            for (char i = 0; i < 3; i++) {

                //Pink Led
                LATB = 0b00000001;
                __delay_ms(100);

                //Birg Led
                LATB = 0b00000010;
                __delay_ms(100);

                //Orange Led
                LATB = 0b00000100;
                __delay_ms(100);

                //Purple Led
                LATB = 0b00001000;
                __delay_ms(100);

                //Red Led
                LATB = 0b00010000;
                __delay_ms(100);

                //White Led
                LATB = 0b00100000;
                __delay_ms(100);

                //Yellow Led
                LATB = 0b01000000;
                __delay_ms(100);

                //Blue Led
                LATB = 0b10000000;
                __delay_ms(100);
            }

        } else if (PORTDbits.RD1 == 1) {

            //All LEDs light up one after the other in reverse order
            for (char i = 0; i < 3; i++) {

                //Blue Led
                LATB = 0b10000000;
                __delay_ms(100);

                //Yellow Led
                LATB = 0b01000000;
                __delay_ms(100);

                //White Led
                LATB = 0b00100000;
                __delay_ms(100);

                //Red Led
                LATB = 0b00010000;
                __delay_ms(100);

                //Purple Led
                LATB = 0b00001000;
                __delay_ms(100);

                //Orange Led
                LATB = 0b00000100;
                __delay_ms(100);

                //Birg Led
                LATB = 0b00000010;
                __delay_ms(100);

                //Pink Led
                LATB = 0b00000001;
                __delay_ms(100);
            }
        }
        else if (PORTDbits.RD2 == 1) {

            //The LEDs light up in pairs
            for (char i = 0; i < 3; i++) {

                //Pink Led and Blue Led
                LATB = 0b10000001;
                __delay_ms(100);

                //Yellow Led and Birg Led
                LATB = 0b01000010;
                __delay_ms(100);

                //White Led and Orange Led
                LATB = 0b00100100;
                __delay_ms(100);

                //Red Led and Purple Led
                LATB = 0b00011000;
                __delay_ms(100);
                //Orange Led and Birg Led
                LATB = 0b00100100;
                __delay_ms(100);
                //Birg Led and Yellow Led
                LATB = 0b01000010;
                __delay_ms(100);

            }
            LATB = 0b10000001;
            __delay_ms(100);
        }
            //All the LEDs above turn on, then the ones below
        else if (PORTDbits.RD3 == 1) {
            for (char i = 0; i < 3; i++) {
                LATB = 0b00001111;
                __delay_ms(400);
                LATB = 0b11110000;
                __delay_ms(400);
            }
            //When the process is finished, all the LEDs turn off
        } else {
            LATB = 0b00000000;
        }

    }
    return;
}
