/*******************************************************************************************************
 * API_GPIO.h
 *
 *  Created on         : Nov 4, 2024
 *  Author             : Joel Sanchez
 *  Function of driver : Driver que contiene funcions Uart
 ******************************************************************************************************/
#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

/* Includes *******************************************************************************/
#include <stdint.h> /*Para poder usar el tipo uint16_t en mi nueva definición de tipo led_t*/
#include <stdbool.h>

/* Exported types *************************************************************************/


/* Exported functions prototypes **********************************************************/
bool uartInit();
void uartSendString(uint8_t *pstring);
void uartSendStringSize(uint8_t *pstring, uint16_t size);
void uartReceiveStringSize(uint8_t *pstring, uint16_t size);

#endif /* API_INC_API_UART_H_ */
