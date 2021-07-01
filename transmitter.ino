#include <RHReliableDatagram.h>
#include <RH_NRF24.h> 
#include <SPI.h>
#define joyVert A1 
#define joyHorz A0
#define joysVert A2
#define joysHorz A3
#define button 7
#define pb 4

// Define Joystick Values - Start at 512 (middle position)
int joyposVert = 512;
int joyposHorz = 512;
int joysposVert = 512;
int joysposHorz = 512;
boolean state=0;
#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2

// Create an instance of the radio driver
RH_NRF24 RadioDriver;

// Sets the radio driver to NRF24 and the client address to 1
RHReliableDatagram RadioManager(RadioDriver, CLIENT_ADDRESS);

// Declare unsigned 8-bit motorcontrol array
// 2 Bytes for motor speeds plus 1 byte for direction control
uint8_t motorcontrol[7]; 
//uint8_t motorcontrol[5]; 

// Define the Message Buffer
uint8_t buf[5];

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
 
  // Initialize RadioManager with defaults - 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!RadioManager.init())
    Serial.println("init failed");
  pinMode(button,INPUT_PULLUP);
  pinMode(pb,INPUT_PULLUP);
  pinMode(joysVert,INPUT);
  pinMode(joysHorz,INPUT);

  // Set initial motor direction as forward
  motorcontrol[2] = 90;
 motorcontrol[3]=0;
}

void loop()
{
  // Print to Serial Monitor
  Serial.println("Reading motorcontrol values ");
  
  // Read the Joystick X and Y positions
  joyposVert = analogRead(joyVert); 
  joyposHorz = analogRead(joyHorz);
  joysposVert = analogRead(joysVert); 
  joysposHorz = analogRead(joysHorz);
//heaad part
  if (joysposVert <460)
  {
    motorcontrol[2]=map(joysposVert,460,0,90,0); 
  }
  else if (joysposVert >560)
  {   
    motorcontrol[2]=map(joysposVert,560,1023,90,180); 
    }
else
  {
    // This is Stopped
    motorcontrol[2] = 90;
} 
    if (joysposHorz <460)
  {
    motorcontrol[2]=map(joysposHorz,0,460,0,90); 
  }
  else if (joysposHorz >560)
  {   
    motorcontrol[2]=map(joysposHorz,560,1023,90,180); 
    }
else
  {
    // This is Stopped
    motorcontrol[5] = 90;
}//base part

  if (joyposVert < 460)
  { 
    //set direction backwards
  //  motorcontrol[2]=1; 
    motorcontrol[0] = map(joyposVert, 460, 0, 0, 255);
    motorcontrol[1] = map(joyposVert, 460, 0, 0, 255);

  }
  else if (joyposVert > 564)
  {
    // This is Forward
    // Set Motors forward
    //motorcontrol[2] = 0;

    //Determine Motor Speeds
    motorcontrol[0] = map(joyposVert, 564, 1023, 0, 255);
    motorcontrol[1] = map(joyposVert, 564, 1023, 0, 255); 

  }
  else
  {
    // This is Stopped
    motorcontrol[0] = 0;
    motorcontrol[1] = 0;
//    motorcontrol[2] = 0; 

  }
  
  // Now do the steering
  // The Horizontal position will "weigh" the motor speed
  // Values for each motor

  if (joyposHorz < 460)
  {
    // Move Left
    // As we are going left we need to reverse readings
    // Map the number to a value of 255 maximum
    joyposHorz = map(joyposHorz, 460, 0, 0, 255);

    motorcontrol[0] = motorcontrol[0] - joyposHorz;
    motorcontrol[1] = motorcontrol[1] + joyposHorz;

    // Don't exceed range of 0-255 for motor speeds
    if (motorcontrol[0] < 0)motorcontrol[0] = 0;
    if (motorcontrol[1] > 255)motorcontrol[1] = 255;

  }
  else if (joyposHorz > 564)
  {
    // Move Right
    // Map the number to a value of 255 maximum
    joyposHorz = map(joyposHorz, 564, 1023, 0, 255);
  
    motorcontrol[0] = motorcontrol[0] + joyposHorz;
    motorcontrol[1] = motorcontrol[1] - joyposHorz;

    // Don't exceed range of 0-255 for motor speeds
    if (motorcontrol[0] > 255)motorcontrol[0] = 255;
    if (motorcontrol[1] < 0)motorcontrol[1] = 0;      

  }

  // Adjust to prevent "buzzing" at very low speed
  if (motorcontrol[0] < 8)motorcontrol[0] = 0;
  if (motorcontrol[1] < 8)motorcontrol[1] = 0;
  state = digitalRead(pb);
  if(state==LOW)
  {
    //motorcontrol[0]=0;
  motorcontrol[4]=1;
 //   delay(200);
  }
  else
  {
    motorcontrol[4]=0; 
  }
//  motorcontrol[6]=0;
/*  if(pb==0)
  {
  //motorcontrol[4]=1;
  }
else
  motorcontrol[4]=0;
*/
  //Display the Motor Control values in the serial monitor.
  Serial.print("Motor A: ");
  Serial.print(motorcontrol[0]);
  Serial.print(" - Motor B: ");
  Serial.print(motorcontrol[1]);
  Serial.print(" - Direction: ");
  Serial.println(motorcontrol[2]);
  Serial.println(motorcontrol[3]);
  Serial.println(motorcontrol[4]);

  //Send a message containing Motor Control data to manager_server
  if (RadioManager
  .sendtoWait(motorcontrol, sizeof(motorcontrol), SERVER_ADDRESS))
  {
    Serial.print(" start sending ");
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }
  }
  else
    Serial.println("sendtoWait failed");

//delay(10); // Wait a bit before next transmission
}
