/* 
//max data sheet: https://datasheets.maximintegrated.com/en/ds/MAX6950-MAX6951.pdf

Arduino Uno
SPI
pin 10 - chip select (needed)
pin 11 - Data In 
pin 13 - clock

Molex pin out from OMSI board
pin 1 gnd
pin 2 CS
pin 3 Clk
pin 4 Data In
pin 5 5-12vdc

*/

#include <SPI.h> 
#include <MAX6950.h>


MAX6950 m;


int increment = 0x01;

/////////////////////////////
//SETUP
void setup(){
  m.init();
  m.config_reg(0x11);
  //m.config_reg(0x09);
  m.intensity_reg(0x0f);
  //m.decode_reg(0x00);

  Serial.begin(115200);
}

////////////////////////////
//LOOP
void loop(){

  //0x00 is display 1
  //0x01 is display 2
  //0x02 is display 3
  //0x03 is display 4

  for(int i = 0x00; i<0x70; i++){
    Serial.println(i);
    m.set_digital(0x00,i);
    m.set_digital(0x01,i);
    m.set_digital(0x02,i);
    m.set_digital(0x03,i);
    delay(100);
    m.set_digital(0x00,0x00);
    m.set_digital(0x01,0x00);
    m.set_digital(0x02,0x00);
    m.set_digital(0x03,0x00);

  }  
 

}


