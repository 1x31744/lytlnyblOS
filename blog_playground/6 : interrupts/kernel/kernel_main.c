#include "vga_text.h"
#include "interrupts.h"

vga_text terminal;

void kernel_main(void)
{
    volatile char* vga = (volatile char*)0xB8000;
    
    //signal that we have reached C
    vga[0] = 'C';
    vga[1] = 0x02;

    vga_text_init(&terminal);
    vga_text_writeline(&terminal, "Welcome to the lytlnybl kernel in real mode");
    vga_text_writeline(&terminal, "Interrupts coming soon...");

    idt_init();

    asm volatile("int $32");

    for (;;);
}
