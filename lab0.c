// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      Stephen Nguyen
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRI & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )
//Removed PLL


typedef enum stateTypeEnum{
    //TODO: Define states by name
   
    LED1F, LED2F, LED3F, LED4F, LED1B, LED2B, LED3B, LED4B
    

} stateType;

volatile stateType curState;
volatile stateType nextState;

int main(void)
{
    
    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    while(1)
    {
        //Use a switch statement to define the behavior based on the state
        switch(curState){
            case(LED1F):
                LedSwitch(1);
                nextState = LED2F;
                break;
            case(LED2F):
                LedSwitch(2);
                nextState = LED3F;
                break;
            case(LED3F):
                LedSwitch(3);
                nextState = LED4F;
                break;
            case(LED4F):
                LedSwitch(4);
                nextState = LED1F;
                break;
            case(LED1B):
                LedSwitch(1);
                nextState = LED4B;
                break;
            case(LED2B):
                LedSwitch(2);
                nextState = LED1B;
                break;
            case(LED3B):
                LedSwitch(3);
                nextState = LED2B;
                break;
            case(LED4B):
                LedSwitch(4);
                nextState = LED3B;
                break;
            default:
                curState = LED1F;
                break;
        }
    }
    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB5 == 0){
        
        checkHold();
    }
    else if(PORTBbits.RB5 != 0){
        curState = nextState;
        
    }
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    //TODO: Change states if necessary.
    switch(curState){
        case(LED1F):
            nextState = LED1B;
            break;
        case(LED2F):
            nextState = LED2B;
            break;
        case(LED3F):
            nextState = LED3B;
            break;
        case(LED4F):
            nextState = LED4B;
            break;
        case(LED1B):
            nextState = LED1F;
            break;
        case(LED2B):
            nextState = LED2F;
            break;
        case(LED3B):
            nextState = LED3F;
            break;
        case(LED4B):
            nextState = LED4F;
            break;
    }
    
   
    //Make sure if you use any variables that they are declared volatile!
}

void checkHold(){
    T1CONbits.TON = 1; //Turn on timmer
    TMR1 = 0; //Please reset the timer counter back to zero....
    while(1){
        if(PORTBbits.RB5 != 0){
            T1CONbits.TON = 0; //Turn off timmer
            break;
        }
    }
    
}


void LedSwitch(int led){
    switch(led){
        case(1):
            LATBbits.LATB12 = 0;
            LATBbits.LATB13 = 1;
            LATBbits.LATB14 = 1;
            LATBbits.LATB15 = 1;
            break;
        case(2):
            LATBbits.LATB12 = 1;
            LATBbits.LATB13 = 0;
            LATBbits.LATB14 = 1;
            LATBbits.LATB15 = 1;
            break;
        case(3):
            LATBbits.LATB12 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB14 = 0;
            LATBbits.LATB15 = 1;
            break;
        case(4):
            LATBbits.LATB12 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB14 = 1;
            LATBbits.LATB15 = 0;
            break;
    }
}