/*
* File:   initLab0.c
* Author: Stephen Nguyen
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define FOCS  7372800.0
#define FCY  3686400.0//FOCS/2
#define TIME  2.0 //seconds


void initLEDs(){
  
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;

   
   //Turned off all LED
    LATBbits.LATB12 = 1; //Near Button
    LATBbits.LATB13 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 1;
    
}

void initSW1(){
    TRISBbits.TRISB5 = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    CNEN2bits.CN27IE = 1;
}


void initTimer1(){
    unsigned int prVal = (FCY*TIME)/256.0 - 1.0;
    PR1 = prVal; //PRVAL //2 Seconds

    TMR1 = 0; //Reset the counter to 0
    T1CONbits.TCKPS = 0b11; //1:256 prescale Value
    IFS0bits.T1IF = 0; //Put down flag first
    IEC0bits.T1IE = 1; //Enable Timer Interrupt at start
    T1CONbits.TON = 0; //Turn off  timer
}


