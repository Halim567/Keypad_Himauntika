#include "rfidHeader.h"
#include "mode.h"

const byte PIN_SS = 10;
const byte PIN_RST = A0;

MFRC522 rfid(PIN_SS, PIN_RST);
String id_rfid;

    
void rfid_setup() {
    SPI.begin();
    rfid.PCD_Init();
}

void rfid_loop() {

    if (!rfid.PICC_IsNewCardPresent() or !rfid.PICC_ReadCardSerial())
        return;

    for (byte i = 0; i < 4; i++) {
        id_rfid += String(rfid.uid.uidByte[i]);
    }

    // Pengecekan id
    if (id_rfid == "571406274") {
        lcd.setCursor(0, 1);
        lcd.print("Akses diberikan");
        RFID_MODE = false;

        delay(2000);
        lcd.clear();
    } else {
        lcd.setCursor(0, 1);
        lcd.print("Akses ditolak");
        RFID_MODE = false;

        delay(2000);
        lcd.clear();
    }

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    id_rfid = "";
}