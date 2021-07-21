#include <SimpleDHT.h>
#include<Wire.h>
int pinDHT11 =A0;
int c,d;
String s;
int l;
int data[]={0,0};
SimpleDHT11 dht11(pinDHT11);
void setup()
{  
  pinMode(pinDHT11, INPUT);
  Serial.begin(9600);
  Wire.begin();
}
void temp()
{
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
 
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
 
  Serial.print("Sample OK: ");
  Serial.print(temperature); Serial.print(" *C, ");
  Serial.print(humidity); Serial.println(" H");
 c = temperature;
 d = humidity;
 

 
 
 
 //delay(1500);
  // DHT11 sampling rate is 1HZ.
 
}
void loop()
{
  temp();
  data[0]=c;
  data[1]=d;
  Wire.requestFrom(8,1);                           
  int MasterReceive = Wire.read();
  Wire.beginTransmission(8);                       // start transmit to slave arduino (8)
  uint8_t Buffer[2];
  Buffer[0]=data[0];
  Buffer[1]=data[1];
 
  Wire.write(Buffer,2);
  //Wire.write(Buffer,1);
  Serial.print("data sent:");
  Serial.print(Buffer[0]);// sends one byte converted POT value to slave
  Wire.endTransmission();  
  delay(1000);
  
}
