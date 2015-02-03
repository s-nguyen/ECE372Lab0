
#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>


//LED Switching Function
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