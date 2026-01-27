#include <Arduino.h>
#include "const.h"
#include "buttons.h"
#include "game.h"

int pullUp = LOW;
int greenButtonState;
int redButtonState;
int blueButtonState;
int yellowButtonState;
int whiteButtonState;
int varButtonState;

void setup()
{
  Serial.begin(9600);
  setupButtons();
}

void loop()
{
  readButtonState();
}
