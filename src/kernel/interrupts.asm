[BITS 32]

extern isr_handler

global idt_load
global isr0

idt_load:
    mov eax, [esp + 4]
    lidt [eax]
    ret

isr0:
    push dword 0
    call isr_handler
    add esp, 4
    iret
