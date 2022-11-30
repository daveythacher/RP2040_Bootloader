#ifndef UART_H
#define UART_H

#include "Interface.h"

class UART : public Interface {
    public:
        UART();

        bool enter();
        int read(uint8_t *buffer, uint16_t len);
        void ack();
        void nack();
};

#endif