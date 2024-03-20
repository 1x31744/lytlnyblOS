BOOT_FILE = bootloader/bootloader.asm 
KERNEL_FILE = kernel/basic_kernel.asm 

build: $(BOOT_FILE) $(KERNEL_FILE)
	nasm -f bin $(BOOT_FILE) -o bootstrap.o
	nasm -f bin $(KERNEL_FILE) -o kernel.o
	dd if=bootstrap.o of=kernel.img
	dd seek=1 conv=sync if=kernel.o of=kernel.img bs=512
	qemu-system-x86_64 -s kernel.img
	
clean:
	rm -f *.o