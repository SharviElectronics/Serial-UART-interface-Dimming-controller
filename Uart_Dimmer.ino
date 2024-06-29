/*
  
 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>
int dimmerResponse();
SoftwareSerial DimmerSeial(2, 3); // RX, TX

uint8_t dimmPkt [5], dimm =0;;
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Uart Based Dimmer Test");

  // set the data rate for the SoftwareSerial port
  DimmerSeial.begin(9600);
  DimmerSeial.setTimeout(70);  //m sec
  
  
}

void loop() // run over and over
{
  for(dimm =0; dimm<255; dimm++)
  {
    dimmPkt[0] = 0x41;
    dimmPkt[1] = 0x54;
    dimmPkt[2] = 0x2B;
    dimmPkt[3] = 0x44;
    dimmPkt[4] = dimm;
    DimmerSeial.write(dimmPkt,5);
    if(!dimmerResponse())
    {
      Serial.println("Device is not Responding - Check Serial Cable UNO Pin 2 - HW RX & UNO Pin 3 - HW TX");
      delay(2000);
    }
    delay(100);
    //Serial.print("Dim Level: ");
    //Serial.println(dimm);
    
  }
}

int dimmerResponse()
{
  int timeout = 1000;
  char incomingByte[10]={0};
  while(timeout--)
  {
    if(DimmerSeial.available()>0)
    {
      DimmerSeial.readBytes(incomingByte, (sizeof(incomingByte)-1) );
      Serial.print(incomingByte[0]);
      Serial.print(incomingByte[1]);
      
      if(incomingByte[3] == 'D')
      {
        Serial.print(" , Dimm Level - ");
        Serial.println((int)(0xFF & (incomingByte[4])));
      }else
      {
        Serial.println("Error Dimm Level");
      }
      
      return 1;
    }
    
  }
  return 0;
}
