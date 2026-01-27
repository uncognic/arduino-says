#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"

void lcdInit()
{
    lcd.init();
    lcd.clear();
    lcd.backlight();
    Serial.println("LCD initialized.");
}

void lcdClearPrint(const char* message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
    Serial.print("LCD message: ");
    Serial.println(message);
}