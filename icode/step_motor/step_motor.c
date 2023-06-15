/*
 * step_motor.c
 *
 *  Created on: May 7, 2023
 *      Author: wzw
 */
#include "step_motor.h"

// 定义ULN2003所连接的引脚
#define IN1_PIN GPIO_PIN_0
#define IN2_PIN GPIO_PIN_15
#define IN3_PIN GPIO_PIN_14
#define IN4_PIN GPIO_PIN_13

// 定义步进电机每个步进的延迟时间
#define STEP_DELAY_MS 1

// 定义每个阶段的控制信号
const uint8_t StepSequence[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};

// 定义电机的当前状态
volatile bool motor_running = false;

// 向步进电机发送下一个步进脉冲
void StepMotor(bool forward)
{
  static uint8_t sequence_index = 0;
  if (forward)
  {
    sequence_index = (sequence_index + 1) & 0x07;
  }
  else
  {
    sequence_index = (sequence_index - 1) & 0x07;
  }
  uint8_t sequence = StepSequence[sequence_index];

  // 控制ULN2003的引脚
  HAL_GPIO_WritePin(GPIOD, IN1_PIN, (sequence & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, IN2_PIN, (sequence & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, IN3_PIN, (sequence & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, IN4_PIN, (sequence & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  // 延迟一段时间
  HAL_Delay(STEP_DELAY_MS);
}

// 启动电机
void StartMotor(bool forward)
{
  motor_running = true;
  while (motor_running)
  {
    StepMotor(forward);
  }
}

// 停止电机
void StopMotor()
{
  motor_running = false;
}

// 正转函数
void Forward()
{
  StartMotor(true);
}

// 反转函数
void Reverse()
{
  StartMotor(false);
}
void Forward_turn_step(int step){
  while (step--)
  {
    StepMotor(true);
  }
}
void Reverse_turn_step(int step){
  while (step--)
  {
    StepMotor(false);
  }
}

