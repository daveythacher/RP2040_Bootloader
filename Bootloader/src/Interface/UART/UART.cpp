#include "Interface/UART/UART.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"

dma_channel_config UART::c;

UART::UART() : Interface() {
    gpio_init(28);
    gpio_set_dir(28, GPIO_IN);
    gpio_pull_up(28);

    gpio_init(0);
    gpio_init(1);
    gpio_set_dir(0, GPIO_OUT);
    gpio_set_dir(1, GPIO_IN);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    uart_init(uart0, 115200);

    c = dma_channel_get_default_config(0);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_8);
    channel_config_set_write_increment(&c, true);
    channel_config_set_read_increment(&c, false);
    channel_config_set_dreq(&c, DREQ_UART0_RX);
    dma_channel_set_irq1_enabled(0, true);
}

bool UART::enter(uint32_t *adr) {
    address = adr;

    ack();

    return gpio_get(28);
}

bool UART::can_read() {
    if (dma_channel_get_irq0_status(0)) {
        dma_hw->ints0 = 1 << 0;
        return false;
    }

    return true;
}

void UART::ack() {
    dma_channel_configure(0, &c, buf, &uart_get_hw(uart0)->dr, sizeof(buf), true);

    uart_puts(uart0, "ACK");
}
