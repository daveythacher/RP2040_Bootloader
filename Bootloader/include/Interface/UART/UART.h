#ifndef UART_H
#define UART_H

#include "Interface/Interface.h"
#include "hardware/dma.h"

class UART : public Interface {
    public:
        UART();

        bool enter(uint32_t *address);

    protected:
        bool can_read();
        void ack();
        void enter();

    private:
        dma_channel_config c;
};

#endif