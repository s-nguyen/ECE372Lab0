/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define CLOCKRATE = 7372800
#define SOSCATATE = 32768
#define PLL = 2
#define FCY = CLOCKRATE*PLL
#define TIME = 2 //In Seconds
#define PRVAL = (FCY*TIME)/256

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
   

    TMR1 = 0;
    PR1 = 500; //Change

  

    T1CONbits.TON = 1; //Turn on timer
    T1CONbits.TCKPS = 0b11; //1:256 prescale Value
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1; //Enable Timer Interrupt
}
