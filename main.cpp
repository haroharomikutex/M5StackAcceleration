#include <Arduino.h>
#include "M5Stack.h"

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.begin();
  M5.Mpu6886.Init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float ax, ay, az, ax_t, ay_t, az_t;
  float gx, gy, gz, gx_t, gy_t, gz_t;

  ax = ay = az = 0.0f;
  gx = gy = gz = 0.0f;
  for (int i = 0; i < 10; ++i) {
    M5.Mpu6886.getAccelData(&ax_t, &ay_t, &az_t);
    M5.Mpu6886.getGyroData(&gx_t, &gy_t, &gz_t);

    ax += ax_t, ay += ay_t, az += az_t;
    gx += gx_t, gy += gy_t, gz += gz_t;
  }
  ax /= 10.0f, ay /= 10.0f, az /= 10.0f;
  gx /= 10.0f, gy /= 10.0f, gz /= 10.0f;

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("Acc: X:%.4f Y:%.4f Z:%.4f\n", ax, ay, az);
  M5.Lcd.printf("Gyr: X:%.4f Y:%.4f Z:%.4f\n", gx, gy, gz);
  delay(100);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
