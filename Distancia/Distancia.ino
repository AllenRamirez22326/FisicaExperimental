



#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int trigPin = A0;
int echoPin = A1;
float distance;
float duration; 
float velocidadDelSonido = 0.0347; 
int temperaturaPin= A2;
void setup() {
   Wire.begin();
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0, 0); 
  lcd.print("Encendido");
  delay(2000);
}

void ultrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * velocidadDelSonido / 2; 
}


void loop() {
  
  ultrasonic();
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.print(distance);
  lcd.print(" cm");
  Serial.println(distance);
  delay(500); 
}
