/*******************************************************************************************************
 * API_GPIO.h
 *
 *  Created on         : NOV 26, 2024
 *  Author             : Joel Sanchez
 *  Function of driver : Driver que contiene funciones anti rebote que utiliza funciones
 *  					 de la HAL de STM32 Nucleo F4xx
 ******************************************************************************************************/

#ifndef API_API_DEBOUNCE_H_
#define API_API_DEBOUNCE_H_
#define DEBOUNCE_DELAY 40
/* Includes *******************************************************************************/
#include <stdint.h> /*Para poder usar el tipo uint16_t en mi nueva definición de tipo led_t*/
#include <stdbool.h> /*Para poder definir el tipo buttonStatus_t que será boolean*/

/* Exported types *************************************************************************/
typedef enum {
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RISING
} debounceState_t;
/* Exported functions prototypes **********************************************************/
bool readKey();
void debounceInit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void debounceUpdate(void);
debounceState_t getButtonState(void);

#endif /* API_API_DEBOUNCE_H_ */
