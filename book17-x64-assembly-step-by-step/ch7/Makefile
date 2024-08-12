# Chapter 7 Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
CC=gcc
LD=ld

all: 01-sandbox 02-tolower 03-arithmetic-ops

02-tolower: 02-tolower.o
	$(LD) -o $@ $<

03-arithmetic-ops: 03-arithmetic-ops.o
	$(LD) -o $@ $<

%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-sandbox 02-tolower 03-arithmetic-ops

