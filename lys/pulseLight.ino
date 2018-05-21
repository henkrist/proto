
void pulseLight(){
  milliPulse = millis();

  //skrur av og på led1
  if(light1on){
    //denne gjør at det pulserer
    led1Pulse.update(milliPulse);
  }else{
    digitalWrite(led1,LOW);
  }

  //led2
  if(light2on){
    //denne gjør at det pulserer
    led2Pulse.update(milliPulse);
  }else{
    digitalWrite(led2,LOW);
  }

  //led3
  if(light3on){
    //denne gjør at det pulserer
    led3Pulse.update(milliPulse);
  }else{
    digitalWrite(led3,LOW);
  }
  
}

