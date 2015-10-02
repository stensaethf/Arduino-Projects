// State_Transistions_p1.ino
// A program to examplify how to have multiple states in one program.
// Created by Frederik Roenn Stensaeth
// 02.02.14

// Importing Servo library
#include <Servo.h>

// Defining variables, pins, and lists, as well as 
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
int lowest = 1000; // set really high so that any recording is lower
int angle = 0;
int direction = 1;
int i;
int j;

// lists containing notes, delay times, and servo speeds
int notes [22] = {c, d, e, f, g, g, a, a, a, a, g, f, f, f, f, e, e, d, d, d, d, c};
int delay_times [22] = {900, 900, 900, 900, 1900, 1900, 900, 900, 900, 900, 3900, 900, 900, 900, 900, 1900, 1900, 900, 900, 900, 900, 3900};
int servo_speed [22] = {1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90};

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
  Serial.println(state); // print state
  
  if (state == 0) // if statement to call upon searching_light() function if state == 0
  {
    searching_light(); // call upon searching_light() function
  }
  else if (state == 1) // else if statement to call upon song() function if state == 1
  {
    song(); // call upon song() function
  }
  else // if state is neither 0, nor 1, call upon light_spin() funciton
  {
    light_spin(); // call upon light_spin() function
  }
}


// Function to increase state by 1 every time button 1 is pressed
void increase()
{
  state = (state + 1) % 3; // increase state by 1, but set state = 0 when state reaches 3
}


// Function to decrease state by 1 every time button 2 is pressed
void decrease()
{
  state -= 1; // decrease state by 1
  
  if (state == -1) // if statement to set state = 2, if state reaches -1
  {
    state = 2;
  }
}


// Function to turn servo with light sensor attached to it around to search for light
void searching_light()
{
  servo1.write(94); // stops servo1
  
  noTone(beeper); // no tone coming from beeper
  
  for (i = 3; i<= 177; i += direction) // for loop to make servo sweep across
  {
    if (state != 0) // check if state is still 0
    {
      return; // return to void loop if state is not 0
    }
    
    servo3.write(i); // position servo1 to i
    
    delay(150); // delay 150ms
    
    int lightValue = analogRead(photocell); // record light value
    
    if (lightValue < lowest) // if statement to store angle and lightValue, if value is lower than previous lowest recording. Point servo2 to angle.
    {
      angle = i; // store i as angle where lowest value was seen
      lowest = lightValue; // store lowest value seen
      servo4.write(angle); // point servo4 to angle
    }
  }
}


// Function to play 'Lisa Gikk Til Skolen'
void song()
{
  for (int j = 0; j < 22; j++) // for loop to loop over lists
  {
    if (state != 1) // check if state is still 1
    {
      return; // return to void loop if state is not 1
    }
    
    servo1.write(servo_speed[j]); // set servo speed number at index j in servo_speed
    
    tone(beeper, notes[j]); // play note at index j in notes
    
    delay(delay_times[j]); // delay for time at index j in delay_times
    
    if (state != 1) // check if state is still 1
    {
      return; // return to void loop if state is not 1
    }
    
    noTone(beeper); // play no tone
    
    delay(100); // delay 100ms
  }
}


// The LED will gradually turn brighter before
// dimming again, just like as if someone becomes gradually more delighted before
// returning to normal emotional level again. The servo's lever moves smoothly
// from side to side representing the same as the gradually brighter/ diming light.
void light_spin()
{
  noTone(beeper); // no tone from beeper
  
  servo1.write(94); // stops servo1
  
  servo2.write(brightness); // set servo2 to brightness
  
  brightness += movement; // accumulate the brightness variable
  
  analogWrite(light, brightness); // set LED to brightness
  
  delay(100); // delay 100ms
  
  // Changes the sign of the 'direction' variable depending on what number the
  // 'brightness' variable has reached. Condtion: brightness variable is smaller
  // than or equal to 0, or larger than or equal to 254.
  if (brightness >= 200 || brightness <= 0)
  {
    movement = movement * -1;
  }
}
