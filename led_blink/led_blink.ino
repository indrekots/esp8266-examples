#define ESP8266_LED 5
#define OUTPUT_PIN 8

void setup() 
{
  Serial.begin(9600);
  pinMode(ESP8266_LED, OUTPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, HIGH);
}

void loop() 
{
  digitalWrite(ESP8266_LED, HIGH);
  delay(500);
  Serial.println("blink");
  digitalWrite(ESP8266_LED, LOW);
  delay(500);
}

