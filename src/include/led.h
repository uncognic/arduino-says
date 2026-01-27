#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "const.h"
#include "buttons.h"
#include "game.h"
#include "lcd.h"
#include "led.h"

void ledInit();
void ledFlash(int ledPin);
int parseLed(int ledNumber);