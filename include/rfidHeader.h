#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#include "liquidCryHeader.h"
#include "id_member.h"
#include "mode.h"

extern const byte PIN_SS;
extern const byte PIN_RST;

extern MFRC522 rfid;
extern String id_rfid;
extern bool found;

extern void pengecekan_id();
extern void rfid_setup();
extern void rfid_loop();
