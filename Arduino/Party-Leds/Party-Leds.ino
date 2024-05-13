#define SECOND 1000
#define BUZZER_PIN 13
int State = 1;

#define PHOTORESISTOR_1 A0
#define PHOTORESISTOR_2 A1

#pragma region NOTES

#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_C6  1047
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_C4  262
#define NOTE_DS4 311
#define NOTE_F4  349
#define NOTE_E4  330
#define NOTE_D4  294
#define NOTE_AS3 233

#define REST 0

#pragma endregion


#pragma region Game of Thrones - GoT

const int GoTMelody[]
{
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, 
  NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4,  NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, 
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4,  NOTE_D4, NOTE_C4, 
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_F4, 
  NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_C4,
  NOTE_DS4, NOTE_F4, NOTE_G4,  NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_AS3, NOTE_D4, 
  NOTE_DS4, NOTE_D4, NOTE_AS3, NOTE_C4, NOTE_C5, NOTE_AS4, NOTE_C4, NOTE_G4, NOTE_DS4, NOTE_DS4, 
  NOTE_F4, NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_C4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_C5, 
  NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, 
  NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, REST, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, 
  NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5
};

const int GotDurations[] = 
{
  8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 
  8, 8, 16, 16, 4, 4, 16, 16, 4, 4, 16, 16, 1, 4, 4, 16, 16, 4, 4, 16, 16, 1, 4, 4, 16, 16, 4, 4, 16, 
  16, 1, 4, 4, 16, 16, 4, 4, 16, 16, 1, 4, 4, 16, 16, 4, 4, 16, 16, 2, 4, 4, 8, 8, 8, 8, 1, 2, 2, 2, 
  2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 4, 4, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 4, 16, 
  16, 8, 8, 16, 16, 8, 16, 16, 16, 8, 8, 16, 16
};

#define GoTSize sizeof(GotDurations)/sizeof(int)
int goTCurrentNote = 0;

#pragma endregion

#pragma region Pirates of the Caribbean - PotC

const int PotCMelody[] = 
{
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST, NOTE_C5, 
  NOTE_D5, NOTE_B4, NOTE_B4, REST, NOTE_A4, NOTE_G4, NOTE_A4, REST, NOTE_E4, NOTE_G4, NOTE_A4, 
  NOTE_A4, REST, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 
  REST, NOTE_A4, NOTE_G4, NOTE_A4, REST, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4, 
  NOTE_C5, NOTE_D5, NOTE_D5, REST, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST, NOTE_E5, NOTE_D5, 
  NOTE_E5, NOTE_A4, REST, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST, NOTE_D5, NOTE_E5, NOTE_A4, 
  REST, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST, NOTE_C5, NOTE_A4, NOTE_B4, REST, NOTE_A4, 
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_B4, 
  NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST, NOTE_A4, NOTE_G4, NOTE_A4,
  REST, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST, 
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST, NOTE_A4, 
  NOTE_B4, NOTE_C5, NOTE_C5, REST, NOTE_D5, NOTE_E5, NOTE_A4, REST, NOTE_A4, NOTE_C5, NOTE_B4, 
  NOTE_B4, REST, NOTE_C5, NOTE_A4, NOTE_B4, REST, NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST, NOTE_D5, REST, REST, 
  NOTE_C5, REST, REST, NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4, NOTE_E5, REST, REST, 
  NOTE_F5, REST, REST, NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST, 
  NOTE_D5, REST, REST, NOTE_C5, REST, REST, NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
};

const int PotCDurations[] = 
{
  8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 
  8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 4, 8, 4,
  8, 8, 8, 4, 8, 8, 8, 8, 4, 4, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 
  4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 
  8, 4, 8, 8, 4, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 4, 4, 8, 4, 4, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 
  8, 4, 4, 8, 4, 8, 8, 8, 8, 8, 2, 4, 8, 4, 4, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 4, 4, 8, 4, 8, 
  8, 8, 8, 8, 2
};

#define PotCSize sizeof(PotCDurations)/sizeof(int)
int potCCurrentNote = 0;

#pragma endregion

void Play()
{
  if(State == 1)
  {
    if(goTCurrentNote >= GoTSize) goTCurrentNote = 0;

    while(goTCurrentNote < GoTSize && State == 1) 
    {
      int duration = SECOND/GotDurations[goTCurrentNote];
      tone(BUZZER_PIN, GoTMelody[goTCurrentNote], duration);

      int pauseBetweenNotes = duration * 1.30;
      delay(pauseBetweenNotes);

      noTone(BUZZER_PIN);
      goTCurrentNote++;
      State = 0;
    }
  }
  else if (State == 2)
  {
    if(potCCurrentNote >= PotCSize) potCCurrentNote = 0;

    while(potCCurrentNote < PotCSize && State == 2) 
    {
      int duration = SECOND/PotCDurations[potCCurrentNote];
      tone(BUZZER_PIN, PotCMelody[potCCurrentNote], duration);

      int pauseBetweenNotes = duration * 1.30;
      delay(pauseBetweenNotes);

      noTone(BUZZER_PIN);
      potCCurrentNote++;
      State = 0;
    }
  }
}

const int Val1 = 400;
const int Val2 = 450;
const int Val3 = 500;
const int Val4 = 550;

int Flag = true;
int Flag2 = true;
int CurrentLight2 = 8;

void TurnLeds(int x) 
{
  if (x < Val4)
  {
    digitalWrite(4, x < Val4 && Flag ? HIGH : LOW);
    digitalWrite(5, x < Val3 && !Flag ? HIGH : LOW);
    digitalWrite(6, x < Val2 && Flag ? HIGH : LOW);
    digitalWrite(7, x < Val1 && !Flag ? HIGH : LOW);
    Play();
    Flag = !Flag;
  }
  else 
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
}

void TurnLeds2(int x) 
{
  if (x < Val4)
  {
    digitalWrite(8, x < Val4 && Flag ? HIGH : LOW);
    digitalWrite(9, x < Val3 && !Flag ? HIGH : LOW);
    digitalWrite(10, x < Val2 && Flag ? HIGH : LOW);
    digitalWrite(11, x < Val1 && !Flag ? HIGH : LOW);
    Play();
    Flag = !Flag;
  }
  else 
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int photoresistor1Value = analogRead(PHOTORESISTOR_1);
  int photoresistor2Value = analogRead(PHOTORESISTOR_2);
  
  if(photoresistor1Value > photoresistor2Value + 5 ) 
  {
    TurnLeds(1000);
    TurnLeds2(photoresistor2Value);
    State = 1;
  }
  else if(photoresistor2Value > photoresistor1Value + 5) 
  {
    TurnLeds2(1000);
    TurnLeds(photoresistor1Value);
    State = 2;
  }
  else
  {
    TurnLeds(1000);
    TurnLeds2(1000);
    State = 0;
  }
}