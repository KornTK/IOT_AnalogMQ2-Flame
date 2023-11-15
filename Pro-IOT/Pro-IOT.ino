#define BUZZER_PIN 16

#define BLYNK_TEMPLATE_ID "TMPL6J2b7dpxe"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "r6fAQINtrC8GFhyFBgK7W6fbKfxcXOpm"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266HTTPClient.h>

char ssid[] = "KornTK-2.4G";
char pass[] = "pokde111*";
String APIserver = "https://iot.korntk.com/iot-pro1/iot-api1.php?";

int analogPin = A0;
int sensor_Flame = 5; // Assuming the flame sensor is connected to pin D5

int MQ = 0;
int Flam = 0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  Blynk.run();
  HTTPClient http;

  MQ = analogRead(analogPin);
  Flam = digitalRead(sensor_Flame);

  Serial.print("Flame = ");
  Serial.println(Flam);
  Blynk.virtualWrite(V1, Flam);

  Serial.print("Mq2 = ");
  Serial.println(MQ);
  Blynk.virtualWrite(V0, MQ);

  if (MQ > 500 || Flam == 0) {
    digitalWrite(BUZZER_PIN, LOW);
    Blynk.virtualWrite(V10, 1);
    APIserver = "https://iot.korntk.com/iot-pro1/iot-api1.php?mq2=" + String(MQ) + "&flarm=" + String(Flam); // Construct API URL
    Serial.print(APIserver);
    WiFiClientSecure client; // Create a WiFiClientSecure object for HTTPS
    client.setInsecure(); // Allow insecure connections (not recommended in production)
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS); // Follow strict redirects
    http.begin(client, APIserver);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    delay(2500);
  } else {
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.virtualWrite(V10, 0);
  }

  delay(500);
}
