#include "liquidCryHeader.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcdInit() {
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.clear();
}