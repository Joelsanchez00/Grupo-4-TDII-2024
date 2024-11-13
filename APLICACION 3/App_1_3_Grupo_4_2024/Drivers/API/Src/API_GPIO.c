/******************************************************************************************************
 * API_GPIO.c
 *
 *  Created on         : SEP 15, 2024
 *  Author             : Joel Sanchez
 *****************************************************************************************************/

/* Includes ************************************************************************/
#include "main.h"
#include "API_GPIO.h"

/*Defines *************************************************************************/

/*Declaration of variables ********************************************************/
//Valores esperados para LDx: LD1_Pin|LD3_Pin|LD2_Pin
led_t LDx;
bool botonPresionado = false;
uint32_t tiempoUltimoCambio = 0;
uint8_t secuenciaActual = 0;
uint8_t numeroTotalSecuencias = 5; // numero de secuenias
/*** Function definition ***********************************************************/
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/**
  * @brief GPIO Led on Function
  * @param led_t LDx
  * @retval None
  */
void writeLedOn_GPIO(led_t LDx)
{
	HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_SET);
}

/**
  * @brief GPIO Led off Function
  * @param led_t LDx
  * @retval None
  */
void writeLedOff_GPIO(led_t LDx)
{
	HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_RESET);
}

/**
  * @brief GPIO toggle Led Function
  * @param led_t LDx
  * @retval None
  */
void toggleLed_GPIO(led_t LDx)
{
	HAL_GPIO_TogglePin(GPIOB, LDx);
}

/**
  * @brief GPIO read button Function
  * @param none
  * @retval Button Status: True if On, False if Off
  */
buttonStatus_t readButton_GPIO(void)
{
	return HAL_GPIO_ReadPin(GPIOC, USER_Btn_Pin);
}

/**
  * @brief: FUNCION NO BLOQUEANTE
  * @param: none
  * @retval Button Status: La función actualiza las variables globales
  */
void delayInit(delay_t *delay, tick_t duration) {
    delay->startTime = 0;
    delay->duration = duration;
    delay->running = false;
}
bool_t delayRead(delay_t *delay) {
    if (!delay->running) {
        delay->startTime = HAL_GetTick();
        delay->running = true;
        return false; // Retorna falso al iniciar el retardo
            } else {
                if (HAL_GetTick() - delay->startTime >= delay->duration) {
                    delay->running = false;
                    return true; // Retorna verdadero al finalizar el retardo
                } else {
                    return false; // Retorna falso si el retardo aún no ha finalizado
                }
            }
        }
void delayWrite(delay_t *delay, tick_t duration) {
    delay->duration = duration;
}

/**
  * @brief Secuencia de delay
  * @param none
  * @retval Button Status: tiempo de delay
  */
secuenciadelay_t secuencias[] = {
	{150, 150, 0},
	{300, 300},
	{100, 300, 600},
	{150, 150, 10}
};

uint8_t secuenciaIndices[] = {0, 1, 2, 3};

/**
  * @brief:Lee el estado de un botón y actualiza la secuencia actual si se detecta una pulsación válida.
  * @param: none
  * @retval Button Status: La función actualiza las variables globales: botonPresionado, tiempoUltimoCambio, secuenciaActual
  */
void BOTONCTR (){

	bool BOTONCTR = HAL_GPIO_ReadPin(GPIOC, USER_Btn_Pin) == GPIO_PIN_RESET;
	    if (BOTONCTR && !botonPresionado && HAL_GetTick() - tiempoUltimoCambio > 10) {
	        secuenciaActual = (secuenciaActual + 1) % numeroTotalSecuencias;
	        if (secuenciaActual == 0) {
	            secuenciaActual = 1;
	        }
	        tiempoUltimoCambio = HAL_GetTick();
	        botonPresionado = true;
	    } else if (!BOTONCTR) {
	        botonPresionado = false;
	    }
}
