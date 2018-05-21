
void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len){
  //konverterer til int
  int convertedData = convertToInt(data);
  rawData = convertedData;

  if(rawData){
    transitionBetweenValues();
  }else{
    sendData(0);
  }
}

