#include <Servo.h>

// Defining notes with respective frequencies, and pins, as well as 
// naming servos.
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 392;
const int a = 440;
const int beeper = 9;
const int light = 8;
const int button = 11;
const int button2 = 10;
int brightness = 0;
int direction = 4;
Servo servo1;
Servo servo2;

// Telling the arduino which device is plugged in where
void setup()
{
  pinMode(beeper, OUTPUT);
  servo1.attach(A1);
  servo2.attach(A2);
  pinMode(light, OUTPUT);
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
} 

void loop()
{
  // If both buttons are clicked at the same time the condition
  // is fullfilled and the 'if' statement will be
  // executed, namely the happy Norwegian tune 'Line gikk til
  // skolen' plays and a contiual rotation servo spins
  if ((digitalRead(button) + digitalRead(button2)) == 0)
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
    // between speed 1 and 90.    servo1.write(90);
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
    delay(100);
  }
  
  // If only one of the buttons is pressed everything in the 'else if'
  // statement will be executed. The LED will gradually turn brighter before
  // dimming again, just like as if someone becomes gradually more delighted before
  // returning to normal emotional level again. The servo's lever moves smoothly
  // from side to side representing the same as the gradually brighter/ diming light.
  else if ((digitalRead(button) + digitalRead(button2)) == 1)
  {
    servo2.write(brightness);
    brightness += direction; // accumulate the brightness variable
    analogWrite(light, brightness); // set LED to brightness
    delay(50); 
  }
  
  // If neither of the two buttons are pressed the 'else' statement is executed.
  // Nothing happens.
  else
  { 
    noTone(beeper); // Beeper plays no tone
    analogWrite(light, 0); // Light is off
    servo1.write(94); // Servo 1 is stands still (speed 94)
    servo2.write(90); // Servo 2 returns to 90 degree position
  }

  Serial.println(brightness); // prints brightness variable in serial monitor
  
  // Changes the sign of the 'direction' variable depending on what number the
  // 'brightness' variable has reached. Condtion: brightness variable is smaller
  // than or equal to 0, or larger than or equal to 254.
  if (brightness >= 200 || brightness <= 0)
  {
    direction = direction * -1;
  }
  
  // Delay 0.05sec (50ms)
  delay(50);
}
  
  
  
  
  
  
