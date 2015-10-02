long counter = 0;
volatile int state = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, updateState, FALLING);
}

void loop() {
  if (state == 0) {
    countByOnes();
  } else if (state == 1) {
    countByTens();
  } else {
    countByHundreds();
  }
  delay(1000);
}

void updateState() {
  state = (state + 1) % 3;
}

void countByOnes() {
  counter = counter + 1;
  Serial.println(counter);
}

void countByTens() {
  counter = counter + 10;
  Serial.println(counter);
}

void countByHundreds() {
  counter = counter + 100;
  Serial.println(counter);
}
