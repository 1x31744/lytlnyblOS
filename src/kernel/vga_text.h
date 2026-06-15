#ifndef VGA_TEXT_H
#define VGA_TEXT_H

#include <stddef.h>
#include <stdint.h>

typedef enum vga_color {
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
};

struct vga_text {
    size_t row;
    size_t column;

    uint8_t fcolor;
    uint8_t bcolor;

    uint16_t* buffer;
};

// init
void vga_text_init(struct vga_text* vga);

//screen ops
//
void vga_text_clear(struct vga_text* vga);

/* cursor ops */
void vga_text_set_cursor(
    struct vga_text* vga,
    size_t row,
    size_t column
};

/* Color ops */
void vga_text_set_color(
    struct vga_text* vga,
    vga_color foreground,
    vga_color background
);

/* char out */
void vga_text_putchar(
    struct vga_text* vga,
    char c
);

/* string out */
void vga_text_write(
    struct vga_text* vga,
    const char* string
);

void vga_text_writeline(
    struct vga_text* vga,
    const char* string
);

/* num out */
void vga_text_write_dec(
    struct vga_text* vga,
    uint32_t value 
);

void vga_text_write_hex(
    struct vga_text* vga,
    uint32_t value
);

/* low level writing */

void vga_text_put_entry_at(
    struct vga_text* vga,
    char character,
    uint8_t fcolor,
    uint8_t bcolor,
    size_t row,
    size_t column
);
