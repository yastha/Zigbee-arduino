
void setup() {
  Serial.begin(9600);
  const int motorPin1  = 10; // Pin  7 of L293
  const int motorPin2  = 8;  // Pin  2 of L293
  char r;
}

void loop() {
  
  if (Serial.available()>0){
    Serial.write(Serial.read());
  }
  
   if(r == '1'){
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
  }
  else if(r == '2'){
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
  }
 

}
