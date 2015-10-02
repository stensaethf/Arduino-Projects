// Sweep the one servo across rapidly. Servo goes back to brightest area and reads
// that area again twice to check for accuracy. Second servo points to angle where brightest
// light was found.
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
int direction = 25;

// tell arduino where the servos are attached and that the serial monitor
// will be used.
void setup()
{
  Serial.begin(9600);
  servo1.attach(servopin);
  servo2.attach(servopin2);
}

void loop()
{
  int i = 28; // position
  int lowest = 1000; // set really high so that any recording is lower
  int angle = 0; // define temporary angle for which lowest value was found.
  int angle2 = 0; // define temporary angle for which lowest value was found the second time.
  int angle3 = 0; // define temporary angle for which lowest value was found the third time.
  for (i; i<= 178; i += direction) // for loop to make servo sweep across
  {
    servo1.write(i); // position servo1 to i
    delay(500); // delay 0.5sec (500ms)
    int lightValue = analogRead(photocell); // record light value
    if (lightValue < lowest) // if statement to update lowest value and angle it was read at. Point servo to that angle
    {
      angle = i;
      lowest = lightValue;
      servo2.write(angle);
    }
  } 
  int j = angle - 13; // define j
  for (j; j <= (angle + 13); j++) // for loop to make servo sweep across around brightest angle found
  {
    servo1.write(j); // position servo1 to j
    delay(125); // delay 125ms
    int precise_light = analogRead(photocell); // record light value
    if (precise_light < lowest) // if statement to update lowest value and angle, and point servo2 to angle.
    {
      angle2 = j;
      lowest = precise_light;
      servo2.write(angle2);
    }
  }
  int h = angle - 13; // define h
  for (h; h <= (angle + 13); h++) // for loop to make servo sweep across around brightest angle found
  {
    servo1.write(h); // position servo1 to h
    delay(125); // delay 125ms
    int precise_light2 = analogRead(photocell); // record light value
    if (precise_light2 < lowest) // if statement to update angle
    {
      angle3 = h;
    }
  }
  int y = abs(angle2 - angle3); // find difference between angle2 and angle3
  if (y <= 5) // if statement to check for accuracy, point both servos to angle found, and print out angle in serial monitor
  {
    servo1.write(angle3 + (y / 2));
    servo2.write(angle3 + (y / 2));
    Serial.print("The light source is located at angle: ");
    Serial.println(angle3 + (y / 2));
    delay (5000); // delay 5sec (5000ms)
  }
}



