// Accelerometer__Servo.ino
// An Arduino program to set servo angle according to accelerometer readings
// Created by Frederik Roenn Stensaeth
// 02.10.14

// Import libraries
#include <Wire.h>
#include <MMA_7455.h>
#include <Servo.h>

MMA_7455 accel = MMA_7455(); // Set up accelerometer for use

const int servopin = 11; // define servopin

Servo servo1; // Name servo

void setup()
{
  accel.initSensitivity(2); // Setup accelerometer sensitivity
  servo1.attach(servopin); // Setup servo at servopin
  accel.calibrateOffset(-63, 140, 0); // calibrate accelerometer, such that both x and y is 125 at middle
}

void loop()
{
  int yVal = accel.readAxis('y'); // read y-axis accelerometer
    
  int angle = (yVal - 60) * (90 / 65) + 35; // convert yVal to Servo angle
  
  servo1.write(angle); // set Servo to angle
  
  delay(100); // delat 0.1sec (100ms)
}

// Notes to self:
// x | 125, 190 - 190
// y | 125, 188 - 60

// y:
// 125 = 90 angle
// 190 = 180 angle
// 60 = 0 angle
// each point = 90/65 angle
// need to compensate for servo being slightly more than 180 degrees
