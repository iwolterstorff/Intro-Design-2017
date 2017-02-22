#include <Wire.h>

#define NUM_CHARS 4

//I am sending/slave

//char turn[NUM_CHARS];
int turn = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(12);
  Wire.onRequest(requestEvent);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
//  Serial.readBytes(turn, NUM_CHARS);
  if (Serial.available() > 0) {
      turn = Serial.parseInt();
    }
  Serial.println(turn);
}

void requestEvent() {
//  memset(chars, 0, NUM_CHARS);
  Wire.write(turn);
}

