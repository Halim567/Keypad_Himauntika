#pragma once

#include <Arduino.h>
#include <Keypad.h>

#include "liquidCryHeader.h"

static const byte keypadRows = 4;
static const byte keypadCols = 4;

extern char keymap[keypadRows][keypadCols];

extern byte keypadRowsPin[keypadRows];
extern byte keypadColsPin[keypadCols];

extern byte index; 
extern const byte passwordLength;
extern String password;

extern Keypad mykeypad;

extern void keyPad();
