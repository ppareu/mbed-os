/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

int main()
{
    while(1)
    {
        printf("Hello, Mbed!\n");
        ThisThread::sleep_for(1000);
    }
}