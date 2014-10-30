#include <SPI.h>

#include <SD.h>

#define SD_ChipSelectPin 4


int value = 0;

const int threshold = 10;

int low[]={
  959,930,843, 877, 779, 799};
  
int high[] = {
  960, 932,845,878,781,801};
  
void setup(){
  Serial.begin(38400);
  tmrpcm.speakerPin = 9;
  
  if (!SD.begin(SD_ChipSelectPin)){
    return;
  }
  
  tmrpcm.volume(1);
  tmrpcm.play("1.wav");
}

void loop(){
  
  value = analogRead(A0);
  delay(50);
  
  //Serial.print(value);
  
  if(value >= low[0] && value <= high[0]){
    tmrpcm.play("1.wav");
    Serial.println("wav1");
  }
  
  if(value >= low[1] && value <= high[1]){
    tmrpcm.play("2.wav");
    Serial.println("wav2");
  }
  
  if(value >= low[2] && value <= high[2]){
    tmrpcm.play("3.wav");
    Serial.println("wav3");
  }
  
  if(value >= low[3] && value <= high[3]){
    tmrpcm.play("4.wav");
    Serial.println("wav4");
  }
  
  if(value >= low[4] && value <= high[4]){
    tmrpcm.play("5.wav");
    Serial.println("wav5");
  }
  
  if(value >= low[5] && value <= high[5]){
    tmrpcm.play("6.wav");
    Serial.println("wav6");
  }
}
