// PINS
const int LEDsDice [4] = { 2, 3, 4, 5 };
const int LEDsDiceSize = sizeof(LEDsDice) / sizeof(int);

const int DisplayLEDs [7] = { 7, 8, 9, 10, 11, 12, 13 };
const int DisplayLEDsSize = sizeof(DisplayLEDs) / sizeof(int);

#define Button 6

#define OrangeLed 9
#define RedLed 10

// VARIABLES
int State = 0;
int Flag = 0;
int isButtonPressed = false;

unsigned long startTime = 0;
unsigned long endTime = 0;

void setup() 
{  
  Serial.begin(9600);

  pinMode(Button, INPUT);

  // INIT DICE LEDs
  for(int i = 0; i < LEDsDiceSize; i++) pinMode(LEDsDice[i], OUTPUT);

  for(int i = 0; i < DisplayLEDsSize; i++) pinMode(DisplayLEDs[i], OUTPUT);
  
}

void loop() 
{
  
  int buttonValue = digitalRead(Button);
  
  Serial.print("Pulser: ");
  Serial.println(buttonValue);
  
  Serial.print("State: ");
  Serial.println(State);
  if(buttonValue == 0) {
    if(!isButtonPressed && startTime == 0) {
      Serial.println("--------------------------------------");
      startTime = millis();
      isButtonPressed = true;
    }

    if (Flag == 0) {
      Flag = 1;
    }
  }
  else
  {
    if(isButtonPressed && startTime > 0) {
      Serial.println("++++++++++++++++++++++++++++++++++++++++");
      endTime = millis();
      unsigned long timeDifference = endTime - startTime;

      isButtonPressed = false;
      startTime = 0;
      endTime = 0;

      if(timeDifference * 1000 > 3) {
        State = 1;
      }
    }
    if(Flag == 1) {
      Flag = 2;
    }
    else if(Flag == 2) {
      int randomNumber = random(1, 7);
      Serial.print("Random: ");
      Serial.println(randomNumber);
      
      //PreRandom();
      RandomDisplay(randomNumber);
      RandomDice(randomNumber);
      
      Flag = 0;
    }
  }
}

void PreRandom()
{
  delay(100);
  for(int i = 0; i < LEDsDiceSize; i++)
  {
    digitalWrite(LEDsDice[i], HIGH);
    delay(100);
  }

  for(int i = 0; i < LEDsDiceSize; i++) 
  {
    digitalWrite(LEDsDice[i], LOW);
  }
  delay(100);
}

void RandomDice(int randomNumber)
{
  for(int i = 0; i < LEDsDiceSize; i++) 
  {
    digitalWrite(LEDsDice[i], LOW);
  }

  switch (randomNumber)
  {
    case 1:
      digitalWrite(LEDsDice[3], HIGH);
      break;
    case 2:
      digitalWrite(LEDsDice[1], HIGH);
      break;
    case 3:
      digitalWrite(LEDsDice[1], HIGH);
      digitalWrite(LEDsDice[3], HIGH);
      break;
    case 4:
      digitalWrite(LEDsDice[0], HIGH);
      digitalWrite(LEDsDice[2], HIGH);
      break;
    case 5:
      digitalWrite(LEDsDice[0], HIGH);
      digitalWrite(LEDsDice[2], HIGH);
      digitalWrite(LEDsDice[3], HIGH);
      break;
    case 6:
      for(int i = 0; i < LEDsDiceSize - 1; i++) 
      {
        digitalWrite(LEDsDice[i], HIGH);
      }
      break;
    default:  
      break;
  }
}

void RandomDisplay(int randomNumber)
{
  /*
    2
  1   3
    0
  4   6
    5
  */
  for(int i = 0; i < DisplayLEDsSize; i++) 
  {
    digitalWrite(DisplayLEDs[i], LOW);
  }

  switch (randomNumber)
  {
    case 1:
      digitalWrite(DisplayLEDs[3], HIGH);
      digitalWrite(DisplayLEDs[6], HIGH);
      break;
    case 2:
      digitalWrite(DisplayLEDs[2], HIGH);
      digitalWrite(DisplayLEDs[3], HIGH);
      digitalWrite(DisplayLEDs[0], HIGH);
      digitalWrite(DisplayLEDs[4], HIGH);
      digitalWrite(DisplayLEDs[5], HIGH);
      break;
    case 3:
      digitalWrite(DisplayLEDs[2], HIGH);
      digitalWrite(DisplayLEDs[3], HIGH);
      digitalWrite(DisplayLEDs[0], HIGH);
      digitalWrite(DisplayLEDs[6], HIGH);
      digitalWrite(DisplayLEDs[5], HIGH);
      break;
    case 4:
      digitalWrite(DisplayLEDs[1], HIGH);
      digitalWrite(DisplayLEDs[3], HIGH);
      digitalWrite(DisplayLEDs[0], HIGH);
      digitalWrite(DisplayLEDs[6], HIGH);
      break;
    case 5:
      digitalWrite(DisplayLEDs[2], HIGH);
      digitalWrite(DisplayLEDs[1], HIGH);
      digitalWrite(DisplayLEDs[0], HIGH);
      digitalWrite(DisplayLEDs[6], HIGH);
      digitalWrite(DisplayLEDs[5], HIGH);
      break;
    case 6:
      digitalWrite(DisplayLEDs[2], HIGH);
      digitalWrite(DisplayLEDs[1], HIGH);
      digitalWrite(DisplayLEDs[0], HIGH);
      digitalWrite(DisplayLEDs[4], HIGH);
      digitalWrite(DisplayLEDs[5], HIGH);
      digitalWrite(DisplayLEDs[6], HIGH);
      break;
    default:  
      break;
  }
}