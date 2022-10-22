
// ไลบรารี่ที่ใช้เพิ่มเติม
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

// โค้ด DHT อ้างอิงจากตัวอย่าง DHT sensor Library > DHTtester

#include "DHT.h"

#define MQ2 PA5         // กำหนดขาต่อกับ A0 ของ mq-2
#define RELAY PC13      // กำหนดขาต่อกับ Relay

#define DHTPIN PB11     // กำหนดขาที่ต่อกับ DHT sensor
#define DHTTYPE DHT11   // กำหนดรุ่นเซนเซอร์เป็น DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  digitalWrite(RELAY, HIGH);
  pinMode(RELAY, OUTPUT);
}

void loop() {

  // อ่านค่าจากเซนเซอร์ DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // อ่านค่าจากเซนเซอร์ mq-2
  int gas = analogRead(PA5);    // อ่านค่าอนาลอก มีค่า 0-4095

  // แสดงค่า
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print("%  Temperature: "); Serial.print(t); Serial.println("°C ");
  Serial.print("Gas: "); Serial.println(gas);

  // เงือนไขการทำงานพัดลม
  if (gas > 2500 || t > 40) {             // แก้สมากกว่า 2500 หรืออุณหภูมิสูงกว่า 40 ให้รีเลย์ทำงาน
    digitalWrite(RELAY, LOW);             // Relay เป็น Active low
  } else {                                // พัดลมหยุดทำงาน
    digitalWrite(RELAY, HIGH);
  }

  delay(2000);
}
