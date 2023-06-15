/*
 * 4x4key.c
 *
 *  Created on: Apr 20, 2023
 *      Author: wzw
 */
#include "4x4key.h"

#define ROWS 4
#define COLS 4

//GPIO_TypeDef* row_ports[ROWS] = {GPIOB, GPIOB, GPIOF, GPIOF};
//uint16_t row_pins[ROWS] = {GPIO_PIN_11, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_13};
//GPIO_TypeDef* col_ports[COLS] = {GPIOC, GPIOA, GPIOB, GPIOB};
//uint16_t col_pins[COLS] = {GPIO_PIN_1, GPIO_PIN_1, GPIO_PIN_0, GPIO_PIN_1};

GPIO_TypeDef* row_ports[ROWS] = {GPIOC, GPIOA, GPIOB, GPIOB};
uint16_t row_pins[ROWS] = {GPIO_PIN_1, GPIO_PIN_1, GPIO_PIN_0, GPIO_PIN_1};
GPIO_TypeDef* col_ports[COLS] ={GPIOB, GPIOB, GPIOF, GPIOD};
uint16_t col_pins[COLS] = {GPIO_PIN_11, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_1};

//void key4x4_Init(void)//错误输出得开始设置为高电平 此处直接用cubemx设置
//{
//  GPIO_InitTypeDef GPIO_InitStruct;
//
//  // 配置行引脚为输入模式，上拉
//  for (int i = 0; i < ROWS; i++) {
//    GPIO_InitStruct.Pin = row_pins[i];
//    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(row_ports[i], &GPIO_InitStruct);
//  }
//
//  // 配置列引脚为输出模式
//  for (int i = 0; i < COLS; i++) {
//    GPIO_InitStruct.Pin = col_pins[i];
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull=GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(col_ports[i], &GPIO_InitStruct);
//  }
//}

int read_keypad(void)
{
  int key = -1; // 默认未按下按键

  // 扫描行
  for (int i = 0; i < ROWS; i++) {
    HAL_GPIO_WritePin(col_ports[i], col_pins[i], GPIO_PIN_RESET); // 将列引脚置低
    for (int j = 0; j < COLS; j++) {
      if (HAL_GPIO_ReadPin(row_ports[j], row_pins[j]) == GPIO_PIN_RESET) { // 检测行引脚是否被拉低
    	HAL_Delay(10);
        while (HAL_GPIO_ReadPin(row_ports[j], row_pins[j]) == GPIO_PIN_RESET);
        //key = i * COLS + j; // 计算按键的索引
        key = j * ROWS + i;
        break;
      }
    }
    HAL_GPIO_WritePin(col_ports[i], col_pins[i], GPIO_PIN_SET); // 恢复列引脚高电平
  }

  return key;
}

//int main(void)
//{
//  HAL_Init(); // 初始化HAL库
//  MX_GPIO_Init(); // 配置GPIO引脚
//
//  while (1) {
//    int key = read_keypad(); // 读取按键值
//    if (key != -1) {
//      // 按键被按下，执行相应操作
//      // 根据key值判断具体是哪个按键被按下，进行相应处理
//    }
//  }
//}


