/**/
int red  = 13;
int yellow = 12;
int green = 11;

int const SECOND = 1000;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(7.5*SECOND);
  digitalWrite(red, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(2*SECOND);
  digitalWrite(yellow, LOW);
  
  digitalWrite(green, HIGH);
  delay(5*SECOND);
  digitalWrite(green, LOW);
}
*/