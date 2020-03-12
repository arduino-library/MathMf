/* 
 * Math library
 *
 * This source file can be found under:
 * http://www.github.com/microfarad-de/Math
 * 
 * Please visit:
 *   http://www.microfarad.de
 *   http://www.github.com/microfarad-de
 * 
 * Copyright (C) 2019 Karim Hraibi (khraibi at gmail.com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

#include "Math.h"


void FirFilterClass::initialize (int16_t *memory, uint16_t size) {
  this->memory = memory;
  this->size = size;
  this->index = 0;
  this->initialized = true;
}

int16_t FirFilterClass::process (int16_t input) {
  uint16_t i;
  int32_t output = 0;
  if (!initialized) return 0;
  
  memory[index] = input;
  index++;
  if (index >= size) index = 0;

  for (i = 0; i < size; i++) {
    output = output + memory[i];
  }

  return (int16_t)(output / size);
}


/*#######################################################################################*/

int16_t IirFilterClass::process (int16_t input, uint16_t size) {
  output = ((size - 1) * output + (int32_t)input) / size;
  return (int16_t)output;
}


/*#######################################################################################*/


uint32_t HysteresisClass::apply (uint32_t value, int32_t threshold) {
  int32_t delta = value - lastValue;
  int8_t sign = sgn (delta);
  uint32_t result;

  if ( abs (delta) >= threshold || sign == lastSign) {
    result = value;
    lastSign = sign;
    lastValue = value;
  }
  else {
    result = lastValue;
  }

  return result;
}


/*#######################################################################################*/

uint32_t crcCalc(uint8_t *buf, uint16_t bufSize) {

  const uint32_t crcTable[16] = {
    0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
    0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
    0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
  };

  uint32_t crc = ~0L;

  for (uint16_t index = 0 ; index < bufSize  ; ++index) {
    crc = crcTable[(crc ^ buf[index]) & 0x0f] ^ (crc >> 4);
    crc = crcTable[(crc ^ (buf[index] >> 4)) & 0x0f] ^ (crc >> 4);
    crc = ~crc;
  }
  return crc;
}


/*#######################################################################################*/

int8_t sgn (int val) {
  if (val < 0) return -1;
  else         return 1;
}

