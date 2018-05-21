//calibrerer med offset
void offset(){
  MPUconfig(0x1A,0b00000000);
  int ax = 0, ay = 0,az = 0,i;
  int sampleSize = 700;
  MPUread();
  MPUread();
  ax = AcX;
  ay = AcY;
  az = AcZ;
  for(i=0;i<sampleSize;i++){
    MPUread();
    if(i>100){
      ax = (ax+AcX)/2;
      ay = (ay+AcY)/2;
      az = (az+AcZ)/2;
    } 
  }
  AcXo = ax;
  AcYo = ay;
  AcZo = az;
  MPUconfig(0x1A,0b00000110);

  calibrationDone = true;
}

//leser av accelerometer
void readValues(){  
  t = millis();
  MPUread();
  Ax = (float)(AcX-AcXo)/16384;
  Ay = (float)(AcY-AcYo)/16384;
  Az = (float)(AcZ-AcZo)/16384;
  dt = millis()-t;
  int vector = smoothValue((makeVector(Ax, Ay, Az)));
  vectorGlobal = vector;
}

//lager vektor av verdiene
float makeVector(float x, float y, float z){
  double vector = sqrt(sq(x) + sq(y) + sq(z));
  return round(vector*100);
}

//smoother verdiene
int smoothValue(float data){
  return (int)as.smooth(data);
}

//calibrerer av og til gitt tiden
void timedCalibration(){
  offset();
}


