#include <inttypes.h>
#include "pico/time.h"
#include "hardware/regs/m0plus.h"
#include "Interface/Interface.h"

static void switch_vtor(uint32_t adr) {
  uint32_t *ptr = (uint32_t *) (PPB_BASE + M0PLUS_VTOR_OFFSET);

  // TODO: disable Interputs?
  *ptr = adr & 0xFFFFFF00;
}

static void  __attribute__((naked)) start_app(uint32_t pc, uint32_t sp) {
    __asm("           \n\
          msr msp, r1 /* load r1 into MSP */\n\
          bx r0       /* branch to the address at r0 */\n\
    ");
}

int main() {
  uint32_t *app_code = (uint32_t *) (0x10000000 + 32768);
  uint32_t app_sp = app_code[0];
  uint32_t app_start = app_code[1];
  Interface *i = Interface::create();

  for (int x = 0; x < 10; x++) {
    if (i->enter(app_code))
      i->process();
    else 
      sleep_us(10);
  }

  switch_vtor(app_start);
  start_app(app_start, app_sp);

  while (1);
}
