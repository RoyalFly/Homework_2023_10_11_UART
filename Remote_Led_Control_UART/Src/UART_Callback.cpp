//
// Created by 98383 on 2023/10/1.
//

#include "main.h"
#include "usart.h"

extern uint8_t re_data;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  //if (huart->Instance == UART8){
    HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_1);
    HAL_UART_Receive_IT(huart,&re_data,1);
  //}
}
