#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "include/const.h"
#include "include/buttons.h"
#include "include/game.h"
#include "include/lcd.h"
#include "include/led.h"

void ledInit()
{
    pinMode(green, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(white, OUTPUT);
    pinMode(orange, OUTPUT);

    Serial.println("LEDs initialized.");
}
void ledFlash(int ledPin)
{
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    Serial.print("LED on pin ");
    Serial.print(ledPin);
    Serial.print(" flashed");
}
int parseLed(int ledNumber) {
    switch (ledNumber) {
        case 1:
            Serial.println("Green LED activated.");
            break;
        case 2:
            Serial.println("Red LED activated.");
            break;
        case 3:
            Serial.println("Blue LED activated.");
            break;
        case 4:
            Serial.println("Yellow LED activated.");
            break;
        case 5:
            Serial.println("White LED activated.");
            break;
        case 6:
            Serial.println("Orange LED activated.");
            break;
        default:
            Serial.println("Unknown LED pin.");
            break;
    }
}