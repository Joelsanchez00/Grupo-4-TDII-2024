/******************************************************************************************************
 * API_GPIO.c
 *
 *  Created on         : NOV 26, 2024
 *  Author             : Joel Sanchez
 *****************************************************************************************************/

/* Includes ************************************************************************/
#include "main.h"
#include "API_debounce.h"

/*Defines *************************************************************************/
/*Declaration of variables ********************************************************/
static GPIO_TypeDef* debouncePinGPIOx;
static uint16_t debouncePinPin;
static uint32_t debounceTimer;
static debounceState_t buttonState = BUTTON_UP;
static bool flagFlancoDescendente = false;
/*** Function definition ***********************************************************/

/**
  * @brief FUNCION ANTEREBOTE
  * @param debounceInit
  * @retval None
  */
void debounceInit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    // Inicializar el GPIO para leer el estado del botón
    debouncePinGPIOx = GPIOC;
    debouncePinPin = USER_Btn_Pin;

    // Configurar el GPIO como entrada
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = debouncePinPin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    // ... Otras configuraciones según tu MCU

    HAL_GPIO_Init(debouncePinGPIOx, &GPIO_InitStruct);

    // Inicializar el temporizador (si es necesario)
    debounceTimer = HAL_GetTick();
}

void debounceUpdate(void) {
    static uint32_t previousButtonValue = 0;
    uint32_t currentButtonValue = HAL_GPIO_ReadPin(debouncePinGPIOx, debouncePinPin);

    // Detectar flanco descendente
    if (currentButtonValue == GPIO_PIN_RESET && previousButtonValue == GPIO_PIN_SET) {
        flagFlancoDescendente = true;
        debounceTimer = HAL_GetTick();
    }

    // Si ha pasado el tiempo de debounce y se detectó un flanco descendente
    if (flagFlancoDescendente && HAL_GetTick() - debounceTimer > DEBOUNCE_DELAY) {
        buttonState = BUTTON_DOWN;
        flagFlancoDescendente = false; // Reiniciar el flag
    } else if (currentButtonValue == GPIO_PIN_SET) {
        buttonState = BUTTON_UP;
        flagFlancoDescendente = false; // Reiniciar el flag en caso de que el botón se suelte
    }

    previousButtonValue = currentButtonValue;
}

bool readKey() {
    bool keyPressed = false;
    if (buttonState == BUTTON_DOWN) {
        keyPressed = true;
        buttonState = BUTTON_UP; // Restablecer el estado del botón
    }
    return keyPressed;
}

debounceState_t getButtonState(void) {
    return buttonState;
}
