BOOT_FILE = bootloader/bootloader.asm 
KERNEL_FILE = kernel/basic_kernel.asm 
LINKER = kernel/linker.ld
        
build: $(BOOT_FILE) $(KERNEL_FILE)
	nasm -f bin $(BOOT_FILE) -o bootstrap.o
	nasm -f elf32 -g -F dwarf $(KERNEL_FILE) -o kernel.o
	ld -m elf_i386 -T $(LINKER) kernel.o -o kernel.elf
	objcopy -O binary kernel.elf kernel.bin
	dd if=bootstrap.o of=kernel.img
	dd if=kernel.bin of=kernel.img seek=1 conv=notrunc
	qemu-system-i386 -drive format=raw,file=kernel.img -s -S
            
clean:
	rm -f *.o

