/*******************************************************************************************************
 * API_GPIO.h
 *
 *  Created on         : SEP 15, 2024
 *  Author             : Joel Sanchez
 *  Function of driver : Driver que contiene funciones para manejo de puertos GPIO que utiliza funciones
 *  					 de la HAL de STM32 Nucleo F4xx
 ******************************************************************************************************/

#ifndef API_INC_API_GPIO_H_
#define API_INC_API_GPIO_H_


/* Includes *******************************************************************************/
#include <stdint.h> /*Para poder usar el tipo uint16_t en mi nueva definición de tipo led_t*/
#include <stdbool.h> /*Para poder definir el tipo buttonStatus_t que será boolean*/

/* Exported types *************************************************************************/
typedef uint16_t led_t;  /*Importante que el tipo sea uint16_t, si no, no funciona LD3_Pin*/
typedef bool buttonStatus_t;
typedef struct {
    uint16_t tiempo_encendido;
    uint16_t tiempo_apagado;
    uint16_t tiempo_extra;

} secuenciadelay_t;
typedef uint32_t tick_t;
typedef bool bool_t;
typedef struct {
    tick_t startTime;
    tick_t duration;
    bool_t running;
} delay_t;
/* Exported functions prototypes **********************************************************/
void MX_GPIO_Init(void);
void writeLedOn_GPIO(led_t LDx);
void writeLedOff_GPIO(led_t LDx);
void toggleLed_GPIO(led_t LDx);
void delayInit(delay_t *delay, tick_t duration);
bool_t delayRead(delay_t *delay);
void delayWrite(delay_t *delay, tick_t duration);
buttonStatus_t readButton_GPIO(void);
extern bool botonPresionado;
extern uint32_t tiempoUltimoCambio;
extern uint8_t secuenciaActual;
extern uint8_t numeroTotalSecuencias;
extern secuenciadelay_t secuencias[];
#endif /* API_INC_API_GPIO_H_ */
