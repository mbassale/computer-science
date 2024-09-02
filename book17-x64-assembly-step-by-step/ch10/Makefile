# Chapter 10 Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
LD=ld

all: 01-hexdump

01-hexdump: 01-hexdump.o
	$(LD) -o $@ $<

%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-hexdump

