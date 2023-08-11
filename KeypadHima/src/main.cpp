#include "keypadHeader.h"
#include "rfidHeader.h"
#include "mode.h"
#include "liquidCryHeader.h"

void setup() {
  lcdInit();
  rfid_setup();
}

void loop() {
  if (RFID_MODE) {
    rfid_loop();
  } else {
    keyPad();
  }
}

