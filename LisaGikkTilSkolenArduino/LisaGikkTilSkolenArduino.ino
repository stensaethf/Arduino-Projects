#include <Servo.h>

// Defining notes with respective frequencies, and pins, as well as naming servos
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 392;
const int a = 440;
const int pin = A3;
const int light = 12;
Servo servo1;
Servo servo2;

// Telling the arduino which device is plugged in where
void setup()
{
  pinMode(pin, OUTPUT);
  servo1.attach(A1);
  servo2.attach(A2);
  pinMode(light, OUTPUT);
} 

void loop()
{
  servo1.write(1); // Servo1 to position 1
  servo2.write(90); // Servo2 to position 90
  digitalWrite(light, HIGH); // Light on
  tone(pin, c); // note c
  delay(900);
  digitalWrite(light, LOW); // Light off (will seem like a pause)
  tone(pin, 0); // Pause in melody
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, d); // note d
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, e); // note e
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, f); // note f
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, g); // note g
  delay(1900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, g); // note g
  delay(1900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, a); // note a
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, a); // note a
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, a); // note a
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, a); // note a
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, g); // note g
  delay(3900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, f); // note f
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, f); // note f
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, f); // note f
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, f); // note f
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, e); // note e
  delay(1900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, e); // note e
  delay(1900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, d); // note d
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, d); // note d
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, d); // note d
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(1);
  servo2.write(90);
  digitalWrite(light, HIGH);
  tone(pin, d); // note d
  delay(900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(100);
  servo1.write(90);
  servo2.write(1);
  digitalWrite(light, HIGH);
  tone(pin, c); // note c
  delay(3900);
  digitalWrite(light, LOW);
  tone(pin, 0);
  delay(3000); // 3 second delay before it loops back up to give the listener
               // a clear idea of that one loop is over.
}
