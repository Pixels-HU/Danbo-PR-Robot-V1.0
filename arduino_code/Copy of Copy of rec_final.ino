#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
 void servoPulse (int servo, int angle); //function of operation
// Include dependant SPI Library 
#include <SPI.h>
 
// Define addresses for radio channels
#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2
 
// Motor A Connections
//int enA = 10;
//int in1 = 10;
//int in2 = 4;
int in1=9;
//aduio player/
//TMRpcm tmrpcm;

// Motor B Connections
//int enB = 9;
//int in3 = 7;
//int in4 = 6;
int in2 =3;

//motor c
int in3=4;

//servo motors
int servo1 = 6;
int servo2 = 5;
int angle;
int pwm;
// Create an instance of the radio driver
RH_NRF24 RadioDriver;
 
// Sets the radio driver to NRF24 and the server address to 2
RHReliableDatagram RadioManager(RadioDriver, SERVER_ADDRESS);
 
// Define a message to return if values received
uint8_t ReturnMessage[] = "JoyStick Data Received"; 

// Define the Message Buffer
uint8_t buf[5];
  
void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
  
  // Set all the motor control pins to outputs
//  pinMode(enA, OUTPUT);
  //pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode (servo1,OUTPUT);
  pinMode (servo2, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  //pinMode(in4, OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  // Initialize RadioManager with defaults - 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!RadioManager.init())
    Serial.println("init failed");
} 
 
void loop()
{
  if (RadioManager.available())
  {
 // Wait for a message addressed to us from the client
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAck(buf, &len, &from))
 
    {
 
      //Serial Print the values of joystick
      Serial.print("got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": MotorA = ");
      Serial.print(buf[0]);
      Serial.print(" MotorB = ");
      Serial.print(buf[1]);
      Serial.print(" servo = ");
      Serial.println(buf[2]);
      Serial.println(buf[3]);
      Serial.println(buf[4]);
      // Set Motor Direction
     /* if (buf[2] == 1)
      {
    // Motors are backwards
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //digitalWrite(in3, LOW);
    //digitalWrite(in4, HIGH);
    }else{
    // Motors are forwards
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
   // digitalWrite(in3, HIGH);
    //digitalWrite(in4, LOW);
     }
 */
      
      // Drive Motors
      analogWrite(in1, buf[1]);
      analogWrite(in2, buf[0]);
     servoPulse (servo1, (int) buf[2]);
     //delay (50);
      servoPulse (servo2, (int) buf[2]);
      if(buf[4]==1)
      {
      digitalWrite(in3,HIGH);
      Serial.println("motor on");
      }
      else
      {
        digitalWrite(in3,LOW);
      }
      // Send a reply back to the originator client, check for error
      if (!RadioManager.sendtoWait(ReturnMessage, sizeof(ReturnMessage),&from))
        Serial.println("sendtoWait failed");
    }
  }              
}

//servo function
void servoPulse (int servo, int angle)
{
 pwm = (angle*11) + 500;      // Convert angle to microseconds
 digitalWrite(servo, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(servo, LOW);
//delay(50);                   // Refresh cycle of servo
}
