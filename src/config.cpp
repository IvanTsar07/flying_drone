#include "config.hpp"

// class PeriodicTask
// {
//   unsigned long previousMillis;
//   unsigned long interval;
//   void (*task)();

// public:
//   PeriodicTask(unsigned long _interval, void (*_task)())
//   {
//     interval = _interval;
//     task = _task;
//     previousMillis = 0;
//   }

//   void run()
//   {
//     unsigned long currentMillis = millis();
//     if (currentMillis - previousMillis >= interval)
//     {
//       previousMillis = currentMillis;
//       (*task)();
//     }
//   }
// };


PeriodicTask::PeriodicTask(unsigned long _interval, void (*_task)())
  {
    interval = _interval;
    task = _task;
    previousMillis = 0;
  }

void PeriodicTask::run(){
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
