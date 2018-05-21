
boolean runOffset = true;
int layingStillCounter;
int movingCounter;

//metode for å sjekke om den ligger stille
void checkIdle(){
  if(layingStill()){
    layingStillCounter++;
    movingCounter = 0;
  }else{
    movingCounter++;
    layingStillCounter = 0;
  }
  
  if(layingStillCounter >= 900){
    isIdle = true;
    if(runOffset){
      offset();
      runOffset = false;
    }
  }else{
    if(movingCounter >= 10){
      if(!runOffset){
        isIdle = true;
      }else{
        isIdle = false;
      }
      runOffset = true;
    }
  }  
}

int currentValue;
int previousValue;

bool layingStill(){
  currentValue = vectorGlobal;
  bool idleBool;
  
  if(inRange(currentValue,previousValue-10,previousValue+10)){
    idleBool = true;
  }else{
    idleBool = false;
  }
  previousValue = currentValue;
  return idleBool;
}

bool inRange(int val, int minimum, int maximum){
  return ((minimum <= val) && (val <= maximum));
}

