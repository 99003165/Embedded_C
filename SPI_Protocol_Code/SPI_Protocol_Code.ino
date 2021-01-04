#include <SPI.h>

volatile boolean Rxd;
volatile byte Slave_Rxd;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT); // SS
  digitalWrite(10, LOW);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);  //Turn on SPI in Slave Mode
  SPCR |= _BV(SPIE); //Turn on SPI Interrupt in Slave Mode
  Rxd = false;
  //Serial.begin(9600);
  SPI.attachInterrupt(); 
}

ISR (SPI_STC_vect)                        //Interrupt routine function 
{
  Slave_Rxd = SPDR;                  
  Rxd = true;                        
}

void loop() {
  
  if(Rxd)
  {
    if (Slave_Rxd != 0)
    {
      Serial.println("LED OFF : Motion not detected !!!");
      Rxd = false;
      //delay(1000); 
    }
    else
    {
      Serial.println("LED ON : Motion detected!!!");
      Rxd = false;
      //delay(3000);
    }
  }
}
