#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

#define PIR 13
#define BUZZER 4

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);

  pinMode(PIR, INPUT);
  pinMode(BUZZER, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop()
{
  int motion = digitalRead(PIR);

  if(motion == HIGH)
  {
    Serial.println("Intruder Detected!");

    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }

  delay(500);
}