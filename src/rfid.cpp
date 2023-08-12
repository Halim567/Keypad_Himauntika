#include "rfidHeader.h"

const byte PIN_SS = 10;
const byte PIN_RST = A0;

MFRC522 rfid(PIN_SS, PIN_RST);

String id_rfid;
bool found = false;
    
void rfid_setup() {
    SPI.begin();
    rfid.PCD_Init();
}

void rfid_loop() {

    if (!rfid.PICC_IsNewCardPresent() or !rfid.PICC_ReadCardSerial())
        return;

    for (byte i = 0; i < rfid.uid.size; i++) {
        id_rfid.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
        id_rfid.concat(String(rfid.uid.uidByte[i], HEX));
    }

    id_rfid.toUpperCase();
    // lcd.setCursor(0, 0);
    // lcd.print(id_rfid);

    pengecekan_id();

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    found = false;
    id_rfid = "";
}

void pengecekan_id() {
    for (String id : id_user) {
        if (id_rfid == id) {
            found = true;
            lcd.setCursor(0, 1);
            lcd.print("Akses diberikan");
            RFID_MODE = false;
            
            delay(2000);
            lcd.clear();
            break;
        }
    } 
    if (!found) {
        lcd.setCursor(0, 1);
        lcd.print("Akses ditolak");
        RFID_MODE = false;
            
        delay(2000);
        lcd.clear();
    }
}