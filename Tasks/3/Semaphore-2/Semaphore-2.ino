#define SECOND 1000

class Semaphore 
{
  private:
    int RedPin, YellowPin, GreenPin, State, Id;
    unsigned long LastTime;
    
    void UpdateLights() 
    {
      digitalWrite(RedPin, State == 0 ? HIGH : LOW);
      digitalWrite(YellowPin, State == 1 ? HIGH : LOW);
      digitalWrite(GreenPin, State == 2 ? HIGH : LOW);
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
          (State == 0 && currentTime - LastTime >= 5*SECOND) ||
          (State == 1 && currentTime - LastTime >= 2*SECOND) ||
          (State == 2 && currentTime - LastTime >= 5*SECOND)
        ) 
      {
        State = (State + 1) % 3;
        LastTime = currentTime;
        UpdateLights();
      }
    }
};

Semaphore* Semaphores[2];

void setup() 
{
  Semaphores[0] = new Semaphore(0, 13, 12, 11, 0);
  Semaphores[1] = new Semaphore(1, 7, 6, 5, 2);
}

void loop() 
{
  Semaphores[0]->UpdateState();
  Semaphores[1]->UpdateState();
}