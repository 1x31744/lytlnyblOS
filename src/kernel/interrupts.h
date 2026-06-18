#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>
typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t reserved;
    uint8_t flags;
    uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtr_t;

/* registers passed from asm to C */
typedef struct {
    uint32_t ds;
    

} registers_t;

#define IDT_ENTRIES 256

void idt_init(void);

void idt_set_gate(
    uint8_t interrupt,
    uint32_t handler_address,
    uint16_t selector,
    uint8_t flags
);


#endif
