/*
 * File:   gpio_driver.c
 * Author: Edyson
 *
 * Created on February 28, 2023, 10:11 PM
 */

#include "gpio_driver.h"


void GPIO_Init(GPIOx_Handle_t * pGPIOHandle){
    uint16_t temp = 0;
    if (pGPIOHandle->GPIOx_Config.GPIO_PinAnalog == GPIO_ANSEL_OFF)
        {
        pGPIOHandle->pGPIOx->ANSEL &=~( 1 << pGPIOHandle->GPIOx_Config.GPIO_PinNumber);
        
        
        // configure the pin direction
       
        if (pGPIOHandle->GPIOx_Config.GPIO_PinDirection == GPIO_PIN_OUTPUT)
            pGPIOHandle->pGPIOx->TRIS &= ~(1 << pGPIOHandle->GPIOx_Config.GPIO_PinNumber);
        else
            pGPIOHandle->pGPIOx->TRIS |= (1 << pGPIOHandle->GPIOx_Config.GPIO_PinNumber);
    
        //configre the pull setting
        if (pGPIOHandle->GPIOx_Config.GPIO_PinPull == GPIO_PULL_UP)
        {   
             pGPIOHandle->pGPIOx->CNPU |= ENABLE << pGPIOHandle->GPIOx_Config.GPIO_PinNumber;
        }
        else if (pGPIOHandle->GPIOx_Config.GPIO_PinPull == GPIO_PULL_DOWN)
        {
            pGPIOHandle->pGPIOx->CNPD |= ENABLE << pGPIOHandle->GPIOx_Config.GPIO_PinNumber;
        }
        else 
              pGPIOHandle->pGPIOx->CNPU  = pGPIOHandle->pGPIOx->CNPD = 0;
        
        //configure the output level
        pGPIOHandle->pGPIOx->LAT |= pGPIOHandle->GPIOx_Config.GPIO_PinLatch << pGPIOHandle->GPIOx_Config.GPIO_PinNumber;
           
    }
    else
    {
        pGPIOHandle->pGPIOx->ANSEL |= GPIO_ANSEL_ON << pGPIOHandle->GPIOx_Config.GPIO_PinNumber;
    }
 
    
}
void GPIO_Pin_Direction(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber,uint8_t dir ){
    pGPIOx->TRIS |= dir << pinNumber; // 0 means output; 1 means input 

}

void GPIO_Pin_Pull(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber, uint8_t pull ){
    
    if(pull == ENABLE) // 1 means pull-up
     pGPIOx->CNPU |= 1 << pinNumber; // 0 means output; 1 means input 
    else
        pGPIOx->CNPD |= 1 << pinNumber;
}

void GPIO_Pin_AnalogMode(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber, uint8_t setting){


}

void GPIO_Pin_SetOutputLevel(GPIOx_RegDef_t * pGPIOx, uint8_t pinNumber, uint8_t level){
    if (level == GPIO_PIN_SET)
        pGPIOx->LAT |= level << pinNumber;
    else
        pGPIOx->LAT &= ~(1 << pinNumber);// negat ca sa avem 0 doar acolo

}

bool GPIO_Pin_Read(GPIOx_RegDef_t *pGPIOx,uint8_t pinNumber){
    bool value = false;
    value = pGPIOx->PORT >> pinNumber & 0x0001;
    return value;
}


void GPIO_Pin_ToggleOutput(GPIOx_RegDef_t *pGPIOx, uint8_t pinNumber){
    pGPIOx->LAT ^= 1<<pinNumber;

}