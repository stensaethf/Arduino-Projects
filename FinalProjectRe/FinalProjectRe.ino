// FinalProjectRe.ino
// A Arduino program to turn on/ off LEDs and move servos depending on joystick position.
// Created by Frederik Roenn Stensaeth
// 02.27.14 - 03.15.14

// DISCLAIMERS:
// The code is not very clean, but it works. The reason for this is that it did not allow
// me to make an array containing servos, hence, many if/else if/ else statements.
// I have included the code I wrote for making the game, however, I did not get that to
// work in time. I would appreciate any feedback on that code. Thank you!

// Import libraries
#include <CarlServo.h>

// Defining variables, pins, and lists, as well as naming servos
const int button = 2;
const int beeper = 12;
const int failure = 300;
const int success = 900;
const int joystickx = A0;
const int joysticky = A1;
const int joystickPush = A2;
const int servopin1 = 41;
const int servopin2 = 40;
const int servopin3 = 39;
const int servopin4 = 42;
const int servopin5 = 38;
const int servopin6 = 43;

// Define state variable as volatile
volatile int state = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// Find which one is blue light
int light1 = 50;
int light2 = 19;
int light3 = 49;
int light4 = 17;
int light5 = 48;
int light6 = 18;
int light7 = 16;
int light_blue = 47;

// Ceiling light FIND WHICH ONE IS WHICH AND WRONG
int ceil_light1 = 3;
int ceil_light2 = 4;
int ceil_light3 = 5;
int ceil_light4 = 6;
int ceil_light5 = 1;
int ceil_light6 = 0;

// LEDs for displaying states
int light_state0 = 15;
int light_state1 = 14;

// Define lowest, highest, middle variable.
int lowest = 5;
int highest = 75;
int middle = 40;

// Make arrays containing lights on board and lights in ceiling
int light_list[7] = {light1, light2, light3, light4, light5, light6, light7};
int light_ceiling[6] = {ceil_light1, ceil_light2, ceil_light3, ceil_light4, ceil_light5, ceil_light6};

void setup()
{
  // Define devices as input/ output
  pinMode(button, INPUT);
  pinMode(beeper, OUTPUT);
  pinMode(joystickx, INPUT);
  pinMode(joysticky, INPUT);
  pinMode(joystickPush, INPUT);
  
  // Define board lights as output
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(light4, OUTPUT);
  pinMode(light5, OUTPUT);
  pinMode(light6, OUTPUT);
  pinMode(light7, OUTPUT);
  
  // Define blue LEDs as output
  pinMode(light_blue, OUTPUT);
  
  // Define ceiling ligths as output
  pinMode(ceil_light1, OUTPUT);
  pinMode(ceil_light2, OUTPUT);
  pinMode(ceil_light3, OUTPUT);
  pinMode(ceil_light4, OUTPUT);
  pinMode(ceil_light5, OUTPUT);
  pinMode(ceil_light6, OUTPUT);
  
  // Define state lights as output
  pinMode(light_state0, OUTPUT);
  pinMode(light_state1, OUTPUT);
  
  // Tell arduino where servos are attached
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo6.attach(servopin6);
  
  // Attach interrupt on button when it is falling and call State function
  attachInterrupt(0, State, FALLING);
 }

// Define loop function. Takes no parameters. Turns blue LEDs and appropriate state
// LEDs on. Calls a function (Motion, Weird, Random) depending on the variable state
void loop()
{
  // Turn light_blue on
  digitalWrite(light_blue, HIGH);
  
  // Call State_light function with parameter state
  State_light(state);
  
  // If state is 0 call Motion()
  if (state == 0)
  {
    Motion();
  }
  // If state is 1 call Weird()
  else if (state == 1)
  {
    Weird();
  }
  // If state is 2 call Random()
  else
  {
    Random();
  }
}

// Define function called State. Takes no parameters. Accumulates the variable state.
void State()
{
  state = (state + 1) % 3;
}

// Define function called State_light. Takes the integer state as parameter.
// Turns on appropriate state lights.
void State_light(int state)
{
  // If state is 0 turn light_state0 on and light_state1 off
  if (state == 0)
  {
    digitalWrite(light_state0, HIGH);
    digitalWrite(light_state1, LOW);
  }
  // If state is 1 turn light_state1 on and light_state0 off
  else if (state == 1)
  {
    digitalWrite(light_state1, HIGH);
    digitalWrite(light_state0, LOW);
  }
  // If state is 2 turn both light_state0 and light_state1 on
  else
  {
    digitalWrite(light_state1, HIGH);
    digitalWrite(light_state0, HIGH);
  }
}

void Motion()
{
  // Get x, y, and push coordinates of joystick and map to range 0 - 5
  int xcord = analogRead(joystickx); // read joystick in x plane
  int ycord = analogRead(joysticky); // read joystick in y plane
  int push = analogRead(joystickPush); // read joystick push
  int x = map(xcord, 0, 1023, 0, 5); // sets range to 0 - 5
  int y = map(ycord, 0, 1023, 0, 5); // sets range to 0 - 5
  
  // Move all servos to lowest
  servo1.write(lowest);
  servo2.write(lowest);
  servo3.write(lowest);
  servo4.write(lowest);
  servo5.write(lowest);
  servo6.write(lowest);
  
  // Loop over lights in ceiling and turn them off
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(light_ceiling[i], LOW);
  }
  
  // Loop of lights on board and turn them off
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(light_list[i], LOW);
  }
  
  // If x or y is equal to 0 or 5 execute if body
  if ((x == 0) || (x == 5) || (y == 0) || (y == 5))
  {
    // If y is 5 execute else if body
    if (y == 5)
    {
      // If x is 0 set servo 1 to highest, beeper to 100, and lights at position
      // 0 on board on and 0 in ceiling on.
      if (x == 0)
      {
        digitalWrite(light_ceiling[0], HIGH);
        servo1.write(highest);
        digitalWrite(light_list[0], HIGH);
        tone(beeper, 100);
      }
      // If x is 1 set servo 2 to highest, beeper to 200, and lights at position
      // 1 on board on and 1 in ceiling on.
      if (x == 1)
      {
        digitalWrite(light_ceiling[1], HIGH);
        servo2.write(highest);
        digitalWrite(light_list[1], HIGH);
        tone(beeper, 200);
      }
      // If x is 2 set servo 3 to highest, beeper to 300, and lights at position
      // 2 on board on and 2 in ceiling on.
      if (x == 2)
      {
        digitalWrite(light_ceiling[2], HIGH);
        servo3.write(highest);
        digitalWrite(light_list[2], HIGH);
        tone(beeper, 300);
      }
      // If x is 3 set servo 4 to highest, beeper to 400, and lights at position
      // 3 on board on and 3 in ceiling on.
      if (x == 3)
      {
        digitalWrite(light_ceiling[3], HIGH);
        servo4.write(highest);
        digitalWrite(light_list[3], HIGH);
        tone(beeper, 400);
      }
      // If x is 4 set servo 5 to highest, beeper to 500, and lights at position
      // 4 on board on and 4 in ceiling on.
      if (x == 4)
      {
        digitalWrite(light_ceiling[4], HIGH);
        servo5.write(highest);
        digitalWrite(light_list[4], HIGH);
        tone(beeper, 500);
      }
      // If x is 5 set servo 6 to highest, beeper to 600, and lights at position
      // 5 and 6 on board on and 5 in ceiling on.
      if (x == 5)
      {
        digitalWrite(light_ceiling[5], HIGH);
        servo6.write(highest);
        digitalWrite(light_list[5], HIGH);
        digitalWrite(light_list[6], HIGH);
        tone(beeper, 600);
      }
    }
    
    // If x is 5 execute else if body
    else if (x == 5)
    {
      // If y is 0 set servo 1 to highest, beeper to 700, and lights at position
      // 0 on board on and 0 in ceiling on.
      if (y == 0)
      {
        digitalWrite(light_ceiling[0], HIGH);
        servo1.write(highest);
        digitalWrite(light_list[0], HIGH);
        tone(beeper, 700);
      }
      // If y is 1 set servo 2 to highest, beeper to 800, and lights at position
      // 1 on board on and 1 in ceiling on.
      if (y == 1)
      {
        digitalWrite(light_ceiling[1], HIGH);
        servo2.write(highest);
        digitalWrite(light_list[1], HIGH);
        tone(beeper, 800);
      }
      // If y is 2 set servo 3 to highest, beeper to 900, and lights at position
      // 2 on board on and 2 in ceiling on.
      if (y == 2)
      {
        digitalWrite(light_ceiling[2], HIGH);
        servo3.write(highest);
        digitalWrite(light_list[2], HIGH);
        tone(beeper, 900);
      }
      // If y is 3 set servo 4 to highest, beeper to 1000, and lights at position
      // 3 on board on and 3 in ceiling on.
      if (y == 3)
      {
        digitalWrite(light_ceiling[3], HIGH);
        servo4.write(highest);
        digitalWrite(light_list[3], HIGH);
        tone(beeper, 1000);
      }
      // If y is 4 set servo 5 to highest, beeper to 500, and lights at position
      // 4 on board on and 4 in ceiling on.
      if (y == 4)
      {
        digitalWrite(light_ceiling[4], HIGH);
        servo5.write(highest);
        digitalWrite(light_list[4], HIGH);
        tone(beeper, 500);
      }
      // If y is 5 set servo 6 to highest, beeper to 5, and lights at position
      // 5 and 6 on board on and 5 in ceiling on.
      if (y == 5)
      {
        digitalWrite(light_ceiling[5], HIGH);
        servo6.write(highest);
        digitalWrite(light_list[5], HIGH);
        digitalWrite(light_list[6], HIGH);
        tone(beeper, 5);
      }
    }
    
    // If y is 0 execute else if body
    else if (y == 0)
    {
      // If x is 0 set servo 1 to highest, beeper to 150, and lights at position
      // 0 on board on and 0 in ceiling on.
      if (x == 0)
      {
        digitalWrite(light_ceiling[0], HIGH);
        servo1.write(highest);
        digitalWrite(light_list[0], HIGH);
        tone(beeper, 150);
      }
      // If x is 1 set servo 2 to highest, beeper to 350, and lights at position
      // 1 on board on and 1 in ceiling on.
      if (x == 1)
      {
        digitalWrite(light_ceiling[1], HIGH);
        servo2.write(highest);
        digitalWrite(light_list[1], HIGH);
        tone(beeper, 350);
      }
      // If x is 2 set servo 3 to highest, beeper to 550, and lights at position
      // 2 on board on and 2 in ceiling on.
      if (x == 2)
      {
        digitalWrite(light_ceiling[2], HIGH);
        servo3.write(highest);
        digitalWrite(light_list[2], HIGH);
        tone(beeper, 550);
      }
      // If x is 3 set servo 4 to highest, beeper to 750, and lights at position
      // 3 on board on and 3 in ceiling on.
      if (x == 3)
      {
        digitalWrite(light_ceiling[3], HIGH);
        servo4.write(highest);
        digitalWrite(light_list[3], HIGH);
        tone(beeper, 750);
      }
      // If x is 4 set servo 5 to highest, beeper to 950, and lights at position
      // 4 on board on and 4 in ceiling on.
      if (x == 4)
      {
        digitalWrite(light_ceiling[4], HIGH);
        servo5.write(highest);
        digitalWrite(light_list[4], HIGH);
        tone(beeper, 950);
      }
      // If x is 5 set servo 6 to highest, beeper to 1015, and lights at position
      // 5 and 6 on board on and 5 in ceiling on.
      if (x == 5)
      {
        digitalWrite(light_ceiling[5], HIGH);
        servo6.write(highest);
        digitalWrite(light_list[5], HIGH);
        digitalWrite(light_list[6], HIGH);
        tone(beeper, 1015);
      }
    }
    
    // If x is equal to 0 execute else if body
    else if (x == 0)
    {
      // If y is 0 set servo 1 to highest, beeper to 50, and lights at position
      // 0 on board on and 0 in ceiling on.
      if (y == 0)
      {
        digitalWrite(light_ceiling[0], HIGH);
        servo1.write(highest);
        digitalWrite(light_list[0], HIGH);
        tone(beeper, 50);
      }
      // If y is 1 set servo 2 to highest, beeper to 250, and lights at position
      // 1 on board on and 1 in ceiling on.
      if (y == 1)
      {
        digitalWrite(light_ceiling[1], HIGH);
        servo2.write(highest);
        digitalWrite(light_list[1], HIGH);
        tone(beeper, 250);
      }
      // If y is 2 set servo 3 to highest, beeper to 450, and lights at position
      // 2 on board on and 2 in ceiling on.
      if (y == 2)
      {
        digitalWrite(light_ceiling[2], HIGH);
        servo3.write(highest);
        digitalWrite(light_list[2], HIGH);
        tone(beeper, 450);
      }
      // If y is 3 set servo 4 to highest, beeper to 650, and lights at position
      // 3 on board on and 3 in ceiling on.
      if (y == 3)
      {
        digitalWrite(light_ceiling[3], HIGH);
        servo4.write(highest);
        digitalWrite(light_list[3], HIGH);
        tone(beeper, 650);
      }
      // If y is 4 set servo 5 to highest, beeper to 850, and lights at position
      // 4 on board on and 4 in ceiling on.
      if (y == 4)
      {
        digitalWrite(light_ceiling[4], HIGH);
        servo5.write(highest);
        digitalWrite(light_list[4], HIGH);
        tone(beeper, 850);
      }
      // If y is 5 set servo 6 to highest, beeper to 1015, and lights at position
      // 5 and 6 on board on and 5 in ceiling on.
      if (y == 5)
      {
        digitalWrite(light_ceiling[5], HIGH);
        servo6.write(highest);
        digitalWrite(light_list[5], HIGH);
        digitalWrite(light_list[6], HIGH);
        tone(beeper, 1015);
      }
    }
  }
  
  else
  {
    // silent beeper
    noTone(beeper);
  }
}

void Weird()
{
  // Get x, y, and push coordinate of joystick and map to range 0 - 5.
  int xcord = analogRead(joystickx); // read joystick in x plane
  int ycord = analogRead(joysticky); // read joystick in y plane
  int push = analogRead(joystickPush); // read joystick push
  int x = map(xcord, 0, 1023, 0, 5); // sets range to 0 - 5
  int y = map(ycord, 0, 1023, 0, 5); // sets range to 0 - 5
  
  // Silent beeper
  noTone(beeper);
  
  // Loop over board lights and turn them off
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(light_list[i], LOW);
  }
  
  // Loop over ceiling lights and turn them off
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(light_ceiling[i], LOW);
  }
  
  // Move all servos to position 90  
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  
  // If x == 2 and y is equal to 2 turn lights in position 3 on board and 4 in ceiling
  // off
  if ((x == 2) && (y == 2))
  {
    digitalWrite(light_list[3], LOW);
    digitalWrite(light_ceiling[4], LOW);
  }
  // If x is 0 execute else if body
  else if (x == 0)
  {
    // If y coordinate is 0, move servo 4 down and servo 5 and 3 to middle. Lights at position
    // 3 on board and 3 in ceiling goes on.
    if (y == 0)
    {
      digitalWrite(light_list[3], HIGH);
      servo4.write(lowest);
      servo3.write(middle);
      servo5.write(middle);
      digitalWrite(light_ceiling[3], HIGH);
    }
    // If y coordinate is 1, move servo 5 down and servo 4 and 6 to middle. Lights at position
    // 4 on board and 4 in ceiling goes on.
    else if (y == 1)
    {
      digitalWrite(light_list[4], HIGH);
      servo5.write(lowest);
      servo4.write(middle);
      servo6.write(middle);
      digitalWrite(light_ceiling[4], HIGH);
    }
    // If y coordinate is 2, move servo 6 down and servo 5 to middle. Lights at position
    // 5 on board and 5 in ceiling goes on.
    else if (y == 2)
    {
      digitalWrite(light_list[5], HIGH);
      servo6.write(lowest);
      servo5.write(middle);
      digitalWrite(light_ceiling[5], HIGH);
    }
    // If y coordinate is 3, move servo 6 down and servo 5 to middle. Lights at position
    // 5 on board and 5 in ceiling goes on.
    else if (y == 3)
    {
      digitalWrite(light_list[5], HIGH);
      servo6.write(lowest);
      servo5.write(middle);
      digitalWrite(light_ceiling[5], HIGH);
    }
    // If y coordinate is 4, move servo 6 down and servo 5 to middle. Lights at position
    // 6 on board and 5 in ceiling goes on.
    else if (y == 4)
    {
      digitalWrite(light_list[6], HIGH);
      servo6.write(lowest);
      servo5.write(middle);
      digitalWrite(light_ceiling[5], HIGH);
    }
    // If y coordinate is 5, move servo 6 down and servo 5 to middle. Lights at position
    // 6 on board and 5 in ceiling goes on.
    else if (y == 5)
    {
      digitalWrite(light_list[6], HIGH);
      servo6.write(lowest);
      servo5.write(middle);
      digitalWrite(light_ceiling[5], HIGH);
    }
  }
  // If x is not 0 execute else body
  else
  {
    // If y coordinate is 0, move servo 4 down and servo 3 and 5 to middle. Lights at position
    // 3 goes on.
    if (y == 0)
    {
      digitalWrite(light_list[3], HIGH);
      servo4.write(lowest);
      servo3.write(middle);
      servo5.write(middle);
      digitalWrite(light_ceiling[3], HIGH);
    }
    // If y coordinate is 1, move servo 3 down and servo 2 and 4 to middle. Lights at position
    // 2 goes on.
    else if (y == 1)
    {
      digitalWrite(light_list[2], HIGH);
      servo3.write(lowest);
      servo2.write(middle);
      servo4.write(middle);
      digitalWrite(light_ceiling[2], HIGH);
    }
    // If y coordinate is 2, move servo 3 down and servo 2 and 4 to middle. Lights at position
    // 2 goes on.
    else if (y == 2)
    {
      digitalWrite(light_list[2], HIGH);
      servo3.write(lowest);
      servo2.write(middle);
      servo4.write(middle);
      digitalWrite(light_ceiling[2], HIGH);
    }
    // If y coordinate is 3, move servo 2 down and servo 3 and 1 to middle. Lights at position
    // 1 goes on.
    else if (y == 3)
    {
      digitalWrite(light_list[1], HIGH);
      servo2.write(lowest);
      servo1.write(middle);
      servo3.write(middle);
      digitalWrite(light_ceiling[1], HIGH);
    }
    // If y coordinate is 4, move servo 1 down and servo 2 to middle. Lights at position
    // 0 goes on.
    else if (y == 4)
    {
      digitalWrite(light_list[0], HIGH);
      servo1.write(lowest);
      servo2.write(middle);
      digitalWrite(light_ceiling[0], HIGH);
    }
    // If y coordinate is 5, move servo 1 down and servo 2 to middle. Lights at position
    // 0 goes on.
    else if (y == 5)
    {
      digitalWrite(light_list[0], HIGH);
      servo1.write(lowest);
      servo2.write(middle);
      digitalWrite(light_ceiling[0], HIGH);
    }
  }
}

// Define function called Random. Takes no parameters. Plays random sounds with beeper
// and turns on random lights
void Random()
{
  // Loop over every light on the board and turn them off
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(light_list[i], LOW);
  }
  
  // Loop over every light in the ceiling and turn them off
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(light_ceiling[i], LOW);
  }
  
  // Beeper is silent
  noTone(beeper);
    
  // Set all servos to random positions
  servo1.write(random(5, 100));
  servo2.write(random(5, 100));
  servo3.write(random(5, 100));
  servo4.write(random(5, 100));
  servo5.write(random(5, 100));
  servo6.write(random(5, 100));
  
  // Generate random numbers
  int ran_num = random(0, 6);
  int ran_num_b = random(0, 7);
  int ran_tone = random(0, 1000);
  
  // User random numbers to indicate which lights go on and which tone the beeper plays
  digitalWrite(light_ceiling[ran_num], HIGH);
  digitalWrite(light_list[ran_num_b], HIGH);
  tone(beeper, ran_tone);
  
  // Delay 150ms
  delay (150);
}

// My attempt at making a guessing game. The user points the joystick at a coordinate
// and locks in the coordinate by pressing the joystick button. The user does this twice.
// If both coordinates are correct (they are in the game_pair lists) a light goes on.
// User tries to get all lights to go on.
void Game()
{
  // Define variables and arrays to be used
  int success_count = 0;
  int game_pair_x[6] = {5, 4, 0, 1, 5, 0};
  int game_pair_y[6] = {5, 0, 0, 5, 3, 5};
  int game_pair_x2[6] = {5, 4, 0, 1, 5, 0};
  int game_pair_y2[6] = {5, 0, 0, 5, 3, 5};
  int game_pair1x[2] = {};
  int game_pair1y[2] = {};
  int size_count = 1;
  
  // Turn lights on board off
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(light_list[i], LOW);
  }
  
  // Define variable j
  int j = 1;
  // Create infinite loop with variable j
  while (j == 1)
  {
    // If state variable no longer is 2 return to main function
    if (state != 2)
    {
      return;
    }
    
    // Silent beeper
    noTone(beeper);
    
    // Turn lights in ceiling off
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(light_ceiling[i], LOW);
    }
        
    int xcord = analogRead(joystickx); // read joystick in x plane
    int ycord = analogRead(joysticky); // read joystick in y plane
    int push = analogRead(joystickPush); // read joystick push
    int x = map(x, 0, 1023, 0, 5); // sets range to 0 - 5
    int y = map(y, 0, 1023, 0, 5); // sets range to 0 - 5
    
    // Turn appropriate light in ceiling on depending on coordinate position of joystick
    if ((x == 0) || (x == 5) || (y == 0) || (y == 5))
    {
      if (y == 5)
      {
        if (x == 0)
        {
          digitalWrite(light_ceiling[0], HIGH);
        }
        else if (x == 1)
        {
          digitalWrite(light_ceiling[1], HIGH);
        }
        else if (x == 2)
        {
          digitalWrite(light_ceiling[2], HIGH);
        }
        else if (x == 3)
        {
          digitalWrite(light_ceiling[3], HIGH);
        }
        else if (x == 4)
        {
          digitalWrite(light_ceiling[4], HIGH);
        }
        else if (x == 5)
        {
          digitalWrite(light_ceiling[5], HIGH);
        }
      }
      
      else if (x == 5)
      {
        if (y == 0)
        {
          digitalWrite(light_ceiling[0], HIGH);
        }
        else if (y == 1)
        {
          digitalWrite(light_ceiling[1], HIGH);
        }
        else if (y == 2)
        {
          digitalWrite(light_ceiling[2], HIGH);
        }
        else if (y == 3)
        {
          digitalWrite(light_ceiling[3], HIGH);
        }
        else if (y == 4)
        {
          digitalWrite(light_ceiling[4], HIGH);
        }
      }
      
      else if (y == 0)
      {
        if (x == 0)
        {
          digitalWrite(light_ceiling[0], HIGH);
        }
        else if (x == 1)
        {
          digitalWrite(light_ceiling[1], HIGH);
        }
        else if (x == 2)
        {
          digitalWrite(light_ceiling[2], HIGH);
        }
        else if (x == 3)
        {
          digitalWrite(light_ceiling[3], HIGH);
        }
        else if (x == 4)
        {
          digitalWrite(light_ceiling[4], HIGH);
        }
      }
      
      else if (x == 0)
      {
        if (y == 1)
        {
          digitalWrite(light_ceiling[1], HIGH);
        }
        else if (y == 2)
        {
          digitalWrite(light_ceiling[2], HIGH);
        }
        else if (y == 3)
        {
          digitalWrite(light_ceiling[3], HIGH);
        }
        else if (y == 4)
        {
          digitalWrite(light_ceiling[4], HIGH);
        }
      }
    }
    
    // If joystick button is pushed execute if body
    if (push == 0)
    {
      // If size_count variable is 1 save x and y in arrays
      if (size_count == 1)
      {
        game_pair1x[0] = x;
        game_pair1y[0] = y;
      }
      // If size_count is 2 save x and y in arrays
      else if (size_count == 2)
      {
        game_pair1x[1] = x;
        game_pair1y[1] = y;
      }
      
      // Accumulate size_count variable
      size_count += 1;
      
      // If size_count is 3 execute if body   
      if (size_count == 3)
      {
        // Set size_coutn to be 1
        size_count == 1;
        
        // Loop in range 0 - 5
        for (int i = 0; i < 5; i++)
        {
          // If x and y coordinates that were locked in mathces the ones in arrays, then proceed.
          if (game_pair_x[i] == game_pair1x[1])
          {
            if (game_pair_y[i] == game_pair1y[1])
            {
              if (game_pair_x2[i] == game_pair1x[0])
              {
                if (game_pair_y2[i] == game_pair1y[0])
                {
                  // Set light on board in position i on
                  digitalWrite(light_list[i], HIGH);

                  // If i is 5 set light on board in position 6 on
                  if (i == 5)
                  {
                    digitalWrite(light_list[6], HIGH);
                  }
                  
                  // Play success note with beeper for 250ms
                  tone(beeper, success);
                  delay(250);
                  // Silent beeper
                  noTone(beeper);
                  
                  // Increment success_count
                  success_count += 1;
                  // If success_count is 6 play the entre spectrum of notes with beeper,
                  // as a tribute to the player for completing the gmae.
                  if (success_count == 6)
                  {
                    for (int i = 0; i < 1000; i++)
                    {
                      tone(beeper, i);
                      delay(10);
                    }
                    // Silent beeper
                    noTone(beeper);
                    // Return to main function
                    return;
                  }
                }
                // If coordinate did not match play failure tone
                else
                {
                  tone(beeper, failure);
                  delay(250);
                  noTone(beeper);
                }
              }
              // If coordinate did not match play failure tone
              else
              {
                tone(beeper, failure);
                delay(250);
                noTone(beeper);
              }
            }
            // If coordinate did not match play failure tone
            else
            {
              tone(beeper, failure);
              delay(250);
              noTone(beeper);
            }
          }
          // If coordinate did not match play failure tone
          else
          {
            tone(beeper, failure);
            delay(250);
            noTone(beeper);
          }
        }
      }
    }
  }
}


