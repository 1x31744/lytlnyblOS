ASM = C:\Program Files\NASM\nasm.exe
BOOT_FILE = bootloader/bootloader.asm 
KERNEL_FILE = kernel/basic_kernel.asm 
DD_WIN = C:\Users\TotallyOrdinaryPC\Documents\dd-0.6beta3\dd.exe
QEMU_WIN = C:\Program Files\qemu\qemu-system-x86_64.exe

build: $(BOOT_FILE) $(KERNEL_FILE)
	$(ASM) -f bin $(BOOT_FILE) -o bootstrap.o
	$(ASM) -f bin $(KERNEL_FILE) -o kernel.o
	$(DD_WIN) if=bootstrap.o of=kernel.img
	$(DD_WIN) seek=1 conv=sync if=kernel.o of=kernel.img bs=512
	$(QEMU_WIN) -s kernel.img
	
clean:
	rm -f *.o