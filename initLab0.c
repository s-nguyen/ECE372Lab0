/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;

   
    //TODO: Turn each LED OFF
    LATBbits.LATB12 = 1; //Near Button
    LATBbits.LATB13 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 1;
    
}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
    TRISBbits.TRISB5 = 1;
}


void initTimer1(){
    //TODO: Initialize the timer
    T1CONbits.TON = 1;
    // What to do? On the refference page 125
    //Prescaler at 1:1

}