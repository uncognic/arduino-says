#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/led.h"

extern LiquidCrystal_I2C lcd;

void lcdInit();
void lcdPrint(const char* message);
void lcdPrintInt(int number);
void lcdPrintIntAtCurPos(int number);
void lcdPrintAtLineTwo(const char* message);
void lcdPrintAtCurPos(const char* message);