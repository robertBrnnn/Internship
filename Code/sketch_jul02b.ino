#include <SoftwareSerial.h>

#define MIDI_CC_MODULATION 0x01
#define MIDI_CC_BREATH 0x02
#define MIDI_CC_VOLUME 0x07
#define MIDI_CC_BALANCE 0x08
#define MIDI_CC_PAN 0x0A
#define MIDI_CC_EXPRESSION 0x0B
#define MIDI_CC_EFFECT1 0x0C
#define MIDI_CC_EFFECT2 0x0D

#define MIDI_CC_GENERAL1 0x0E
#define MIDI_CC_GENERAL2 0x0F
#define MIDI_CC_GENERAL3 0x10
#define MIDI_CC_GENERAL4 0x11
#define MIDI_CC_GENERAL5 0x12
#define MIDI_CC_GENERAL6 0x13
#define MIDI_CC_GENERAL7 0x14
#define MIDI_CC_GENERAL8 0x15
#define MIDI_CC_GENERAL9 0x16
#define MIDI_CC_GENERAL10 0x17
#define MIDI_CC_GENERAL11 0x18
#define MIDI_CC_GENERAL12 0x19
#define MIDI_CC_GENERAL13 0x1A
#define MIDI_CC_GENERAL14 0x1B
#define MIDI_CC_GENERAL15 0x1C
#define MIDI_CC_GENERAL16 0x1D
#define MIDI_CC_GENERAL17 0x1E
#define MIDI_CC_GENERAL18 0x1F

#define MIDI_CC_GENERAL1_FINE 0x2E
#define MIDI_CC_GENERAL2_FINE 0x2F
#define MIDI_CC_GENERAL3_FINE 0x30
#define MIDI_CC_GENERAL4_FINE 0x31
#define MIDI_CC_GENERAL5_FINE 0x32
#define MIDI_CC_GENERAL6_FINE 0x33
#define MIDI_CC_GENERAL7_FINE 0x34
#define MIDI_CC_GENERAL8_FINE 0x35
#define MIDI_CC_GENERAL9_FINE 0x36
#define MIDI_CC_GENERAL10_FINE 0x37
#define MIDI_CC_GENERAL12_FINE 0x38
#define MIDI_CC_GENERAL13_FINE 0x39
#define MIDI_CC_GENERAL14_FINE 0x3A
#define MIDI_CC_GENERAL15_FINE 0x3B
#define MIDI_CC_GENERAL16_FINE 0x3C
#define MIDI_CC_GENERAL17_FINE 0x3D
#define MIDI_CC_GENERAL18_FINE 0x3E
#define MIDI_CC_GENERAL19_FINE 0x3F

#define MIDI_CC_SUSTAIN 0x40
#define MIDI_CC_REVERB 0x5B
#define MIDI_CC_CHORUS 0x50
#define MIDI_CC_CONTROL_OFF 0x79
#define MIDI_CC_NOTES_OFF 0x78

//------------------------------------------//

#define NOTE_ON 0x90
#define NOTE_OFF 0x80
#define VELOCITY 20

//------------------------------------------//

SoftwareSerial SSerial(2,3);//set up RX/TX on midi shield

unsigned char notes[] = {
  0x0E, 0x0F, 0x10};

//Generate Note On Event
void note_on(uint8_t notenum, uint8_t velocity)
{
  SSerial.write(NOTE_ON);
  SSerial.write(notenum);
  SSerial.write(VELOCITY);
  
}

//Generate Note Off Event
void note_off(unsigned char notenum)
{
  SSerial.write(NOTE_OFF);
  SSerial.write(notenum);
  SSerial.write(32);
}

long inactivityTimer;
uint8_t activity;

void setup(void)
{
  uint8_t i;
  
  SSerial.begin(31250);
  Serial.begin(38400);
  
  for(int x = 4; x<=6; x++){
    pinMode(x, INPUT);
  }
  
}

void loop()
{
  uint8_t event;
  
  //If no midi activity for while, generate new line
  
  if(activity && (((long)millis() - inactivityTimer) >= 0))
  {
    Serial.println();
    activity = 0;
  }
  
  int val = 0;
  
  for(int x = 4; x<=6; x++){
    val = digitalRead(x);
    if(val == 1){
      unsigned char note = notes[x];
      note_on(note, 20);
    }
    delay(75);
  }
}
  
  
  
