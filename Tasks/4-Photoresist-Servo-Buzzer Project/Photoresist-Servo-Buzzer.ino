#include <Servo.h>

#define BUZZER_PIN 13
Servo MyServo;

#define SERVO_PIN 2
int State = 1;

#define PHOTORESISTOR_1 A0
#define PHOTORESISTOR_2 A1

#pragma region NOTES

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_DB3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_EB3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
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
      int duration = 1000/GotDurations[goTCurrentNote];
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
      int duration = 1000/PotCDurations[potCCurrentNote];
      tone(BUZZER_PIN, PotCMelody[potCCurrentNote], duration);

      int pauseBetweenNotes = duration * 1.30;
      delay(pauseBetweenNotes);

      noTone(BUZZER_PIN);
      potCCurrentNote++;
      State = 0;
    }
  }
}

double GetAngleIncrement(int x) 
{
  if (x < 100) x = 100;
  if (x > 800) x = 800;

  return 8 - (x-100) * (8-1) / (800-100);
}

void setup()
{
  //Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  
  MyServo.attach(SERVO_PIN);
  MyServo.write(90);
}

void loop()
{
  int currentAngle = MyServo.read();
  /*
  Serial.print("Current Angle: ");
  Serial.println(currentAngle);
  */
  int photoresistor1Value = analogRead(PHOTORESISTOR_1);
  int photoresistor2Value = analogRead(PHOTORESISTOR_2);
  /*
  Serial.print("LDR 01: ");
  Serial.print(photoresistor1Value);
  Serial.print(" - LDR 02: ");
  Serial.println(photoresistor2Value);
  */
  // Error margin = 5
  if(photoresistor1Value > photoresistor2Value + 5 ) 
  {
    MyServo.write(currentAngle + GetAngleIncrement(photoresistor2Value));
    State = 1;
  }
  else if(photoresistor2Value > photoresistor1Value + 5) 
  {
    MyServo.write(currentAngle - GetAngleIncrement(photoresistor1Value));
    State = 2;
  }
  else
  {
    State = 0;
  }

  Play();

  delay(10);

  if(currentAngle == 0 || currentAngle == 180)
  {
    MyServo.write(90);
  }
}