/*
  Proto-V18
  Henrik Kristiansen
  GY521 + RFduino x2
*/

//libraries
#include <AnalogSmooth.h>
#include<Wire.h>
#include <RFduinoGZLL.h>
#include <I2Cdev.h>
#include <MPU6050.h>
device_t role = DEVICE0;

//Data for MPU6050
AnalogSmooth as = AnalogSmooth();
const int MPU = 0x68;
int t = 0,dt = 1;
int AcX,AcY,AcZ,GyX,GyY,GyZ,tmp;
int AcXo,AcYo,AcZo,GyXo,GyYo,GyZo;
float roll = 0,pitch = 0,rollgy = 0,pitchgy = 0,rollac = 0,pitchac = 0,Ax,Ay,Az,Gx,Gy,Gz,gain = 0.95;

//globale variabler
boolean beginProgram = false;
boolean calibrating = true;
boolean calibrationDone = false;
boolean isIdle = false;

//globale verdier
int vectorGlobal;
int zeroVector;
int tempo;
int sendingTimer = millis();

void setup() {
  Wire.begin(); 
  MPUconfig(0x1A,0b00000110);
  MPUconfig(0x1B,0b00000000);
  MPUconfig(0x1C,0b00000000);
  MPUconfig(0x6B,0b00000000);
  offset();
  
  RFduinoGZLL.begin(role); //setter opp kommunikasjon
  Serial.begin(9600);
}

void loop() {
  //starter programmet
  if(!beginProgram){
    offset();
    beginProgram = true;
  }
  //starter programmet hvis den er kalibrert for første gang
  if(beginProgram){
    readValues();
    checkIdle();
    if(calibrationDone && !isIdle){
      recordInterval();
    }
    if(millis() % 50 == 0){
      sendData(tempo);
    }
  }
}

//metode for å printe ut verdier uten delay
int serialTimer = millis();
void printToSerial(int data){
  if(serialTimer%200 == 0){
    Serial.println(data);
  }
}

