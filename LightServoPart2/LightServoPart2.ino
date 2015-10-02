// Sweep the one servo across continously, a few steps at a time
// Another servo points to where the sweeping servo found the
// strongest light source.
// Created by Freddie Stensaeth
// 01.27.14

// Import servo library
#include <Servo.h>

// name servos and what pins are used for devices.
Servo servo1;
Servo servo2;
int photocell = A0;
int servopin = 12;
int servopin2 = 11;
int i = 3; // position
int lowest = 1000; // set really high so that any recording is lower
int angle = 0;
int direction = 1;

// tell arduino where the servos are attached and that the serial monitor
// will be used.
void setup()
{
  servo1.attach(servopin);
  servo2.attach(servopin2);
}

void loop()
{
  for (i; i<= 177; i += direction) // for loop to make servo sweep across
  {
    servo1.write(i); // position servo1 to i
    delay(150); // delay 150ms
    int lightValue = analogRead(photocell); // record light value
    if (lightValue < lowest) // if statement to store angle and lightValue, if value is lower than previous lowest recording. Point servo2 to angle.
    {
      angle = i;
      lowest = lightValue;
      servo2.write(angle);
    }
    if ((i == 177) || (i == 2)) // if statement to change direction if i == 177 or i == 2.
    {
      direction = direction * -1;
    }
  } 
}


