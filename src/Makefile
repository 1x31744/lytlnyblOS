ASM = nasm
CC = gcc
BOOT_FILE = bootloader/bootloader.asm 
INIT_KERNEL_FILES = starter.asm
KERNEL_FILES = main.c
KERNEL_FLAGS = -Wall -m32 -c -ffreestanding -fno-asynchronous-unwind-tables -fno-pie
KERNEL_OBJECT = -o kernel.elf

build: $(BOOT_FILE) $(KERNEL_FILE)
	$(ASM) -f bin $(BOOT_FILE) -o bootstrap.o
	$(ASM) -f bin $(KERNEL_FILE) -o kernel.o
	$(CC) $(KERNEL_FLAGS) $(KERNEL_FILES) $(KERNEL_OBJECT)
	ld -melf_i386 -Tlinker.ld starter.o kernel.elf -o lytlnybl.elf
	objcopy -0 binary 539kernel.elf 539kernel.bin
	dd if=bootstrap.o of=kernel.img
	dd seek=1 conv=sync if=lytlnybl.bin of=kernel.img bs=512 count=5
	dd seek=6 conv=sync if=/dev/zero of=kernel.img bs=512 count=2046
	qemu-system-x86_64 -s kernel.img
	
clean:
	rm -f *.owhar 