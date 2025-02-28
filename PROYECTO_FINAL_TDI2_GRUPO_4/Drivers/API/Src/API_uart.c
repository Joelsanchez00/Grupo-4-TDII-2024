/******************************************************************************************************
 * API_uart.c
 *
 *  Created on         : NOV 4, 2024
 *  Author             : Joel Sanchez
 *****************************************************************************************************/

/* Includes ************************************************************************/
#include "main.h"
#include "API_uart.h"
#include <string.h>
/*Defines *************************************************************************/

/*Declaration of variables ********************************************************/
static UART_HandleTypeDef huart3;
/*** Function definition ***********************************************************/

/**
  * @brief FUNCION ANTEREBOTE
  * @param debounceInit
  * @retval None
  */

bool uartInit() {
    // Inicialización de USART3
    if (HAL_UART_Init(&huart3) != HAL_OK) {
    	Error_Handler();
        return false; // Error en la inicialización
    }

    // Enviar mensaje de confirmación
    uint8_t message[] = "UART initialized successfully\r\n";
    HAL_UART_Transmit(&huart3, message, sizeof(message), HAL_MAX_DELAY);

    return true;
}

void uartSendString(uint8_t *pstring) {
    HAL_UART_Transmit(&huart3, pstring, strlen((char*)pstring), HAL_MAX_DELAY);
}

void uartSendStringSize(uint8_t *pstring, uint16_t size) {
    HAL_UART_Transmit(&huart3, pstring, size, HAL_MAX_DELAY);
}

void uartReceiveStringSize(uint8_t *pstring, uint16_t size) {
    // Implementación de la recepción
    // Utilizar HAL_UART_Receive() con timeout para evitar bloqueos
    // Manejar errores y condiciones de timeout
    HAL_StatusTypeDef status = HAL_UART_Receive(&huart3, pstring, size, HAL_MAX_DELAY);
    if (status != HAL_OK) {
    	// Manejo de error, por ejemplo, imprimir un mensaje de error o reiniciar el dispositivo
    	        Error_Handler();
    }
}
