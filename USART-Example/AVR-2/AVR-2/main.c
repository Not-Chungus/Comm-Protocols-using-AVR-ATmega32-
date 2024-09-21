/*
 * AVR-2.c
 *
 * Created: 8/20/2024 3:33:09 AM
 * Author : Ibrahim
 */ 

#include <avr/io.h>
#include "../../USART-Config.h"


int main(void)
{
    DDRD |= (1<<2); // Set PB0 as output
    USART_Init(MYUBRR);
    while (1) 
    {
		if(USART_Receive() == 0x01)
			PORTD |= 1<<2;
		else 
			PORTD &= ~(1<<2); // Turn off LED
    }
}

