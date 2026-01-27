#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"

int ledRandom[6];
int buttonHitTimes;
int stage;
bool gameRunning = false;

void startGame()
{
    for (int i = 0; i < 6; i++)
    {
        ledRandom[i] = random(1, 7);
    }
    stage = 1;
    buttonHitTimes = 0;
    gameRunning = true;
    flashGameLeds();
}

int getPressedButton()
{

    if (greenButtonState == LOW)
        return 1;
    if (redButtonState == LOW)
        return 2;
    if (blueButtonState == LOW)
        return 3;
    if (yellowButtonState == LOW)
        return 4;
    if (whiteButtonState == LOW)
        return 5;
    if (orangeButtonState == LOW)
        return 6;
    return 0;
}

void waitForRelease()
{
    while (getPressedButton() != 0)
    {
        readButtonState();
        delay(10);
    }
}

void updateButtonHitTimes()
{
    int pressed = getPressedButton();
    if (pressed == 0)
        return;
    Serial.print("Button pressed: ");
    Serial.println(pressed);

    if (pressed == ledRandom[buttonHitTimes])
    {
        Serial.println("Correct button pressed");
        buttonHitTimes++;
        waitForRelease();
    }
    else
    {
        Serial.println("Wrong button pressed. Game over.");
        gameRunning = false;
    }
}

void checkStageEnd()
{
    if (buttonHitTimes >= stage)
    {
        Serial.println("Stage completed.");
        stage++;
        buttonHitTimes = 0;
    }
    if (stage > 6)
    {
        Serial.println("Game over. You completed all stages");
        gameRunning = false;
    }
}

void flashGameLeds()
{
    if (!gameRunning)
    {
        return;
    }
    for (int i = 0; i < stage; i++)
    {
        int ledPin = parseLed(ledRandom[i]);
        ledFlash(ledPin);
        delay(500);
    }
    Serial.println("Game LEDs flashed");
}
void waitForStart()
{
    Serial.println("Press any button to start the game");
    while (true) {
        readButtonState();
        if (getPressedButton() != 0) {
            break;
        }
        delay(10);
    }
    Serial.println("Game started!");
}