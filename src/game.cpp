#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"
#include "include/eeprom.h"

int ledRandom[6];
int buttonHitTimes;
int stage;
bool gameRunning = false;
int highScore = 0;
int streak = 0;

void startGame()
{
    for (int i = 0; i < 6; i++)
    {
        ledRandom[i] = random(1, 7);
    }
    stage = 1;
    buttonHitTimes = 0;
    gameRunning = true;
    lcdPrint("Game started!");
    flashGameLeds();
}
void nonBlockingDelay(unsigned long ms)
{
    unsigned long start = millis();
    while (millis() - start < ms)
    {
        readButtonState();
        delay(10);
    }
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
        lcdPrint("Correct button!");
        buttonHitTimes++;
        waitForRelease();
    }
    else
    {
        loseGame();
    }
}

void checkStageEnd()
{
    if (buttonHitTimes >= stage)
    {
        Serial.println("Stage completed.");
        lcdPrint("Stage completed!");
        stage++;
        buttonHitTimes = 0;
    }
    if (stage > 6)
    {
        winGame();
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
    }
    Serial.println("Game LEDs flashed");
}
void waitForStart()
{
    lcdPrint("Button to start...");
    lcdPrintAtLineTwo("Streak: ");
    lcdPrintIntAtCurPos(streak);
    lcdPrintAtCurPos(" High Score: ");
    lcdPrintIntAtCurPos(highScore);
    while (true)
    {
        readButtonState();
        if (getPressedButton() != 0)
        {
            break;
        }
        delay(10);
    }
    Serial.println("Game started!");
    lcdPrint("Game started!");
}
void winGame() {
    Serial.println("Game completed. You won!");
    lcdPrint("Game completed.");
    lcdPrintAtLineTwo("You won!");
    gameRunning = false;
    highScore++;
    streak++;
    saveData();
    nonBlockingDelay(2000);
    lcdPrint("High Score: ");
    lcdPrintIntAtCurPos(highScore);
    nonBlockingDelay(2000);
    lcdPrint("Streak: ");
    lcdPrintIntAtCurPos(streak);
}
void loseGame() {
    Serial.println("Wrong button pressed. Game over.");
    lcdPrint("Wrong button!");
    lcdPrintAtLineTwo("Game over.");
    nonBlockingDelay(2000);
    gameRunning = false;
    streak = 0;
    saveData();
    lcdPrint("Streak reset :(");
}