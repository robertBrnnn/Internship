void setup(){
  Serial.begin(38400);
  
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}

void loop(){
  int val = 0;
  
  for(int x = 4; x<=5; x++){
    val = digitalRead(x);
    if(val == 1){
      Serial.print("Pin ");
      Serial.print(x);
    }
    delay(75);
  }
}
  
  
