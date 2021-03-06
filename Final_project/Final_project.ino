// Final_project.ino
// A Arduino program XX
// Created by Frederik Roenn Stensaeth
// 02.27.14

// Import libraries
#include <CarlServo.h>

// Defining variables, pins, and lists, as well as naming servos
const int button = 2;
const int beeper = XX;
const int failure = XX;
const int success = XX:
const int joystickx = A2;
const int joysticky = A1;
const int joystickPush = A0;
const int servopin1 = XX:
const int servopin2 = XX;
const int servopin3 = XX;
const int servopin4 = XX;
const int servopin5 = XX;
const int servopin6 = XX;
const int servopin7 = XX;

activate = False;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;

int light1 = XX;
int light2 = XX;
int light3 = XX;
int light4 = XX;
int light5 = XX;
int light6 = XX;
int light7 = XX;
int light_state0 = XX;
int light_state1 = XX:
int light_state2 = XX:

game_pair_list[2] = {};
game_list[10] = {XX};
game_actions[10] = {XX};
servo_list[7] = {servo1, servo2, servo3, servo4, servo5, servo6, servo7};
light_list[7] = {light1, light2, light3, light4, light5, light6, light7};
state_light[3] = {light_state0, light_state1, light_state2};
tone_list[XX] = {XX};
tone_list_push[XX] = {XX};

// Tell arduino where the devices are attached and whether they are input or
// output, as well as configuring interrupts
void setup()
{
  pinMode(button, INPUT);
  pinMode(beeper, OUTPUT);
  pinMode(joystickx, INPUT);
  pinMode(joysticky, INPUT);
  pinMode(joystickPush, INPUT);
  
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(light4, OUTPUT);
  pinMode(light5, OUTPUT);
  pinMode(light6, OUTPUT);
  pinMode(light7, OUTPUT);
  pinMode(light_state0, OUTPUT);
  pinMode(light_state1, OUTPUT);
  pinMode(light_state2, OUTPUT);
  
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo6.attach(servopin6);
  servo7.attach(servopin7);
  
  attachInterrupt(0, state, FALLING);
}

void loop()
{
  if (activate == False)
  {
    LEDS ON BOARD OFF
    activate = activate();
    if (activate == True)
    {
      LEDS ON BOARD ON
    }
  }
  
  if (activate == True)
  {
    if (state == 0)
    {
      state_light(state);
      motion();
    }
  
    else if (state == 1)
    {
      state_light(state);
      piano();
    }
  
    else
    {
      state_light(state);
      game();
    }
  }
}

// Function to increment state by 1 every time button is pressed
void state()
{
  state = (state + 1) % 3;
  activate = False;
}

void motion()
{
  x, y, push = joystick();
  if (((XX < x) || (x < XX)) && ((XX < y) || (y < XX)) && (push == 0))
  {
    XX
  }
  only do rest if x,y is something else than standard
  -LIGHT ON BOARD OFF
  -LIGHT ON (x,y) COORDINATE ON
  -LIGHT ON AROUND COORDINATE, DIMMER
  -LIGHT COLOR DEPENDS ON SPEED OF MOVEMENT
  -MOVE SERVO AT COORDINATE UP AND SURROUNDING SERVOS DOWN (WAVE)
  servo_list[XX].write(XX);
  analogWrite(light_list[XX], XX);
  if (servo_list[XX] == servo1)
  {
    servo_list[6].write(XX);
    analogWrite(light_list[4], XX);
    servo_list[1].write(XX);
    analogWrite(light_list[1], XX);
  }
  else if (servo_list[XX] == servo7)
  {
    servo_list[0].write(XX);
    analogWrite(light_list[0], XX);
    servo_list[5].write(XX);
    analogWrite(light_list[3], XX);
  }
  else
  {
    servo_list[XX - 1].write(XX);
    analogWrite(light_list[XX - 1], XX);
    servo_list[XX + 1].write(XX);
    analogWrite(light_list[XX + 1], XX);
  }
  for (int i = 0; i < 6; i++)
  {
    if ((servo_list[i].read() != XX) || (servo_list[i].read() != XX))
    {
      servo_list[i].write(XX);
      analogWrite(light_list[i], 0);
    }
  }
}

void piano()
{
  x, y, push = joystick();
  if (((XX < x) || (x < XX)) && ((XX < y) || (y < XX)))
  {
    only do rest if x,y is something else than standard
    -LIGHTS ON BOARD OFF
    -LIGHT ON IN WAVE
    -SERVO UP ONLY AT COORDINATE
    if (push == 0)
    {
      tone(beeper, tone_list_push[XX]);
    }
    else:
    {
      tone(beeper, tone_list[XX]);
    }
  }
  else
  {
    noTone(beeper);
  }
}

void game()
{
  int success_count = 0;
  while True
  {
    if (state != 2)
    {
      return
    }
    x, y, push = joystick();
    only do the rest if x,y is something else than standard
    if (((XX < x) || (x < XX)) && ((XX < y) || (y < XX)) && (push == 0))
    {
      XX
    }
    -LIGHTS ON BOARD OFF
    -LIGHTS ON BOARD GO IN CIRCLE (LOOP) INDEXING THROUGH LIST
    int size_count = 0;
    for index in game_pair_list
    {
      size_count += 1;
    }
    if push == 0
    {
      game_pair = (x, y);
      game_pair_list[size_count + 1] = game_pair;
      TURN LIGHT ON FOR PAIR
    }
    if size_count == 2
    {
      count = -1;
      for tuple in game_list
      {
        count += 1;
        pair = (game_pair_list[0], game_pair_list[1]);
        if (tuple == pair)
        {
          success_count += 1
          tone(beeper, success);
          delay(300);
          noTone(beeper);
          action = game_actions[count];
          if (count <= 4)
          {
            digitalWrite(action);
          }
          else
          {
            servo.write(action);
          }
          if (success_count == 10)
          {
            ALL WAVE LIGHTS OFF AND SERVOS DOWN
            servo1.write(XX);
            servo2.write(XX);
            servo3.write(XX);
            servo4.write(XX);
            servo5.write(XX);
            success_count = 0;
          }
        }
        else
        {
          tone(beeper, failure);
          delay(300);
          noTone(beeper);
          LIGHTS PAIRS OFF
        }
      game_pair_list.clear();
      }
    }
  -check if pair is in a list, if they are light changes and stays on, if not
  - - light goes off. User keeps on doing this until all 5 combos are done
  - sound for success / failure
  do same for servos moving up, however, different pairs
  }
}

void joystick()
{
  int x = analogRead(joystickx); // read joystick in x plane
  int y = analogRead(joysticky); // read joystick in y plane
  int push = analogRead(joystickPush); // read joystick push
  int xcord = map(x, 0, 1023, 1, 180) // sets range to 1 - 180
  int ycord = map(y, 0, 1023, 1, 180) // sets range to 1 - 180
  return xcord, ycord, push;
}

void activate()
{
  push = analogRead(joystickPush);
  if (push == 0)
  {
    return True;
  }
  else:
  {
    return False;
  }
}

void state_light(int state)
{
  for (int i = 0; i < 2; i++)
  {
    if (i = state)
    {
      digitalWrite(state_light[i], HIGH);
    }
    else
    {
      digitalWrite(state_light[i], LOW);
    }
  }
}
