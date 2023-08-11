#include "keypadHeader.h"
#include "mode.h"

// Global Variabel    
char keymap[keypadRows][keypadCols] = 
{
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte keypadRowsPin[keypadRows] = {2, 3, 4, 5};
byte keypadColsPin[keypadCols] = {6, 7, 8, 9};

byte index = 0;
const byte passwordLength = 5;
String password;

Keypad mykeypad = Keypad(makeKeymap(keymap), keypadRowsPin, keypadColsPin, keypadRows, keypadCols);

// Fungsi loop
void keyPad() {
    char getKey = mykeypad.getKey();

    lcd.setCursor(0, 0);
    lcd.print("Masukan password");

    if (getKey != NO_KEY) {
        if (getKey == '*') {
            RFID_MODE = true;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Scan RFID");
            password = "";
            index = 0;
        }
                
        lcd.setCursor(index, 1);
        lcd.print(getKey);
        password += getKey;
        index++;
                
        if (index >= passwordLength) {
            lcd.setCursor(0, 1);
            lcd.print((password == "12456") ? "Akses diberikan" : "Akses ditolak");
            delay(2000);
            lcd.clear();
            index = 0;
            password = "";
        }
    }
}
