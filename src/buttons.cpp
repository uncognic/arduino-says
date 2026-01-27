#include <Arduino.h>
#include "buttons.h"

int greenButtonState;
int redButtonState;
int blueButtonState;
int yellowButtonState;
int whiteButtonState;
int orangeButtonState;

void setupButtons()
{
    pinMode(greenButton, INPUT_PULLUP);
    pinMode(green, OUTPUT);

    pinMode(redButton, INPUT_PULLUP);
    pinMode(red, OUTPUT);

    pinMode(blueButton, INPUT_PULLUP);
    pinMode(blue, OUTPUT);

    pinMode(yellowButton, INPUT_PULLUP);
    pinMode(yellow, OUTPUT);

    pinMode(whiteButton, INPUT_PULLUP);
    pinMode(white, OUTPUT);

    pinMode(orangeButton, INPUT_PULLUP);
    pinMode(orange, OUTPUT);

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