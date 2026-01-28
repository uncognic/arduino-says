#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "include/const.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"

extern int greenButtonState;
extern int redButtonState;
extern int blueButtonState;
extern int yellowButtonState;
extern int whiteButtonState;
extern int orangeButtonState;

void setupButtons();
void readButtonState();
