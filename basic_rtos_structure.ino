#include "Application.h"

void setup() {
  // put your setup code here, to run once:
  // pinMode(2, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(25, OUTPUT);
  Serial.begin(115200);
  freeRTOS_setup();
}

void loop() {
}
