#ifndef _AFMotor_h_
#define _AFMotor_h_

#include <inttypes.h>
#if defined(STM32F4) // STM32F4 시리즈를 대상으로 함
    #include "stm32f4xx_hal.h"

    //#define MOTORDEBUG 1

    #define MICROSTEPS 16                       // 8 or 16

    // #define MOTOR12_64KHZ (1 << CS20)             // no prescale
    // #define MOTOR12_8KHZ (1 << CS21)              // divide by 8
    // #define MOTOR12_2KHZ (1 << CS21) | (1 << CS20)  // divide by 32
    // #define MOTOR12_1KHZ (1 << CS22)              // divide by 64

    // #define MOTOR34_64KHZ (1 << CS00)             // no prescale
    // #define MOTOR34_8KHZ (1 << CS01)              // divide by 8
    // #define MOTOR34_1KHZ (1 << CS01) | (1 << CS00)  // divide by 64
    
    #define DC_MOTOR_PWM_RATE   8000    // PWM rate for DC motors
    // #define STEPPER1_PWM_RATE   MOTOR12_64KHZ   // PWM rate for stepper 1
    // #define STEPPER2_PWM_RATE   MOTOR34_64KHZ   // PWM rate for stepper 2
    
#endif

// Bit positions in the 74HCT595 shift register output
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 0
#define MOTOR4_B 6
#define MOTOR3_A 5
#define MOTOR3_B 7

// Constants that the user passes in to the motor calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

// Constants that the user passes in to the stepper calls
// #define SINGLE 1
// #define DOUBLE 2
// #define INTERLEAVE 3
// #define MICROSTEP 4

/*
#define LATCH 4
#define LATCH_DDR DDRB
#define LATCH_PORT PORTB

#define CLK_PORT PORTD
#define CLK_DDR DDRD
#define CLK 4

#define ENABLE_PORT PORTD
#define ENABLE_DDR DDRD
#define ENABLE 7

#define SER 0
#define SER_DDR DDRB
#define SER_PORT PORTB
*/

// Arduino pin names for interface to 74HCT595 latch
#define MOTORLATCH D12
#define MOTORCLK D4
#define MOTORENABLE D7
#define MOTORDATA D0

class AFMotorController
{
  public:
    AFMotorController(void);
    void enable(void);
    friend class AF_DCMotor;
    void latch_tx(void);
    uint32_t TimerInitalized;
};

class AF_DCMotor
{
 public:
  AF_DCMotor(uint32_t motornum, uint32_t freq = DC_MOTOR_PWM_RATE);
  void run(uint32_t);
  void setSpeed(uint32_t);

 private:
  uint32_t motornum, pwmfreq;
};

/*
class AF_Stepper {
 public:
  AF_Stepper(uint16_t, uint8_t);
  void step(uint16_t steps, uint8_t dir,  uint8_t style = SINGLE);
  void setSpeed(uint16_t);
  uint8_t onestep(uint8_t dir, uint8_t style);
  void release(void);
  uint16_t revsteps; // # steps per revolution
  uint8_t steppernum;
  uint32_t usperstep, steppingcounter;
 private:
  uint8_t currentstep;

};
*/

uint32_t getlatchstate(void);

#endif
