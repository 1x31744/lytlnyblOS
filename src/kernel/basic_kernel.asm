; no org code starts at 0x0900 though
start:
    mov ax, cs
    mov ds, ax

    mov si, hello_string
    call print_string

    jmp enter_protected

print_string:
    mov ah, 0Eh

print_char:
    lodsb ; sets al = [DS:SI++]

    cmp al, 0
    je done
    
    int 10h

    jmp print_char

done:
    ret

enter_protected:
    cli ;disable interrupts
    lgdt [gdtr] ; load GDT registor with start address of GDT
    mov eax, cr0
    or eax, 1 ;set protection enable bit in control register 0 (cr0)
    mov cr0, eax

    ; perform far jump to selector 08h (offset into GDT, pointing at a 32bit
    ; PM code segment descriptor)
    ; to load CS with proper PM32 descriptor)

    jmp dword 08h:p_mode_main
    jmp enter_protected

[bits 32]
p_mode_main:
    mov ax, 10h
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000
    ;mov dword [0xB8000], 0x07410741
hang:
    jmp hang

hello_string db 'Hello World!, i am lytlnyblOS, running in real mode', 0

gdt:

gdt_null:
    dq 0
gdt_code:
    dw 0FFFFh
    dw 0
    db 0
    db 10011010b ;
    db 11001111b
    db 0
gdt_data:
    dw 0FFFFh
    dw 0
    db 0
    db 10010010b
    db 11001111b
    db 0
gdt_end:
gdtr:
    dw gdt_end - gdt
    dd gdt

