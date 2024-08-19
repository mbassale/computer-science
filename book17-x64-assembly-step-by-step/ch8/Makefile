# Chapter 8 Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
LD=ld

all: 01-stack 02-uppercase

01-stack: 01-stack.o
	$(LD) -o $@ $<

02-uppercase: 02-uppercase.o
	$(LD) -o $@ $<

%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-stack 02-uppercase

