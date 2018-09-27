/*
  Proto-V18
  HK
  GY521 + RFduino x2
*/

//libaries
#include <RFduinoGZLL.h>
device_t role = HOST;

//instanser
int sendDataPin2 = 2;
int sendDataPin3 = 3;
int sendDataPin4 = 4;

//globale variabler
int rawData;
int finishedData;
bool isIdle;

int targetValue;
int changingValue;
unsigned long previousMillis = 0; 
const long interval = 500;

void setup() {
  //setter rolle for podiet
  pinMode(sendDataPin2, OUTPUT);
  pinMode(sendDataPin3, OUTPUT);
  pinMode(sendDataPin4, OUTPUT);
  
  RFduinoGZLL.begin(role);
  Serial.begin(9600);
}

void loop(){
}
