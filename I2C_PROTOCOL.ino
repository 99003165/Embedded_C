#include<Wire.h> 

Serial.begin(9600); 

Wire.begin(8);   

Wire.onReceive(receiveEvent);       
Wire.onRequest(requestEvent);  
    
void requestEvent()                         
  {
  int value = digitalRead(buttonpin);         

  if (value == HIGH)                            
{
    x=1;
  }
  else
  {
   x=0;
  }
  Wire.write(x);                           
 }


void receiveEvent (int howMany)           
{
  byte a = Wire.read();
  if (a == 1{
   digitalWrite(LED,HIGH);
   Serial.println("Slave LED ON");

  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.println("Slave LED OFF");
  }
  delay(500);
}
