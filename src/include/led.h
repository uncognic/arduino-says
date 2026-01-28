#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"

void ledInit();
void ledFlash(int ledPin);
int parseLed(int ledNumber);
void varOrange();
void varOrangeOff();
void ledOn(int ledPin);
void ledOff(int ledPin);