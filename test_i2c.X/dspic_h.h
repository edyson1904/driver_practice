/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DSPIC_H
#define	DSPIC_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#define PORTA_BASE_ADDR                     0xE00u
#define PORTB_BASE_ADDR                     0xE1Cu
#define PORTE_BASE_ADDR                     0xE70u

#define ENABLE                              1
#define DISABLE                             0
#define GPIO_PIN_SET                        ENABLE 
#define GPIO_PIN_CLEAR                      DISABLE
#define GPIO_PIN_OUTPUT                     DISABLE
#define GPIO_PIN_INPUT                      ENABLE


typedef struct{
    volatile uint16_t ANSEL;                         // Addr offset 0x00
    volatile uint16_t TRIS;                          // Addr offset 0x02
    volatile uint16_t PORT;                          // Addr offset 0x04
    volatile uint16_t LAT;                           // Addr offset 0x06
    volatile uint16_t ODC;                           // Addr offset 0x08
    volatile uint16_t CNPU;                          // Addr offset 0x0A
    volatile uint16_t CNPD;                          // Addr offset 0x0C
    volatile uint16_t CNCON;                         // Addr offset 0x0E
    volatile uint16_t CNEN0;                         // Addr offset 0x10
    volatile uint16_t CNSTAT;                        // Addr offset 0x12
    volatile uint16_t CNEN1;                         // Addr offset 0x14
    volatile uint16_t CNF;                           // Addr offset 0x16

}GPIOx_RegDef_t;

#define PORTA_REGS ((GPIOx_RegDef_t *) PORTA_BASE_ADDR)
#define PORTB_REGS ((GPIOx_RegDef_t *) PORTB_BASE_ADDR)
#define PORTE_REGS ((GPIOx_RegDef_t *) PORTE_BASE_ADDR)


//typedef struct nigga {
//    volatile uint16_t CRCCONL_E; //addr offset 0
//    volatile uint16_t CRCCONH_E; //addrd offet 2
//    volatile uint16_t CRCXORL_E; //addrd offset 4
//    volatile uint16_t CRCXORH_E;
//    volatile uint16_t CRCDATL_E;
//    volatile uint16_t CRCDATH_E;
//    volatile uint16_t CRCWDATL_E;
//    volatile uint16_t CRCWDATH_E;
//} CRC_RegDef_t;
//
//typedef struct {
//    uint16_t RESERVED0: 2;
//    volatile uint16_t MOD : 1;
//    volatile uint16_t LENDIAN : 1;
//    volatile uint16_t CRCGO : 1;
//    volatile uint16_t CRCISEL : 1;
//    volatile uint16_t CRCMPT : 1;
//    volatile uint16_t CRCFUL : 1;
//    volatile uint16_t VWORD : 5;
//    volatile uint16_t CSIDL : 1;
//    uint16_t RESERVED1: 1;
//    volatile uint16_t CRCEN : 1;
//} CRCCONL_RegDef_t;

#endif	/* XC_HEADER_TEMPLATE_H */

