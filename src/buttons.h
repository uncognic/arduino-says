#pragma once

#include <Arduino.h>
#include "const.h"

extern int greenButtonState;
extern int redButtonState;
extern int blueButtonState;
extern int yellowButtonState;
extern int whiteButtonState;
extern int varButtonState;

void setupButtons();
void readButtonState();
