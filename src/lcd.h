#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "const.h"
#include "buttons.h"
#include "game.h"

extern LiquidCrystal_I2C lcd;

void lcdInit();
void lcdClearPrint(const char* message);