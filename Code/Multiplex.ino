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




void setup ()
{


}




void loop() {
  

value = analogRead(A0);


  Serial.println(value);


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


  }
  if(value>=low[6] && value<=high[6]){


    tone(8,notes[6],20);


  }



}
