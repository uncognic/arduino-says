#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "const.h"
#include "buttons.h"
#include "game.h"
#include "lcd.h"
#include "led.h"

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