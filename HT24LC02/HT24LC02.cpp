#include "Arduino.h"
#include "Wire.h"
#include "HT24LC02.h"

HT24LC02::HT24LC02(int chipAddress) 
{
  _chipAddress = chipAddress;
}

void HT24LC02::write(byte address, byte data) 
{
   Wire.beginTransmission(_chipAddress);
   Wire.write(address); 
   Wire.write(data);
   Wire.endTransmission();
   delay(WRITE_DELAY);
}

void HT24LC02::write(byte address, byte* data, int length)
{
  byte wordsWritten = 0;
  byte currentAddress = address;
  while (wordsWritten < length) {
    if (wordsWritten % PAGE_SIZE == 0) {
      if (wordsWritten > 0) {
        Wire.endTransmission();  
        delay(WRITE_DELAY);
      } 
      Wire.beginTransmission(_chipAddress);
      Wire.write(currentAddress++);
    } else {
      currentAddress++; 
    }
    Wire.write(data[wordsWritten++]);           
  } 
  Wire.endTransmission();
  delay(WRITE_DELAY);
}

byte HT24LC02::read(byte address)
{
  byte result = 0xFF;
  
  Wire.beginTransmission(_chipAddress);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(_chipAddress, 1);
  if (Wire.available()) result = Wire.read();
  
  return result;
}

void HT24LC02::read(byte address, byte* buffer, int length)
{
  byte wordsRead = 0;
  Wire.beginTransmission(_chipAddress);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(_chipAddress, length);
  while (Wire.available()) buffer[wordsRead++] = Wire.read();
}



