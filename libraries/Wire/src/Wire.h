/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
  Modified 2020 by Greyson Christoforo (grey@christoforo.net) to implement timeouts
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "Stream.h"

#define BUFFER_LENGTH 32

// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

class TwoWire : public Stream
{
private:
    uint8_t rxBuffer[BUFFER_LENGTH];
    uint8_t rxBufferIndex;
    uint8_t rxBufferLength;

    uint8_t txAddress;
    uint8_t txBuffer[BUFFER_LENGTH];
    uint8_t txBufferIndex;
    uint8_t txBufferLength;

    // static uint8_t transmitting;
    // static void (*user_onRequest)(void);
    // static void (*user_onReceive)(int);
    // static void onRequestService(void);
    // static void onReceiveService(uint8_t *, int);

    uint32_t m_base;
    int m_address;

public:
    TwoWire(uint32_t base);
    void begin();
    void begin(int address);
    void end();
    void setClock(uint32_t clock);
    void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false);
    bool getWireTimeoutFlag(void);
    void clearWireTimeoutFlag(void);
    void beginTransmission(int);
    int endTransmission(void);
    int endTransmission(int sendStop);
    int requestFrom(int address, int quantity);
    int requestFrom(int address, int quantity, int sendStop);
    int requestFrom(int address, int quantity, int iaddress, int isize, int sendStop);
    virtual size_t write(uint8_t data);
    virtual size_t write(const void *data, size_t quantity);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    // void onReceive(void (*)(int));
    // void onRequest(void (*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
};
#ifdef ARDUINO
extern TwoWire Wire;
#endif
#endif
