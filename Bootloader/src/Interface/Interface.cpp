#include "hardware/flash.h"
#include "Interface/Interface.h"

Interface::Interface() {
    // TODO: Setup watchdog
}

Interface::~Interface() {

}

// TODO: Improve (CRC, protocol, etc.)
void Interface::process() {
    bool stop = false;
    size_t len = 0;
    
    while (!stop) {
        flash_range_erase((uint32_t) address, sizeof(buf) - 4);
        while(!can_read());

        uint32_t state = buf[0];
        switch(state) {
            case 0:         // Program
                len = buf[1] + (buf[2] << 8);
                if (len > (sizeof(buf) - 4))
                    while (1);  // Error!
                flash_range_program((uint32_t) address, buf + 4, len);
                break;
            case 1:         // Exit
                stop = true;
                break;
            default:
                while (1);      // Error!
                break;
        }

        address = address + sizeof(buf) - 4;
        ack();
    }
}