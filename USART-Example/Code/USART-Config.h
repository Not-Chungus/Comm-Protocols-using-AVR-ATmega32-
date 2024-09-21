/*
 * USART_Config.h
 *
 * Created: 8/20/2024 3:21:20 AM
 *  Author: Ibrahim
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define F_CPU 8000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
 
void USART_Init(unsigned int ubrr) {
	UBRRH = (unsigned char)(ubrr >> 8); /*setting baud rate*/
	UBRRL = (unsigned char)ubrr;        
	UCSRB = (1<<RXEN) | (1<<TXEN); // Enable receiver and transmitter
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); // 8-bit data, 1 stop bit
}
//--------------------------------------------------------------------------------------

void USART_Transmit(unsigned char data) {
	while (!(UCSRA & (1<<UDRE))); // Wait for empty transmit buffer
	UDR = data; // Put data into buffer, sends the data
}
//--------------------------------------------------------------------------------------

unsigned char USART_Receive(void) {
	while (!(UCSRA & (1<<RXC))); // Wait for data to be received
	return UDR; // Get and return received data from buffer
	
	
}





#endif /* USART-CONFIG_H_ */