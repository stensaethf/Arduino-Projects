#include <Wire.h>
#include <MMA_7455.h>

// Sets up accelerometer for use
MMA_7455 accel = MMA_7455();

void setup() {
  Serial.begin(9600);
  accel.initSensitivity(2);
  //accel.calibrateOffset(-55,17,-19);
}

void loop() {
  char xVal = accel.readAxis('x');
  char yVal = accel.readAxis('y');
  char zVal = accel.readAxis('z');
  
  // DEC = print as number even though
  // it's a char
  Serial.print(xVal,DEC);
  Serial.print('\t');
  Serial.print(yVal,DEC);
  Serial.print('\t');
  Serial.println(zVal,DEC);
  delay(100);
}
  
