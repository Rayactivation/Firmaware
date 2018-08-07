#include <AccelStepper.h>

int analog_pin = A0;
int dir_pin = 12;
int step_pin = 2;
AccelStepper stepper(AccelStepper::DRIVER, step_pin, dir_pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(dir_pin, OUTPUT);
  digitalWrite(dir_pin, HIGH);
  stepper.setMaxSpeed(10000);
  stepper.setSpeed(500);    
}
void loop() {
  // put your main code here, to run repeatedly:
  stepper.runSpeed();
}
