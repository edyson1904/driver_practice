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
#ifndef GPIO_H
#define	GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "dspic_h.h"
#include "stdbool.h"
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate
typedef enum {
    PORTA_x=0,
    PORTB_x,
    PORTC_x,
    PORTD_x,
    PORTE_x
}PORTS_AVAILABLE_ENUM;
typedef enum{
    GPIO_NO_PULL= 0,
    GPIO_PULL_UP = 1,
    GPIO_PULL_DOWN = 2
}GPIO_PULL_ENUM;

typedef enum {
    GPIO_ODC_OFF = 0,
    GPIO_ODC_ON
}GPIO_ODC_ENUM;

typedef enum {
    GPIO_ANSEL_OFF = 0,
    GPIO_ANSEL_ON
}GPIO_ANALOG_SEL_ENUM;


// TODO Insert declarations
typedef struct{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinDirection;
    uint8_t GPIO_PinLatch;
    uint8_t GPIO_PinPull;
    uint8_t GPIO_PinAnalog;
}GPIOx_Config_t;
// Comment a function and leverage automatic documentation with slash star star

typedef struct
{
    GPIOx_RegDef_t * pGPIOx;
    GPIOx_Config_t GPIOx_Config; 

}GPIOx_Handle_t;

/*
 * GPIO Configuration
 */
void GPIO_Init(GPIOx_Handle_t * pGPIOHandle);
void GPIO_Pin_Direction(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber,uint8_t dir );
void GPIO_Pin_Pull(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber, uint8_t pull );
void GPIO_Pin_AnalogMode(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber, uint8_t setting);

/*
 * GPIO Output Read/Write
 */
void GPIO_Pin_SetOutputLevel(GPIOx_RegDef_t * pGPIOHandle, uint8_t pinNumber, uint8_t level);
bool GPIO_Pin_Read(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber);
void GPIO_Pin_ToggleOutput(GPIOx_RegDef_t *pGPIOx, uint8_t pinNumber);


/*
 * GPIO IRQ
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t Priority, uint8_t en);
void GPIO_IRQHandler(void);


 /**   <p><b>Function prototype:</b></p>
  
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



#endif	/* XC_HEADER_TEMPLATE_H */

