#include <Wire.h> 
#include <LiquidTWI2.h> 
#include <SeeedRFID.h>

#define RFID_RX_PIN 1
#define RFID_TX_PIN 2

SeeedRFID RFID(RFID_RX_PIN, RFID_TX_PIN);
RFIDdata tag;

LiquidTWI2 lcd(27); // 0 = i2c address 
void setup() { 
lcd.setMCPType(LTI_TYPE_MCP23008); // must be called before begin() 
lcd.begin(16,2); 
lcd.setBacklight(LOW); // only supports HIGH or LOW } 

void loop() { 
  if(RFID.isAvailable()){
        lcd.setBacklight(HIGH);
        tag = RFID.data();
        lcd.print("RFID card number: ");
        lcd.print(RFID.cardNumber());
#ifdef TEST
    Serial.print("RFID raw data: ");
    for(int i=0; i<tag.dataLen; i++){
        Serial.print(tag.raw[i], HEX);
        Serial.print('\t');
        }
#endif
    }
lcd.print(“Hello World!”); 
delay(500); 
lcd.clear(); 
delay(500); 
} 
