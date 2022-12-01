#include "hardware/flash.h"
#include "Interface/Interface.h"
#include "Interface/UART/UART.h"

Interface::Interface() {

}

Interface::~Interface() {

}

// TODO: Fix this
Interface *Interface::create() {
    return new UART();
}

void Interface::process() {
    bool stop = false;
    size_t len = 0;
    
    while (!stop) {
        flash_range_erase((uint32_t) address, sizeof(buf));
        while(!can_read());

        uint32_t state = buf[0];
        switch(state) {
            case 0:         // Program
                len = buf[1] + (buf[2] << 8);
                flash_range_program((uint32_t) address, buf + 4, len);
                break;
            case 1:         // Exit
                stop = true;
                break;
            default:
                while (1);  // Error!
                break;
        }

        address = address + sizeof(buf);
        ack();
    }
}