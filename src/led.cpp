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