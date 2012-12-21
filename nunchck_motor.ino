/*
 * ArduinoNunchuk Demo
 * 
 * Copyright 2011-2012 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 * 
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <AFMotor.h>

AF_DCMotor motor(4);
#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();
const int ledPin = 13;
const int ledPin2 = 11;
void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  motor.setSpeed(200);
 
  motor.run(RELEASE);
}

void loop()
{
  nunchuk.update();
  
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
 //forward tilt forward over 500
 
  if (nunchuk.zButton == 1) {
    digitalWrite(ledPin2, HIGH);
    motor.run(BACKWARD);
  } 
  else {
    digitalWrite(ledPin2,LOW); 
    motor.run(RELEASE);
  }
  delay(10);
  if (nunchuk.cButton == 1) {
    digitalWrite(ledPin, HIGH);
    motor.run(FORWARD);
  } 
  else {
    digitalWrite(ledPin,LOW); 
    motor.run(RELEASE);
  }
}
