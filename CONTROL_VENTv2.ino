#include <SoftwareSerial.h>

SoftwareSerial bt(1,0);
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
char dato=0;

void setup()
{
  bt.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);  
  delay(500);//Delay to let system boot
  
  
}

void loop()
{

  if(bt.available())
  {
    dato=bt.read();
      if(dato=='0')
      {
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
      }
      if(dato=='9')
      {
        digitalWrite(10,HIGH);
        digitalWrite(9,HIGH);
      }
  }
  
  DHT.read11(dht_apin);
  float temp=DHT.temperature;
      bt.print(temp); 
    //si se detecta una communicacion abrir serie de if
      delay(2000);//Wait 5 seconds before accessing sensor again.
}
 
