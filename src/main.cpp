#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "const.h"
#include "buttons.h"
#include "game.h"
#include "lcd.h"
#include "led.h"

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  Serial.begin(9600);
  setupButtons();
  lcdInit();
  ledInit();
}

void loop()
{
  readButtonState();
  checkButtons();
  checkStageEnd();
}
