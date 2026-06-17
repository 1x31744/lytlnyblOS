#include "vga_text.h"

vga_text terminal;

void kernel_main(void)
{
    volatile char* vga = (volatile char*)0xB8000;
    
    //signal that we have reached C
    vga[0] = 'C';
    vga[1] = 0x02;

    vga_text_init(&terminal);
    vga_text_putchar(&terminal, 'A');
    vga_text_writeline(&terminal, "hello does this write line work");
    vga_text_writeline(&terminal, "okay testingggg...?");
    vga_text_write_dec(&terminal, 1234);
    vga_text_write_hex(&terminal, 0xFA1F54B1);
    vga_text_put_entry_at(
        &terminal,
        'a',
        VGA_COLOR_GREEN,
        VGA_COLOR_BLUE,
        20,
        30);
    for (;;);
}
