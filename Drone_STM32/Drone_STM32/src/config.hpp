#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

extern Adafruit_BME280 bme;
extern MPU6050 mpu;

/*Motor PINS*/
#define RT_FRONT (PB0)
#define LF_FRONT (PB1)
#define RT_BACK (PA6)
#define LF_BACK (PA7)

#define BAT_PIN (PC4)

#define MODE_Prcnt (0)
#define MODE_VOLT (1)

float getBattery(bool MODE);
