

// include the lcd library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//include the dht library
#include <dht.h> // load lib                    
#define dht_apin   6
dht DHT; 
//for moisture sensor
int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;
int sensorValue1 = 0;  // variable to store the value coming from the sensor
const int buzzer = 9; //buzzer to arduino pin 9
const int motorPin1  = 10; // Pin  7 of L293
const int motorPin2  = 9;  // Pin  2 of L293
char r;

void setup() {
   Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  DHT.read11(dht_apin);
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
    pinMode(8,OUTPUT);
    pinMode(10,OUTPUT);
  
}

void loop() {
  DHT.read11(dht_apin);
 //Node 3
  Serial.print(3);
  Serial.print(",");
  
  //Temperature
 lcd.print("Temp=");      
 lcd.print(DHT.temperature);
 lcd.print("*C");

 Serial.print(DHT.temperature); 
 Serial.print(",");

 //Humidity
 lcd.print(" Humid="); 
 lcd.print(DHT.humidity);
 lcd.print("*C");
  
 Serial.print(DHT.humidity); 
 Serial.print (","); 
  
  //Moisture       
  
  sensorValue = analogRead(sensorPin);
  sensorValue1=sensorValue/10;
              
 lcd.print("Moist=" );  
 lcd.print(sensorValue);
                      
 Serial.print(sensorValue1); 

 //
   
    if(sensorValue<1000){
        delay(1000);       
        noTone(buzzer);    
        delay(1000);      
            
    }
  
 for (int positionCounter = 0; positionCounter<80; positionCounter++) {
  lcd.scrollDisplayLeft();
  delay(5000);
  
 }
 lcd.clear();
   if(r == '1'){
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
  }
  else if(r == '2'){
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
  }
 
  }
 
