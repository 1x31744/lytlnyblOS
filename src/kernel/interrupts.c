#include "interrupts.h"
#include "vga_text.h"

extern vga_text terminal;

idt_entry_t idt[256];
idtr_t idtr;

static void memset(void* ptr, uint8_t val, uint32_t size) {
    uint8_t* p = ptr;

    for (uint32_t i = 0; i < size; i++) {
        p[i] = val;
    }
}

void idt_set_gate(
    uint8_t interrupt,
    uint32_t handler_address,
    uint16_t selector,
    uint8_t flags
) {
    idt[interrupt].offset_low = handler_address & 0xFFFF;

    idt[interrupt].selector = selector;

    idt[interrupt].reserved = 0;

    idt[interrupt].flags = flags;

    idt[interrupt].offset_high = (handler_address >> 16) & 0xFFFF;
}

void isr_handler(registers_t* regs) {
    vga_text_writeline(&terminal, "Exception occured");

    for(;;)
    {
    }
}

void idt_init(void) {
    memset(idt, 0, sizeof(idt));

    idtr.limit = sizeof(idt) - 1;

    idtr.base = (uint32_t)idt;

    idt_set_gate(
        0,
        (uint32_t)isr0,
        0x08,
        0x8E
    );

    idt_load(&idtr);
}
