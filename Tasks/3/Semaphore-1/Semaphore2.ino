#define SECOND 1000

const int sem1Pins[3] = { 13, 12, 11 };
const int sem2Pins[3] = { 10, 9, 8 };

int sem1State = 0;
int sem2State = 1;

long sem1ChangeTime = 0;
long sem2ChangeTime = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(sem1Pins[i], OUTPUT);
    pinMode(sem2Pins[i], OUTPUT);
  }
  updateLights(sem1Pins, sem1State);
  updateLights(sem2Pins, sem2State);
}

void loop() {
  updateState(sem1Pins, &sem1State, &sem1ChangeTime);
  updateState(sem2Pins, &sem2State, &sem2ChangeTime);
}

void updateLights(int pins[3], int state) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins[i], i == state ? HIGH : LOW);
  }
}

void updateState(int pins[3], int* state, unsigned long* changeTime) {
  long currentTime = millis();
  if(
    (*state == 0 && currentTime - *changeTime >= 5*SECOND) ||
    (*state == 1 && currentTime - *changeTime >= 2*SECOND) ||
    (*state == 2 && currentTime - *changeTime >= 5*SECOND)
    ) 
  {
    *state = (*state + 1) % 3;
    *changeTime = currentTime;
    updateLights(pins, *state);
  }
}