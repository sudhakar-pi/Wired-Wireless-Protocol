#include<Wire.h>                          
int SlaveReceived[10];
int i;
void setup() 
{                          
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 

void loop(void) 
{
                        
  Serial.println("temp Received From Master:");   //Prints in Serial Monitor 
  Serial.println(SlaveReceived[0]); 
  Serial.println("humidity Received From Master:");   //Prints in Serial Monitor 
  Serial.println(SlaveReceived[1]);
  delay(1000);

  
}

void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master
{
  for(int i=0;i<2;i++)//organizes the data from the slave in the table
{
int c = Wire.read(); // receive a byte as character
SlaveReceived[i]=c;
}
   
}

void requestEvent()                                //This Function is called when Master wants value from slave
{
  int potvalue = 13;                   // Reads analog value from POT (0-5V)
  byte SlaveSend = potvalue;    // Convert potvalue digital value (0 to 1023) to (0 to 127)
  Wire.write(SlaveSend);                          // sends one byte converted POT value to master
}
