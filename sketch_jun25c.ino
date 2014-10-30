void setup(){
  
  Serial.begin(31250);
}

void loop(){
  
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  delay(1);
  
}
