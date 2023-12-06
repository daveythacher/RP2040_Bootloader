#include <stdio.h>
#include "Interface/CDC/CDC.h"
#include "hardware/gpio.h"
#include "pico/stdio_usb.h"

CDC::CDC() : Interface() {
    gpio_init(28);
    gpio_set_dir(28, GPIO_IN);
    gpio_pull_up(28);

    stdio_usb_init();
}

bool CDC::enter(uint32_t *adr) {
    address = adr;

    if (gpio_get(28)) {
        ack();
        
        return true;
    }

    return false;
}

bool CDC::can_read() {
    uint32_t counter = 0;

    while (counter < sizeof(buf)) {
        char c = getchar();
        
        if (c == EOF)
            while(1);

        buf[counter] = (uint8_t) c;
        ++counter;
    }

    return counter == sizeof(buf);
}

void CDC::ack() {
    printf("ACK");
}
