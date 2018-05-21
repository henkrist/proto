
//konverterer til int
int convertToInt(String input){
  return input.toInt();
}

//lager en smooth overgang mellom verdiene fra staven
void transitionBetweenValues(){
  unsigned long currentMillis = millis();
  targetValue = rawData;
  
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis; 
    
    if(targetValue != changingValue){
      if(targetValue < changingValue){
        changingValue --;
      }
      if(targetValue > changingValue){
        changingValue ++;
      }
    }else{
      changingValue = targetValue;
    }
  }
  sendData(changingValue);
}

//Sender data
void sendData(int data){ 
  //Sender data til Caroline 
  sendParallellBinary(data);
  //sender data til MAX
  printToSerial(data);
  delay(2);
}

//sender binær data til Arduino og lys
void sendParallellBinary(int data){
  for(int i = 0; i<3; i++){
    if(bitRead(data,i)){
      digitalWrite(2+i,HIGH);
    }else{
      digitalWrite(2+i,LOW);
    }
  }
}


//printer ut data uten delay
int serialTimer = millis();
void printToSerial(int data){
  if(serialTimer%200 == 0){
    Serial.println(data);
  }
}



