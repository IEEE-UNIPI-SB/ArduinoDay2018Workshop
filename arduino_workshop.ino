// Oria sta opia ginontai interactions apo to arduino
#define GREENLIMIT 70
#define BLUELIMIT 60
#define REDLIMIT 50
#define CRASHLIMIT 40
// constants me ta pins pou xrisimopoiountai
const int trigPin = 6;
const int echoPin = 7;
const int buzzer = 8;
const int greenLed = 11;
const int blueLed = 12;
const int redLed = 13;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration= pulseIn(echoPin,HIGH);
  distance= (duration/2)/29.1;

  Serial.print("distance: ");
  Serial.println(distance);
  // anavei ta leds me vasi to an i apostasi ksepernaei ta oria tous
  digitalWrite(greenLed, distance < GREENLIMIT ? HIGH : LOW);
  digitalWrite(blueLed, distance < BLUELIMIT ? HIGH : LOW);
  digitalWrite(redLed, distance < REDLIMIT ? HIGH : LOW);

  // an ksepernaei to CRASHLIMIT tote kanei ena beep to buzzer
  if (distance < CRASHLIMIT) {
    tone(buzzer, 1000);
  }
  delay(100);
  noTone(buzzer);
  delay(100);
}
