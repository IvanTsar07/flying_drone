#include "config.hpp"

uint32_t motors_pins[4] = {LF_FRONT, LF_BACK, RT_BACK, RT_FRONT};

float P = 0, Po = 0;
const float pow_Hei = 1/5.255 , L_To = 44330;

void initDrone(void)
{
    analogWriteResolution(10);
    mpu.initialize();
    mpu.CalibrateAccel();
    mpu.CalibrateGyro();
    bme.begin();
    Po = bme.readPressure();
    for (int i = 0; i < 4; i++)
    {
        pinMode(motors_pins[i],OUTPUT);
    }
    
       
}

float getBattery(bool MODE)
{
  float batteryLevel = analogRead(BAT_PIN) * 3.6 / 4095; // 5.0V / 1024

  if (MODE == MODE_Prcnt)
  {
    batteryLevel = map(batteryLevel, 0, 3.6, 0, 100); // 0% - 100%
  }

  Serial.println(batteryLevel);

  return batteryLevel;
}