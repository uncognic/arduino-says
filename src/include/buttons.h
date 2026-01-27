#pragma once

#include <Arduino.h>
#include "const.h"

extern int greenButtonState;
extern int redButtonState;
extern int blueButtonState;
extern int yellowButtonState;
extern int whiteButtonState;
extern int orangeButtonState;

void setupButtons();
void readButtonState();
