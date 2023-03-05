/*
 * File:   newmainXC16.c
 * Author: Edyson
 *
 * Created on February 26, 2023, 1:25 PM
 */

// DSPIC33CK256MP508 Configuration Bit Settings

// 'C' source line config statements

// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
#pragma config BSLIM = 0x1FFF           // Boot Segment Flash Page Address Limit bits (Enter Hexadecimal value)

// FSIGN

// FOSCSEL
#pragma config FNOSC = FRCDIVN          // Oscillator Source Selection (Internal Fast RC (FRC) Oscillator with postscaler)
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)
#pragma config PLLKEN = ON              // PLL Lock Status Control (PLL lock signal will be used to disable PLL clock output if lock is lost)
#pragma config XTCFG = G3               // XT Config (24-32 MHz crystals)
#pragma config XTBST = ENABLE           // XT Boost (Boost the kick-start)

// FWDT
#pragma config RWDTPS = PS2147483648    // Run Mode Watchdog Timer Post Scaler select bits (1:2147483648)
#pragma config RCLKSEL = LPRC           // Watchdog Timer Clock Select bits (Always use LPRC)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer operates in Window mode)
#pragma config WDTWIN = WIN50           // Watchdog Timer Window Select bits (WDT Window is 50% of WDT period)
#pragma config SWDTPS = PS16777216      // Sleep Mode Watchdog Timer Post Scaler select bits (1:16777216)
#pragma config FWDTEN = ON_SW           // Watchdog Timer Enable bit (WDT controlled via SW, use WDTCON.ON bit)

// FPOR
#pragma config BISTDIS = DISABLED       // Memory BIST Feature Disable (mBIST on reset feature disabled)

// FICD
#pragma config ICS = PGD3               // ICD Communication Channel Select bits (Communicate on PGC3 and PGD3)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config NOBTSWP = DISABLED       // BOOTSWP instruction disable bit (BOOTSWP instruction is disabled)

// FDMTIVTL
#pragma config DMTIVTL = 0xFFFF         // Dead Man Timer Interval low word (Enter Hexadecimal value)

// FDMTIVTH
#pragma config DMTIVTH = 0xFFFF         // Dead Man Timer Interval high word (Enter Hexadecimal value)

// FDMTCNTL
#pragma config DMTCNTL = 0xFFFF         // Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Enter Hexadecimal value)

// FDMTCNTH
#pragma config DMTCNTH = 0xFFFF         // Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Enter Hexadecimal value)

// FDMT
#pragma config DMTDIS = OFF             // Dead Man Timer Disable bit (Dead Man Timer is Disabled and can be enabled by software)

// FDEVOPT
#pragma config ALTI2C1 = OFF            // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins)
#pragma config ALTI2C3 = OFF            // Alternate I2C3 Pin bit (I2C3 mapped to SDA3/SCL3 pins)
#pragma config SMBEN = SMBUS            // SM Bus Enable (SMBus input threshold is enabled)
#pragma config SPI2PIN = PPS            // SPI2 Pin Select bit (SPI2 uses I/O remap (PPS) pins)

// FALTREG
#pragma config CTXT1 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)
#pragma config CTXT3 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits (Not Assigned)
#pragma config CTXT4 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits (Not Assigned)

// FBTSEQ
#pragma config BSEQ = 0xFFF             // Relative value defining which partition will be active after device Reset; the partition containing a lower boot number will be active (Enter Hexadecimal value)
#pragma config IBSEQ = 0xFFF            // The one's complement of BSEQ; must be calculated by the user and written during device programming. (Enter Hexadecimal value)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define FCY 4000000ul
#include <libpic30.h>
#include <xc.h>



#include "xc.h"
#include "dspic_h.h"
#include "gpio_driver.h"

int main(void) {

    Nop();
        Nop();
        
    GPIOx_Handle_t GPIO_LED;
    GPIO_LED.pGPIOx = PORTE_REGS;
    GPIO_LED.GPIOx_Config.GPIO_PinAnalog = GPIO_ANSEL_OFF;
    GPIO_LED.GPIOx_Config.GPIO_PinDirection = GPIO_PIN_OUTPUT;
    GPIO_LED.GPIOx_Config.GPIO_PinNumber = 5;
    GPIO_LED.GPIOx_Config.GPIO_PinPull = GPIO_NO_PULL;
    GPIO_LED.GPIOx_Config.GPIO_PinLatch = GPIO_PIN_SET;
    
    
    GPIOx_Handle_t GPIO_BTN;
    GPIO_BTN.pGPIOx = PORTE_REGS;
    GPIO_BTN.GPIOx_Config.GPIO_PinAnalog = GPIO_ANSEL_OFF;
    GPIO_BTN.GPIOx_Config.GPIO_PinDirection = GPIO_PIN_INPUT;
    GPIO_BTN.GPIOx_Config.GPIO_PinNumber = 9;
    GPIO_BTN.GPIOx_Config.GPIO_PinPull = GPIO_NO_PULL;
//    GPIO_BTN.GPIOx_Config.GPIO_PinLatch = GPIO_PIN_SET;n 
    
    
    GPIO_Init(&GPIO_LED);
    GPIO_Init(&GPIO_BTN);
    

    while (1) {
        if (!GPIO_Pin_Read(GPIO_BTN.pGPIOx,GPIO_BTN.GPIOx_Config.GPIO_PinNumber) ) 
        {
            __delay_ms(300);
            GPIO_Pin_ToggleOutput(GPIO_LED.pGPIOx, GPIO_LED.GPIOx_Config.GPIO_PinNumber);
        
        }
        Nop();
        Nop();

    }
}
