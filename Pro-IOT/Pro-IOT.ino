#define BUZZER_PIN 16

int analogPin = A0; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int sensor_Flame = 5;

int MQ = 0;
int Flam = 0;
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN,OUTPUT);
}
void loop() {
MQ = analogRead(analogPin); //อ่านค่าสัญญาณ analog ขา5
Flam = digitalRead(sensor_Flame);
Serial.print("Flame = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "Flame = "
Serial.println(Flam);
Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "MQ = "
Serial.println(MQ); // พิมพ์ค่าของตัวแปร val
if (MQ > 500) { // สามารถกำหนดปรับค่าได้ตามสถานที่ต่างๆ
  digitalWrite(BUZZER_PIN,LOW);   //ปิดเสียงเตือน}
}else {
  digitalWrite(BUZZER_PIN,HIGH);   //ปิดเสียงเตือน}
    if (Flam == 0) { // สามารถกำหนดปรับค่าได้ตามสถานที่ต่างๆ
    digitalWrite(BUZZER_PIN,LOW);   //ปิดเสียงเตือน}
    }else {
      digitalWrite(BUZZER_PIN,HIGH);   //ปิดเสียงเตือน}

  };
};
delay(1000);
}