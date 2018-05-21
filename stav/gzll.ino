
//Send data til andre RFduino
void sendData(int data){
  String dataToPodie;
  if(!isIdle){
    dataToPodie = (String)data;
  }else{
    dataToPodie = (String)0;
  }
  Serial.println(dataToPodie);
  RFduinoGZLL.sendToHost(dataToPodie);
}

//bestem hva som skjer når data kommer tilbake
void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len){
}
