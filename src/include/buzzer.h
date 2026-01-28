#pragma once

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
#include "include/pitches.h"

void buzzerInit();
void buzzerPlayTone(int frequency, int duration);
void buzzerPlay(int frequency);
void buzzerStop();