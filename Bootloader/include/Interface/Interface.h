#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>

class Interface {
    public:
        Interface();
        virtual ~Interface();

        static Interface *create();

        virtual void process();
        virtual bool enter(uint32_t *address) = 0;
    
    protected:
        virtual bool can_read() = 0;
        virtual void ack() = 0;

        uint8_t buf[32768 + 4];
        uint32_t *address;
};

#endif