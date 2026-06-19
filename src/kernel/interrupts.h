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

    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;

    uint32_t interrupt_number;
    uint32_t error_code;

    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t user_esp;
    uint32_t ss; 

} registers_t;

#define IDT_ENTRIES 256

void idt_init(void);

void idt_set_gate(
    uint8_t interrupt,
    uint32_t handler_address,
    uint16_t selector,
    uint8_t flags
);

void isr_handler(registers_t* regs);
void irq_handler(registers_t* regs);

void pic_remap(void);
void pic_send_eoi(uint8_t irq);

extern void idt_load(idtr_t* idtr);

extern void isr0(void);

#endif
