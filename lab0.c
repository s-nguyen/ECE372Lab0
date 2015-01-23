// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
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

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{
    //TODO: Define states by name
    //test
    forwardstage1,
    forwardstage2,
    forwardstage3,
    forwardstage4,
    backwardstage1,
    backwardstage2,
    backwardstage3,
    backwardstage4


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
            case(forwardstage1):

                if(PORTBbits.RB5 == 0){
                    LATBbits.LATB12 = 0;
                    LATBbits.LATB13 = 1;
                    LATBbits.LATB14 = 1;
                    LATBbits.LATB15 = 1;
                    nextState = forwardstage2;
                }
                else
                    nextState = forwardstage1;                
                break;
            case(forwardstage2):
                if(PORTBbits.RB5 == 0){
                    LATBbits.LATB12 = 1;
                    LATBbits.LATB13 = 0;
                    LATBbits.LATB14 = 1;
                    LATBbits.LATB15 = 1;
                    nextState = forwardstage3;
                }
                else
                    nextState = forwardstage2;
                break;
            case(forwardstage3):
                if(PORTBbits.RB5 == 0){
                    LATBbits.LATB12 = 1;
                    LATBbits.LATB13 = 1;
                    LATBbits.LATB14 = 0;
                    LATBbits.LATB15 = 1;
                    nextState = forwardstage4;
                }
                else
                    nextState = forwardstage3;
                break;
            case(forwardstage4):
                if(PORTBbits.RB5 == 0){
                    LATBbits.LATB12 = 1;
                    LATBbits.LATB13 = 1;
                    LATBbits.LATB14 = 1;
                    LATBbits.LATB15 = 0;
                    nextState = forwardstage1;
                }
                else
                    nextState = forwardstage4;
                break;
            case(backwardstage1):
                break;
            case(backwardstage2):
                break;
            case(backwardstage3):
                break;
            case(backwardstage4):
                break;
            default:
                curState = forwardstage1;
        }
    }
    return 0;
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;

    //TODO: Change states if necessary.
    curState = nextState;
    //Make sure if you use any variables that they are declared volatile!
}