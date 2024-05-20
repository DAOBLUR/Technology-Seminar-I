//  Proximity Sensor
#define TrigPin 6
#define EchoPin 7
int PingTravelTime;

int counter = 0;
String str;

void setup() 
{
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  ProximitySensor();
}

void ProximitySensor()
{
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(100);
  PingTravelTime = pulseIn(EchoPin, HIGH);
  delay(25);
  digitalWrite(TrigPin, LOW);
  Serial.println(PingTravelTime/60);

  ReceiveAndSend(PingTravelTime/60);
}

void ReceiveAndSend(int distance) 
{
  //Serial.print("Serial.available = ");
  //Serial.println(Serial.available());
  
  if(Serial.available()) 
  {
    str = Serial.readString();
    Serial.print("str: ");
    Serial.println(str);
    Serial.flush();
  }
  
  Serial.println(distance);
  delay(1000);
}