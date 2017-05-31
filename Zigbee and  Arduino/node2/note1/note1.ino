/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll

 */

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
int sensorValue = 0;  // variable to store the value coming from the sensor
const int motorPin1  = 10; // Pin  7 of L293
const int motorPin2  = 9;  // Pin  2 of L293
const int buzzer = 9; //buzzer to arduino pin 9


void setup() {
   Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
   
}

void loop() {
  
 //Moisture test
 
  Serial.println("Node 3");
  sensorValue = analogRead(sensorPin);              
  Serial.print("Moisture=" );
  lcd.print("Moist=" );                       
  Serial.println(sensorValue); 
  delay(500);
   lcd.print(sensorValue);
   if (sensorValue<1000)
{
     tone(buzzer, 3000); // Send 1KHz sound signal...
  delay(2000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(100);        // ...for 1sec //Set pins as outputs
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
    
    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    
}
  else{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
  }
   
   //DHT sensor
 
 DHT.read11(dht_apin);
 Serial.print("Humidity="); 
 lcd.print(" Humid="); 
 lcd.print(DHT.humidity); 
 Serial.println(DHT.humidity);   
 Serial.print("Temperature=");   
 lcd.print(" Temp=");      
 lcd.print(DHT.temperature);
  Serial.println(DHT.temperature); 
 lcd.print("*C"); 
  Serial.println("*C");        
  // scroll 40 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter<80; positionCounter++) {
    // scroll one position left:
   
    lcd.scrollDisplayLeft();
    // wait a bit:
 delay(150);
  }
lcd.clear();

}
