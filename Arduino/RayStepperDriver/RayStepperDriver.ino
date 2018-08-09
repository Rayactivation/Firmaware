git st#include <AccelStepper.h>

int analog_pin = A0;
int dir_pin = 12;
int step_pin = 2;
int max_speed = 2400;
int current_speed = 0;
int sw1_pin = 7;
int sw2_pin = 6;
int st_pin = 4;
int sw1_rp_pin = A4;
int sw2_rp_pin = A5;
int wing_mode;
long last_rt_sw_time;
long last_rt_wait;
int run_state;

long last_ain_time;

#define RT_DELAY 60000
#define START_DELAY 60000
#define RUNNING 1
#define STOPPING 2
#define STOPPED 3

AccelStepper stepper(AccelStepper::DRIVER, step_pin, dir_pin);

double avalue;
double getSmoothedValue(){
  int ar;
  ar = analogRead(analog_pin);
/*  int ar;
  int sw1, sw2;
  int st;
  sw1 = digitalRead(sw1_pin);
  sw2 = digitalRead(sw2_pin);
  st = digitalRead(st_pin);
  ar = analogRead(analog_pin);
  Serial.print(ar);
  Serial.print(" ");
  Serial.print(sw1);
  Serial.print(" ");
  Serial.print(sw2);
  Serial.print(" ");
  Serial.println(run_state);*/
  if(millis() > last_ain_time + 100){
    if(ar > avalue){
      avalue = (avalue * .99) + (.01 * (double)(ar));
    }else{
      avalue = (avalue * .9) + (.1 * (double)(ar));
    }
    last_ain_time = millis();
  }
  return avalue;
}

void stopMotor(){
  stepper.setSpeed(0);
}

void setSpeed(double ain){
  int ts;
  int hys;
  ts = map(ain, 0, 860, 0, max_speed);
  //hys = abs(ts - current_speed);
  //if(hys > 20){
    current_speed = ts;
    stepper.setSpeed(ts);
  //}
}

void setup() {
  // put your setup code here, to run once:
  delay(10000);
  Serial.begin(115200);
  Serial.flush();
  pinMode(analog_pin, A0);
  pinMode(dir_pin, OUTPUT);
  pinMode(sw1_rp_pin, OUTPUT);
  pinMode(sw2_rp_pin, OUTPUT);
  pinMode(sw1_pin, INPUT);
  pinMode(sw2_pin, INPUT);
  pinMode(st_pin, INPUT);
  digitalWrite(dir_pin, HIGH);
  stepper.setMaxSpeed(10000);
  avalue = 0;
  wing_mode = digitalRead(st_pin);
  setSpeed(avalue);    
  run_state = STOPPED;
  last_rt_wait = millis() + RT_DELAY;
  last_ain_time = millis();
  
}

void loop() {
  int sw1;
  int sw2;
  sw1 = digitalRead(sw1_pin);
  sw2 = digitalRead(sw2_pin);
  // put your main code here, to run repeatedly:
  digitalWrite(sw1_rp_pin, sw1);
  digitalWrite(sw2_rp_pin, sw2);
  if(wing_mode == 1){
    setSpeed(getSmoothedValue());  
    stepper.runSpeed();
  }else{
    switch(run_state){
      case RUNNING:
      if(sw1 == 1){
        last_rt_sw_time = millis();    
      }else{
       if(millis() > last_rt_sw_time + RT_DELAY){
         run_state = STOPPING;
       }
      }
      setSpeed(getSmoothedValue());  
      stepper.runSpeed();
      break;
      case STOPPING:
      if(sw2 == 1){
        stopMotor();
        run_state = STOPPED;
        last_rt_sw_time = millis();     
        last_rt_wait = millis() + START_DELAY; 
      }else{
        setSpeed(getSmoothedValue());  
        stepper.runSpeed();
      }
      break;
      case STOPPED:
      if(sw1 == 1){
        last_rt_sw_time = millis();    
      }else{
       if(millis() > last_rt_sw_time + RT_DELAY){
        last_rt_wait = millis() + START_DELAY;
       }
      }
      if(millis() > last_rt_wait){
        run_state = RUNNING;
      }
      getSmoothedValue();
      break;
    }
  }
  
}
