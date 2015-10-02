void loop()
{
  digitalWrite(light_blue, HIGH);
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(light_list[i], HIGH);
    delay(250);
  }
  
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(light_ceiling[i], HIGH);
    delay(250);
  }
  digitalWrite(light_state0, HIGH);
  delay(250);
  digitalWrite(light_state1, HIGH);
  delay(250);
  
  for (int i = 7; i > -1; i--)
  {
    digitalWrite(light_list[i], LOW);
    delay(250);
  }
  
  for (int i = 6; i > -1; i--)
  {
    digitalWrite(light_ceiling[i], LOW);
    delay(250);
  }
  digitalWrite(light_state0, LOW);
  delay(250);
  digitalWrite(light_state1, LOW);
  delay(250);
  
  State_light(state);
  state = (state + 1) % 2;
}
