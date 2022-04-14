#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

int LEDB=11;
int LEDR=9;
int BUZR=6;
int tim = 1;  //the value of delay time
int serial;

void setup()
{ Serial.begin(1);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(BUZR, OUTPUT); 
}

void loop() 
{  digitalWrite(LEDB, HIGH);  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distance<10)
  {
      digitalWrite(BUZR, HIGH);
      delay(500);
      digitalWrite(BUZR, LOW);
  }
  if(Serial.available()>0){
      serial=Serial.read();
      delay(10);
      if(serial=='1')
    {digitalWrite(LEDR, HIGH);
      digitalWrite(LEDB, LOW);
      digitalWrite(BUZR, HIGH);
      delay(3000);
      digitalWrite(LEDB, HIGH);
      digitalWrite(LEDR, LOW);
      digitalWrite(BUZR, LOW);
    }
   }
}
