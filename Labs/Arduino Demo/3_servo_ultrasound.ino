#include <Servo.h>


// Ultrasonic sensor pins
int trigger_pin = 8;
int echo_pin = 12;


// LED pins
int greenLED = 11;
int yellowLED = 10;
int redLED = 9;


// Servo pin
#define SERVO_PIN 13


Servo myservo;


// Distance variables
float duration;
float cm;
float inches;


void setup()
{
  // Serial Monitor
  Serial.begin(9600);


  // Ultrasonic sensor
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);


  // LEDs
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);


  // Servo
  myservo.attach(SERVO_PIN);
  myservo.write(90);   // Start centered
}


void loop()
{
  // Trigger ultrasonic sensor
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);


  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);


  digitalWrite(trigger_pin, LOW);


  // Read echo
  duration = pulseIn(echo_pin, HIGH);


  // Calculate distance
  cm = (duration / 2.0) / 29.1;
  inches = (duration / 2.0) / 74.0;


  // Print to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();


  // Distance logic
  if (cm > 30.0)
  {
    // GREEN
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);


    myservo.write(180);
  }
  else if (cm > 15.0)
  {
    // YELLOW
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);


    myservo.write(90);
  }
  else
  {
    // RED
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);


    myservo.write(0);
  }


  delay(500);
}

