
const int joystickx = A2;
const int joysticky = A1;
const int joystickPush = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(joystickx, INPUT);
  pinMode(joysticky, INPUT);
  pinMode(joystickPush, INPUT);
}

void loop()
{
  int x = analogRead(joystickx);
  int y = analogRead(joysticky);
  int push = analogRead(joystickPush);
  int xcord = map(x, 0, 1023, 0, 180);
  int ycord = map(y, 0, 1023, 0, 180);
  Serial.print(xcord);
  Serial.print('\t');
  Serial.print(ycord);
  Serial.print('\t');
  Serial.println(push);
  delay(300);
}
