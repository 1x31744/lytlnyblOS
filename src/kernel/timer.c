#include "timer.h"
#include "interrupts.h"
#include "vga_text.h"

static volatile uint64_t ticks;
static uint32_t freq;

void init_timer(uint32_t frequency) {
    freq = frequency;
    uint16_t divisor = 1193182 / frequency;

    /* tell pit how we send the divisor value and the mode*/
    outb(PIT_COMMAND, PIT_ACCESS_LOHIBYTE | PIT_MODE3);
    io_wait();

    /* write low and high bytes respectively */
    outb(PIT_CHANNEL0_DATA, divisor & 0xFF);
    outb(PIT_CHANNEL0_DATA, divisor << 8);
}
