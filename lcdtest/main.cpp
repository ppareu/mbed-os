 
#if 1
#include "mbed.h"
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x7E, 16, 2);

DigitalOut led(LED1);

int main()
{
    // initialize the LCD
    lcd.begin();

    // Turn on the blacklight and print a message.
    lcd.backlight();
    lcd.print("Hello, world!");
    
    while (1) {
        /*
        // Read temperature register
        data_write[0] = LM75_REG_TEMP;
        i2c.write(LM75_ADDR, data_write, 1, 1); // no stop
        i2c.stop();
        wait(0.01);
        i2c.read(LM75_ADDR, data_read, 2, 0);
        i2c.stop();
*/
        led = !led;
        ThisThread::sleep_for(1000);
    }


}
#endif

#if 0
/* Scan I2C bus on specified pins and prints out
* the all address where an active device responds.
*
  By Joseph Ellsworth CTO of A2WH
  Take a look at A2WH.com Producing Water from Air using Solar Energy
  March-2016 License: https://developer.mbed.org/handbook/MIT-Licence 
  Please contact us http://a2wh.com for help with custom design projects.

  
* Don't forget 3K pull-up resistors on sda,scl 
* 
* I tested this by soldering in a I2C chip known to respond at
* address dec=120 hex=70 and the utility got the ack as expected.
* when the chip was de-soldered it was no longer detected.  
*/

#include "mbed.h"

 #define D_SDA                  D14 
 #define D_SCL                  D15 
   // sda=PB7, scl=PB_6 Pins specific to Nucleo-F303K8
  // must change pins to match your board.

I2C i2c(D_SDA, D_SCL);  
  
DigitalOut myled(LED1);
 
int ack;   
int address;  
void scanI2C() {
  for(address=1;address<127;address++) {    
    ack = i2c.write(address, "11", 1);
    if (ack == 0) {
       printf("\tFound at %3d -- %3x\r\n", address,address);
       i2c.write(address)
    }    
    ThisThread::sleep_for(50);          
  } 
}
 
int main() {
  printf("I2C scanner \r\n");
  scanI2C();
  printf("Finished Scan\r\n");
  // just blink to let us know the CPU is alive 
  while(1) { 
      ThisThread::sleep_for(2000);          
      myled = !myled;
  }
}
  
#endif