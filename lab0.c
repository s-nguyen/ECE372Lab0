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


    LED1F, LED2F, LED3F, LED4F //F for forward B for backwards


} stateType;


volatile stateType curState;
volatile stateType nextState;

int main(void)
{
    initLEDs();
    initTimer1();
    initSW1();
    while(1)
    {
        if(PORTBbits.RB5 != 0){
            switch(curState){
            case(LED1F):
                LedSwitch(4);
                nextState = LED2F;
                break;
            case(LED2F):
                LedSwitch(3);
                nextState = LED3F;
                break;
            case(LED3F):
                LedSwitch(2);
                nextState = LED4F;
                break;
            case(LED4F):
                LedSwitch(1);
                nextState = LED1F;
                break;
            default:
                curState = LED1F;
                break;
             }
        }

    }
    return 0;
}

void _ISR _CNInterrupt(void){
     TMR1 = 0; //Please reset the timer counter back to zero....
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB5 == 0){
      T1CONbits.TON = 1; //Turn on timmer
      TMR1 = 0; //Please reset the timer counter back to zero....
    }
    else if(PORTBbits.RB5 == 1){
        T1CONbits.TON = 0;
        curState = nextState;
    }
  
}

void _ISR _T1Interrupt(void){
    //Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    switch(curState){
        case(LED1F):
            nextState = LED4F;
            break;
        case(LED2F):
            nextState = LED1F;
            break;
        case(LED3F):
            nextState = LED2F;
            break;
        case(LED4F):
            nextState = LED3F;
            break;
    }

    //Make sure if you use any variables that they are declared volatile!
}

