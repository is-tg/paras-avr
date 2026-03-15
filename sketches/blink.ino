void setup() {
  // 8 = P10
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, LOW);  // on
  delay(200);
  digitalWrite(10, HIGH);  // off
  delay(200);
}