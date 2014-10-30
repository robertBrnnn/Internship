#include "pitches.h"




int value;


const int threshold = 10;



//notes to play corresponding to sensors


int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4 };
  


int low[] = {
  959, 930, 843, 877, 779, 799};
 

 
int high[] = {
  960, 932, 845, 878, 781, 801};  
  
int velocity = 100;//velocity of MIDI notes must be between 0 and 127
//higher velocity usually makes instruments louder

int noteON = 144; //144 = 10010000 in binary, note on command




void setup ()
{
  //setup midi baud rate
  
  Serial.begin(31250);//Midi rate is lower, but midi serial changes to midi rate
  //resulting is less latency problems

}




void loop() {
  

value = analogRead(A0);


  /*Serial.println(value);


  if(value >= low[0] && value <= high[0]){
    

     tone(8, notes[1], 20);
  

  }
  
  

  if(value>=low[2] && value<=high[2]){


    tone(8,notes[2],20);


  }


  if(value>=low[3] && value<=high[3]){


    tone(8,notes[3],20);


  }

  if(value>=low[4] && value<=high[4]){


    tone(8,notes[5],20);


  }
  if(value>=low[5] && value<=high[5]){


    tone(8,notes[6],20);


  }*/
  if(value>=low[6] && value<=high[6]){


    MIDImessage(noteON, notes[6], velocity);
    delay(300); //holds note for 300 ms
    MIDImessage(noteON, notes[6], 0);//turns note off
    delay(200);//wait 200 ms until trigger next note


  }
  
 /* switch(value){
    
    case(value>=low[0] && value<=high[0]):
    MIDImessage(noteON, notes[0], velocity);
    break;
    
  }*/



}

void MIDImessage(int command, int MIDInote, int MIDIvelocity){
  Serial.write(command);
  Serial.write(MIDInote);
  Serial.write(MIDIvelocity);
}
