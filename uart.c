/**
 * @file sw_uart.c
 * @author Ahmed Mohamed
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "uart.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;


/**
 * @brief Initialize the UART module
 * 
 * @param baudRate The baud rate of the UART module
 */
void SWUART_init(uint32_t baudrate){
    uint32_t baud_prescale = (((F_CPU / (baudrate * 16UL))) - 1);
    /* Set the baud rate */
    UBRR0H = (uint8_t)(baud_prescale>>8);
    UBRR0L = (uint8_t)baud_prescale;
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    // Set frame format: 8 data, 2 stop bit 
    UCSR0C = (1<<USBS0)|(3<<UCSZ00)|(1<<UPM01) | (1<<UPM00);
    // Disenable receive interrupt 
    UCSR0B &= ~(1<<RXCIE0);
}
/**
 * @brief Send a byte through the UART module
 * 
 * @param data The byte to be sent
 */
void SWUART_send(uint8_t data){
    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
    UDR0 = data;//send the data
}
/**
 * @brief Receive a byte through the UART module
 * 
 * @return The byte received
 */
void SWUART_recieve(uint8_t *data){
    /*
    Use this to recieve a single byte, it will split it up into individual parts
    send those parts, and then send the new line code
    */
    while ((UCSR0A & (1 << RXC0)) == 0);//make sure the data register is cleared
    *data = UDR0; //goes through and splits the string into individual bits, sends them
}
/**
 * @brief set the call back function for the UART module
 * 
 * @param callBackPtr The address of the call back function
 */
void int_setCallBack(void(*callBackPtr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = callBackPtr;
}
/**
 * @brief Interrupt service routine for the UART module
 * 
 */
ISR(USART0_RX_vect){
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)();
	}
}