#include <Wire.h>
#include <Adafruit_ADXL345_U.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
TinyGPSPlus gps;
HardwareSerial SerialGPS(2); // UART2: RX2=D16, TX2=D17

void setup() {
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17); // GPS
  Wire.begin(21, 22); // I2C para ADXL345

  Serial.println("Iniciando sensores...");

  if (!accel.begin()) {
    Serial.println("Erro ao iniciar ADXL345!");
    while (1);
  }
  Serial.println("ADXL345 pronto!");
}

void loop() {
  // Leitura do acelerômetro
  sensors_event_t event;
  accel.getEvent(&event);
  Serial.print("Aceleração X: "); Serial.print(event.acceleration.x);
  Serial.print(" Y: "); Serial.print(event.acceleration.y);
  Serial.print(" Z: "); Serial.println(event.acceleration.z);

  // Leitura do GPS
  while (SerialGPS.available() > 0) {
    gps.encode(SerialGPS.read());
    if (gps.location.isUpdated()) {
      Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
    }
  }

  delay(1000);
}
