#include "game.h"
#include "buttons.h"
#include "const.h"
#include <Arduino.h>

int ledRandom[6];
int buttonHitTimes;
int stage;
bool gameRunning = false;

void startGame()
{
    for (int i = 0; i <= 6; i++)
    {
        ledRandom[i] = random(0, 7);
    }
    gameRunning = true;
}

void checkButtons()
{
    if (greenButtonState == LOW)
    {
        Serial.println("Green button pressed.");
        buttonHitTimes++;
    }
    if (redButtonState == LOW)
    {
        Serial.println("Red button pressed.");
        buttonHitTimes++;
    }
    if (blueButtonState == LOW)
    {
        Serial.println("Blue button pressed.");
        buttonHitTimes++;
    }
    if (yellowButtonState == LOW)
    {
        Serial.println("Yellow button pressed.");
        buttonHitTimes++;
    }
    if (whiteButtonState == LOW)
    {
        Serial.println("White button pressed.");
        buttonHitTimes++;
    }
    if (varButtonState == LOW)
    {
        Serial.println("Var button pressed.");
        buttonHitTimes++;
    }
}
void checkStageEnd() {
    if (buttonHitTimes >= stage) {
        Serial.println("Stage completed.");
        stage++;
        buttonHitTimes = 0;
    }
    if (stage > 6) {
        Serial.println("Game over. You completed all stages!");
        gameRunning = false;
    }
}
