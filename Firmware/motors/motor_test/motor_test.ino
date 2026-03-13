#define STEP_PIN 2
#define DIR_PIN 3

int stepsPerMove = 1600;   // how far it moves each direction
int stepDelay = 100;     // microseconds between steps (bigger = slower)


//this function makes the motor step 
void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
  }
}

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() {

  // rotate one direction
  digitalWrite(DIR_PIN, HIGH); //gives motor direciton to rotate
  stepMotor(stepsPerMove); //causes motor to rotate

  delay(1000);

  // rotate the other direction
  digitalWrite(DIR_PIN, LOW);
  stepMotor(stepsPerMove);

  delay(1000);
}