/* Encoder Version 1.0 */

#pragma once  //instead of safe include guard

#include <mbed.h>

extern DigitalOut led1;

class Encoder {
    public:
    Encoder(PinName pinA, PinName pinB)
      : _pinA(pinA), _pinB(pinB),_bi(pinA,pinB){} // Encoder 클래스 생성할 때 인수로서 A, B상에 해당하는 pinA, pinB를 지정 
    void init()    {  // 모든 edges에 대해 callbacks 할당
        _pinA.rise(callback(this, &Encoder::decode)); 
        _pinA.fall(callback(this, &Encoder::decode));
        _pinB.rise(callback(this, &Encoder::decode));
        _pinB.fall(callback(this, &Encoder::decode));
        _previousState = _bi;
        _count = 0;
        _errorCount=0;
    }
    int32_t getCount()    {
        return _count;
    }
    void setCount(int32_t EncoderVal){
        _pinA.disable_irq (); _pinB.disable_irq ();
        _count = EncoderVal;
        _pinA.enable_irq ();_pinB.enable_irq ();
    }
    int32_t getErrorCount()    {
        return _errorCount;
    }     
  private:

    InterruptIn _pinA;
    InterruptIn _pinB;
    
    BusIn _bi;
    uint8_t _previousState;
    volatile int32_t _count;
    volatile uint32_t _errorCount;

    void decode()    {
//        uint8_t newState = _bi;
        uint8_t newState = (uint8_t)(_pinB << 1 | _pinA);
        switch((_previousState << 2) | newState) {
        case 0b0001: // 0x01 PREV|CURR
        case 0b0111: // 0x07
        case 0b1110: // 0x0E
        case 0b1000: // 0x08
            _count --; break;
        case 0b0010: // 0x02
        case 0b1011: // 0x0B
        case 0b1101: // 0x0D
        case 0b0100: // 0x04
            _count ++; break;
        default:
            _errorCount++; break;
        } 
        _previousState = newState; 
        led1=!led1;
    } 
};