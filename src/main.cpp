#include "config.hpp"

byte joyLeftValues[2], _joyLeftValues[2]{0}, joyRightValue[2], _joyRightValue[2]{0};

// byte ptr_l[2] = *joyLeftValues;
// byte ptr_r[2] = *joyLeftValues;

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void joystick1_read();
void joystick2_read();
void getBatteryLevel();

void setup()
{
  // put your setup code here, to run once:
  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, 200);
  tft.init(240, 320);
  tft.fillScreen(ST77XX_BLUE);
  tft.setRotation(2);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.print("Joystick 1X:");
  tft.setCursor(10, 30);
  tft.print("Joystick 1Y:");
  tft.setCursor(10, 50);
  tft.print("Joystick 2X:");
  tft.setCursor(10, 70);
  tft.print("Joystick 2Y:");


}

PeriodicTask DETECT_LEFT_JOYSTICK_VALUE(100, joystick1_read), DETECT_RIGHT_JOYSTICK_VALUE(100, joystick2_read), DETECT_BATTERY(1000, getBatteryLevel);

void loop()
{
  DETECT_LEFT_JOYSTICK_VALUE.run();
  DETECT_RIGHT_JOYSTICK_VALUE.run();

  if (millis() % 100 == 0)
  {
    if (joyLeftValues[0]!=_joyLeftValues[0] || joyLeftValues[1]!=_joyLeftValues[1])
    {
      /* code */
      _joyLeftValues[0]=joyLeftValues[0];
      _joyLeftValues[1]=joyLeftValues[1];
      tft.fillRect(167,10,36,50,ST77XX_BLUE);
      tft.setCursor(167,10);
      tft.print(_joyLeftValues[0]);
      tft.setCursor(167,30);
      tft.print(_joyLeftValues[0]);
    }
    
    tft.print(joyLeftValues[0]);
    tft.print(joyLeftValues[1]);

    tft.print(joyRightValue[0]);

    tft.print(joyRightValue[1]);
  }
}

void joystick1_read()
{
  read_Joystick(LEFT_JOY, joyLeftValues);
}

void joystick2_read()
{
  read_Joystick(RIGHT_JOY, joyRightValue);
}

void getBatteryLevel()
{
  float battery = getBattery(MODE_Prcnt);

  tft.setCursor(40, 10);
  tft.print("Battery: ");
  tft.print(String(battery));

  if (MODE_Prcnt)
  {
    tft.print("%");
  }
}