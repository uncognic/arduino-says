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
#include "include/buzzer.h"

void buzzerInit()
{
    pinMode(buzzerPin, OUTPUT);
    Serial.println("Buzzer initialized.");
}

void buzzerPlayTone(int frequency, int duration)
{
    Serial.print("Buzzer playing tone: ");
    Serial.print(frequency);
    Serial.print(" Hz for ");
    Serial.print(duration);
    Serial.println(" ms");
    tone(buzzerPin, frequency, duration);
}