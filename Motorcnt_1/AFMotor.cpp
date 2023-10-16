#include "AFMotor.h"

DigitalOut en1(A3);
DigitalOut en2(A4);
DigitalOut en3(A5);
DigitalOut out1(D2);
DigitalOut out2(D3);
DigitalOut out3(D4);

void Motorcnt(bool dir, int stepNum)
{
    out1 = 0; out2 = 0; out3 = 0;
    

    en1 = 1; en2 = 1; en3 = 1; 
    
    int stepCount = 0;
    
    char data_array[]={1,2,0, 1,0,2, 2,0,1, 0,2,1, 0,1,2, 2,1,0};
    char data_arrayInv[]={0,1,2, 0,2,1, 2,0,1, 1,0,2, 1,2,0, 2,1,0};
    
    if(dir==1)
        for(int k=0; k<18; k++)
            data_array[k] = data_arrayInv[k];      
    
    for (int i=0; i<stepNum; i++)
    {
        i%=6;
        out1 = data_array[3*i];    (data_array[3*i]   == 2)?(en1 = 0):(en1 = 1);   
        out2 = data_array[3*i+1];  (data_array[3*i+1] == 2)?(en2 = 0):(en2 = 1); 
        out3 = data_array[3*i+2];  (data_array[3*i+2] == 2)?(en3 = 0):(en3 = 1); 
        // thisTread::sleep_for(delay_time);   
        if(++stepCount == stepNum) break;    
    }   
}

void oneStep(bool dir,int* prevStep)
{
    out1 = 0; out2 = 0; out3 = 0;
    
    en1 = 1; en2 = 1; en3 = 1; 
    
    char data_array[]={1,2,0, 1,0,2, 2,0,1, 0,2,1, 0,1,2, 2,1,0};
      
    if(dir==1)
        *prevStep = *prevStep + 1;
    else 
        *prevStep = *prevStep - 1; 
        
    int i = *prevStep;
        
    if (i<0)
    {
        i*=(-1); i%=6; i=6-i; 
        i%=6;
    }   
    else 
        i%=6;
    
    out1 = data_array[3*i];    (data_array[3*i]   == 2)?(en1 = 0):(en1 = 1);   
    out2 = data_array[3*i+1];  (data_array[3*i+1] == 2)?(en2 = 0):(en2 = 1); 
    out3 = data_array[3*i+2];  (data_array[3*i+2] == 2)?(en3 = 0):(en3 = 1);
    // ThisThread::sleep_for(delay_time);
}
