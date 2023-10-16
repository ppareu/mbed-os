/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Encoder.h"

DigitalOut led1 (LED1);
Encoder enco(D2, D13);

int main()
{
    enco.init();
    enco.setCount(0);
    while(1) {
        printf("count= %ld , %ld\n", enco.getCount(), enco.getErrorCount());
        led1 = !led1;
        ThisThread::sleep_for(1000);
    }
}