//  Proximity Sensor
#define TriggerPin 6
#define EchoPin 7

float Distance;
float Duration;

int counter = 0;
int code;

void setup() 
{
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() 
{
  ProximitySensor();
}

void ProximitySensor()
{  
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TriggerPin, LOW);
  
  delayMicroseconds(10);
  Duration = pulseIn(EchoPin, HIGH);
  Distance = (Duration * 0.035)/2;
  
  int intDistance = Distance;

  digitalWrite(8, intDistance < 11 && intDistance > 5 ? HIGH : LOW);
  digitalWrite(9, intDistance < 16 && intDistance > 10 ? HIGH : LOW);
  digitalWrite(10, intDistance < 21 && intDistance > 15 ? HIGH : LOW);

  //Serial.println(intDistance);
  
  if(intDistance < 6)
  {
    tone(12, 100, 100);
  }
  else
  {
    noTone(12);
  }

  if(counter > 35)
  {
    ReceiveAndSend(intDistance);
    counter = 0;
  }
  else 
  {
    counter++;
  }
  delay(25);
}

void ReceiveAndSend(int distance) 
{
  /*
  if (Serial.available() > 0) 
  {
    String getSerial = Serial.readString();
    code = getSerial.toInt();
    //Serial.print(code);
    Serial.flush();
  }
  */
  //Sending new data to Esp8266
  Serial.println(distance);
}