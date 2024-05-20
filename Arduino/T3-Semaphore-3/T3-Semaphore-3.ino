#include <LiquidCrystal.h>

#define SECOND 1000

LiquidCrystal lcd(2,3,4,5,6,7);

class Semaphore 
{
  private:
    int RedPin, GreenPin, YellowPin , State, Id;
    unsigned long LastTime;
    
    void UpdateLights() 
    {
      digitalWrite(RedPin, State == 0 ? HIGH : LOW);
      digitalWrite(GreenPin, State == 1 ? HIGH : LOW);
      digitalWrite(YellowPin, State == 2 ? HIGH : LOW);
      Print();
    }

    void Print()
    {
      char buffer[16];

      switch (State) {
        case 0:
          sprintf(buffer, "Sem %d: RED   ", Id);
          break;
        case 1:
          sprintf(buffer, "Sem %d: GREEN ", Id);
          break;
        case 2:
          sprintf(buffer, "Sem %d: YELLOW", Id);
          break;
        default:
          sprintf(buffer, "Sem %d: ERROR ", Id);
          break;
      }

      if(Id == 0) lcd.setCursor(0, 0);
      else lcd.setCursor(0, 1);
    
      Serial.println(buffer);
      lcd.print(buffer);
    }
    
  public:
    Semaphore(int id, int redPin, int yellowPin, int greenPin, int initialState) 
    {
      Id = id;
      RedPin = redPin;
      YellowPin = yellowPin;
      GreenPin = greenPin;
      State = initialState;
      LastTime = millis();
      
      pinMode(RedPin, OUTPUT);
      pinMode(YellowPin, OUTPUT);
      pinMode(GreenPin, OUTPUT);
      
      UpdateLights();
    }

    void UpdateState() 
    {
      unsigned long currentTime = millis();
      
      if(
          (State == 0 && currentTime - LastTime >= 7*SECOND) ||
          (State == 1 && currentTime - LastTime >= 5*SECOND) ||
          (State == 2 && currentTime - LastTime >= 2*SECOND)
        ) 
      {
        State = (State + 1) % 3;
        LastTime = currentTime;
        UpdateLights();
      }
    }
};

void StartingLCD()
{
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Semaphore");
  
  lcd.setCursor(0, 1);
  lcd.print("Starting");
  delay(0.25*SECOND);

  for(int i = 0; i < 5; i++) 
  {
    lcd.setCursor(0, 0);
    lcd.print("Semaphore");
    lcd.setCursor(0, 1);
    lcd.print("Starting.  ");
    delay(0.25*SECOND);

    lcd.setCursor(0, 0);
    lcd.print("Semaphore");
    lcd.setCursor(0, 1);
    lcd.print("Starting.. ");
    delay(0.25*SECOND);

    lcd.setCursor(0, 0);
    lcd.print("Semaphore");
    lcd.setCursor(0, 1);
    lcd.print("Starting...");
    delay(0.25*SECOND);
    
    lcd.clear();
  }

  lcd.clear();
}

Semaphore* Semaphores[2];

void setup() 
{
  StartingLCD();

  Semaphores[0] = new Semaphore(0, 13, 12, 11, 0);
  Semaphores[1] = new Semaphore(1, 10, 9, 8, 1);
}

void loop() 
{
  Semaphores[0]->UpdateState();
  Semaphores[1]->UpdateState();
}