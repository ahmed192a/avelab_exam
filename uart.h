/**
 * @file uart.h
 * @author Ahmed Mohamed
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

//-------------------------------------------
//Macros (defines)
//-------------------------------------------

#define DEBUG 0
//-------------------------------------------
//Prototypes
//-------------------------------------------
/**
 * @brief Initialize the UART module
 * 
 * @param baudRate The baud rate of the UART module
 */
void SWUART_init(uint32_t baudrate);
/**
 * @brief Send a byte through the UART module
 * 
 * @param data The byte to be sent
 */
void SWUART_send(uint8_t data);
/**
 * @brief Receive a byte through the UART module
 * 
 * @return The byte received
 */
void SWUART_recieve(uint8_t *data);
/**
 * @brief set the call back function for the UART module
 * 
 * @param callBackPtr The address of the call back function
 */
void int_setCallBack(void(*a_ptr)(void));





#endif /* MCAL_UART_UART_H_ */