#ifndef VGA_TEXT_H
#define VGA_TEXT_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GREY,
    VGA_COLOR_DARK_GREY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_LIGHT_BROWN,
    VGA_COLOR_WHITE
} vga_color;

typedef struct {
    size_t row;
    size_t column;

    size_t width;
    size_t height;

    uint8_t fcolor;
    uint8_t bcolor;

    uint16_t* buffer;
} vga_text;

// init
void vga_text_init(vga_text* terminal);

//screen ops
//
void vga_text_clear( vga_text* terminal);

/* cursor ops */
void vga_text_set_cursor(
     vga_text* vga,
    size_t row,
    size_t column
);

/* Color ops */
void vga_text_set_color(
     vga_text* vga,
    vga_color foreground,
    vga_color background
);

/* char out */
void vga_text_putchar(
     vga_text* vga,
    char c
);

/* string out */
void vga_text_write(
     vga_text* vga,
    const char* string
);

void vga_text_writeline(
     vga_text* vga,
    const char* string
);

/* num out */
void vga_text_write_dec(
     vga_text* vga,
    uint32_t value 
);

void vga_text_write_hex(
     vga_text* vga,
    uint32_t value
);

/* low level writing */

void vga_text_put_entry_at(
    vga_text* vga,
    char character,
    uint8_t fcolor,
    uint8_t bcolor,
    size_t row,
    size_t column
);

#endif
