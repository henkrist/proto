
int led1 = 11; // the PWM pin the LED is attached to
int led2 = 10;
int led3 = 9;


int binaryIn1 = A0; // pin 2 på rfduino
int binaryIn2 = A1; // pin 3 på rfduino
int binaryIn3 = A2; // pin 4 på rfduino

int buttonPin1 = 2;   // knapp 1
int buttonPin2 = 3;   // knapp 2
int buttonPin3 = 4;   // knapp 3


int lastButtonState1 = 0; //forrige tilstand til knappen
int lastButtonState2 = 0; //forrige tilstand til knappen
int lastButtonState3 = 0; //forrige tilstand til knappen

int button1 = 1;     //tallet som sendes til MAX
int button2 = 2;     //tallet som sendes til MAX
int button3 = 3;     //tallet som sendes til MAX

unsigned long currentMillisButton = 0;
long lastButtonPress = 100; //ant millisek fra forrige trykk
unsigned long previousMillisButton = 0; //forrige tall  

boolean light1on = true; // sjekker om lys 1 er på eller av
boolean light2on = true; // sjekker om lys 2 er på eller av
boolean light3on = true; // sjekker om lys 3 er på eller av

int diode1 = 5; //presto
int diode2 = 6; //veloce
int diode3 = 7; //moderato
int diode4 = 8; //andante
int diode5 = 12; //lento


#include "QuadraticWaveLed.h"
QuadraticWaveLed led1Pulse;
QuadraticWaveLed led2Pulse;
QuadraticWaveLed led3Pulse;
float skalar = 1; //ganges med bølgelengden for å endre den
unsigned long WAVE_LEN = 480;  //DETTE ER BØLELENGDEN
unsigned long WAVE = 1;
unsigned long milliPulse = 0;

void setup() {
  pinMode(binaryIn1, INPUT);
  pinMode(binaryIn2, INPUT);
  pinMode(binaryIn3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(diode1, OUTPUT);
  pinMode(diode2, OUTPUT);
  pinMode(diode3, OUTPUT);
  pinMode(diode4, OUTPUT);
  pinMode(diode5, OUTPUT);
  setupPulse();
  
}

void setupPulse(){
  led1Pulse.setup(led1, WAVE);
  led2Pulse.setup(led2, WAVE);
  led3Pulse.setup(led3, WAVE);
}

int takt;

void loop() {
  readInput();
  pushButton();
  pulseLight();
  setupPulse();
  takt = readParallellBinary();
}
