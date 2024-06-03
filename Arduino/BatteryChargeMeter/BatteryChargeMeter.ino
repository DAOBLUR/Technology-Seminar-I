// PINS
#define GreenLED D0
#define YellowLED D1
#define RedLED D2

#define BatteryAnalog A0

// VARIABLES
const float maxVoltage = 1.5;
const float midVoltage = 1.3;
const float minVoltage = 0.3;

void setup() 
{  
  Serial.begin(9600);

  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(RedLED, OUTPUT);

  Serial.println("\nInitialize 2...\n");
}

void loop() 
{
  float analogValue = analogRead(BatteryAnalog);
  float voltage = (1.0 / 1023) * analogValue * 3;

  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(1000);

  if(voltage >= maxVoltage)
  {
    digitalWrite(GreenLED, HIGH);
    digitalWrite(YellowLED, LOW);
    digitalWrite(RedLED, LOW);
  }
  else if(voltage < maxVoltage && voltage > midVoltage)
  {
    digitalWrite(GreenLED, LOW);
    digitalWrite(YellowLED, HIGH);
    digitalWrite(RedLED, LOW);
  }
  else if(voltage < midVoltage && voltage > minVoltage)
  {
    digitalWrite(GreenLED, LOW);
    digitalWrite(YellowLED, LOW);
    digitalWrite(RedLED, HIGH);
  }
  else
  {
    digitalWrite(GreenLED, LOW);
    digitalWrite(YellowLED, LOW);
    digitalWrite(RedLED, LOW);
  }
}