// State_Transistions_p1.ino
// A program to examplify how to have multiple states in one program.
// Created by Frederik Roenn Stensaeth
// 02.02.14

// Importing Servo library
#include <Servo.h>

// Defining variables and pins, as well as 
// naming servos.
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 392;
const int a = 440;
const int beeper = 9;
const int light = 8;
const int button = 2;
const int button2 = 21;
const int photocell = A0;
const int servopin = A1;
const int servopin2 = A2;
const int servopin3 = 12;
const int servopin4 = 11;
int brightness = 0;
int movement = 4;
int i = 3; // position
int lowest = 1000; // set really high so that any recording is lower
int angle = 0;
int direction = 1;
volatile int state = 0;
Servo servo1; // Continous rotation servo for music
Servo servo2; // Servo with light getting brighter/ dimmer
Servo servo3; // Servo looking for light
Servo servo4; // Servo poitning to light


// Tell arduino where the devices are attached and whether they are input
// or output, as well as configuring interrupts
void setup()
{
  pinMode(beeper, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  servo1.attach(servopin);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  attachInterrupt(0, increase, FALLING);
  attachInterrupt(2, decrease, FALLING);
  Serial.begin(9600);
}


void loop()
{
  Serial.println(state);
  if (state == 0)
  {
    searching_light();
  }
  else if (state == 1)
  {
    song();
  }
  else
  {
    light_spin();
  }
}


// Function to increase state by 1 every time button 1 is pressed
void increase()
{
  state = (state + 1) % 3;
}


// Function to decrease state by 1 every time button 2 is pressed
void decrease()
{
  state -= 1;
  
  if (state == -1)
  {
    state = 2;
  }
}

void searching_light()
{
  for (i = 3; i<= 177; i += direction) // for loop to make servo sweep across
  {
    if (state != 0)
    {
      return;
    }
    servo3.write(i); // position servo1 to i
    delay(150); // delay 150ms
    int lightValue = analogRead(photocell); // record light value
    if (lightValue < lowest) // if statement to store angle and lightValue, if value is lower than previous lowest recording. Point servo2 to angle.
    {
      angle = i;
      servo4.write(angle);
    }
  }
}


void song()
{
  // The melody is broken up into 4 second intervals using whitespace
  // First 4 seconds. Light is turned off and note C, D, E, and F is played 
  // for 0.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.
  analogWrite(light, 0); // Turns light off
  servo1.write(1);
  tone(beeper, c); // Note C
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, d); // Note D
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, e); // Note E
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, f); // Note F
  delay(900);
  tone(beeper, 0);
  delay(100);
  
  // Second 4 seconds. Note G is played twice 
  // for 1.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.
  servo1.write(1);
  tone(beeper, g); // Note G
  delay(1900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, g); // Note G
  delay(1900);
  tone(beeper, 0);
  delay(100);
    
  // Third 4 seconds. Note A is played four times
  // for 0.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.
  servo1.write(1);
  tone(beeper, a); // Note A
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, a); // Note A
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, a); // Note A
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, a); // Note A
  delay(900);
  tone(beeper, 0);
  delay(100);
  
  // Fourth 4 seconds. Note G is played 
  // for 3.9 seconds each with 0.1 seconds pause afterwards. Servo speed 
  // is 1.
  servo1.write(1);
  tone(beeper, g); // Note G
  delay(3900);
  tone(beeper, 0);
  delay(100);
  
  // Fifth 4 seconds. Note F is played four times
  // for 0.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.    
  servo1.write(90);
  tone(beeper, f); // Note F
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, f); // Note F
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, f); // Note F
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, f); // Note F
  delay(900);
  tone(beeper, 0);
  delay(100);
  
  // Sixth 4 seconds. Note E is played twice
  // for 1.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.    
  servo1.write(90);
  tone(beeper, e); // Note E
  delay(1900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, e); // Note E
  delay(1900);
  tone(beeper, 0);
  delay(100);
  
  // Seventh 4 seconds. Note D is played four times 
  // for 0.9 seconds each with 0.1 seconds pause in between. Servo alters 
  // between speed 1 and 90.
  servo1.write(90);
  tone(beeper, d); // Note D
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, d); // Note D
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(90);
  tone(beeper, d); // Note D
  delay(900);
  tone(beeper, 0);
  delay(100);
  servo1.write(1);
  tone(beeper, d); // Note D
  delay(900);
  tone(beeper, 0);
  delay(100);
  
  // Eighth 4 seconds. Note C is played 
  // for 3.9 seconds with 0.1 seconds pause afterwards. Servo speed 
  // is 1.
  servo1.write(90);
  tone(beeper, c); // Note C
  delay(3900);
  tone(beeper, 0);
  delay(5000);
}


// The LED will gradually turn brighter before
// dimming again, just like as if someone becomes gradually more delighted before
// returning to normal emotional level again. The servo's lever moves smoothly
// from side to side representing the same as the gradually brighter/ diming light.
void light_spin()
{
  servo2.write(brightness);
  brightness += movement; // accumulate the brightness variable
  analogWrite(light, brightness); // set LED to brightness
  delay(100);
  
  // Changes the sign of the 'direction' variable depending on what number the
  // 'brightness' variable has reached. Condtion: brightness variable is smaller
  // than or equal to 0, or larger than or equal to 254.
  if (brightness >= 200 || brightness <= 0)
  {
    movement = movement * -1;
  }
}
