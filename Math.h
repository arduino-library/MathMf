/* 
 * Math library
 *
 * This source file is part of the Lithium-Ion Battery Charger Arduino firmware
 * found under http://www.github.com/microfarad-de/Math
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

#ifndef __MATH123_H
#define __MATH123_H

#include <Arduino.h>


/*
 * FIR Filter class
 */
class FirFilterClass {
  public:
    void initialize (int16_t *memory, uint16_t size);
    int16_t process (int16_t input);
  private:
    bool initialized = false;
    int16_t *memory;
    uint16_t size;
    int16_t index;
};


/*
 * IIR Filter class
 */
class IirFilterClass {
  public:
    int16_t process (int16_t input, uint16_t size);
  private:
    int32_t output = 0;
};


/*
 * Calculate the CRC checksum
 */
uint32_t crcCalc(uint8_t *buf, uint16_t bufSize);


/*
 * return the sign of a value
 */
int8_t sgn (int val);



#endif // __MATH123_H