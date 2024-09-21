/*
 * AVR-1.c
 *
 * Created: 8/20/2024 3:20:39 AM
 * Author : Ibrahim
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../../USART-Config.h"

//This is the switch AVR
int main(void)
{
    DDRA = 0x00;
	USART_Init(MYUBRR);
    while (1) 
    {
		USART_Transmit(PINA);
		 _delay_ms(50);
    }
}

