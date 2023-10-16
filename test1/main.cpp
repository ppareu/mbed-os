/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut led(LED1);

int main()
{
    printf("Hello, Mbed!\n");
    while (1)
    {
        led = 1;
        ThisThread::sleep_for(5000); // 5000이면 5초
        led = 0;
        ThisThread::sleep_for(1000); // 1000이면 1초
    }
    
    return 0;
}