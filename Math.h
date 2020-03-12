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
    uint16_t index;
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
 * Class for applying a hysteresis
 */
class HysteresisClass {

  public:
    /*
     * Apply the hystereseis
     */
    uint32_t apply (
        uint32_t value,    // Input value
        int32_t threshold  // Hysteresis threshold
        );

  private:
    uint32_t lastValue = 0;
    int8_t   lastSign  = 1;
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
