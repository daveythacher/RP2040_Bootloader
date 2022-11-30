#include "hardware/flash.h"
#include "Interface.h"
#include "Interface/UART.h"

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

        uint32_t state = 0;     // TODO:
        switch(state) {
            case 0:
                len = 0;        // TODO:
                flash_range_program((uint32_t) address, buf + 16, len);
                break;
            case 1:
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