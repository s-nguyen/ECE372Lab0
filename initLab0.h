/* 
* File:   initLab0.h
* Author: Stephen Nguyen
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef INITLAB0_H
#define	INITLAB0_H


//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12
#define INPUT 1
#define OUTPUT 0

#define OFF 1;
#define ON 0;

void initLEDs();
void initSW1();
void initTimer1();

//new
void checkHold();
void LedSwitch(int led);


#endif	/* INITLAB0_H */

