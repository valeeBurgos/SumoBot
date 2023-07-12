#include <Button.h>
//Status
int Status = 0;
//Button
Button button1(A4);
//Middle Sonar
int echoM = 13;
int trigM = 5;
int dM = 0;

//Left Sonar
int echoL = 6;
int trigL = 12;
int dL = 0;

//Right Sonar
int echoR = 11;
int trigR = 10;
int dR = 0;

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 2;
int in4 = 4;

void setup() {
  //Pin Declaration
  pinMode(trigM, OUTPUT);
  pinMode(echoM, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  button1.begin();
  Serial.begin(9600);

}

void loop() {
  if(Status==0){
    if (button1.pressed()){
      Status = 1;
      Serial.println("Fight Mode Activated");
      delay(4000);
    }
    else{
      Serial.println("ready");
      delay(200);
    }
  }
  if (Status == 1){
    if(button1.pressed()){
      Status = 0;
      digitalWrite(enB, 0);
	    digitalWrite(in3, LOW);
	    digitalWrite(in4, LOW);
      digitalWrite(enA, 0);
	    digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
      Serial.println("Fight Mode Deactivated");
      delay(10);
    }
    else{
      //get distance for all sensors
      dM = getDistance(trigM, echoM);
      Serial.println(dM);
      delayMicroseconds(10);
      dL = getDistance(trigL, echoL);
      delayMicroseconds(10);
      dR = getDistance(trigR, echoR);
      Serial.println(dR);
      delayMicroseconds(10);
      //print to Monitor where (Left, Middle, Right) the opponent is
      Action(dL,dM,dR);
      delay(50);
    }
  }
}
//getDistance: INT, INT -> INT
//Takes the pins of the sensor and returns the distance of the object to 
//  that sensor 
int getDistance(int triggerPin, int echoPin){
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  unsigned long pulseTime = pulseIn(echoPin, HIGH);
  int distance = pulseTime/58;
  return distance;
}
//recon: INT, INT, INT -> None
//Takes the distance from the 3 sensors and prints to Serial an array where the
//  position of the 1 indicates where is the nearest obstacle. in case no 
//  obstacle is detected, prints NO DETECTION
void Action(int leftDistance, int middleDistance, int rightDistance){
  if (leftDistance >= 100 && middleDistance >= 100 && rightDistance >= 100){
    Serial.println("NO DETECTION");
    digitalWrite(enA, 255);
	  digitalWrite(in1, LOW);
	  digitalWrite(in2, HIGH);
    digitalWrite(enB, 255);
	  digitalWrite(in3, HIGH);
	  digitalWrite(in4, LOW);
    delayMicroseconds(10);
  }
  else{
    int dirL = min(min(leftDistance,middleDistance),rightDistance)/leftDistance;
    int dirR = min(min(leftDistance,middleDistance),rightDistance)/rightDistance;
    int dirM = 1 - max(dirL, dirR);

    Serial.print(dirL);
    Serial.print("|");
    Serial.print(dirM);
    Serial.print("|");
    Serial.print(dirR);
    Serial.println();


   if(dirM == 1){
      digitalWrite(enA, 255);
	    digitalWrite(in1, HIGH);
	    digitalWrite(in2, LOW);
      digitalWrite(enB, 255);
	    digitalWrite(in3, HIGH);
	    digitalWrite(in4, LOW);
      delayMicroseconds(10);
    }
    if (dirR == 1){
      digitalWrite(enA, 255);
	    digitalWrite(in1, HIGH);
	    digitalWrite(in2, LOW);
      digitalWrite(enB, 100);
	    digitalWrite(in3, HIGH);
	    digitalWrite(in4, LOW);
      delayMicroseconds(10);
    }
    if (dirL == 1){
      digitalWrite(enA, 100);
	    digitalWrite(in1, HIGH);
	    digitalWrite(in2, LOW);
      digitalWrite(enB, 255);
	    digitalWrite(in3, HIGH);
	    digitalWrite(in4, LOW);
      delayMicroseconds(10);
    }
  }
}