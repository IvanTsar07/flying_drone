#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#ifdef LED_BUILTIN
#undef LED_BUILTIN
#endif

#define TFT_CS (12)
#define TFT_RST (10)
#define TFT_DC (8)
#define TFT_BL (9)


#define Joy1_X (A0)
#define Joy1_Y (A1)
#define Joy2_X (A2)
#define Joy2_Y (A3)
#define Butt_A (A4)
#define BATT_P (A7)

#define LEFT_JOY (0)
#define RIGHT_JOY (1)

#define MODE_Prcnt (0)
#define MODE_VOLT (1)

// extern

void read_Joystick(bool which, byte data[2]),
    turnOFF_display(void);

float getBattery(bool mode);

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

class JoystickButton
{
  private:
    uint16_t t_hold_min, t_hold_max, current_t_hold;
    uint8_t pin_number;

  public:
    JoystickButton(uint16_t t_hold_min, uint16_t t_hold_max, uint8_t pin_number);
    bool isPressed();
};