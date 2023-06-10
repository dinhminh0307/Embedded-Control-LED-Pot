#include <Arduino.h>


int redPin = 11;
int yellowPin = 5;
int greenPin = 6;
int readPin = A1;
int readVal = 0;
float Vout = 0.0;
int rate = 9600;
int delayVal = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(readPin, INPUT);
  Serial.begin(rate);
}

// put function definitions here:
float changeColor(float Volt, float Vout) {
  Volt += Vout;
  return (Volt / 5.) * 255;
}

float calculateVoltage(int readVal) {
  return (5./1023.) * readVal;
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin); // Read the value from the pin

  // Calculate the actual voltage
  float voltagePin = 0.0;
  
  Vout = calculateVoltage(readVal);
  Serial.println(Vout);
  delay(delayVal);

  voltagePin = changeColor(voltagePin, Vout);
  analogWrite(redPin, voltagePin);
}

// V = 255 = 5V, V =0 = 0
// Vout = x => 
