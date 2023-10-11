//
// Created by 98383 on 2023/9/30.
//

#include "main.h"
#include "usart.h"

void UART_Send_Message(uint8_t flag);

void Led1_Control();

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN) { // 按一次发一个包
  if (GPIO_PIN == GPIO_PIN_2) {
    Led1_Control();
  }
}

void Led1_Control() {
  static bool led1_state = false; // 默认LED状态为关闭
  if (led1_state) {
    UART_Send_Message(0); // 若为打开，向另一块板传入0即关闭信号
  } else {
    UART_Send_Message(1); // 传入1为开启信号
  }
  led1_state = !led1_state;
}

void UART_Send_Message(uint8_t flag) { // 发送开关信号，0为关信号，1为开信号
  static int d = 0;
  uint8_t data = 0;
  d++;
  data = flag;
  HAL_UART_Transmit_IT(&huart8, &data, 1);
}
