#include <Arduino.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"
#include "include/eeprom.h"

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  Serial.begin(9600);
  setupButtons();
  lcdInit();
  ledInit();
  loadData();
  waitForStart();
  startGame();
}

void loop()
{
  if (!gameRunning)
  {
    waitForStart();
    startGame();
  }
  lcdPrint("Stage: ");
  lcdPrintIntAtCurPos(stage);
  readButtonState();
  updateButtonHitTimes();
  checkStageEnd();
}
