#include <msp430.h> 

// declarations
void init();

// variables
char commutation_table[6]={};

/*
 * main.c
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	return 0;
}

void init(){

	// set up the clock
	WDTCTL = CALDCO_16MHZ;
	BSCTL1 = CALBC1_16MHZ;

	// set up port 4 for timer counter
	P4SEL |= 0x7F; //set the pins to be used with the timer B including TBOUT, pins 0-6
	P4DIR |= 0x7F; //set the output direction

	// set up port 1 for the hall sensor input
	P1SEL &= 0x1F; //set up the input pins to be i-o pins P1.7,6,5
	P1DIR &= 0x1F; // set the i-o pins to be in direction

	// set up the timer B
	TBCTL = 0x7A30;
}
