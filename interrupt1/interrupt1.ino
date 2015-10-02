const int led = 13;
const int button = 2;
// Any variable used in an ISR must be
// declared as volatile
volatile int state = LOW; // Light on or off

void setup()
{
  pinMode(led,OUTPUT);
  // RISING , FALLING , CHANGE
  attachInterrupt(0, blink, CHANGE);
}

void loop()
{
  digitalWrite(led,state);
}

// My function that will handle the button
// Interrupt Service Routine (ISR)
void blink()
{
  if (state == LOW)
    state = HIGH;
  else
    state = LOW;
}
