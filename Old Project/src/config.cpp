#include "config.hpp"

PeriodicTask::PeriodicTask(unsigned long _interval, void (*_task)())
{
  interval = _interval;
  task = _task;
  previousMillis = 0;
}

void PeriodicTask::run()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    (*task)();
  }
}

void turnOFF_display(void)
{
  digitalWrite(TFT_BL, 0);
}

void read_Joystick(bool which, byte data[2])
{
  switch (which)
  {
  case LEFT_JOY:
    /* code */
    data[0] = analogRead(Joy1_X) >> 2;
    data[1] = analogRead(Joy1_Y) >> 2;
    break;

  case RIGHT_JOY:
    /* code */
    data[0] = analogRead(Joy2_X) >> 2;
    data[1] = analogRead(Joy2_Y) >> 2;
    break;
  }
}

float getBattery(bool MODE)
{
  float batteryLevel = analogRead(BATT_P) * 0.0048828125; // 5.0V / 1024

  if (MODE == MODE_Prcnt)
  {
    batteryLevel = map(batteryLevel, 0, 1023, 0, 100); // 0% - 100%
  }

  Serial.println(batteryLevel);

  return batteryLevel;
}
