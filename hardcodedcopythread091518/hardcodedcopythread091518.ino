#include <Cth.h>
#include <Wire.h>

int value;

void setup() {
  Serial.begin(9600);
//  Serial.println("Serial link established.");
  
  //Begin looping threads
  Scheduler.startLoop(readSerial);
}

void readSerial() {
  // Wait for Serial.available():
  Scheduler.wait_available(Serial);
  value = Serial.read();

//  Serial.println (value);

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
    default:
      // TODO: Handle parameter changes here
      break;
  }

}

void drum1(void) {
//      Serial.println("Drum 1");
  //Actuator down
  digitalWrite(2, LOW); //IN2 OFF
  digitalWrite(3, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration1

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  
  //Actuator up
  digitalWrite(3, LOW); //IN2 OFF
  digitalWrite(2, HIGH); //IN1 ON
  delay(35);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  }


void drum2(void) {
//  Serial.println("Drum 2");
  //Actuator down
  digitalWrite(5, LOW); //IN2 OFF
  digitalWrite(4, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  //Actuator up
  digitalWrite(4, LOW); //IN2 OFF
  digitalWrite(5, HIGH); //IN1 ON
  delay(35);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void drum3(void) {
//  Serial.println("Drum 3");
  //Actuator down
  digitalWrite(7, LOW); //IN2 OFF
  digitalWrite(6, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration1

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  
  //Actuator up
  digitalWrite(6, LOW); //IN2 OFF
  digitalWrite(7, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void drum4(void) {
//  Serial.println("Drum 4");
  //Actuator down
  digitalWrite(9, LOW); //IN2 OFF
  digitalWrite(8, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration1

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
  //Actuator up
  digitalWrite(8, LOW); //IN2 OFF
  digitalWrite(9, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void drum5(void) {
  
//  Serial.println("Drum 5");
  //Actuator down
  digitalWrite(10, LOW); //IN2 OFF
  digitalWrite(11, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  //Actuator up
  digitalWrite(11, LOW); //IN2 OFF
  digitalWrite(10, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
}

void drum6(void) {
  
//  Serial.println("Drum 6");
  //Actuator down
  digitalWrite(13, LOW); //IN2 OFF
  digitalWrite(12, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  //Actuator up
  digitalWrite(12, LOW); //IN2 OFF
  digitalWrite(13, HIGH); //IN1 ON
  delay(40);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
}

//void drum7(void) {
//  
//  Serial.println("Drum 7");
//  
//  //Actuator down
//  pwm1.setPin(6, 4095); //PWM ON
//  pwm1.setPin(7, 0); //IN2 OFF
//  pwm1.setPin(8, 4095); //IN1 ON
//  Scheduler.delay(35);       //Keep on for down duration
//
//  //Change states to stop - IN1 OFF, IN2 OFF
//  pwm1.setPin(1, 0); //IN2 OFF
//  pwm1.setPin(2, 0); //IN1 OFF
//  
//  //Actuator up
//  pwm1.setPin(7, 4095); //IN2 ON
//  pwm1.setPin(8, 0); //IN1 OFF
//  Scheduler.delay(35);       //Keep on for up duration
//
//  //Change states to stop - IN1 OFF, IN2 OFF
//  pwm1.setPin(1, 0); //IN2 OFF
//  pwm1.setPin(2, 0); //IN1 OFF
//  
//}
//
//void drum8(void) {
//  
//  Serial.println("Drum 8");
//  
//  //Actuator down
//  pwm1.setPin(11, 4095); //PWM ON
//  pwm1.setPin(10, 0); //IN2 OFF
//  pwm1.setPin(9, 4095); //IN1 ON
//  Scheduler.delay(35);       //Keep on for down duration
//
//  //Change states to stop - IN1 OFF, IN2 OFF
//  pwm1.setPin(10, 0); //IN2 OFF
//  pwm1.setPin(9, 0); //IN1 OFF
//  
//  //Actuator up
//  pwm1.setPin(10, 4095); //IN2 ON
//  pwm1.setPin(9, 0); //IN1 OFF
//  Scheduler.delay(30);       //Keep on for up duration
//
//  //Change states to stop - IN1 OFF, IN2 OFF
//  pwm1.setPin(10, 0); //IN2 OFF
//  pwm1.setPin(9, 0); //IN1 OFF
//}
