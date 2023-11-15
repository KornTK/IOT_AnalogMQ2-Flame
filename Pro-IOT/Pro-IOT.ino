#define BUZZER_PIN 16

#define BLYNK_TEMPLATE_ID "TMPL6J2b7dpxe"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "r6fAQINtrC8GFhyFBgK7W6fbKfxcXOpm"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "KornTK-2.4G";
char pass[] = "pokde111*";

int analogPin = A0; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int sensor_Flame = 5;

int MQ = 0;
int Flam = 0;
void setup() {
  Serial.begin(9600);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(BUZZER_PIN,OUTPUT);
}
void loop() {
    Blynk.run();

MQ = analogRead(analogPin); //อ่านค่าสัญญาณ analog ขา5
Flam = digitalRead(sensor_Flame);
Serial.print("Flame = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "Flame = "
Serial.println(Flam);
Blynk.virtualWrite(V1, Flam);

Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "MQ = "
Serial.println(MQ); // พิมพ์ค่าของตัวแปร val
Blynk.virtualWrite(V0, MQ);

if (MQ > 500) { // สามารถกำหนดปรับค่าได้ตามสถานที่ต่างๆ
  digitalWrite(BUZZER_PIN,LOW);   //เปิดเสียงเตือน}
  Blynk.virtualWrite(V10, 1);
  delay(2500);

}else {
  digitalWrite(BUZZER_PIN,HIGH);   //ปิดเสียงเตือน}
  Blynk.virtualWrite(V10, 0);

    if (Flam == 0) { // สามารถกำหนดปรับค่าได้ตามสถานที่ต่างๆ
    digitalWrite(BUZZER_PIN,LOW);   //เปิดเสียงเตือน}
    Blynk.virtualWrite(V10, 1);
    delay(2500);

    }else {
      digitalWrite(BUZZER_PIN,HIGH);   //ปิดเสียงเตือน}
      Blynk.virtualWrite(V10, 0);


  };
};
delay(500);
}