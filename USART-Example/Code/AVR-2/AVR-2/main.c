/*
 * AVR-2.c
 *
 * Created: 8/20/2024 3:33:09 AM
 * Author : Ibrahim
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../../USART-Config.h"


int main(void)
{
    DDRA = 0xFF; // Set PORTA as output
    USART_Init(MYUBRR);
    while (1) 
    {
		PORTA = USART_Receive();
    }
}

