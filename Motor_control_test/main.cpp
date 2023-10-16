/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "AFMotor.h"

AF_DCMotor motor_1(1);     // 모터 1 객체         
 
 
void setup() {
  motor_1.setSpeed(255);    // 모터 1 속도 설정          
  motor_1.run(RELEASE);     // 모터 1 돌리지 않는 상태
}

int main()
{
    motor_1.run(FORWARD);    // 정방향으로 회전
    ThisThread::sleep_for(1000);
    motor_1.run(RELEASE);    // 쉬기
    ThisThread::sleep_for(1000);
    motor_1.run(BACKWARD);   // 역방향 회전
    ThisThread::sleep_for(1000);
    motor_1.run(RELEASE);    // 쉬기
    ThisThread::sleep_for(1000);
}