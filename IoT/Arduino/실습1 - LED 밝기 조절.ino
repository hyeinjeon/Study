#include <LiquidCrystal.h>

/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int led = 11;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int val = analogRead(A0);
  int light = map(val, 0, 1023, 0, 255);
  analogWrite(led, light);
  delay(10);// delay in between reads for stability
}

<메모>
map(value, fromLow, fromHigh, toLow, toHigh)

value: 변환할 수
fromLow: 현재 범위 값의 하한
fromHigh: 현재 범위 값의 상한
toLow: 목표 범위 값의 하한
toHigh: 목표 범위 값의 상한

반환: 변환된 값