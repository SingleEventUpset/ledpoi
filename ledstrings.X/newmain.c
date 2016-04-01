/*
 * File:   newmain.c
 * Author: mike
 *
 * Created on 14 January 2016, 11:07 PM
 */

#include <pic18f2455.h>
#include "config.h"


void delay(int delay) {
    for(int i = 0; i < delay; i++) {
        
    }
}

void halfOne() {
                    // 1
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
}

void one() {
                // 1
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
}

void halfZero() {
                // 0
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;

}

void zero() {
                // 0
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=1;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
            PORTAbits.RA0=0;
}

#define LED_COUNT 30
void main(void) {
    TRISA=0;
    TRISB=0;
    TRISC=0;
    PORTA=0xff;
    PORTB=0xff;
    PORTC=0xff;
    
    ADCON1=0b00001111;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1OSCEN = 0;
    
    const int ledCount = LED_COUNT;
    long ledColour[LED_COUNT];// = {0x00001f, 0x001f00, 0x1f0000, 0x00001f, 0x00001f, 0x00001f, 0x00001f, 0x00001f, 0x00001f, 0x00001f, 0x00001f, 0x00001f};
    
    for(int i = 0; i < ledCount; i++) {
        ledColour[i] = 0;
    }
    //ledColour[0] = 0x00ff01;
    
    int currentLed = 0;
    long changeDelay = 1;
    long changeDelayCounter = changeDelay;
    while(1) {
        /*
        for(int i = 0; i < ledCount; i++) {
//            ledColour[i]++;
            if(ledColour[i] > 0x1f1f1f) {
                ledColour[i] = 0x00ff00;
            }
        }
        */
        
        /*
        for(int i = 0; i < ledCount; i++) {
            if(ledColour[i] > 0) {
                ledColour[i]++;
            }
            
            if(ledColour[i] >= 0xffff) {
                ledColour[i] = 0;
                if(i < 11) {
                    ledColour[i + 1] = 0x00ff01;
                } else {
                    ledColour[0] = 0x00ff01;
                }
            }
        }
         */
        
    
        if(changeDelayCounter-- <= 0) {
            //ledColour[0]++;
            ledColour[currentLed] <<= 1;
            ledColour[currentLed] += 1;
            changeDelayCounter = changeDelay;
        }
        if(ledColour[currentLed] >= 0xffffff) {
            ledColour[currentLed] = 0;
            currentLed++;
            if(currentLed >= ledCount) {
                currentLed = 0;
            }
        }

        for(int ledIndex = 0; ledIndex < 30; ledIndex++) {
            long tempColour = ledColour[ledIndex];
            ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();

            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();

            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();

            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();

            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();

            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
            tempColour >>= 1; ((tempColour & 1) == 0) ? zero() : one();
        }
        
        for(int i = 0; i < 1000; i++) {
            PORTAbits.RA0=0;
        }
        
        
    }
 
    return;
}
