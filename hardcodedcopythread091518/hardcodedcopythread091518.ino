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

//Begin looping threads
  Scheduler.startLoop(readSerial);
}

void readSerial() {
  // Wait for Serial.available():
  Scheduler.wait_available(Serial);
    value = Serial.read();
    
    Serial.println (value);
// Switch statements for different cases based on which drum you use.
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
//Function for Drum 1
void drum1(void) {
      Serial.println("Drum 1");
      //Actuator down
      pwm0.setPin(0,0); //PWM OFF
      pwm0.setPin(1,0); //IN2 OFF
      pwm0.setPin(2,4095); //IN1 ON
      pwm0.setPin(0,4095); //PWM ON
      Scheduler.delay(60);      //Keep on for down duration
      //Actuator up
      pwm0.setPin(0,0); //PWM OFF
      pwm0.setPin(1,4095); //IN2 ON
      pwm0.setPin(2,0); //IN1 OFF
      pwm0.setPin(0,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for up duration
      pwm0.setPin(0,0); //PWM OFF
      }
// Function for Drum 2
void drum2(void) {
      Serial.println("Drum 2");
      //Actuator down
      pwm0.setPin(5,0); //PWM OFF
      pwm0.setPin(4,0); //IN2 OFF
      pwm0.setPin(3,4095); //IN1 ON
      pwm0.setPin(5,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm0.setPin(5,0); //PWM OFF
      pwm0.setPin(4,4095); //IN2 ON
      pwm0.setPin(3,0); //IN1 OFF
      pwm0.setPin(5,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for up duration
      pwm0.setPin(5,0); //PWM OFF
      }

//Function for Drum 3
void drum3(void) {
      Serial.println("Drum 3");
      //Actuator down
      pwm0.setPin(6,0); //PWM OFF
      pwm0.setPin(7,0); //IN2 OFF
      pwm0.setPin(8,4095); //IN1 ON
      pwm0.setPin(6,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm0.setPin(6,0); //PWM OFF
      pwm0.setPin(7,4095); //IN2 ON
      pwm0.setPin(8,0); //IN1 OFF
      pwm0.setPin(6,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      pwm0.setPin(6,0); //PWM OFF
}
//Function for Drum 4
void drum4(void) {
      Serial.println("Drum 4");
      //Actuator down
      pwm0.setPin(11,0); //PWM OFF
      pwm0.setPin(10,0); //IN2 OFF
      pwm0.setPin(9,4095); //IN1 ON
      pwm0.setPin(11,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm0.setPin(11,0); //PWM OFF
      pwm0.setPin(10,4095); //IN2 ON
      pwm0.setPin(9,0); //IN1 OFF
      pwm0.setPin(11,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      pwm0.setPin(11,0); //PWM OFF
      }

      //---------------PWM 1------------------
// Function for Drum 5
void drum5(void) {
      Serial.println("Drum 5");
      //Actuator down
      pwm1.setPin(0,0); //PWM OFF
      pwm1.setPin(1,0); //IN2 OFF
      pwm1.setPin(2,4095); //IN1 ON
      pwm1.setPin(0,4095); //PWM ON
      Scheduler.delay(60);      //Keep on for down duration
      //Actuator up
      pwm1.setPin(0,0); //PWM OFF
      pwm1.setPin(1,4095); //IN2 ON
      pwm1.setPin(2,0); //IN1 OFF
      pwm1.setPin(0,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for up duration
      pwm1.setPin(0,0); //PWM OFF
      }
// Function for Drunm 6 
void drum6(void) {
      Serial.println("Drum 6");
      //Actuator down
      pwm1.setPin(5,0); //PWM OFF
      pwm1.setPin(4,0); //IN2 OFF
      pwm1.setPin(3,4095); //IN1 ON
      pwm1.setPin(5,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm1.setPin(5,0); //PWM OFF
      pwm1.setPin(4,4095); //IN2 ON
      pwm1.setPin(3,0); //IN1 OFF
      pwm1.setPin(5,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for up duration
      pwm1.setPin(5,0); //PWM OFF
      }

// Function for Drum 7
void drum7(void) {
      Serial.println("Drum 7");
      //Actuator down
      pwm1.setPin(6,0); //PWM OFF
      pwm1.setPin(7,0); //IN2 OFF
      pwm1.setPin(8,4095); //IN1 ON
      pwm1.setPin(6,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm1.setPin(5,0); //PWM OFF
      pwm1.setPin(4,4095); //IN2 ON
      pwm1.setPin(3,0); //IN1 OFF
      pwm1.setPin(5,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      pwm1.setPin(5,0); //PWM OFF
}
// Function for Drum 8
void drum8(void) {
      Serial.println("Drum 8");
      //Actuator down
      pwm1.setPin(11,0); //PWM OFF
      pwm1.setPin(10,0); //IN2 OFF
      pwm1.setPin(9,4095); //IN1 ON
      pwm1.setPin(11,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      //Actuator up
      pwm1.setPin(11,0); //PWM OFF
      pwm1.setPin(10,4095); //IN2 ON
      pwm1.setPin(9,0); //IN1 OFF
      pwm1.setPin(11,4095); //PWM ON
      Scheduler.delay(60);       //Keep on for down duration
      pwm1.setPin(11,0); //PWM OFF
      }
