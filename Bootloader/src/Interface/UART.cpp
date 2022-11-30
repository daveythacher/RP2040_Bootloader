#include "Interface/UART.h"

UART::UART() : Interface() {

}

// TODO
bool UART::enter(uint32_t *adr) {
    address = adr;
    return false;
}

// TODO
bool UART::can_read() {
    return false;
}

// TODO
void UART::ack() {

}
