#include <Cth.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int value;

//instantiate pwm controllers
Adafruit_PWMServoDriver pwm0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial link established.");

  //Initialize pwms

  pwm0.begin();
  pwm0.setPWMFreq(1600);  // This is the maximum PWM frequency
  Serial.println("PWM 0 initialized.");

  pwm1.begin();
  pwm1.setPWMFreq(1600);  // This is the maximum PWM frequency
  Serial.println("PWM 1 initialized.");

  //Set up all actuators in stop state
  //PWM 0
  //Loop "A" channels
  for(int i=0; i<4; i+=3){
    //Change states to stop - PWM ON, IN1 OFF, IN2 OFF
    pwm0.setPin(i, 4095); //PWM ON
    pwm0.setPin(i+1, 0); //IN1 OFF
    pwm0.setPin(i+2, 0); //IN2 OFF
  }
  //Loop "B" channels
  for(int i=3; i<4; i+=3){
    //Change states to stop - PWM ON, IN1 OFF, IN2 OFF
    pwm0.setPin(i, 4095); //PWM ON
    pwm0.setPin(i+1, 0); //IN2 OFF
    pwm0.setPin(i+2, 0); //IN1 OFF
  }
    //Loop "A" channels
  for(int i=0; i<4; i+=3){
    //Change states to stop - PWM ON, IN1 OFF, IN2 OFF
    pwm0.setPin(i, 4095); //PWM ON
    pwm0.setPin(i+1, 0); //IN1 OFF
    pwm0.setPin(i+2, 0); //IN2 OFF
  }
  //PWM 1
  //Loop "B" channels
  for(int i=3; i<4; i+=3){
    //Change states to stop - PWM ON, IN1 OFF, IN2 OFF
    pwm0.setPin(i, 4095); //PWM ON
    pwm0.setPin(i+1, 0); //IN2 OFF
    pwm0.setPin(i+2, 0); //IN1 OFF
  }
  //Begin looping threads
  Scheduler.startLoop(readSerial);
}

void readSerial() {
  // Wait for Serial.available():
  Scheduler.wait_available(Serial);
  value = Serial.read();

  Serial.println (value);

  switch (value) {
    case '1':
      Scheduler.start(drum1);
      break;
    case '2':
      Scheduler.start(drum2);
      break;
    case '3':
      Scheduler.start(drum3);
      break;
    case '4':
      Scheduler.start(drum4);
      break;
    case '5':
      Scheduler.start(drum5);
      break;
    case '6':
      Scheduler.start(drum6);
      break;
    case '7':
      Scheduler.start(drum7);
      break;
    case '8':
      Scheduler.start(drum8);
      break;
    default:
      // TODO: Handle parameter changes here
      break;
  }

}

void drum1(void) {
  Serial.println("Drum 1");
  //Actuator down
  pwm0.setPin(0, 4095); //PWM ON
  pwm0.setPin(1, 0); //IN2 OFF
  pwm0.setPin(2, 4095); //IN1 ON
  Scheduler.delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(1, 0); //IN2 OFF
  pwm0.setPin(2, 0); //IN1 OFF
  
  //Actuator up
  pwm0.setPin(1, 4095); //IN2 ON
  pwm0.setPin(2, 0); //IN1 OFF
  Scheduler.delay(25);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(1, 0); //IN2 OFF
  pwm0.setPin(2, 0); //IN1 OFF
}

void drum2(void) {
  Serial.println("Drum 2");
  //Actuator down
  pwm0.setPin(5, 4095); //PWM ON
  pwm0.setPin(4, 0); //IN2 OFF
  pwm0.setPin(3, 4095); //IN1 ON
  Scheduler.delay(30);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(4, 0); //IN2 OFF
  pwm0.setPin(3, 0); //IN1 OFF
  
  //Actuator up
  pwm0.setPin(4, 4095); //IN2 ON
  pwm0.setPin(3, 0); //IN1 OFF
  Scheduler.delay(30);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(4, 0); //IN2 OFF
  pwm0.setPin(3, 0); //IN1 OFF
}

void drum3(void) {
  Serial.println("Drum 3");

  //Actuator down
  pwm0.setPin(6, 4095); //PWM ON
  pwm0.setPin(7, 0); //IN2 OFF
  pwm0.setPin(8, 4095); //IN1 ON
  Scheduler.delay(25);       //Keep on for down duration
  
  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(7, 0); //IN2 OFF
  pwm0.setPin(8, 0); //IN1 OFF
  
  //Actuator up
  pwm0.setPin(7, 4095); //IN2 ON
  pwm0.setPin(8, 0); //IN1 OFF
  Scheduler.delay(25);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(7, 0); //IN2 OFF
  pwm0.setPin(8, 0); //IN1 OFF

}

void drum4(void) {

  //Need to request opposite direction for this actuator.
  
  Serial.println("Drum 4");
  
  //Actuator up
  pwm0.setPin(11, 4095); //PWM ON
  pwm0.setPin(10, 4095); //IN2 ON
  pwm0.setPin(9, 0); //IN1 OFF
  Scheduler.delay(35);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(10, 0); //IN2 OFF
  pwm0.setPin(9, 0); //IN1 OFF

  //Actuator down
  pwm0.setPin(10, 0); //IN2 OFF
  pwm0.setPin(9, 4095); //IN1 ON
  Scheduler.delay(35);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm0.setPin(10, 0); //IN2 OFF
  pwm0.setPin(9, 0); //IN1 OFF
  
}

//---------------PWM 1------------------

void drum5(void) {
  
  Serial.println("Drum 5");

  //Actuator down
  pwm1.setPin(0, 4095); //PWM ON
  pwm1.setPin(2, 4095); //IN1 ON
  pwm1.setPin(1, 0); //IN2 OFF
  Scheduler.delay(30);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(1, 0); //IN2 OFF
  pwm1.setPin(2, 0); //IN1 OFF

  //Actuator up
  pwm1.setPin(2, 0); //IN1 OFF
  pwm1.setPin(1, 4095); //IN2 ON
  Scheduler.delay(30);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(1, 0); //IN2 OFF
  pwm1.setPin(2, 0); //IN1 OFF
  
}

void drum6(void) {
  
  Serial.println("Drum 6");
  //Actuator down
  pwm1.setPin(5, 4095); //PWM ON
  pwm1.setPin(4, 0); //IN2 OFF
  pwm1.setPin(3, 4095); //IN1 ON
  Scheduler.delay(35);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(4, 0); //IN2 OFF
  pwm1.setPin(3, 0); //IN1 OFF
  
  //Actuator up
  pwm1.setPin(4, 4095); //IN2 ON
  pwm1.setPin(3, 0); //IN1 OFF
  Scheduler.delay(30);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(4, 0); //IN2 OFF
  pwm1.setPin(3, 0); //IN1 OFF
  
}

void drum7(void) {
  
  Serial.println("Drum 7");
  
  //Actuator down
  pwm1.setPin(6, 4095); //PWM ON
  pwm1.setPin(7, 0); //IN2 OFF
  pwm1.setPin(8, 4095); //IN1 ON
  Scheduler.delay(35);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(1, 0); //IN2 OFF
  pwm1.setPin(2, 0); //IN1 OFF
  
  //Actuator up
  pwm1.setPin(7, 4095); //IN2 ON
  pwm1.setPin(8, 0); //IN1 OFF
  Scheduler.delay(35);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(1, 0); //IN2 OFF
  pwm1.setPin(2, 0); //IN1 OFF
  
}

void drum8(void) {
  
  Serial.println("Drum 8");
  
  //Actuator down
  pwm1.setPin(11, 4095); //PWM ON
  pwm1.setPin(10, 0); //IN2 OFF
  pwm1.setPin(9, 4095); //IN1 ON
  Scheduler.delay(35);       //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(10, 0); //IN2 OFF
  pwm1.setPin(9, 0); //IN1 OFF
  
  //Actuator up
  pwm1.setPin(10, 4095); //IN2 ON
  pwm1.setPin(9, 0); //IN1 OFF
  Scheduler.delay(30);       //Keep on for up duration

  //Change states to stop - IN1 OFF, IN2 OFF
  pwm1.setPin(10, 0); //IN2 OFF
  pwm1.setPin(9, 0); //IN1 OFF
}
