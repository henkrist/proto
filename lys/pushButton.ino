

void pushButton(){
  unsigned long currentMillisButton = millis(); //begynner å telle
  if(currentMillisButton - previousMillisButton >= lastButtonPress){
    
    //knapp 1
    int buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 != lastButtonState1) { //sammenligner buttonstaten med forrige
      if (buttonState1 == LOW) { //hvis den er LOW, telles det
        sendData(button1);
        if (light1on) {
          light1on = false;
        }else{
          light1on = true;
        }
      }
     }
     lastButtonState1 = buttonState1;

  //knapp 2
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2) { //sammenligner buttonstaten med forrige
    if (buttonState2 == LOW) { //hvis den er LOW, telles det
      sendData(button2);
        if (light2on) {
          light2on = false;
        }else{
          light2on = true;
        }
       }
      }
        
    lastButtonState2 = buttonState2;
    
   //knapp 3
  int buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 != lastButtonState3) { //sammenligner buttonstaten med forrige
    if (buttonState3 == LOW) { //hvis den er LOW, telles det
      sendData(button3);
        if (light3on) {
          light3on = false;
        }else{
          light3on = true;
        }
       }
      }
        
    lastButtonState3 = buttonState3;
    previousMillisButton = currentMillisButton;
  }
}

void  sendData(int input){
  Serial.println(input); //printer ut tallene for hver knapp, som brukes i MaxMSP
}

