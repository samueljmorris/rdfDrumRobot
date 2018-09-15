#include <DeepSleepScheduler.h>
#include <DeepSleepScheduler_avr.h>
#include <DeepSleepScheduler_esp.h>

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

}

void loop() {

  Serial.println("Starting loop.");

  if (Serial.available()) {
  
    value = Serial.read();
    if (value == 1) {
      Serial.println("Drum 1");
      //Actuator down
      
      //Disable output
      pwm0.setPin(0,0); //PWM OFF
      //Switch states
      pwm0.setPin(1,0); //IN2 OFF
      pwm0.setPin(2,4095); //IN1 ON
      //Enable output
      pwm0.setPin(0,4095); //PWM ON
      //Keep on for down duration
      delay(300); //0.1 second
      
      //Actuator up
    
      //Disable output
      pwm0.setPin(0,0); //PWM OFF
      //Switch states
      pwm0.setPin(1,4095); //IN2 ON
      pwm0.setPin(2,0); //IN1 OFF
      //Enable output
      pwm0.setPin(0,4095); //PWM ON
      //Keep on for down duration
      delay(300); //0.1 second
      }
    if (value == 2) {
      Serial.println("Drum 2");
      //Actuator down
      
      //Disable output
      pwm0.setPin(5,0); //PWM OFF
      //Switch states
      pwm0.setPin(4,0); //IN2 OFF
      pwm0.setPin(3,4095); //IN1 ON
      //Enable output
      pwm0.setPin(5,4095); //PWM ON
      //Keep on for down duration
      delay(300); //0.1 second
      
      //Actuator up
    
      //Disable output
      pwm0.setPin(5,0); //PWM OFF
      //Switch states
      pwm0.setPin(4,4095); //IN2 ON
      pwm0.setPin(3,0); //IN1 OFF
      //Enable output
      pwm0.setPin(5,4095); //PWM ON
      //Keep on for down duration
      delay(300); //0.1 second
      }
    if (value == 3) {
      Serial.println("Drum 3");
      //Actuator down
      
      //Disable output
      pwm0.setPin(5,0); //PWM OFF
      //Switch states
      pwm0.setPin(4,0); //IN2 OFF
      pwm0.setPin(3,4095); //IN1 ON
      //Enable output
      pwm0.setPin(5,4095); //PWM ON
      //Keep on for down duration
      delay(100); //0.1 second
      
      //Actuator up
    
      //Disable output
      pwm0.setPin(5,0); //PWM OFF
      //Switch states
      pwm0.setPin(4,4095); //IN2 ON
      pwm0.setPin(3,0); //IN1 OFF
      //Enable output
      pwm0.setPin(5,4095); //PWM ON
      //Keep on for down duration
      delay(100); //0.1 second
      }
    
    Serial.println (value);
}
}
