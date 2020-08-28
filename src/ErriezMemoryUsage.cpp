/*
 * MIT License
 *
 * Copyright (c) 2020 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \file ErriezMemoryUsage.cpp
 * \brief Memory usage library for Arduino by Erriez
 * \details
 *      Source:         https://github.com/Erriez/ErriezMemoryUsage
 *      Documentation:  https://erriez.github.io/ErriezMemoryUsage
 */

#include <Arduino.h>
#include <ErriezMemoryUsage.h>

/*!
 * \brief Get RAM size in Bytes.
 * \return RAMEND - RAMSTART + 1.
 */
unsigned int getRamSize()
{
    return RAMEND - RAMSTART + 1;
}

/*!
 * \brief Get data section size in Bytes.
 * \return Data section size.
 */
unsigned int getDataSectionSize()
{
    extern unsigned int __data_start;
    extern unsigned int __data_end;

    return (unsigned int)&__data_end - (unsigned int)&__data_start;
}

/*!
 * \brief Get BSS section size in Bytes.
 * \return BSS section size.
 */
unsigned int getBssSectionSize()
{
    extern unsigned int __bss_start;
    extern unsigned int __bss_end;

    return (unsigned int)&__bss_end - (unsigned int)&__bss_start;
}

/*!
 * \brief Get stack size in Bytes.
 * \return Stack size.
 */
unsigned int getStackSize()
{
    return (unsigned int)RAMEND - (unsigned int)SP;
}

/*!
 * \brief Get heap size in Bytes.
 * \return Heap size.
 */
unsigned int getHeapSize()
{
    extern unsigned int __heap_start;
    extern unsigned int *__brkval;

    if (__brkval == NULL) {
        return 0;
    } else {
        return (unsigned int)__brkval - (unsigned int)&__heap_start;
    }
}

/*!
 * \brief Get free memory size in Bytes.
 * \return Free memory size.
 */
unsigned int getFreeMemSize()
{
    return getRamSize() -
           getStackSize() -
           getHeapSize() -
           getBssSectionSize() -
           getDataSectionSize();
}

/*!
 * \brief Print memory usage on serial port.
 */
void printMemoryUsage()
{
    Serial.print(F("SRAM size:  "));
    Serial.print(getRamSize());
    Serial.println(F(" Bytes"));

    Serial.print(F(".data size: "));
    Serial.print(getDataSectionSize());
    Serial.println(F(" Bytes"));

    Serial.print(F(".bss size:  "));
    Serial.print(getBssSectionSize());
    Serial.println(F(" Bytes"));

    Serial.print(F("Stack size: "));
    Serial.print(getStackSize());
    Serial.println(F(" Bytes"));

    Serial.print(F("Heap size:  "));
    Serial.print(getHeapSize());
    Serial.println(F(" Bytes"));

    Serial.print(F("Free mem:   "));
    Serial.print(getFreeMemSize());
    Serial.println(F(" Bytes"));
    Serial.println();
}
