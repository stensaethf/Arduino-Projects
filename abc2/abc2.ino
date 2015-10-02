
const int joystickx = A0;
const int joysticky = A1;
const int joystickPush = A2;

void setup()
{
  pinMode(joystickx, INPUT);
  pinMode(joysticky, INPUT);
  pinMode(joystickPush, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(joystickx); // read joystick in x plane
  int y = analogRead(joysticky); // read joystick in y plane
  int push = analogRead(joystickPush); // read joystick push
  int xcord = map(x, 0, 1023, 0, 5); // sets range to 1 - 180
  int ycord = map(y, 0, 1023, 0, 5); // sets range to 1 - 180
  Serial.print(xcord);
  Serial.print('\t');
  Serial.print(ycord);
  Serial.print('\t');
  Serial.println(push);
  delay(250);
}
