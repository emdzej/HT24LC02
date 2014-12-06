/*
  HT24LC02.h - Library for I2C EEPROM
  Created by Michal Jaskolski, 2014-12-06
  Distributed under the MIT Licence
  
  Datasheet can be found here http://www.holtek.com/pdf/memory/ht24lc02v180.pdf
*/

#ifndef HT24LC02_h
#define HT24LC02_h

#include "Arduino.h"


#define WORD_COUNT 256
#define PAGE_SIZE 8
#define WRITE_DELAY 5

class HT24LC02
{
  public:
    HT24LC02(int chipAddress);
    void write(byte address, byte data);
    void write(byte address, byte* data, int length);
    byte read(byte address);
    void read(byte address, byte* buffer, int length);
   private:
     int _chipAddress;
};

#endif
