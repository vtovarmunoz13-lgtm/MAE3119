int trigger_pin = 8;
int echo_pin = 12;

// creating variables for distance calculations to be preformed later
float duration;
float cm;
float inches;
 
void setup() 
{
  // set up serial monitor at a baud rate of 9600 
  Serial.begin (9600);

  // declaring the pin modes as either output or input
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  // LEDs
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

 
void loop() 
{
  // activating the ultrasonic sensor to collect pulse length data
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  // placing the pulse length data in the "duration" variable
  duration = pulseIn(echo_pin, HIGH);

  // calculate the distance from the pulse length data
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  // Sending the raw and calculated distances (cm and inches) to the serial monitor 
  Serial.print("duration(ms):");
  Serial.print(duration);
  Serial.print(", cm:");
  Serial.print(cm);
  Serial.print(", inches:");
  Serial.print(inches);
  Serial.println();

  // creating a statement saying:
  // if the distance (cm) is greater than 30 then turn on pin 11 (LED #1)
  // if the distance (cm) is greater than 15 and equal to or less than 30 then turn on pin 10 (LED #2)
  // if the distance (cm) is anything else, turn on pin 9 (LED #3)
  if(cm > 10) 
    {
        digitalWrite(11,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
    }
    else if(cm > 5 && cm <= 10) 
    {
        digitalWrite(11,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(9,LOW);
    }
    else 
    {
        digitalWrite(11,LOW);
        digitalWrite(10,LOW);
        digitalWrite(9,HIGH);
    }
    
   // delay 500 milliseconds (0.5 seconds)
  delay(500);
    }
