#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>

class Interface {
    public:
        Interface();
        virtual ~Interface();

        virtual void process();
        virtual bool enter(uint32_t *address) = 0;
    
    protected:
        virtual bool can_read() = 0;
        virtual void ack() = 0;
        virtual void enter() = 0;

        uint8_t buf[1024 + 4];
        uint32_t *address;
};

#endif