int delayTimes [4] = {1, 2, 3, 4};
int notes [4] = {100, 200, 300, 400};

void setup() {
  Serial.begin(9600); 
}

void loop() {
  for (int i = 0; i < 4; i++) {  
    Serial.println(notes[i]);
    Serial.println(delayTimes[i]); 
  }  
}

int notes [22] = {c, d, e, f, g, g, a, a, a, a, g, f, f, f, f, e, e, d, d, d, d, c};
int delay_times [22] = {900, 900, 900, 900, 1900, 1900, 900, 900, 900, 900, 3900, 900, 900, 900, 900, 1900, 1900, 900, 900, 900, 900, 3900};
int servo_speed [22] = {1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90, 1, 90};

for (int i = 0; i < 22; i++)
{
  analogWrite(light, 0);
  servo1.write(servo_speed[i]);
  tone(beeper, notes[i]);
  delay(delat_times[i]);
  tone(beeper, 0);
  delay(100);
}
