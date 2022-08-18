
/**
 * @file main.c
 * @author Ahmed Mohamed
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "uart.h"
#include "std_types.h"
int main(void)
{
    // initialize the UART module
    SWUART_init(9600);
    uint8 data;
    // set data to A and send it
    data = 'A';
    SWUART_send(data);

    
    /* Replace with your application code */
    while (1)
    {
    }
}