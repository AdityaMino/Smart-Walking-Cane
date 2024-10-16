#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1; 
Servo servo2;
double distance = 0;
int cloud;
int dist;
int buzz=2;
int bolt =A0;
double freq;
// echo = 5 , trig =6
int i; int a=10; int j;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);// Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo1.attach(3);
  servo2.attach(10);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT);

  lcd.init();         
  lcd.backlight();

  Serial.begin(9600);
  lcd.setCursor(1, 0);
  lcd.print("HELLO & WELCOME");
  lcd.setCursor(1, 1);
  lcd.print("Everyone");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("TO MY");
  lcd.setCursor(1,1);
  lcd.print("MINIPROJECT");
  delay(2000);
  lcd.clear();
  //lcd.setCursor(1, 0);
  //lcd.print("& ADITYA MINOCHA");
  //delay(2000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("SMART WALKING");
  lcd.setCursor(6,6);
  lcd.print("CANE");
  delay(2000);
}

void loop()
{
  
if(Serial.available()>0)  
  { 
    for(i=0;i<=180;i=i+a)
    {
    distance = 0.01723 * readUltrasonicDistance(6, 5);
    dist=distance;
    freq=1100;
    analogWrite(A0,dist);
    Serial.println(distance);
  if (distance < 50) 
    {
      tone(buzz,freq);
    j=i;
    if(j<180)
    {
      lcd.setCursor(0, 0);
      lcd.print("Dist=");
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(1, 1);
      lcd.print("Move Left");
      //Serial.println("Move Left to Avoid Obtsacle");
      delay(20);
      j=i+90;
      servo2.write(j);
    } 
    if(j>180)
    { 
      lcd.setCursor(0, 0);
      lcd.print("Dist=");
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(1, 1);
      lcd.print("Move Right");
      //Serial.println("Move Right to Avoid Obtsacle");
      delay(20);
      j=i-90;
      servo2.write(j);
    }

    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
  if (distance > 50 && distance < 70) {
    tone(buzz,freq);
    delay(25);
     noTone(buzz);
     lcd.setCursor(0, 0);
      lcd.print("Dist=");
      lcd.print(distance);
      lcd.print("cm ");
      lcd.setCursor(1, 1);
      lcd.print("");
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
  }
  if (distance > 70) {
    noTone(buzz);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    lcd.setCursor(0, 0);
      lcd.print("Dist=");
      lcd.print(distance);
      lcd.print("cm ");
      lcd.setCursor(1, 1);
      lcd.print("");
  }

    servo1.write(i); // Set position of Servo motor 1 
	  delay(100); 

    if(i==180)
    {
      a=-10;
    }	
    if(i==0)
    {
      a=10;
    }		 
   
  	 
  delay(10); // Delay a little bit to improve simulation performance
  delay(150);
    }
}
}

