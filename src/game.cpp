#include "game.h"
#include "buttons.h"
#include "const.h"
#include <Arduino.h>

int randomNumber[6];

void startGame()
{
    for (int i = 0; i < 6; i++) {
        randomNumber[i] = random(0, 7);
    }
}

