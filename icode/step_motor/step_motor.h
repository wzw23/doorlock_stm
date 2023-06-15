/*
 * step_motor.h
 *
 *  Created on: May 7, 2023
 *      Author: wzw
 */
#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H
#include "stm32l4xx_hal.h"
#include "main.h"
#include <stdbool.h>
void StepMotor(bool forward);
void StartMotor(bool forward);
void StopMotor();
void Forward();
void Reverse();
void Forward_turn_step(int step);
void Reverse_turn_step(int step);
#endif


