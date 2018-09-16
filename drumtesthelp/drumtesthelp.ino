void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Drum 1");
  //Actuator down
  digitalWrite(3, LOW); //IN2 OFF
  digitalWrite(2, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration1

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  
  //Actuator up
  digitalWrite(2, LOW); //IN2 OFF
  digitalWrite(3, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

  Serial.println("Drum 2");
  //Actuator down
  digitalWrite(4, LOW); //IN2 OFF
  digitalWrite(5, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  //Actuator up
  digitalWrite(5, LOW); //IN2 OFF
  digitalWrite(4, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  Serial.println("Drum 3");
  //Actuator down
  digitalWrite(5, LOW); //IN2 OFF
  digitalWrite(6, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration1

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  //Actuator up
  digitalWrite(5, LOW); //IN2 OFF
  digitalWrite(6, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  Serial.println("Drum 4");
  //Actuator down
  digitalWrite(7, LOW); //IN2 OFF
  digitalWrite(8, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  
  //Actuator up
  digitalWrite(7, LOW); //IN2 OFF
  digitalWrite(8, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

  Serial.println("Drum 5");
  //Actuator down
  digitalWrite(9, LOW); //IN2 OFF
  digitalWrite(10, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  
  //Actuator up
  digitalWrite(10, LOW); //IN2 OFF
  digitalWrite(9, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  Serial.println("Drum 6");
  //Actuator down
  digitalWrite(11, LOW); //IN2 OFF
  digitalWrite(12, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  //Actuator up
  digitalWrite(12, LOW); //IN2 OFF
  digitalWrite(11, HIGH); //IN1 ON
  delay(25);      //Keep on for down duration

  //Change states to stop - IN1 OFF, IN2 OFF
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
