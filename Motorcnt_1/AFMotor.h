#ifndef AFMotor_H
#define AFMotor_H

#include "mbed.h"

void Motorcnt(bool dir, int stepNum);
void oneStep(bool dir, int* prevStep);

#endif
