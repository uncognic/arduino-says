#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"

int greenButtonState;
int redButtonState;
int blueButtonState;
int yellowButtonState;
int whiteButtonState;
int orangeButtonState;

void setupButtons()
{
    pinMode(greenButton, INPUT_PULLUP);
    pinMode(redButton, INPUT_PULLUP);
    pinMode(blueButton, INPUT_PULLUP);
    pinMode(yellowButton, INPUT_PULLUP);
    pinMode(whiteButton, INPUT_PULLUP);
    pinMode(orangeButton, INPUT_PULLUP);
    Serial.println("Buttons setup complete.");
}

void readButtonState()
{
    greenButtonState = digitalRead(greenButton);
    redButtonState = digitalRead(redButton);
    blueButtonState = digitalRead(blueButton);
    yellowButtonState = digitalRead(yellowButton);
    whiteButtonState = digitalRead(whiteButton);
    orangeButtonState = digitalRead(orangeButton);

    Serial.println("Button states read.");
}