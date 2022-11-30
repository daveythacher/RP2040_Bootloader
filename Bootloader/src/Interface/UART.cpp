#include "Interface/UART.h"

UART::UART() : Interface() {

}

bool UART::enter() {
    return false;
}

int UART::read(uint8_t *buffer, uint16_t len) {
    return 0;
}

void UART::ack() {

}

void UART::nack() {

}
