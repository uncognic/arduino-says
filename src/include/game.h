#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/lcd.h"
#include "include/led.h"

extern int ledRandom[6];
extern int stage;
extern int buttonHitTimes;
extern bool gameRunning;
extern int highScore;
extern int streak;

void startGame();
void updateButtonHitTimes();
void checkStageEnd();
void flashGameLeds();
int getPressedButton();
void waitForRelease();
void waitForStart();
void winGame();
void loseGame();