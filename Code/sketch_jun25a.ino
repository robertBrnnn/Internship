
 int velocity = 100;//velocity of MIDI notes, must be between 0 and 127
 //higher velocity usually makes MIDI instruments louder
 
 int noteON = 144;//144 = 10010000 in binary, note on command
 int noteOFF = 128;//128 = 10000000 in binary, note off command
 
 int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4 };
  


int low[] = {
  959, 930, 843, 877, 779, 799};
 

 
int high[] = {
  960, 932, 845, 878, 781, 801};  

void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
}

void loop() {
  for (int note=50;note<70;note++) {//from note 50 (D3) to note 69 (A4)
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  }
}
