#include <NewPing.h>

int trigger = 12;
int echo = 4;

NewPing sonar(trigger,echo);
//NewPing sonarhappy(7,4);

void setup()
{
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.println(distance);
  delay(500);
}  
