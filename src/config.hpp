#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#ifdef LED_BUILTIN
#undef LED_BUILTIN
#endif

#if defined(__AVR_ATmega2560__)
#define TFT_CS (53)
#define TFT_RST (49)
#define TFT_DC (48)
#define TFT_BL (46)
#elif defined(__AVR_ATmega328__)
#define TFT_CS (12)
#define TFT_RST (10)
#define TFT_DC (8)
#define TFT_BL (9)
#endif

#define Joy1_X (A0)
#define Joy1_Y (A1)
#define Joy2_X (A2)
#define Joy2_Y (A3)
#define LEFT_JOY (0)
#define RIGHT_JOY (1)

// extern

void read_Joystick(bool which, byte data[2]),
    turnOFF_display(void);

class PeriodicTask
{
  private:
    unsigned long previousMillis;
  unsigned long interval;
  void (*task)();

public:
  PeriodicTask(unsigned long interval, void (*task)());
  void run();
};
