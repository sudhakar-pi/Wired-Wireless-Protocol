//Slave Arduino Programming

//I2C SLAVE CODE
//I2C Communication between Two Arduino
//CircuitDigest
//Pramoth.T

#include<Wire.h>                          //Library for I2C Communication functions
    //Define LCD Module Pins (RS,EN,D4,D5,D6,D7)

int SlaveReceived[10];
int i;
void setup() 

{
                            //Clears LCD display
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 

void loop(void) 
{
                        //Prints SlaveReceived value in LCD received from Master
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
   //Used to read value received from master and store in variable SlaveReceived
}

void requestEvent()                                //This Function is called when Master wants value from slave
{
  int potvalue = 13;                   // Reads analog value from POT (0-5V)
  byte SlaveSend = potvalue;    // Convert potvalue digital value (0 to 1023) to (0 to 127)
  Wire.write(SlaveSend);                          // sends one byte converted POT value to master
}
