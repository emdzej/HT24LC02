#include <Wire.h>
#include "HT24LC02.h"

HT24LC02 eeprom(0x50);
char buffer[32];
void setup() 
{
  char data[] = "Hello, HT24LC02";
  Wire.begin();
  Serial.begin(9600);
  eeprom.write(0, (byte*)data, sizeof(data));
  eeprom.write(WORD_COUNT - 1, '-');
  Serial.println("Message written");
}

void loop() 
{
  eeprom.read(0, (byte*)buffer, sizeof(buffer));
  Serial.print(buffer);  
  Serial.println("#");
  Serial.println((char)eeprom.read(WORD_COUNT - 1));
  delay(1000);
}
