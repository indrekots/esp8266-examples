#include <ESP8266WiFi.h>

const char* ssid = "Thomson2C63BC";
const char* password = "F01688D264";

const int FORWARDS = 5;
const int BACKWARDS = 0;
const int RIGHT = 4;
const int LEFT = 13;

const int SERVER_PORT = 1111;
const int BAUD_RATE = 9600;

WiFiServer server(SERVER_PORT);

void initOutputs() {
  pinMode(FORWARDS, OUTPUT);
  pinMode(BACKWARDS, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);
}

void connectWifi() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to WIFI network");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
}

void startServer() {
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void moveForwards() {
  digitalWrite(BACKWARDS, LOW);
  digitalWrite(FORWARDS, HIGH);
}

void moveBackwards() {
  digitalWrite(FORWARDS, LOW);
  digitalWrite(BACKWARDS, HIGH);
}

void turnRight() {
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, HIGH);
}

void turnLeft() {
  digitalWrite(RIGHT, LOW);
  digitalWrite(LEFT, HIGH);
}

void resetSteering() {
  digitalWrite(RIGHT, LOW);
  digitalWrite(LEFT, LOW);
}

void resetEngine() {
  digitalWrite(FORWARDS, LOW);
  digitalWrite(BACKWARDS, LOW);
}

void setup() {
  Serial.begin(BAUD_RATE);
  delay(10);

  initOutputs();
  connectWifi();
  startServer();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  char c = client.read();

  switch(c) {
    case 'd':
      Serial.println("turn right");
      turnRight();
      break;
    case 'a':
      Serial.println("Turn left");
      turnLeft();
      break;
    default:
      Serial.println("Default");
  }
  
  Serial.println(c);
  client.flush();
  Serial.println("Client disonnected");
}
