
void readInput(){
  switch (takt){
    case 0:
      skalar = 0;
      WAVE = 0;
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode2, LOW);
      digitalWrite(diode3, LOW);
      digitalWrite(diode4, LOW);
      digitalWrite(diode5, LOW);
      break;
    case 3:
      skalar = 1.61; //saktest
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode2, LOW);
      digitalWrite(diode3, LOW);
      digitalWrite(diode4, LOW);
      digitalWrite(diode5, HIGH);
      break;
    case 4:
      skalar = 1.23;
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode2, LOW);
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode3, LOW);
      digitalWrite(diode4, HIGH);
      digitalWrite(diode5, LOW);
      break;
    case 5:
      skalar = 1; //normal
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode3, HIGH);
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode2, LOW);
      digitalWrite(diode4, LOW);
      digitalWrite(diode5, LOW);
      break;
    case 6:
      skalar = 0.85;
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode4, LOW);
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode2, HIGH);
      digitalWrite(diode3, LOW);
      digitalWrite(diode5, LOW);
      break;
    case 7:
      skalar = 0.7; //fortest
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode5, LOW);
      digitalWrite(diode1, HIGH); //diode som hører til
      digitalWrite(diode2, LOW);
      digitalWrite(diode3, LOW);
      digitalWrite(diode4, LOW);
      break;
    default:
      skalar = 1;
      WAVE = WAVE_LEN * skalar; 
      digitalWrite(diode3, HIGH);
      digitalWrite(diode1, LOW); //diode som hører til
      digitalWrite(diode2, LOW);
      digitalWrite(diode4, LOW);
      digitalWrite(diode5, LOW);
      break;
  }
}


int readParallellBinary(){
  int values[3];
  int number;
  values[0] = digitalRead(binaryIn1);
  values[1] = digitalRead(binaryIn2);
  values[2] = digitalRead(binaryIn3);
  
  number = values[0] + values[1]*2 + values[2]*4;
  return number;
}

