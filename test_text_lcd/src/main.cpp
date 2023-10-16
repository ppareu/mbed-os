#include "mbed.h"
#include "TextLCD.h"
 
// Host PC Communication channels
//BufferedSerial pc(USBTX, USBRX); // tx, rx
 
// I2C Communication
I2C i2c_lcd(D14, D15); // SDA, SCL
 
// SPI Communication
//SPI spi_lcd(p5, NC, p7); // MOSI, MISO, SCLK

//TextLCD lcd(p15, p16, p17, p18, p19, p20);                // RS, E, D4-D7, LCDType=LCD16x2, BL=NC, E2=NC, LCDTCtrl=HD44780
//TextLCD_SPI lcd(&spi_lcd, p8, TextLCD::LCD40x4);   // SPI bus, 74595 expander, CS pin, LCD Type  
//TextLCD_I2C lcd(&i2c_lcd, 0x42, TextLCD::LCD20x4);  // I2C bus, PCF8574 Slaveaddress, LCD Type
TextLCD_I2C lcd(&i2c_lcd, 0x7E, TextLCD::LCD16x2); // I2C bus, PCF8574 Slaveaddress, LCD Type, Device Type
//TextLCD_I2C lcd(&i2c_lcd, 0x42, TextLCD::LCD16x2, TextLCD::WS0010); // I2C bus, PCF8574 Slaveaddress, LCD Type, Device Type
//TextLCD_SPI_N lcd(&spi_lcd, p8, p9);               // SPI bus, CS pin, RS pin, LCDType=LCD16x2, BL=NC, LCDTCtrl=ST7032_3V3   
//TextLCD_I2C_N lcd(&i2c_lcd, ST7032_SA, TextLCD::LCD16x2, NC, TextLCD::ST7032_3V3); // I2C bus, Slaveaddress, LCD Type, BL=NC, LCDTCtrl=ST7032_3V3  

int main() {
    printf("LCD Test. Columns=%d, Rows=%d\n\r", lcd.columns(), lcd.rows());
    lcd.setBacklight(TextLCD_Base::LightOn);

    for (int row=0; row<lcd.rows(); row++) {
      int col=0;
      
      printf("MemAddr(Col=%d, Row=%d)=0x%02X\n\r", col, row, lcd.getAddress(col, row));      
//      lcd.putc('-');
      lcd.putc('0' + row);      
      
      for (col=1; col<lcd.columns()-1; col++) {    
        lcd.putc('*');
      }
 
      printf("MemAddr(Col=%d, Row=%d)=0x%02X\n\r", col, row, lcd.getAddress(col, row));      
      lcd.putc('+');
        
    }    
    
// Show cursor as blinking character
    lcd.setCursor(TextLCD::CurOff_BlkOn);
 
// Set and show user defined characters. A maximum of 8 UDCs are supported by the HD44780.
// They are defined by a 5x7 bitpattern. 
    lcd.setUDC(0, (char *) udc_0);  // Show |>
    lcd.putc(0);    
    lcd.setUDC(1, (char *) udc_1);  // Show <|
    lcd.putc(1);    

}