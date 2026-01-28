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

void saveData()
{
    EEPROM.put(0, highScore);
    EEPROM.put(sizeof(highScore), streak);
    Serial.println("Game data saved to EEPROM.");
    lcdPrint("Data saved.");
}
void loadData()
{
    EEPROM.get(0, highScore);
    EEPROM.get(sizeof(highScore), streak);
    Serial.println("Game data loaded from EEPROM.");
    lcdPrint("Data loaded.");
}