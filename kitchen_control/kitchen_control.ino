
// ไลบรารี่ที่ใช้เพิ่มเติม
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

// โค้ด DHT อ้างอิงจากตัวอย่าง DHT sensor Library > DHTtester

#include "DHT.h"

#define DHTPIN PB11     // กำหนดขาที่ต่อกับ DHT sensor
#define DHTTYPE DHT11   // กำหนดรุ่นเซนเซอร์เป็น DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  
  delay(2000);
  
  // อ่านค่าจากเซนเซอร์ DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();

// เช็คกรณีอ่านค่าไม่ได้ ให้กลับไปเริ่มใหม่
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");Serial.print(h);
  Serial.print("%  Temperature: ");Serial.print(t);Serial.println("°C ");
  
}
