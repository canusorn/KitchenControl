
// ไลบรารี่ที่ใช้เพิ่มเติม
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

// โค้ด DHT อ้างอิงจากตัวอย่าง DHT sensor Library > DHTtester

#include "DHT.h"

#define DHTPIN PB11     // กำหนดขาที่ต่อกับ DHT sensor
#define DHTTYPE DHT11   // กำหนดรุ่นเซนเซอร์เป็น DHT 11

DHT dht(DHTPIN, DHTTYPE);

#define MQ2 PA5   // กำหนดขาต่อกับ A0 ของ mq-2

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  // อ่านค่าจากเซนเซอร์ DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // อ่านค่าจากเซนเซอร์ mq-2
  int gas = analogRead(PA5);

  // แสดงค่า
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print("%  Temperature: "); Serial.print(t); Serial.println("°C ");
  Serial.print("Gas: "); Serial.println(gas);

  delay(2000);

}
