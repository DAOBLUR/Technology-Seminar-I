  #include <Servo.h>

#define  a3f    208     // 208 Hz
#define b3f    233     // 233 Hz
#define  b3     247     // 247 Hz
#define  c4     261
     // 261 Hz MIDDLE C
#define  c4s    277     // 277 Hz
#define  e4f    311
     // 311 Hz    
#define  f4     349     // 349 Hz 
#define  a4f    415
     // 415 Hz  
#define  b4f    466     // 466 Hz 
#define  b4     493     //493 Hz 
#define  c5     523     // 523 Hz 
#define  c5s    554     // 554 Hz
#define  e5f    622     // 622 Hz  
#define  f5     698     // 698 Hz 
#define f5s    740     // 740 Hz
#define  a5f    831     // 831 Hz 

#define rest    -1

int piezo = 13; // Connect your piezo buzzer to this pin or changeit to match your circuit!
int led = LED_BUILTIN; 

volatile int beatlength
  = 100; // determines tempo
float beatseparationconstant = 0.3;

int threshold;

int
  a; // part index
int b; // song index
int c; // lyric index

boolean flag;

// Parts 1 and 2 (Intro)

int song1_intro_melody[] =
{c5s,
  e5f, e5f, f5, a5f, f5s, f5, e5f, c5s, e5f, rest, a4f, a4f};

int song1_intro_rhythmn[]
  =
{6, 10, 6, 6, 1, 1, 1, 1, 6, 10, 4, 2, 10};

// Parts 3 or 5 (Verse 1)

int
  song1_verse1_melody[] =
{ rest, c4s, c4s, c4s, c4s, e4f, rest, c4, b3f, a3f,

  rest, b3f, b3f, c4, c4s, a3f, a4f, a4f, e4f,
  rest, b3f, b3f, c4, c4s, b3f,
  c4s, e4f, rest, c4, b3f, b3f, a3f,
  rest, b3f, b3f, c4, c4s, a3f, a3f, e4f,
  e4f, e4f, f4, e4f,
  c4s, e4f, f4, c4s, e4f, e4f, e4f, f4, e4f, a3f,
  rest,
  b3f, c4, c4s, a3f, rest, e4f, f4, e4f
};

int song1_verse1_rhythmn[] =
{
  2, 1, 1, 1, 1, 2, 1, 1, 1, 5,
  1, 1, 1, 1, 3, 1, 2, 1, 5,
  1, 1, 1, 1, 1,
  1, 1, 2, 1, 1, 1, 1, 3,
  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4,
  5, 1, 1, 1,
  1, 1, 1, 1, 2, 2,
  2, 1, 1, 1, 3, 1, 1, 1, 3
};

const char* lyrics_verse1[]
  =
{ "We're ", "no ", "strangers ", "", "to ", "love ", "", "\
\
",


};

//Parts 4 or 6 (Chorus)

int song1_chorus_melody[] =
{ b4f, b4f, a4f, a4f,

  f5, f5, e5f, b4f, b4f, a4f, a4f, e5f, e5f, c5s, c5, b4f,
  c5s, c5s, c5s, c5s,

  c5s, e5f, c5, b4f, a4f, a4f, a4f, e5f, c5s,
  b4f, b4f, a4f, a4f,
  f5,
  f5, e5f, b4f, b4f, a4f, a4f, a5f, c5, c5s, c5, b4f,
  c5s, c5s, c5s, c5s,

  c5s, e5f, c5, b4f, a4f, rest, a4f, e5f, c5s, rest
};

int song1_chorus_rhythmn[]
  =
{ 1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,

  3, 3, 3, 1, 2, 2, 2, 4, 8,
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3,
  1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8, 4
};

const char*
  lyrics_chorus[] =
{};

Servo MyServo;
int ServoPin = 2;
int ServoAngle = 0;
int ServoAngle2 = 180;
bool isAngle1 = true;

#define FOTORRESISTENCIA_1 A0
#define FOTORRESISTENCIA_2 A1

void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode(led,
  OUTPUT);

  digitalWrite(led, LOW);
  Serial.begin(9600);
  flag = true;
	
  a = 4;
  b = 0;
  c = 0;
  //
  MyServo.attach(ServoPin);
  MyServo.write(90);
}

void loop()
{
  int currentAngle = MyServo.read();
  Serial.print("Current Angle: ");
  Serial.println(currentAngle);
  
  int valorFotoresistencia1 = analogRead(FOTORRESISTENCIA_1);
  int valorFotoresistencia2 = analogRead(FOTORRESISTENCIA_2);
  
  Serial.print("LDR 01: ");
  Serial.print(valorFotoresistencia1);
  Serial.print(" - LDR 02: ");
  Serial.println(valorFotoresistencia2);
  
  if(valorFotoresistencia1 < valorFotoresistencia2) 
  {
    //Serial.println(valorFotoresistencia1);
    MyServo.write(currentAngle+1);
    ServoAngle++;
  }
  else if(valorFotoresistencia2 < valorFotoresistencia1) 
  {
    //Serial.println(valorFotoresistencia2);
    MyServo.write(currentAngle-1);
    ServoAngle2--;
  }
  
  ///
  
  //
  delay(10);
  //angulo = MyServo.read();
  //Serial.print("Angulo actual del servo: ");
  //Serial.println(angulo);
  
  
  if (flag == true) 
  {
    play();
  }
}





void Play() 
{
  int noteLength;
  if (a == 1 || a == 2) 
  {
    // intro
    noteLength = beatlength * song1_intro_rhythmn[b];

    if (song1_intro_melody[b] > 0) 
    {
      digitalWrite(led, HIGH);
      tone(piezo, song1_intro_melody[b], noteLength);
    }

    b++;

    if b >= sizeof(song1_intro_melody) / sizeof(int)) 
    {
      a++;
      b = 0;
      c = 0;
    }
  }

  else if (a == 3 || a == 5) 
  {
    // verse
    noteLength = beatlength * 2 * song1_verse1_rhythmn[b];

    if (song1_verse1_melody[b] > 0) 
    {
      digitalWrite(led, HIGH);
      tone(piezo, song1_verse1_melody[b], noteLength);
      c++;
    }

    b++;
    if (b >= sizeof(song1_verse1_melody) / sizeof(int)) 
    {
      a++;
      b = 0;
      c = 0;
    }
  }
  else if (a == 4 || a == 6) 
  {
    // chorus
    noteLength = beatlength * song1_chorus_rhythmn[b];
    if(song1_chorus_melody[b] > 0) 
    {
      digitalWrite(led, HIGH);
      tone(piezo, song1_chorus_melody[b], noteLength);
      c++;
    }

    b++;
    if(b >= sizeof(song1_chorus_melody) / sizeof(int)) 
    {
      a++;
      b = 0;
      c = 0;
    }
  }
  delay(noteLength);

  noTone(piezo);
  digitalWrite(led, LOW);
  delay(noteLength * beatseparationconstant);

  if (a == 7) 
  {
    a = 1;
  }
}