#ifndef UART_H
#define UART_H

#include "Interface.h"

class UART : public Interface {
    public:
        UART();

        bool enter(uint32_t *address);

    protected:
        bool can_read();
        void ack();
};

#endif