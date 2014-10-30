#include <SoftwareSerial.h>

#define NOTE_ON 0x90

#define NOTE_OFF ox80

#define VELOCITY 20

SoftwareSerial SSerial(2,3);

uint8_t notes[] = {
  0x0E, 0x0F, 0x100};
  
void setup(){
}

void loop(){
}
