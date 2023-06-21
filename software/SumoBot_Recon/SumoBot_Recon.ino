//Middle Sonar
int echoM = 2;
int trigM = 3;
int dM = 0;

//Left Sonar
int echoL = 6;
int trigL = 7;
int dL = 0;

//Right Sonar
int echoR = 8;
int trigR = 9;
int dR = 0;

void setup() {
  //Pin Declaration
  pinMode(trigM, OUTPUT);
  pinMode(echoM, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  Serial.begin(9600);

}

void loop() {
  //get distance for all sensors
  dM = getDistance(trigM, echoM);
  delayMicroseconds(10);
  dL = getDistance(trigL, echoL);
  delayMicroseconds(10);
  dR = getDistance(trigR, echoR);
  //print to Monitor where (Left, Middle, Right) the opponent is
  recon(dL,dM,dR);
  delay(50);
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
void recon(int leftDistance, int middleDistance, int rightDistance){
  if (leftDistance >= 100 && middleDistance >= 100 && rightDistance >= 100){
    Serial.println("NO DETECTION");
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
  }
}