#include <inttypes.h>
#include "Interface.h"

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
  bool has_timed_out = false;
  Interface *i = Interface::create();

  while (!has_timed_out) {
    if (0) {    // TODO:
        // TODO
        if (i->enter()) {
          // TODO:
        }
    }
    else
        has_timed_out = true;
  }

  start_app(app_start, app_sp);

  while (1);
}
