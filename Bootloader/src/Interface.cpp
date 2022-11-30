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