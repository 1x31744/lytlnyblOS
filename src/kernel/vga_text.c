#include "vga_text.h"

void vga_text_init(vga_text* terminal) {
    terminal->row = 0;
    terminal->column = 0;

    terminal->fcolor = 0xF;
    terminal->bcolor = 0;

    terminal->width = 80;
    terminal->height = 25;

    terminal->buffer = (uint16_t*)0xB8000;
    vga_text_clear(terminal);
}

void vga_text_clear(vga_text* terminal) {
    uint8_t color = (terminal->bcolor << 4) | terminal->fcolor;

    uint16_t blank = ((uint16_t)color << 8) | ' ';

    for (size_t row = 0; row < terminal->height; row++) {
        for (size_t col = 0; col < terminal->width; col++) {
            size_t index = row * terminal->width + col;
            terminal->buffer[index] = blank;
        }
    }
    
    terminal->row = 0;
    terminal->column = 0;
    
}
