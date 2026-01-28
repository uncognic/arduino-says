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
    pinMode(orangeRed, OUTPUT);
    pinMode(orangeGreen, OUTPUT);
    pinMode(orangeBlue, OUTPUT);

    Serial.println("LEDs initialized.");
}
void ledFlash(int ledPin)
{
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    Serial.print("LED on pin ");
    Serial.print(ledPin);
    Serial.print(" flashed");
}
void ledOn(int ledPin)
{
    digitalWrite(ledPin, HIGH);
    Serial.print("LED on pin ");
    Serial.print(ledPin);
    Serial.println(" turned ON");
}
void ledOff(int ledPin)
{
    digitalWrite(ledPin, LOW);
    Serial.print("LED on pin ");
    Serial.print(ledPin);
    Serial.println(" turned OFF");
}
int parseLed(int ledNumber) {
    switch (ledNumber) {
        case 1:
            return green;
            break;
        case 2:
            return red;
            break;
        case 3:
            return blue;
            break;
        case 4:
            return yellow;
            break;
        case 5:
            return white;
            break;
        default:
            Serial.println("Unknown LED pin.");
            break;
    }
    lcdPrint("Game error");
    gameRunning = false;
    return -1;
}
void varOrange() {
    analogWrite(orangeRed, 255);
    analogWrite(orangeGreen, 165);
    analogWrite(orangeBlue, 0);
}
void varOrangeOff() {
    analogWrite(orangeRed, 0);
    analogWrite(orangeGreen, 0);
    analogWrite(orangeBlue, 0);
}