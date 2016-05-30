const int ENABLE_PIN = 9;
const int DC1 = 4;
const int DC2 = 3;

void setup() {
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(DC1, OUTPUT);
  pinMode(DC2, OUTPUT);

  digitalWrite(ENABLE_PIN, HIGH);
  digitalWrite(DC1, HIGH);
  digitalWrite(DC2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
