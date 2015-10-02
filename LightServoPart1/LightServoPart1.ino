// Sweeps a servo across, a few steps at a time
// and prints out what the lowest value was
// and at what angle it was found. A Second servo points to where the lowest
// value was found.

// import servo library
#include <Servo.h>

// name servos and what pins are used for devices.
Servo servo1;
Servo servo2;
int photocell = A0;
int servopin = 12;
int servopin2 = 11;

void setup()
{
  // tell arduino where the servos are attached and that the serial monitor
  // will be used.
  Serial.begin(9600);
  servo1.attach(servopin);
  servo2.attach(servopin2);
}

void loop()
{
  int i; // position
  int lowest = 1000; // define lowest value as really high so any value found will be lower
  int angle = 0; // define temporary angle for which lowest value was found.
  for (i=2; i<= 177; i=i+1) // for loop to make servo sweep across
  {
    servo1.write(i); // set servo to position i
    delay(150); // delay 150ms
    int lightValue = analogRead(photocell); // store value recorded
    if (lightValue < lowest) // if statement to record the lowest value and at what angle it was found
    {
      angle = i;
      lowest = lightValue;
    }
  }
  servo2.write(angle); // second servo points to where lowest value was found
  // prints out the lowest value seen and at what angle it was found.
  Serial.print("The lowest value seen was: ");
  Serial.println(lowest);
  Serial.print("The lowest value was found at angle: ");
  Serial.println(angle);
}


