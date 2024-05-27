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
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(100);
  PingTravelTime = pulseIn(EchoPin, HIGH);
  delay(25);
  digitalWrite(TrigPin, LOW);
  Serial.println(PingTravelTime/60);

  //ReceiveAndSend(PingTravelTime/60);
    
  int x = (PingTravelTime/60);
    
  digitalWrite(8, x < 10 ? HIGH : LOW);
  digitalWrite(9, x < 15 && x > 10 ? HIGH : LOW);
  digitalWrite(10, x < 20 && x > 15 ? HIGH : LOW);
  
  if(x < 5)
  {
    tone(12, 100, 100);    
  }
  else
  {
    noTone(12);
  }
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