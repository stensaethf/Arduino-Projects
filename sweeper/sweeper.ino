// Sweep the servo across, a few steps at a time
// Count the number of readings I get over 200
// and the number I get under 200
#include <Servo.h>

Servo servo1;
int photocell = A0;
int servopin = 12;

void setup()
{
  Serial.begin(9600);
  servo1.attach(servopin);
}

void loop()
{
  int i; // position
  int above = 0;
  int below = 0;
  for (i=2; i<= 177; i=i+1)
  {
    servo1.write(i);
    delay(100);
    int lightValue = analogRead(photocell);
    //int lightValue = (i % 2)*400;
    //Serial.println(lightValue);
    if (lightValue >= 200)
    {
      above = above + 1;
    }
    else
    {
      below = below + 1;
    }
  }
  Serial.print("Above value is ");
  Serial.println(above);
  Serial.print("Below value is ");
  Serial.println(below);
  
}


