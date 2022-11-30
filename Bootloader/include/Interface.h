#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>

class Interface {
    public:
        Interface();
        virtual ~Interface();

        static Interface *create();

        virtual bool enter() = 0;
        virtual int read(uint8_t *buffer, uint16_t len) = 0;
        virtual void ack() = 0;
        virtual void nack() = 0;
};

#endif