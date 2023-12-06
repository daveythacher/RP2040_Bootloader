#ifndef CDC_H
#define CDC_H

#include "Interface/Interface.h"
#include "hardware/dma.h"

class CDC : public Interface {
    public:
        CDC();

        bool enter(uint32_t *address);

    protected:
        bool can_read();
        void ack();
};

#endif