# Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
LD=ld

all: 01-syscall

01-syscall: 01-syscall.o
	ld -o $@ $<

%.o : %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-syscall

