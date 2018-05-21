
//definerer variabler for å justere følsomhet på tempo
boolean state = false; // under threshold
int threshold = 380; // endre denne i følge testing
boolean tickerStart = false;

//smootheDatane
int dataSampleSize = 5;
int dataTeller = 0;
int sumData;
int averageData;

//variabler for å ta intervaller
long previousMillis = 0;
long startTime;
unsigned long runningTimer;
long elapsedTime;
long totalTime;
long midTime;
int tellerTicker;
const int timeSampleSize = 3;

//metode for å sjekke om vi har truffet et tak
void recordInterval(){
  int data = vectorGlobal;
  if(!state && (data>threshold)){
    state = true;
    sendTick();
  }else if(state && (data<threshold)){
    state = false;
  }
}

//metode for å starte klokka
void sendTick(){
  if(!tickerStart){
    startTime = 0;
    tickerStart = true;
    return;
  }
  if(tickerStart){
    midTime = millis();
    elapsedTime = midTime - startTime;
    startTime = midTime;
    smoothTime();
  }
}

//lager et gjennomsnitt på tiden
void smoothTime(){
  if(tellerTicker <= timeSampleSize){
    totalTime += elapsedTime;
  }else{
    tellerTicker = 0;
    long averageTime = totalTime/timeSampleSize;
    checkTempo(averageTime);
    totalTime = 0;
  }
  tellerTicker++;
}

//sjekker tempo og skriver ut
void checkTempo(long averageTime){
  tempo = (int)timeMapper(averageTime);
}

//konverterer gjennomsnittstiden tilen skalar vi kan bruke 
int timeMapper(long inputTime){
  if(inputTime>1000){
    return 3;
  }
  long tempoScale = map(inputTime, 50, 900, 7, 3);
  return tempoScale;
}


