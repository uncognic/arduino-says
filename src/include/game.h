#pragma once

#include <Arduino.h>
#include "const.h"
#include "buttons.h"

extern int ledRandom[6];
extern int stage;
extern int buttonHitTimes;
extern bool gameRunning;

void startGame();
void updateButtonHitTimes();
void checkStageEnd();
void flashGameLeds();